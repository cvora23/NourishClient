//
// Created by chivora on 1/22/18.
//
#include "Client.h"
#include "MyThread.h"
#include <sstream>
#include <iomanip>

Client::Client()
{
    sock = -1;
    port = 0;
    address = "";
}

bool Client::setup(string address , int port)
{
    if(sock == -1)
    {
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            cout << "Could not create socket" << endl;
        }
    }
    if(inet_addr(address.c_str()) == -1)
    {
        struct hostent *he;
        struct in_addr **addr_list;
        if ( (he = gethostbyname( address.c_str() ) ) == NULL)
        {
            herror("gethostbyname");
            cout<<"Failed to resolve hostname\n";
            return false;
        }
        addr_list = (struct in_addr **) he->h_addr_list;
        for(int i = 0; addr_list[i] != NULL; i++)
        {
            server.sin_addr = *addr_list[i];
            break;
        }
    }
    else
    {
        server.sin_addr.s_addr = inet_addr( address.c_str() );
    }
    server.sin_family = AF_INET;
    server.sin_port = htons( port );
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return false;
    }else{
        MyThread *recvThread = new MyThread();
        recvThread->Create((void*) Client::HandleReceiveMessages,this);
    }
    return true;
}

bool Client::Send(string data)
{
    if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
    {
        cout << "Send failed : " << data << endl;
        return false;
    }
    return true;
}

bool Client::Send(uint8_t* buffer, uint32_t size){
    if( send(sock , buffer, size , 0) < 0)
    {
        cout << "Send failed : " << buffer << endl;
        return false;
    }
    return true;
}

std::string hexStr(unsigned char* data, int len)
{
    std::stringstream ss;
    ss << std::hex;
    for(int i=0;i<len;++i)
        ss << std::setw(2) << std::setfill('0') << (int)data[i];
    return ss.str();
}

string Client::receive(int size)
{
    uint8_t buffer[size];
    memset(buffer,0,size);
    int recvSize = recv(sock,buffer,size,0);
    if( recvSize < 0)// sizeof(buffer)
    {
        cout << "receive failed!" << endl;
    }else{
        cout << "receive success" <<endl;
    }
    std::string reply = hexStr(buffer,recvSize);
    return reply;
}

string Client::read()
{
    char buffer[1] = {};
    string reply;
    while (buffer[0] != '\n') {
        if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
        {
            cout << "receive failed!" << endl;
            break;
        }
        reply += buffer[0];
    }
    return reply;
}

// This assumes buffer is at least x bytes long,
// and that the socket is blocking.
int Client::ReadXBytes(int x, uint8_t* buffer)
{
    int bytesRead = 0;
    int result;
    while (bytesRead < x)
    {
        result = recv(sock, buffer + bytesRead, x - bytesRead,0);
        //cout<<"received something"<<endl;
        if (result == -1 )
        {
            // Throw your error.
            cout<<"Connection error it seems"<<endl;
            break;
        }else if(result == 0){
            // connection dropped
            cout<<"Connection dropped it seems"<<endl;
            break;
        }
        cout <<"result = "<<result<<endl;
        bytesRead += result;
    }
    return result;
}

bool Client::handleHelloMessage(uint8_t* buffer,uint32_t size){
    bool result = false;
    HelloMessage helloMessage;
    deserializeHelloMsg(buffer,&helloMessage);
    cout << "Message received: " << helloMessage.msg << endl;
    return true;
}

bool Client::handleUpdateMessage(uint8_t* buffer,uint32_t size){
    bool result = false;
    PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = NULL;
    PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = NULL;
    deserializePublishUpdateMsg(buffer,&pPublishUpdateMessageTopicName,&pPublishUpdateMessageTopicContent);

    string topicName;
    topicName.assign(&pPublishUpdateMessageTopicName->topicName,&pPublishUpdateMessageTopicName->topicName + pPublishUpdateMessageTopicName->length);
    cout<<"TOPIC NAME = "<<topicName<<endl;
    string topicNameHex = hexStr(&pPublishUpdateMessageTopicName->topicName,pPublishUpdateMessageTopicName->length);
    cout<<"TOPIC NAME HEX = "<<topicNameHex<<endl;

    string topicContent;
    topicContent.assign(&pPublishUpdateMessageTopicContent->topicContent,&pPublishUpdateMessageTopicContent->topicContent + pPublishUpdateMessageTopicContent->length);
    cout<<"TOPIC CONTENT = "<<topicContent<<endl;
    string topicContentHex = hexStr(&pPublishUpdateMessageTopicContent->topicContent,pPublishUpdateMessageTopicContent->length);
    cout<<"TOPIC CONTENT HEX = "<<topicContentHex<<endl;

    return result;
}

void Client::processMessage(ProtocolMessageType protocolMessageType, uint8_t *buffer, uint32_t bufferSize) {

    switch (protocolMessageType){
        case HELLO_MSG:
        {
            cout <<"Received HELLO_MSG Message"<<endl;
            handleHelloMessage(buffer,bufferSize);
        }
        break;
        case UPDATE_MSG:
        {
            cout <<"Received UPDATE_MSG Message"<<endl;
            handleUpdateMessage(buffer,bufferSize);
        }
        break;
        default:
        {
            cout<<"Received INVALID_MSG Message"<<endl;
        }
        break;
    }

}

void * Client::HandleReceiveMessages(void *args){

    Client* client = (Client*)args;
    int n = 0;
    while(1){

        // Read first 5 bytes to get length of the message
        uint32_t msgHeaderBufLen = sizeof(uint32_t)+sizeof(uint8_t);
        uint8_t msgHeaderBuf[msgHeaderBufLen];
        memset(msgHeaderBuf,0,msgHeaderBufLen);
        n = client->ReadXBytes(msgHeaderBufLen,msgHeaderBuf);
        //Client disconnected?
        if(n == 0) {
            //close(client->sock);
            break;
        }
        else if(n < 0) {
            cerr << "Error while receiving message from client: " << endl;
            break;
        }
        MessageHeader messageHeader;
        deserializeMsgHeader(msgHeaderBuf,&messageHeader);

        // Allocated buffer of size msgSize - 5 to get remaining portion of the payload
        uint8_t *buffer = NULL;
        uint32_t bufferSize = messageHeader.size-(sizeof(messageHeader.size) + sizeof(messageHeader.type));
        buffer = new uint8_t[bufferSize];
        // Read the payload section of the message
        n = client->ReadXBytes(bufferSize,buffer);
        cout<<" n = "<<n<<endl;

        //Client disconnected?
        if(n == 0) {
            //close(client->sock);
            break;
        }
        else if(n < 0) {
            cerr << "Error while receiving message from client: " << endl;
        }
        else {
            //Message received. Send to all clients.
            //snprintf(message, sizeof message, "<%s>: %s", client->name, buffer);
            //Server::SendToAll(message);
            client->processMessage(static_cast<ProtocolMessageType>(messageHeader.type),buffer,bufferSize);
        }
    }
    return NULL;
}

bool Client::tearDown(){
    close(sock);
    return true;
}

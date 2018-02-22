#include <iostream>
#include "Client.h"
#include "ProtocolMessage.h"

/* Catch Signal Handler function */
void signal_callback_handler(int signum){

    printf("Caught signal SIGPIPE %d\n",signum);
}

bool validateTopicName(string topicName) {

    /*
     * empty topicName
     */
    if(topicName.empty()){
        return false;
    }

    /*
     * string length cannot be more than 255
     */
    int topicNameLen = topicName.length();
    if(topicNameLen > 255){
        return false;
    }
    /*
     * the string may not start with or end with '-'
     */
    if((topicName[0] == '-') || (topicName[topicNameLen-1] == '-')){
        return false;
    }

    bool foundDash = false;
    for(int i=0;i<topicNameLen;i++){
        /*
         * string must contain only a-z0-9 (note, no uppercase) and '-' character
         */
        if((topicName[i] >='a' && topicName[i] <='a'+25) ||  ((topicName[i] >=48 && topicName[i] <=57)) || (topicName[i] == '-')){
            // No two '-' can be in a row
            if(topicName[i] == '-'){
                // if found two in a row, invalidate topicName
                if(foundDash){
                    return false;
                }else{
                    // found first time
                    foundDash = true;
                }
            }else{
                foundDash = false;
            }
        }else{
            return false;
        }
    }
    /*
     * Passed all validations
     */
    return true;
}

bool validateTopicContent(string topicContent) {

    /*
    * empty topicContent
    */
    if(topicContent.empty()){
        return false;
    }

    /*
    * string length cannot be more than 255
    */
    int topicContentLen = topicContent.length();
    if(topicContentLen > 255){
        return false;
    }

    /*
     * topicContent with only whitespaces
     */
    if(topicContent.find_first_not_of(' ') == std::string::npos)
    {
        // there are only spaces.
        return false;
    }

    for(int i=0;i<topicContentLen;i++){
        /*
         * string must contain only a-zA-Z0-9 and spaces
         */
        if((topicContent[i] >='a' && topicContent[i] <='a'+25) ||  ((topicContent[i] >='A' && topicContent[i] <='A'+25)) ||
           ((topicContent[i] >=48 && topicContent[i] <=57)) || (topicContent[i] == ' ')){
            // all good
        }else{
            return false;
        }
    }

    /*
     * Passed all validations
     */
    return true;
}


int main(int argc, char *argv[])
{
    /*
     * Topic Name and Topic Content UT's
     */
    {
        std::vector<char> chars(255);
        std::fill(chars.begin(),chars.end(),'5'); // fill all 256 sized buffer with 5
        string topicName(chars.begin(),chars.end());
        cout<<validateTopicName(topicName)<<endl;
        cout<<validateTopicContent(topicName)<<endl;
    }

    {
        string topicName("ag");
        cout<<validateTopicName(topicName)<<endl;
    }

    {
        string topicContent("   s   ");
        cout<<validateTopicContent(topicContent)<<endl;
    }

    // Handling SIGPIPE in case the socket to send/write is shutdown for writing or not connected anymore
    signal(SIGPIPE, signal_callback_handler);

    Client tcp[6];
    for(int i=0;i<6;i++)
    {
        if(!tcp[i].setup("127.0.0.1",12345)){
            cout<<"Connection setup failed"<<endl;
            exit(1);
        }


        // sleep for 5 seconds so receive thread is ready to receive any response to the first message - should cause error as server expects hello withing 100 ms
        int no_of_mill_sec = 5;
        usleep(1000 * no_of_mill_sec);

        {
            /*
             * Create Hello Message
             */
            MessageHeader *messageHeader = new MessageHeader;
            HelloMessage *helloMessage = new HelloMessage;
            createHelloMsg(messageHeader,helloMessage);
            uint8_t buffer[4096], *ptr;
            ptr = serializeHelloMsg(buffer,messageHeader,helloMessage);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            delete messageHeader;
            delete helloMessage;
        }

        sleep(1);

        {
            /*
             * Subscribe to a Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            SubUnsubMessage *pSubUnsubMessage = NULL;
            createSubUnsubMsg(messageHeader,SUB_MSG,&pSubUnsubMessage,"test-topic");
            uint8_t buffer[4096], *ptr;
            ptr = serializeSubUnsubMsg(buffer,messageHeader,pSubUnsubMessage);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pSubUnsubMessage);
            delete messageHeader;
        }

        sleep(1);

        {
            /*
             * Publish a Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = NULL;
            PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = NULL;
            createPublishUpdateMsg(messageHeader,PUB_MSG,&pPublishUpdateMessageTopicName,"test-topic",&pPublishUpdateMessageTopicContent,"test topic content");
            uint8_t buffer[4096], *ptr;
            ptr = serializePublishUpdateMsg(buffer,messageHeader,pPublishUpdateMessageTopicName,pPublishUpdateMessageTopicContent);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pPublishUpdateMessageTopicName);
            free(pPublishUpdateMessageTopicContent);
            delete messageHeader;
        }
        sleep(1);

        {
            /*
             * Subscribe to a New Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            SubUnsubMessage *pSubUnsubMessage = NULL;
            createSubUnsubMsg(messageHeader,SUB_MSG,&pSubUnsubMessage,"test-topic-2");
            uint8_t buffer[4096], *ptr;
            ptr = serializeSubUnsubMsg(buffer,messageHeader,pSubUnsubMessage);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pSubUnsubMessage);
            delete messageHeader;
        }

        sleep(1);


        {
            /*
             * Publish a New Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = NULL;
            PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = NULL;
            createPublishUpdateMsg(messageHeader,PUB_MSG,&pPublishUpdateMessageTopicName,"test-topic-2",&pPublishUpdateMessageTopicContent,"test topic content 2");
            uint8_t buffer[4096], *ptr;
            ptr = serializePublishUpdateMsg(buffer,messageHeader,pPublishUpdateMessageTopicName,pPublishUpdateMessageTopicContent);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pPublishUpdateMessageTopicName);
            free(pPublishUpdateMessageTopicContent);
            delete messageHeader;
        }
        sleep(1);
        {
            /*
             * Un Subscribe to a Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            SubUnsubMessage *pSubUnsubMessage = NULL;
            createSubUnsubMsg(messageHeader,UNSUB_MSG,&pSubUnsubMessage,"test-topic");
            uint8_t buffer[4096], *ptr;
            ptr = serializeSubUnsubMsg(buffer,messageHeader,pSubUnsubMessage);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pSubUnsubMessage);
            delete messageHeader;
        }

        sleep(1);

        {
            /*
             * Publish a Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = NULL;
            PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = NULL;
            createPublishUpdateMsg(messageHeader,PUB_MSG,&pPublishUpdateMessageTopicName,"test-topic",&pPublishUpdateMessageTopicContent,"test topic content new");
            uint8_t buffer[4096], *ptr;
            ptr = serializePublishUpdateMsg(buffer,messageHeader,pPublishUpdateMessageTopicName,pPublishUpdateMessageTopicContent);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pPublishUpdateMessageTopicName);
            free(pPublishUpdateMessageTopicContent);
            delete messageHeader;
        }
        sleep(1);

        {
            /*
             * Publish a Topic
             */
            MessageHeader *messageHeader = new MessageHeader;
            PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = NULL;
            PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = NULL;
            createPublishUpdateMsg(messageHeader,PUB_MSG,&pPublishUpdateMessageTopicName,"test-topic-2",&pPublishUpdateMessageTopicContent,"test topic content new");
            uint8_t buffer[4096], *ptr;
            ptr = serializePublishUpdateMsg(buffer,messageHeader,pPublishUpdateMessageTopicName,pPublishUpdateMessageTopicContent);
            if(tcp[i].Send(buffer,ptr-buffer))
            {
                cout<<"Client sent successfully"<<endl;
            }
            free(pPublishUpdateMessageTopicName);
            free(pPublishUpdateMessageTopicContent);
            delete messageHeader;
        }
        sleep(1);

        tcp[i].tearDown();

    }

    return 0;
}
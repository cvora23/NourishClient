//
// Created by chivora on 1/22/18.
//

#ifndef NOURISHCLIENT_CLIENT_H
#define NOURISHCLIENT_CLIENT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>
#include "ProtocolMessage.h"

using namespace std;

class Client
{
private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;
    static void * HandleReceiveMessages(void *args);
    void processMessage(ProtocolMessageType protocolMessageType, uint8_t *buffer, uint32_t bufferSize);
    bool handleUpdateMessage(uint8_t* buffer,uint32_t size);
    bool handleHelloMessage(uint8_t* buffer,uint32_t size);

public:
    Client();
    bool setup(string address, int port);
    bool Send(uint8_t *buffer, uint32_t size);
    bool Send(string data);
    string receive(int size = 4096);
    string read();
    int ReadXBytes(int x, uint8_t* buffer);
    bool tearDown();
};

#endif //NOURISHCLIENT_CLIENT_H

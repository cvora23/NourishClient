//
// Created by chivora on 1/24/18.
//

#ifndef NOURISHCLIENT_PROTOCOLMESSAGE_H
#define NOURISHCLIENT_PROTOCOLMESSAGE_H

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

typedef enum _ProtocolMessageType{
    HELLO_MSG = 0X01,
    SUB_MSG = 0X02,
    UNSUB_MSG = 0X03,
    UPDATE_MSG = 0X04,
    PUB_MSG = 0X05,
    INVALID_MSG
}ProtocolMessageType;

typedef struct _MessageHeader{
    uint32_t    size;
    uint8_t     type;
}MessageHeader;

typedef struct _HelloMessage{
    uint8_t     msg[5];
}HelloMessage;

typedef struct _PublishUpdateMessageTopicName{
    uint16_t length;
    uint8_t topicName;
}PublishUpdateMessageTopicName;

typedef struct _PublishUpdateMessageTopicContent{
    uint16_t length;
    uint8_t topicContent;
}PublishUpdateMessageTopicContent;

typedef struct _SubUnsubMessage{
    uint8_t topicName;
}SubUnsubMessage;

uint8_t * serialize_uint32(uint8_t* buffer,uint32_t value);
uint8_t * deserialize_uint32(uint8_t* buffer,uint32_t *value);
uint8_t * serialize_uint16(uint8_t* buffer,uint16_t value);
uint8_t * deserialize_uint16(uint8_t* buffer,uint16_t *value);
uint8_t * serialize_uint8(uint8_t* buffer,uint8_t value);
uint8_t * deserialize_uint8(uint8_t* buffer,uint8_t *value);
uint8_t * serialize_charBuf(uint8_t* buffer,uint8_t* buf,uint32_t size);
uint8_t * deserialize_charBuf(uint8_t* buffer,uint8_t* buf,uint32_t size);

uint8_t * serializeMessageHeader(uint8_t* buffer,MessageHeader* messageHeader);
uint8_t * deserializeMsgHeader(uint8_t* buffer,MessageHeader* messageHeader);

void createHelloMsg(MessageHeader* messageHeader,HelloMessage* helloMessage);
uint8_t * serializeHelloMsg(uint8_t* buffer,MessageHeader* messageHeader,HelloMessage* helloMessage);
uint8_t * deserializeHelloMsg(uint8_t* buffer,HelloMessage* helloMessage);

void createPublishUpdateMsg(MessageHeader *messageHeader,ProtocolMessageType protocolMessageType, PublishUpdateMessageTopicName **ppPublishUpdateMessageTopicName,string topicName,
                            PublishUpdateMessageTopicContent **ppPublishUpdateMessageTopicContent,string topicContent);
uint8_t * serializePublishUpdateMsg(uint8_t* buffer,MessageHeader* messageHeader,PublishUpdateMessageTopicName* publishUpdateMessageTopicName,
                                    PublishUpdateMessageTopicContent* publishUpdateMessageTopicContent);
uint8_t *deserializePublishUpdateMsg(uint8_t *buffer, PublishUpdateMessageTopicName **ppPublishUpdateMessageTopicName,
                                     PublishUpdateMessageTopicContent **ppPublishUpdateMessageTopicContent);

void createSubUnsubMsg(MessageHeader *messageHeader,ProtocolMessageType protocolMessageType, SubUnsubMessage **ppSubUnsubMessage,string topicName);
uint8_t * serializeSubUnsubMsg(uint8_t* buffer,MessageHeader* messageHeader,SubUnsubMessage* subUnsubMessage);
uint8_t *deserializeSubUnsubMsg(uint8_t *buffer,uint32_t size, SubUnsubMessage **ppSubUnsubMessage);


#endif //NOURISHCLIENT_PROTOCOLMESSAGE_H

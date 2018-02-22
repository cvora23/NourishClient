//
// Created by chivora on 1/25/18.
//

#include "ProtocolMessage.h"

uint8_t* serialize_uint32(uint8_t* buffer,uint32_t value){
    uint32_t nValue = htonl(value);
    memcpy(buffer,&nValue,sizeof(uint32_t));
    return buffer + sizeof(uint32_t);
}

uint8_t* deserialize_uint32(uint8_t* buffer,uint32_t *value){
    memcpy(value,buffer,sizeof(uint32_t));
    *value = ntohl(*value);
    return buffer + sizeof(uint32_t);
}

uint8_t* serialize_uint16(uint8_t* buffer,uint16_t value){
    uint16_t nValue = htons(value);
    memcpy(buffer,&nValue,sizeof(uint16_t));
    return buffer + sizeof(uint16_t);
}

uint8_t* deserialize_uint16(uint8_t* buffer,uint16_t *value){
    memcpy(value,buffer,sizeof(uint16_t));
    *value = ntohs(*value);
    return buffer + sizeof(uint16_t);
}

uint8_t* serialize_uint8(uint8_t* buffer,uint8_t value){
    memcpy(buffer,&value,sizeof(uint8_t));
    return buffer + sizeof(uint8_t);
}

uint8_t* deserialize_uint8(uint8_t* buffer,uint8_t *value){
    memcpy(value,buffer,sizeof(uint8_t));
    return buffer + sizeof(uint8_t);
}

uint8_t* serialize_charBuf(uint8_t* buffer,uint8_t* buf,uint32_t size){
    memcpy(buffer,buf,size);
    return buffer + size;
}

uint8_t* deserialize_charBuf(uint8_t* buffer,uint8_t* buf,uint32_t size){
    memcpy(buf,buffer,size);
    return buffer + size;
}

uint8_t* serializeMessageHeader(uint8_t* buffer,MessageHeader* messageHeader){
    buffer = serialize_uint32(buffer,messageHeader->size);
    buffer = serialize_uint8(buffer,messageHeader->type);
    return buffer;
}

uint8_t * deserializeMsgHeader(uint8_t* buffer,MessageHeader* messageHeader){
    buffer = deserialize_uint32(buffer,&messageHeader->size);
    buffer = deserialize_uint8(buffer,&messageHeader->type);
    return buffer;
}

void createHelloMsg(MessageHeader* messageHeader,HelloMessage* helloMessage){
    memset(helloMessage->msg,0,5);
    memcpy(helloMessage->msg,"hello",5);
    messageHeader->type = HELLO_MSG;
    uint32_t msgSize = sizeof(uint32_t)+sizeof(uint8_t)+sizeof(helloMessage->msg);
    messageHeader->size = msgSize;
}

uint8_t * serializeHelloMsg(uint8_t* buffer,MessageHeader* messageHeader,HelloMessage* helloMessage){
    buffer = serializeMessageHeader(buffer,messageHeader);
    buffer = serialize_charBuf(buffer,helloMessage->msg,5);
    return buffer;
}

uint8_t * deserializeHelloMsg(uint8_t* buffer,HelloMessage* helloMessage){
    buffer = deserialize_charBuf(buffer,helloMessage->msg,5);
    return buffer;
}

void createPublishUpdateMsg(MessageHeader *messageHeader,ProtocolMessageType protocolMessageType, PublishUpdateMessageTopicName **ppPublishUpdateMessageTopicName,string topicName,
                            PublishUpdateMessageTopicContent **ppPublishUpdateMessageTopicContent,string topicContent) {
    PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = *ppPublishUpdateMessageTopicName;
    if(pPublishUpdateMessageTopicName == NULL && !topicName.empty()){
        uint16_t topicNameLen = (uint16_t)topicName.size();
        pPublishUpdateMessageTopicName = (PublishUpdateMessageTopicName*)malloc(sizeof(uint16_t) + topicNameLen);
        pPublishUpdateMessageTopicName->length = topicNameLen;
        memcpy(&pPublishUpdateMessageTopicName->topicName,topicName.c_str(),topicNameLen);
    }
    PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = *ppPublishUpdateMessageTopicContent;
    if(pPublishUpdateMessageTopicContent == NULL && !topicContent.empty()){
        uint16_t topicContentLen = (uint16_t)topicContent.size();
        pPublishUpdateMessageTopicContent = (PublishUpdateMessageTopicContent*)malloc(sizeof(uint16_t) + topicContentLen);
        pPublishUpdateMessageTopicContent->length = topicContentLen;
        memcpy(&pPublishUpdateMessageTopicContent->topicContent,topicContent.c_str(),topicContentLen);
    }
    *ppPublishUpdateMessageTopicName = pPublishUpdateMessageTopicName;
    *ppPublishUpdateMessageTopicContent = pPublishUpdateMessageTopicContent;
    if(messageHeader){
        messageHeader->type = protocolMessageType;
    }
    uint32_t msgSize = sizeof(uint32_t)+sizeof(uint8_t) +
                       sizeof (pPublishUpdateMessageTopicName->length) + pPublishUpdateMessageTopicName->length +
                       sizeof (pPublishUpdateMessageTopicContent->length) + pPublishUpdateMessageTopicContent->length;
    messageHeader->size = msgSize;
}

uint8_t *
serializePublishUpdateMsg(uint8_t* buffer,MessageHeader* messageHeader,PublishUpdateMessageTopicName* publishUpdateMessageTopicName,
                          PublishUpdateMessageTopicContent* publishUpdateMessageTopicContent) {
    buffer = serializeMessageHeader(buffer,messageHeader);
    buffer = serialize_uint16(buffer,publishUpdateMessageTopicName->length);
    buffer = serialize_charBuf(buffer,&publishUpdateMessageTopicName->topicName,publishUpdateMessageTopicName->length);
    buffer = serialize_uint16(buffer,publishUpdateMessageTopicContent->length);
    buffer = serialize_charBuf(buffer,&publishUpdateMessageTopicContent->topicContent,publishUpdateMessageTopicContent->length);
    return buffer;
}

uint8_t *
deserializePublishUpdateMsg(uint8_t *buffer, PublishUpdateMessageTopicName **ppPublishUpdateMessageTopicName,
                                     PublishUpdateMessageTopicContent **ppPublishUpdateMessageTopicContent) {
    PublishUpdateMessageTopicName *pPublishUpdateMessageTopicName = *ppPublishUpdateMessageTopicName;
    if(pPublishUpdateMessageTopicName == NULL){
        uint16_t topicNameLen = 0;
        buffer = deserialize_uint16(buffer,&topicNameLen);
        pPublishUpdateMessageTopicName = (PublishUpdateMessageTopicName*)malloc(sizeof(uint16_t) + topicNameLen);
        pPublishUpdateMessageTopicName->length = topicNameLen;
        buffer = deserialize_charBuf(buffer,&pPublishUpdateMessageTopicName->topicName,pPublishUpdateMessageTopicName->length);
    }
    PublishUpdateMessageTopicContent *pPublishUpdateMessageTopicContent = *ppPublishUpdateMessageTopicContent;
    if(pPublishUpdateMessageTopicContent == NULL){
        uint16_t topicContentLen = 0;
        buffer = deserialize_uint16(buffer,&topicContentLen);
        pPublishUpdateMessageTopicContent = (PublishUpdateMessageTopicContent*)malloc(sizeof(uint16_t) + topicContentLen);
        pPublishUpdateMessageTopicContent->length = topicContentLen;
        buffer = deserialize_charBuf(buffer,&pPublishUpdateMessageTopicContent->topicContent,pPublishUpdateMessageTopicContent->length);
    }
    *ppPublishUpdateMessageTopicName = pPublishUpdateMessageTopicName;
    *ppPublishUpdateMessageTopicContent = pPublishUpdateMessageTopicContent;
    return buffer;
}

void createSubUnsubMsg(MessageHeader *messageHeader,ProtocolMessageType protocolMessageType, SubUnsubMessage **ppSubUnsubMessage, string topicName) {
    SubUnsubMessage *pSubUnsubMessage = *ppSubUnsubMessage;
    uint32_t topicNameLen = topicName.size();
    if(pSubUnsubMessage == NULL && !topicName.empty()){
        pSubUnsubMessage = (SubUnsubMessage*)malloc(topicNameLen);
        memcpy(&pSubUnsubMessage->topicName,topicName.c_str(),topicNameLen);
    }
    *ppSubUnsubMessage = pSubUnsubMessage;
    if(messageHeader){
        messageHeader->type = protocolMessageType;
    }
    uint32_t msgSize = sizeof(uint32_t)+sizeof(uint8_t) +topicNameLen;
    messageHeader->size = msgSize;
}

uint8_t *serializeSubUnsubMsg(uint8_t *buffer, MessageHeader *messageHeader, SubUnsubMessage *subUnsubMessage) {
    buffer = serializeMessageHeader(buffer,messageHeader);
    uint32_t topicNameLen = messageHeader->size - (sizeof(uint32_t)+sizeof(uint8_t));
    buffer = serialize_charBuf(buffer,&subUnsubMessage->topicName,topicNameLen);
    return buffer;
}

uint8_t *deserializeSubUnsubMsg(uint8_t *buffer,uint32_t size, SubUnsubMessage **ppSubUnsubMessage) {
    SubUnsubMessage *pSubUnsubMessage = *ppSubUnsubMessage;
    if(pSubUnsubMessage == NULL){
        pSubUnsubMessage = (SubUnsubMessage*)malloc(size);
        buffer = deserialize_charBuf(buffer,&pSubUnsubMessage->topicName,size);
    }
    *ppSubUnsubMessage = pSubUnsubMessage;
    return buffer;
}



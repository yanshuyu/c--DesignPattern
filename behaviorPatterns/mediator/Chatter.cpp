#include"Chatter.h"
#include"IMediator.h"
#include<iostream>

Chatter::Chatter(const std::string& name, IMediator* mediator, bool logMessage):IColleague(name, mediator)
, m_shouldLogMessage(logMessage) {

}

void Chatter::recevie(IMessage* msg) {
    if (m_shouldLogMessage) {
        std::cout << msg->m_senderName << ": " << msg->m_content << std::endl;
    }

    if (msg->m_targetId != -1) {
        std::cout << m_name << " got private message from " << msg->m_senderName << ": " << msg->m_content << std::endl;
    }
}

void Chatter::sent(IMessage* msg) {
    if (m_mediator != nullptr) {
        m_mediator->broadcastMessage(msg);
    }
}
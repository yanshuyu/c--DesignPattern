#include"ChatRoom.h"

ChatRoom::~ChatRoom() {
    for(auto chatter : m_chatters) {
        delete chatter.second;
    }
    m_chatters.clear();
}


void ChatRoom::join(IColleague* colleague) {
    if (m_chatters.find(colleague->getId()) == m_chatters.end()) {
        m_chatters[colleague->getId()] = colleague;
        auto joinMsg = std::unique_ptr<IMessage>(new IMessage("room", 0, -1, std::string(colleague->getName() + " join")));
        broadcastMessage(joinMsg.get());
    }
}

void ChatRoom::leave(IColleague* colleague) {
    auto pos = m_chatters.find(colleague->getId());
    if (pos != m_chatters.end()) {
        auto leaveMsg = std::unique_ptr<IMessage>(new IMessage("room", 0, -1, colleague->getName() + " leave"));
        broadcastMessage(leaveMsg.get());
        delete pos->second;
        m_chatters.erase(pos);
    }
}

void ChatRoom::broadcastMessage(IMessage* msg) {
    if (msg->m_targetId == -1) {
        for (auto chatter : m_chatters) {
            chatter.second->recevie(msg);
        }
    } else {
        auto targetChatter = m_chatters.find(msg->m_targetId);
        if (targetChatter != m_chatters.end()) {
            targetChatter->second->recevie(msg);
        }
    }
}
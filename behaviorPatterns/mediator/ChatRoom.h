#pragma once
#include"IMediator.h"
#include"IColleague.h"
#include<unordered_map>
#include<memory>


class ChatRoom: public IMediator {
public:
    ~ChatRoom();
    
    void join(IColleague* colleague) override;
    void leave(IColleague* colleague) override;
    void broadcastMessage(IMessage* msg) override;

private:
    std::unordered_map<int, IColleague*> m_chatters;
};
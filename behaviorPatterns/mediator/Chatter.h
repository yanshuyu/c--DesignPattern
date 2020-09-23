#pragma once
#include"IColleague.h"


class Chatter: public IColleague {
public:
    Chatter(const std::string& name, IMediator* mediator, bool logMessage = false);
    void recevie(IMessage* msg) override;
    void sent(IMessage* msg) override;
    bool m_shouldLogMessage;
};
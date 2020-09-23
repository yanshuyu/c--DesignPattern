#pragma once

class IColleague;
class IMessage;

class IMediator {
public:
    virtual ~IMediator() {};

    virtual void join(IColleague* colleague) = 0;
    virtual void leave(IColleague* colleague) = 0;
    virtual void broadcastMessage(IMessage* msg) = 0;
};
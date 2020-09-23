#pragma once
#include<string>

class IMediator;
class IColleague;

class IMessage {
public:
    static IMessage* makeMessage(IColleague* sender, const std::string& msg, int target = -1);

public:
    IMessage(const std::string& senderName, int senderId, int targetId, const std::string& content);
    virtual ~IMessage() {}
    
    std::string m_content;
    std::string m_senderName;
    int m_senderId;
    int m_targetId;

};


class IColleague {
    friend class IMediator;
public:
    IColleague(const std::string& name, IMediator* mediator);
    virtual ~IColleague() {}
    
    virtual void recevie(IMessage* msg) = 0;
    virtual void sent(IMessage* msg) = 0;
    
    std::string getName() const {
        return m_name;
    }

    int getId() const {
        return m_id;
    }

    IMediator* getMedia() const {
        return m_mediator;
    }

    void setMediator(IMediator* mediator) {
        m_mediator = mediator;
    }

protected:
    std::string m_name;
    int m_id;
    IMediator* m_mediator;
};
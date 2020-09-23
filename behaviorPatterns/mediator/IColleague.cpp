#include"IColleague.h"


IMessage* IMessage::makeMessage(IColleague* sender, const std::string& msg, int target) {
    return new IMessage(sender->getName(), sender->getId(), target, msg);
}


IMessage::IMessage(const std::string& senderName, int senderId, int targetId, const std::string& content) {
    m_senderName = senderName;
    m_senderId = senderId;
    m_targetId = targetId;
    m_content = content;
}



IColleague::IColleague(const std::string& name, IMediator* mediator) {
    m_mediator = mediator;
    m_name = name;
    m_id = reinterpret_cast<int>(this);
}
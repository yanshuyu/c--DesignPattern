#include"TelegramWrappers.h"
#include<iostream>
#include<algorithm>
#include<sstream>

TelegramWrapper::TelegramWrapper(Telegram* t):m_wraptee(t) {

}

bool TelegramWrapper::sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) {
    if (m_wraptee != nullptr)
        return m_wraptee->sendMessage(c, target, msg);
    return false;
}

void TelegramWrapper::reviceMessage(int source, const std::string& msg) {
    if (m_wraptee != nullptr)
        m_wraptee->reviceMessage(source, msg);
}


int TelegramWrapper::getId() const {
    if (m_wraptee != nullptr)
        return m_wraptee->getId();
    return 0;
}


void TelegramWrapper::setId(int id) {
    if (m_wraptee != nullptr)
        m_wraptee->setId(id);
}



EncryptedTelegramWrapper::EncryptedTelegramWrapper(Telegram* t):TelegramWrapper(t) {
    
}


bool EncryptedTelegramWrapper::sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) {
    if (m_wraptee != nullptr)
        return m_wraptee->sendMessage(c, target, encrypt(msg));
    return false;
}

void EncryptedTelegramWrapper::reviceMessage(int source, const std::string& msg) {
    std::cout << "id(" << getId() << ") recevie message from id(" << source << ") encrypted: " << msg << std::endl;
    if (m_wraptee != nullptr)
        m_wraptee->reviceMessage(source, deEncrypt(msg));
}


std::string EncryptedTelegramWrapper::encrypt(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

std::string EncryptedTelegramWrapper::deEncrypt(const std::string& s) {
    return std::string(s.rbegin(), s.rend()); 
}



CompressionTelegramWrapper::CompressionTelegramWrapper(Telegram* t):TelegramWrapper(t) {

}

bool CompressionTelegramWrapper::sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) {
    if(m_wraptee != nullptr) 
        return m_wraptee->sendMessage(c, target, compress(msg));
    return false;
}

void CompressionTelegramWrapper::reviceMessage(int source, const std::string& msg) {
   std::cout << "id(" << getId() << ") recevie message from id(" << source << ") compressed: " << msg << std::endl;
   if (m_wraptee != nullptr)
        m_wraptee->reviceMessage(source, deCompress(msg));
}

std::string CompressionTelegramWrapper::compress(const std::string& s) {
    std::stringstream result;
    std::for_each(s.begin(), s.end(), [&](std::string::value_type c) {
        result << int(c) << " ";
    });
    return result.str();
}

std::string CompressionTelegramWrapper::deCompress(const std::string& s) {
    std::stringstream ss(s);
    std::string result;
    int code = 0;
    do {
        ss >> code;
        if (!ss.good())
            break;

        result.push_back(char(code));
    } while (ss.good());
    
    return result;
}
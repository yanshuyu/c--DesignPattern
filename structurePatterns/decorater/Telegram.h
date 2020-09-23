#pragma once
#include<string>
#include<memory>
#include<iostream>

class Telegram;

class CommunicationCenter {
public:
    virtual ~CommunicationCenter() {}
    virtual bool forwardMessage(int source, int target, const std::string& msg) const = 0;
    virtual void addCommunicator(Telegram* t) = 0;
    virtual bool hasCommunicator(int id) const = 0;
    virtual void removeCommunicator(int id) = 0;
};


class Telegram {
public:
    virtual ~Telegram() {}
    
    virtual bool sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) = 0;
    virtual void reviceMessage(int source, const std::string& msg) = 0;
    virtual int getId() const = 0;
    virtual void setId(int id) = 0;
};



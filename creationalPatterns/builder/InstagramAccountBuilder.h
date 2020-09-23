#pragma once 
#include"InstagramAccount.h"
#include<stdexcept>


class AccoutBuildException: public std::logic_error {
public:
    AccoutBuildException(InstagramAccount::CreationError e, const char* msg);

public:
    InstagramAccount::CreationError error;
};


class InstagramAccountBuilder {
public:
    InstagramAccount build();
    void subscribTopic(InterestTopic t);
    void unSubscribTopic(InterestTopic t);

public:
    std::string email;
    std::string password;
    std::string nickName;
    std::string realName;
    std::string career;
    std::string address;
    std::string phone;
    std::string description;

    size_t age;
    std::string height;
    std::string weight;
    Gender gender;
    std::unordered_set<InterestTopic> topics;
};
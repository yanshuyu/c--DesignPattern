#pragma once
#include<string>
#include<unordered_set>
#include<iostream>


enum class Gender {
    Male,
    Female,
    Secrect,
};


enum class InterestTopic {
    Food,
    Art,
    Tecnology,
    Writting,
    Travel,
    Photography,
    Movie,
    Joke,
    Beauty,
    Stock,
};



struct InstagramAccount {
    enum class CreationError {
        MissEmail,
        MissPassword,
        MissNickName,
    };

    const std::string email;
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

    InstagramAccount(const std::string& email, const std::string& password);
    InstagramAccount(const std::string& email, const std::string& password, const std::string& nick);
    

    bool hasSubscribedTopic(InterestTopic t)const;
    size_t subscribedTopicCount() const;
    void subscribTopic(InterestTopic t);
    void unSubscribTopic(InterestTopic t);
};


std::string genderToString(Gender g);
std::string topicToString(InterestTopic t);
std::ostream& operator << (std::ostream& o, const InstagramAccount& account);


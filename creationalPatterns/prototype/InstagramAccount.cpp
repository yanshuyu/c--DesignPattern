#include"InstagramAccount.h"
#include<algorithm>
#include<vector>


InstagramAccount::InstagramAccount(const std::string& email, const std::string& password):InstagramAccount(email, password, "") {

}

InstagramAccount::InstagramAccount(const std::string& email, const std::string& password, const std::string& nick):email(email)
,password(password)
,nickName(nick) {

}

InstagramAccount::InstagramAccount(const InstagramAccount& other):email(other.email) {
    this->age = other.age;
    this->address = other.address;
    this ->career = other.career;
    this->description = other.description;
    this->gender = other.gender;
    this->weight = other.weight;
    this->height = other.height;
    this->nickName = other.nickName;
    this->password = other.password;
    this->phone = other.phone;
    this->realName = other.realName;
    this->topics = other.topics;
}

bool InstagramAccount::hasSubscribedTopic(InterestTopic t) const {
    return topics.find(t) != topics.end();
}

size_t InstagramAccount::subscribedTopicCount() const {
    return topics.size();
}

void InstagramAccount::subscribTopic(InterestTopic t) {
    topics.insert(t);
}

void InstagramAccount::unSubscribTopic(InterestTopic t) {
    auto pos = topics.find(t);
    if(pos != topics.end()) {
        topics.erase(pos);
    }
}

std::ostream& operator << (std::ostream& o, const InstagramAccount& account) {
    o << "Emial: " << account.email << "\n";
    o << "Password: " << account.password << "\n";
    o << "Nickname: " << account.nickName << "\n";
    o << "Realname: " << account.realName << "\n";
    o << "Phone: " << account.phone << "\n";
    o << "Address: " << account.address << "\n";
    o << "Career: " << account.career << "\n";

    o << "Gender: " << genderToString(account.gender) << "\n";
    o << "Age: " << account.age << "\n";
    o << "Height: " << account.height << "\n";
    o << "Weight: " << account.weight << "\n";
    o << "Description: " << account.description << "\n";

    std::vector<InterestTopic> dummy;
    std::back_insert_iterator<std::vector<InterestTopic>> outItr(dummy);
    std::string topicStr;

    std::transform(account.topics.begin(), account.topics.end(), outItr, [&](InterestTopic t) {
        topicStr += " ";
        topicStr += topicToString(t);
        return t;
    });


    o << "Topics:" << topicStr << std::endl;

    return o;
}


std::string genderToString(Gender g) {
    switch (g)
    {
    case Gender::Male:
        return "Male";
    
    case Gender::Female:
        return "Female";
    
    default:
        return "secrect";
    }
}


std::string topicToString(InterestTopic t) {
    switch (t)
    {
    case InterestTopic::Art:
        return "Art";
    case InterestTopic::Beauty:
        return "Beauty";
    case InterestTopic::Food:
        return "Food";
    case InterestTopic::Joke:
        return "Joke";
    case InterestTopic::Movie:
        return "Movie";
    case InterestTopic::Photography:
        return "Photography";
    case InterestTopic::Stock:
        return "Stock";
    case InterestTopic::Tecnology:
        return "Tenology";
    case InterestTopic::Travel:
        return "Travel";
    default:
        return "Writting";
    }
}


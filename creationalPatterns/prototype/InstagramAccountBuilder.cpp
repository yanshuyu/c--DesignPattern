#include"InstagramAccountBuilder.h"


AccoutBuildException::AccoutBuildException(InstagramAccount::CreationError e, const char*  msg):logic_error(msg)
,error(e) {

}


InstagramAccount InstagramAccountBuilder::build() {
    if (email.empty())
        throw AccoutBuildException(InstagramAccount::CreationError::MissEmail, "Accout missing email");
    
    if (password.empty())
        throw AccoutBuildException(InstagramAccount::CreationError::MissPassword, "Accout missing password");
    
    if (nickName.empty())
        throw AccoutBuildException(InstagramAccount::CreationError::MissNickName, "Accout missing nick name");
    
    InstagramAccount accout(email, password, nickName);
    accout.address = address;
    accout.phone = phone;
    accout.realName = realName;
    accout.age = age;
    accout.career = career;
  
    accout.gender = gender;
    accout.height = height;
    accout.weight = weight;
 
    accout.description = description;
    accout.topics = topics;

    return accout;
}

void InstagramAccountBuilder::subscribTopic(InterestTopic t) {
    topics.insert(t);
}

void InstagramAccountBuilder::unSubscribTopic(InterestTopic t) {
    auto pos = topics.find(t);
    if(pos != topics.end()) {
        topics.erase(t);
    }
}
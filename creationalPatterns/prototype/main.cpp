#include<iostream>
#include"InstagramAccount.h"
#include"InstagramAccountBuilder.h"

using std::cout;
using std::endl;


int main() {
    InstagramAccountBuilder b1;
    b1.email = "shuyan@gmail.com";
    b1.password = "123456"; 
    b1.nickName = "handsome boy";
    b1.gender = Gender::Male;
    b1.career = "programmer";
    b1.subscribTopic(InterestTopic::Tecnology);
    b1.subscribTopic(InterestTopic::Food);
    b1.subscribTopic(InterestTopic::Travel);
    b1.description = "Hello world, I love programming!";
    
    InstagramAccount c1 = b1.build();
    cout << "acount: " << c1 << endl;


    InstagramAccount c2 = c1.copy();
     cout << "acount copy: " << c1 << endl;

    return 0;
}
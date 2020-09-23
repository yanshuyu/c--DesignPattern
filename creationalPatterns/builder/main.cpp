#include<iostream>
#include"InstagramAccountBuilder.h"

using std::cout;
using std::endl;


int main() {
    try {

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
        cout << c1 << endl;

        InstagramAccountBuilder b2;
        b2.email = "shuyan@gmail.com";
        b2.password = "123456"; 
        InstagramAccount c2 = b2.build();
        cout << c2 << endl;
    }catch(const AccoutBuildException& e){
        std::cerr << "Accout creation failed, reson: " << e.what() << endl;
    }catch(const std::exception& e) {
        std::cerr << "Accout creation failed with unkonw error!" << endl;
    }
    
    return 0;
}

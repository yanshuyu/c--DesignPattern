#include<iostream>
#include"Chatter.h"
#include"ChatRoom.h"
#include<memory>

using std::cout;
using std::endl;


int main() {
    auto chatRoom = std::unique_ptr<IMediator>(new ChatRoom());
    auto user_1 = new Chatter("XiaoMing", chatRoom.get());
    auto user_2 = new Chatter("XiaoHong", chatRoom.get());
    auto user_3 = new Chatter("XiaoFang", chatRoom.get());

    auto chat_shower = new Chatter("", chatRoom.get(), true);

    chatRoom->join(chat_shower);
    chatRoom->join(user_1);

    auto msg_1 = std::unique_ptr<IMessage>(IMessage::makeMessage(user_1, "hello, is any body here..."));
    user_1->sent(msg_1.get());

    chatRoom->join(user_2);
    user_1->sent(msg_1.get());

    auto msg_2 = std::unique_ptr<IMessage>(IMessage::makeMessage(user_2, "yeah~"));
    user_2->sent(msg_2.get());

    auto msg_3 = std::unique_ptr<IMessage>(IMessage::makeMessage(user_2, "how was today? @XiaoMing"));
    user_2->sent(msg_3.get());

    auto msg_4 = std::unique_ptr<IMessage>(IMessage::makeMessage(user_3, "you looks handsome, want a boy fried ??", user_1->getId()));
    chatRoom->join(user_3);
    user_3->sent(msg_4.get());

    chatRoom->leave(user_1);
   


    return 0;
}
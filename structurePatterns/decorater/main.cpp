#include"MilitaryTelegram.h"
#include"TelegramWrappers.h"
#include<iostream>

using std::cout;
using std::endl;

Telegram* create_enc_sender(int id = 0) {
    return new EncryptedTelegramWrapper(new MilitaryTelegram(id));
}

Telegram* create_enc_revicer(int id = 0) {
    return new EncryptedTelegramWrapper(new MilitaryTelegram(id));
}

Telegram* create_enc_comp_sender(int id = 0) {
    return new EncryptedTelegramWrapper( new CompressionTelegramWrapper( new MilitaryTelegram(id)));
}

Telegram* create_enc_comp_revicer(int id = 0) {
    return new CompressionTelegramWrapper( new EncryptedTelegramWrapper( new MilitaryTelegram(id))); 
}

int main() {
    auto base = std::shared_ptr<CommunicationCenter>(new MilitaryBase());
    auto basePtr = base.get();

    auto m1 = create_enc_sender();
    auto m2 = create_enc_revicer();
    auto m3 = create_enc_comp_sender();
    auto m4 = create_enc_comp_revicer();

    basePtr->addCommunicator(m1);
    basePtr->addCommunicator(m2);
    basePtr->addCommunicator(m3);
    basePtr->addCommunicator(m4);

    m1->sendMessage(basePtr, m2->getId(), "this message is sent to m_2 by m_1.");
    m3->sendMessage(basePtr, m4->getId(), "hello world, hello c++!");



    return 0;
}
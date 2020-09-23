#pragma once
#include"Telegram.h"
#include<unordered_map>

class MilitaryBase:public CommunicationCenter {
public:
    ~MilitaryBase();

    bool forwardMessage(int source, int target, const std::string& msg) const override;
    void addCommunicator(Telegram* t)override;
    bool hasCommunicator(int id) const override;
    void removeCommunicator(int id)override;

private:
    std::unordered_map<int, Telegram*> m_points;
};


class MilitaryTelegram: public Telegram {
    friend class MilitaryBase;
public:
    MilitaryTelegram(int id = 0);
    ~MilitaryTelegram() {
        int address = reinterpret_cast<int>(this);
        std::cout << "id(" << address << ") destoryed." << std::endl;
    }

    bool sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) override;
    void reviceMessage(int source, const std::string& msg) override;
    int getId() const override {
        return m_id;
    }

    void setId(int id) override {
        m_id = id;
    }

protected:
    int m_id;
};
#include"Telegram.h"




class TelegramWrapper: public Telegram {
public:
    TelegramWrapper(Telegram* t);
    virtual ~TelegramWrapper() override {
        if (m_wraptee != nullptr)
            delete m_wraptee;
    }

    virtual bool sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) override;
    virtual void reviceMessage(int source, const std::string& msg) override;
    virtual int getId() const override;
    virtual void setId(int id) override;

protected:
    Telegram* m_wraptee;
};




class EncryptedTelegramWrapper: public TelegramWrapper {
public:
    EncryptedTelegramWrapper(Telegram* t);
    bool sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) override;
    void reviceMessage(int source, const std::string& msg) override;
    std::string encrypt(const std::string& s);
    std::string deEncrypt(const std::string& s);
};



class CompressionTelegramWrapper: public TelegramWrapper {
public:
    CompressionTelegramWrapper(Telegram* t);
    bool sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) override;
    void reviceMessage(int source, const std::string& msg) override;
    std::string compress(const std::string& s);
    std::string deCompress(const std::string& s);
};
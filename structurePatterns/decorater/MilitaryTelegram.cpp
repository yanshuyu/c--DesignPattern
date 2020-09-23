#include"MilitaryTelegram.h"
#include<iostream>
#include<algorithm>

MilitaryBase::~MilitaryBase() {
    std::for_each(m_points.begin(), m_points.end(), [](decltype(m_points)::value_type p) {
        delete p.second;
    });
    m_points.clear();
}

bool MilitaryBase::forwardMessage(int source, int target, const std::string& msg) const {
    auto srcPoint = m_points.find(source);
    auto dstPoint = m_points.find(target);
    
    if (srcPoint != m_points.end() && target == -1) {
        std::for_each(m_points.begin(), m_points.end(), [source, &msg](decltype(m_points)::value_type p) {
            if(p.second->getId() != source)
                p.second->reviceMessage(source, msg);
        });
        return true;
    }

    if (srcPoint != m_points.end() && dstPoint != m_points.end()) {
        dstPoint->second->reviceMessage(source, msg);
        return true;
    }

    return false;
}

void MilitaryBase::addCommunicator(Telegram* t) {
    auto pos = m_points.find(t->getId());
    if (pos == m_points.end()) {
        m_points[t->getId()] = t;
    }
}

bool MilitaryBase::hasCommunicator(int id) const {
    return m_points.find(id) != m_points.end();
}

void MilitaryBase::removeCommunicator(int id) {
    auto pos = m_points.find(id);
    if (pos != m_points.end()) {
        delete pos->second;
        m_points.erase(pos);
    }
}


MilitaryTelegram::MilitaryTelegram(int id):m_id(id) {
    if (m_id == 0)
        m_id = reinterpret_cast<int>(this);
}

bool MilitaryTelegram::sendMessage(const CommunicationCenter* const c, int target, const std::string& msg) {
    if (c != nullptr) 
        return c->forwardMessage(m_id, target, msg);
    return false;
}


void MilitaryTelegram::reviceMessage(int source, const std::string& msg) {
    std::cout << "id(" << m_id << ")" << "revice message from id(" << source << "): " << msg << std::endl;
}
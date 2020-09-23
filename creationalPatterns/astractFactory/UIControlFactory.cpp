#include"UIControlFactory.h"


void UIControlFactory::registerFactory(ControlType ct, IControlFactory* f) {
    this->m_factorys[ct] = f;
}

void UIControlFactory::removeFactory(ControlType ct) {
    auto pos = this->m_factorys.find(ct);
    if (pos != this->m_factorys.end()) {
        this->m_factorys.erase(pos);
    }
}

bool UIControlFactory::hasFactory(ControlType ct) const {
    return this->m_factorys.find(ct) != this->m_factorys.end();
}

UIControl* UIControlFactory::create(ControlType ct, UIScheme s) {
    return this->m_factorys[ct]->create(s);
}
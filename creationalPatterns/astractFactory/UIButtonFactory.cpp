#include"UIButtonFactory.h"

UIControl* UIButtonFactory::create(UIScheme s) {
    return this->m_creaters[s]();
}
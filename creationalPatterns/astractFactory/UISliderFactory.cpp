#include"UISliderFactory.h"


UIControl* UISliderFactory::create(UIScheme s) {
    return this->m_creaters[s]();
}
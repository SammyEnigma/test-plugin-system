#include "foo000.hpp"

#include <iostream>


void CFoo000::FooA() const
{
    std::cout << "CFoo000: FooA" << std::endl;
}


bool CFoo000::FooB(int I_) const
{
    std::cout << "CFoo000: FooB " << I_ << std::endl;
    return I_ > 0;
}

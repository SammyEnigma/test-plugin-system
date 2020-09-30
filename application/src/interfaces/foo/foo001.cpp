#include "foo001.hpp"

#include <iostream>


void CFoo001::FooA() const
{
    std::cout << "CFoo001 FooA" << std::endl;
}


bool CFoo001::FooB(int A1_, int A2_) const
{
    std::cout << "CFoo001 FooB " << A1_ << " " << A2_ << std::endl;
    return A1_ > A2_;
}

#pragma once
#include "base/base_interface.hpp"

namespace plugin_api
{
    class IFoo001 : public IBaseInterface
    {
        DECL_INTERFACE(IFoo001, "Foo001");

    public:
        virtual void FooA() const = 0;
        virtual bool FooB(int A1_, int A2_) const = 0;
    };
}

#pragma once
#include "base/base_interface.hpp"

namespace plugin_api
{
    class IFoo000 : public IBaseInterface
    {
        DECL_INTERFACE(IFoo000, "Foo000");

    public:
        virtual void FooA() const = 0;
        virtual bool FooB(int I_) const = 0;
    };
}

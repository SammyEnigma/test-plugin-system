#pragma once
#include "base/base_interface.hpp"

namespace plugin_api
{
    class IFoo001 final : public IBaseInterface
    {
        DECL_INTERFACE(IFoo001, "Foo001");

        virtual void FooA() const = 0;
        virtual bool FooB(int A1_, int A2_) const = 0;
    };
}

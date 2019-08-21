#pragma once
#include "base/base_interface.hpp"

namespace plugin_api
{
    class IBar001 : public IBaseInterface
    {
        DECL_INTERFACE(IBar001, "Bar001");

    public:
        virtual void BarA() const = 0;
    };
}

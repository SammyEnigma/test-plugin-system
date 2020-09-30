#pragma once
#include "base/base_interface.hpp"

namespace plugin_api
{
    class IBar000 : public IBaseInterface
    {
        DECL_INTERFACE(IBar000, "Bar000");

        virtual void BarA() const = 0;
    };
}

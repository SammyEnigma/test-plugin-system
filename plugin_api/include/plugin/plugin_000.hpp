#pragma once
#include "base/base_plugin.hpp"

namespace plugin_api
{
    class IPlugin000 : public IBasePlugin
    {
        DECL_INTERFACE(IPlugin000, "Plugin000");

    public:
        virtual bool EventA(int A1_) = 0;
    };
}
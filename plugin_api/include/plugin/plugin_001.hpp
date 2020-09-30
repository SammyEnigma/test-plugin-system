#pragma once
#include "base/base_plugin.hpp"

namespace plugin_api
{
    class IPlugin001 : public IBasePlugin
    {
        DECL_INTERFACE(IPlugin001, "Plugin001");

    public:
        virtual bool EventA(int A1_, int A2_) = 0;
    };
}
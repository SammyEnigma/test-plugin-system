#pragma once
#include "plugin_api.hpp"

namespace plugin2
{
    class CPlugin2 final : public plugin_api::IPlugin
    {

    public:
        std::string GetName() const override;
        std::string GetDescription() const override;
        std::string GetShortDescription() const override;
        void GetVersion(size_t &Major_, size_t &Minor_) const override;
        void OnPluginLoaded() override;
        void OnPluginUnloaded() override;
        bool EventA(int A1_, int A2_) override;
    };
}
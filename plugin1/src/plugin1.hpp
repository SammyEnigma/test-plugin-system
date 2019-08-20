#pragma once
#include "plugin_000.hpp"

namespace plugin1
{
    // Test plugin for deprecated version.
    class CPlugin1 final : public plugin_api::IPlugin000
    {
    public:
        std::string GetName() const override;
        std::string GetDescription() const override;
        std::string GetShortDescription() const override;
        void GetVersion(size_t& Major_, size_t& Minor_) const override;
        
        void OnPluginLoaded() override;
        void OnPluginUnloaded() override;

        bool EventA(int A1_) override;
    };
}
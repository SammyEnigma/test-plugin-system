#pragma once
#include "plugin/plugin_000.hpp"

// Test plugin for deprecated version.
class CPlugin1 final : public plugin_api::IPlugin000
{
public:
    const char* GetName() const override;
    const char* GetDescription() const override;
    const char* GetShortDescription() const override;
    void GetVersion(uint32_t& Major_, uint32_t& Minor_) const override;

    void OnPluginLoaded() override;
    void OnPluginUnloaded() override;

    bool EventA(int A1_) override;
};
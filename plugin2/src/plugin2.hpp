#pragma once
#include "plugin_api.hpp"

class CPlugin2 final : public plugin_api::IPlugin
{

public:
    const char* GetName() const override;
    const char* GetDescription() const override;
    const char* GetShortDescription() const override;
    void GetVersion(uint32_t& Major_, uint32_t& Minor_) const override;
    void OnPluginLoaded() override;
    void OnPluginUnloaded() override;
    bool EventA(int A1_, int A2_) override;
};

#pragma once
#include "base_interface.hpp"
#include <functional>
#include <memory>

#define API_EXPORT __declspec(dllexport)

#define IMPL_PLUGIN(__this_class__) \
    plugin_api::FPGetInterface& GetInterfaceHandler() \
    { \
        static plugin_api::FPGetInterface g_fpGetInterface; \
        return g_fpGetInterface; \
    } \
    extern "C" \
    { \
        void API_EXPORT PluginEntryPoint(plugin_api::FPGetInterface fpGetInterface_) \
        { \
            GetInterfaceHandler() = fpGetInterface_; \
        } \
        plugin_api::IBasePlugin* API_EXPORT CreatePlugin() \
        { \
            return new __this_class__(); \
        } \
    }

namespace plugin_api
{
    class IBasePlugin;
    using FPGetInterface = IBaseInterface*(*)(const char*);
    using FPCreatePlugin = IBasePlugin*(*)();
    using FPPluginEntryPoint = void(*)(FPGetInterface);
}

plugin_api::FPGetInterface& GetInterfaceHandler();

namespace plugin_api
{
    class IBasePlugin : public IBaseInterface
    {
    public:
        IBasePlugin() = default;
        ~IBasePlugin() override = default;

        virtual std::string GetName() const = 0;
        virtual std::string GetDescription() const = 0;
        virtual std::string GetShortDescription() const = 0;
        virtual void GetVersion(size_t& Major_, size_t& Minor_) const = 0;
        
        virtual void OnPluginLoaded() = 0;
        virtual void OnPluginUnloaded() = 0;
    };

    template<class TInterface>
    TInterface* GetInterface()
    {
        return dynamic_cast<TInterface*>(GetInterfaceHandler()(TInterface::GetInterfaceID().c_str()));
    }
}


#pragma once
#include "base_interface.hpp"
#include <functional>

#define API_EXPORT __declspec(dllexport)

#define IMPL_PLUGIN(__this_class__) \
    extern "C" \
    { \
        void API_EXPORT PluginEntryPoint(plugin_api::FPGetInterface fpGetInterface_) \
        { \
        } \
        plugin_api::IBasePlugin* API_EXPORT CreatePlugin() \
        { \
            return new __this_class__(); \
        } \
    }


namespace plugin_api
{
    class IBasePlugin;

    using FPCreatePlugin = IBasePlugin*(*)();
    using FPGetInterface = IBaseInterface*(*)(const char*);
    using FPPluginEntryPoint = void(*)(FPGetInterface);

    class IBasePlugin : public IBaseInterface
    {
    public:
        IBasePlugin() = default;
        virtual ~IBasePlugin() = default;

        virtual std::string GetName() const = 0;
        virtual std::string GetDescription() const = 0;
        virtual std::string GetShortDescription() const = 0;
        virtual void GetVersion(size_t& Major_, size_t& Minor_) const = 0;
        
        virtual void OnPluginLoaded() = 0;
        virtual void OnPluginUnloaded() = 0;
    };
}

#pragma once
#include <functional>
#include <memory>

#include "base_interface.hpp"
#include "plugin_api_macro.hpp"


#define IMPL_PLUGIN(__this_class__)                                     \
    PLUGIN_EXPORT plugin_api::IBasePlugin* CreatePlugin()               \
    {                                                                   \
        return new __this_class__();                                    \
    }                                                                   \
    PLUGIN_EXPORT void DestroyPlugin(plugin_api::IBasePlugin* Plugin_)  \
    {                                                                   \
        delete Plugin_;                                                 \
    }                                                                   \


namespace plugin_api
{
    /// Base interface to a plugin.
    class IBasePlugin : public IBaseInterface
    {
    public:
        IBasePlugin() = default;
        ~IBasePlugin() override = default;

        /// Return name of plugin.
        virtual const char* GetName() const = 0;
        /// Return description of a plugin.
        virtual const char* GetDescription() const = 0;
        /// Return short description of a plugin. More like a summary.
        virtual const char* GetShortDescription() const = 0;
        /// Return version of a plugin.
        virtual void GetVersion(uint32_t& Major_, uint32_t& Minor_) const = 0;
        
        /// Plugin has been loaded event.
        virtual void OnPluginLoaded() = 0;
        /// Plugin currently unloading so soon it'll be destroyed.
        virtual void OnPluginUnloaded() = 0;
    };

    using FPCreatePlugin = plugin_api::IBasePlugin* (*)();
    using FPDestroyPlugin = void(*)(plugin_api::IBasePlugin* Plugin_);
}

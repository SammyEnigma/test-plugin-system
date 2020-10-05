#pragma once
#include "plugin_api_macro.hpp"

#include "plugin/plugin_001.hpp"
#include "interface/foo_001.hpp"
#include "interface/bar_001.hpp"

using FPHostGetInterface = plugin_api::IBaseInterface* (_cdecl*)(const char* Id_);
PLUGIN_API int InitAPI(FPHostGetInterface fpGetInterface_);

/// Return implementation of interface for its identifier \a Id_
PLUGIN_API plugin_api::IBaseInterface* GetInterface(const char* Id_);

template<class T>
T* GetInterface()
{
    return dynamic_cast<T*>(GetInterface(T::GetInterfaceID()));
}

namespace plugin_api
{
    // Type aliases for latest interfaces available.
    using IBar = IBar001;
    using IFoo = IFoo001;
    using IPlugin = IPlugin001;
}
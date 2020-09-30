#pragma once
#include "plugin_api_macro.hpp"

#include "plugin/plugin_001.hpp"
#include "interface/foo_001.hpp"
#include "interface/bar_001.hpp"

/// Return implementation of interface for its identifier \a Id_
PLUGIN_API void* GetInterface(const char* Id_);

/// Set implementation of interface with id \a Id_ to \a IImpl_
PLUGIN_API void SetInterface(const char* Id_, void* IImpl_);

template<class T>
T* GetInterface()
{
    return reinterpret_cast<T*>(GetInterface(T::GetInterfaceID()));
}

template<class T>
void SetInterface(T* IImpl_)
{
    SetInterface(T::GetInterfaceID(), static_cast<void*>(IImpl_));
}

namespace plugin_api
{
    // Type aliases for latest interfaces available.
    using IBar = IBar001;
    using IFoo = IFoo001;
    using IPlugin = IPlugin001;
}
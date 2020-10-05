#include "plugin_api.hpp"


static FPHostGetInterface g_HostGetInterface;

PLUGIN_API int InitAPI(FPHostGetInterface HostGetInterface_)
{
    if (g_HostGetInterface)
        return 0;

    g_HostGetInterface = HostGetInterface_;
    return 1;
}


PLUGIN_API plugin_api::IBaseInterface* GetInterface(const char* Id_)
{
    return g_HostGetInterface ? g_HostGetInterface(Id_) : nullptr;
}

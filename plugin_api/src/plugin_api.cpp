#include "plugin_api.hpp"

#include "interface_storage.hpp"


PLUGIN_API void* GetInterface(const char* Id_)
{
    return CInterfacesStorage::Instance().GetInterface(Id_);
}


PLUGIN_API void SetInterface(const char* Id_, void* IImpl_)
{
    CInterfacesStorage::Instance().SetInterface(Id_, IImpl_);
}

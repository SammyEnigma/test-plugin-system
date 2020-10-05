#include "setup_interfaces.hpp"

#include "interface_storage.hpp"

#include "foo/foo000.hpp"
#include "foo/foo001.hpp"
#include "bar/bar000.hpp"
#include "bar/bar001.hpp"

#include "plugin_api.hpp"

static void setupFoo()
{
    CInterfacesStorage& s = CInterfacesStorage::Instance();
    s.RegisterImplementation<CFoo000>();
    s.RegisterImplementation<CFoo001>();
}

static void setupBar()
{
    CInterfacesStorage& s = CInterfacesStorage::Instance();
    s.RegisterImplementation<CBar000>();
    s.RegisterImplementation<CBar001>();
}

plugin_api::IBaseInterface* HostGetInterface(const char* Id_)
{
    return CInterfacesStorage::Instance().GetInterface(Id_);
}

void SetupInterfaces()
{
    if (InitAPI(HostGetInterface)) // Or else someone already did it. But how? Something weird.
    {
        setupFoo();
        setupBar();
    }
}

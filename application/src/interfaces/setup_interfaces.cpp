#include "setup_interfaces.hpp"

#include "plugin_api.hpp"

#include "foo/foo000.hpp"
#include "foo/foo001.hpp"
#include "bar/bar000.hpp"
#include "bar/bar001.hpp"


static void setupFoo()
{
    static CFoo000 foo000;
    static CFoo001 foo001;
    SetInterface(&foo000);
    SetInterface(&foo001);
}

static void setupBar()
{
    static CBar000 bar000;
    static CBar001 bar001;
    SetInterface(&bar000);
    SetInterface(&bar001);
}

void SetupInterfaces()
{
    setupFoo();
    setupBar();
}

#include <Windows.h>
#include <iostream>
#include <memory>
#include "base/base_plugin.hpp"

using namespace std;
using namespace plugin_api;

static IBaseInterface* GetInterface(const char* InterfaceId_)
{
    return nullptr;
}

static bool LoadPlugin(const char* pName_)
{
    cout << pName_ << ": attempting to load plugin" << endl;
    HMODULE hPlugin = LoadLibraryA(pName_);
    if (!hPlugin)
    {
        cout << pName_ << " not found" << endl;
        return false;
    }

    FPPluginEntryPoint fpPluginEntryPoint = reinterpret_cast<FPPluginEntryPoint>(GetProcAddress(hPlugin, "PluginEntryPoint"));
    if (!fpPluginEntryPoint)
    {
        cout << "Plugin entry point not found (missing IMPL_PLUGIN directive?)" << endl;
        return false;
    }

    cout << pName_ << ": executing plugin entry point..." << endl;
    fpPluginEntryPoint(&GetInterface);
    cout << pName_ << ": plugin entry point passed" << endl;

    FPCreatePlugin fpCreatePlugin = reinterpret_cast<FPCreatePlugin>(GetProcAddress(hPlugin, "CreatePlugin"));
    if (!fpCreatePlugin)
    {
        cout << "Plugin creator function not found (missing IMPL_PLUGIN directive?)" << endl;
        return false;
    }

    cout << pName_ << ": creating plugin instance..." << endl;
    shared_ptr<IBasePlugin> spPlugin(fpCreatePlugin());
    if (!spPlugin)
    {
        cout << pName_ << ": unable to create plugin instance" << endl;
        return false;
    }

    cout << pName_ << ": plugin loaded successfully. Getting some information..." << endl;

    cout << "Plugin name: " << spPlugin->GetName() << endl;
    cout << "Plugin short description: " << spPlugin->GetShortDescription() << endl;
    cout << "Plugin description: " << spPlugin->GetDescription() << endl;
    size_t major = 0, minor = 0;
    spPlugin->GetVersion(major, minor);
    cout << "Plugin version: " << major << "." << minor << endl;
    cout << "Plugin interface version: " << spPlugin->GetID() << endl;

    cout << spPlugin->GetName() << ": executing plugin OnPluginLoaded function..." << endl;
    spPlugin->OnPluginLoaded();
    cout << spPlugin->GetName() << ": seems fine, executing OnPluginUnloaded function..." << endl;
    spPlugin->OnPluginUnloaded();
    cout << spPlugin->GetName() << ": seems fine, killing plugin..." << endl;

    cout << endl << endl << endl;
    return true;
}

int main()
{
    if (!LoadPlugin("libplugin2.dll"))
        return EXIT_FAILURE;

    if (!LoadPlugin("libplugin1.dll"))
        return EXIT_FAILURE;

    cout << "Everything is fine :) Shutting down..." << endl;
    return EXIT_SUCCESS;
}
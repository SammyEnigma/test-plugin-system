#include <Windows.h>
#include <iostream>
#include <sstream>
#include <memory>

#include "base/base_plugin.hpp"
#include "interfaces/setup_interfaces.hpp"

using std::cout;
using std::endl;


static bool LoadPlugin(const char* pName_)
{
    cout << pName_ << ": attempting to load plugin" << endl;
    std::stringstream ss;
    ss << PLUGIN_PREFIX << pName_ << PLUGIN_SUFFIX;
    HMODULE hPlugin = LoadLibraryA(ss.str().c_str());
    if (!hPlugin)
    {
        cout << "Plugin " << pName_ << " can not be loaded: " << GetLastError() << endl;
        return false;
    }

    auto fpCreatePlugin = reinterpret_cast<plugin_api::FPCreatePlugin>(GetProcAddress(hPlugin, "CreatePlugin"));
    auto fpDestroyPlugin = reinterpret_cast<plugin_api::FPDestroyPlugin>(GetProcAddress(hPlugin, "DestroyPlugin"));
    if (!fpCreatePlugin || !fpDestroyPlugin)
    {
        cout << "Plugin creator/destroy function not found (missing IMPL_PLUGIN directive?)" << endl;
        return false;
    }

    cout << pName_ << ": creating plugin instance..." << endl;
    plugin_api::IBasePlugin* pPlugin = fpCreatePlugin();
    if (!pPlugin)
    {
        cout << pName_ << ": unable to create plugin instance" << endl;
        return false;
    }

    cout << pName_ << ": plugin loaded successfully. Getting some information..." << endl;

    cout << "Plugin name: " << pPlugin->GetName() << endl;
    cout << "Plugin short description: " << pPlugin->GetShortDescription() << endl;
    cout << "Plugin description: " << pPlugin->GetDescription() << endl;
    uint32_t major = 0, minor = 0;
    pPlugin->GetVersion(major, minor);
    cout << "Plugin version: " << major << "." << minor << endl;
    cout << "Plugin interface version: " << pPlugin->GetID() << endl;

    cout << pPlugin->GetName() << ": executing plugin OnPluginLoaded function..." << endl;
    pPlugin->OnPluginLoaded();
    cout << pPlugin->GetName() << ": seems fine, executing OnPluginUnloaded function..." << endl;
    pPlugin->OnPluginUnloaded();
    cout << pPlugin->GetName() << ": seems fine, killing plugin..." << endl;
    fpDestroyPlugin(pPlugin);

    cout << endl << endl << endl;
    return true;
}

int main()
{
    SetupInterfaces();

    if (!LoadPlugin("plugin2"))
        return EXIT_FAILURE;

    if (!LoadPlugin("plugin1"))
        return EXIT_FAILURE;

    cout << "Everything is fine :) Shutting down..." << endl;
    return EXIT_SUCCESS;
}

#include "plugin2.hpp"

using namespace std;
using namespace plugin_api;

IMPL_PLUGIN(CPlugin2);

const char* CPlugin2::GetName() const
{
    return "Plugin 2";
}


const char* CPlugin2::GetDescription() const
{
    return "This plugin uses latest available plugin API";
}


const char* CPlugin2::GetShortDescription() const
{
    return "Most recent API for plugin";
}


void CPlugin2::GetVersion(uint32_t& Major_, uint32_t& Minor_) const
{
    Major_ = 0;
    Minor_ = 1;
}


void CPlugin2::OnPluginLoaded()
{
    auto pBar = GetInterface<IBar>();
    if (!pBar)
        return;

    pBar->BarA();
}


void CPlugin2::OnPluginUnloaded()
{
    auto pFoo = GetInterface<IFoo>();
    if (!pFoo)
        return;

    pFoo->FooA();
    pFoo->FooB(10, 20);
}


bool CPlugin2::EventA(int A1_, int A2_)
{
    return A1_ < A2_;
}


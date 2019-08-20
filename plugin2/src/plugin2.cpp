#include "plugin2.hpp"

using namespace std;

IMPL_PLUGIN(plugin2::CPlugin2);

namespace plugin2
{
    string CPlugin2::GetName() const
    {
        return "Plugin 2";
    }


    string CPlugin2::GetDescription() const
    {
        return "This plugin uses latest available plugin API";
    }


    string CPlugin2::GetShortDescription() const
    {
        return "Most recent API for plugin";
    }


    void CPlugin2::GetVersion(size_t &Major_, size_t &Minor_) const
    {
        Major_ = 0;
        Minor_ = 1;
    }


    void CPlugin2::OnPluginLoaded()
    {}


    void CPlugin2::OnPluginUnloaded()
    {}


    bool CPlugin2::EventA(int A1_, int A2_)
    {
        return A1_ < A2_;
    }
}

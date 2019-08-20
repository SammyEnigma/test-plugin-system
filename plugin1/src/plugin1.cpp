#include "plugin1.hpp"

using namespace std;
IMPL_PLUGIN(plugin1::CPlugin1);

namespace plugin1
{
    string CPlugin1::GetName() const
    {
        return "Test plugin 1 (deprecated)";
    }
    

    string CPlugin1::GetDescription() const
    {
        return "First created plugin";
    }


    string CPlugin1::GetShortDescription() const
    {
        return "This plugin uses \"deprecated\" API to do some cool stuff";
    }


    void CPlugin1::GetVersion(size_t& Major_, size_t& Minor_) const
    {
        Major_ = 1;
        Minor_ = 0;
    }
    

    void CPlugin1::OnPluginLoaded()
    {

    }


    void CPlugin1::OnPluginUnloaded()
    {

    }


    bool CPlugin1::EventA(int A1_) 
    {
        return A1_ < 0;
    }
}

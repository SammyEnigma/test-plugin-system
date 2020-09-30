#include "interface_storage.hpp"


CInterfacesStorage& CInterfacesStorage::Instance()
{
    static CInterfacesStorage interfacesStorage;
    return interfacesStorage;
}


void* CInterfacesStorage::GetInterface(const std::string& Id_) const
{
    auto it = m_Interfaces.find(Id_);
    return it == m_Interfaces.end() ? nullptr : it->second;
}


void CInterfacesStorage::SetInterface(const std::string& Id_, void* Impl_)
{
    auto it = m_Interfaces.find(Id_);
    if (it != m_Interfaces.end())
        return;

    m_Interfaces.emplace(Id_, Impl_);
}

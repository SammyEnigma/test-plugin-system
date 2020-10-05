#include "interface_storage.hpp"

#include "base/base_interface.hpp"


CInterfacesStorage& CInterfacesStorage::Instance()
{
    static CInterfacesStorage interfacesStorage;
    return interfacesStorage;
}


plugin_api::IBaseInterface* CInterfacesStorage::GetInterface(const std::string& Id_) const
{
    auto it = m_Interfaces.find(Id_);
    return it == m_Interfaces.end() ? nullptr : it->second.get();
}


void CInterfacesStorage::SetInterface(const std::string& Id_, std::unique_ptr<plugin_api::IBaseInterface>&& Impl_)
{
    auto it = m_Interfaces.find(Id_);
    if (it != m_Interfaces.end())
        return;

    m_Interfaces.emplace(Id_, std::move(Impl_));
}

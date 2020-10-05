#pragma once
#include <map>
#include <string>
#include <memory>


namespace plugin_api { class IBaseInterface; }

/// Storage for interfaces implementation. Singletone.
class CInterfacesStorage
{
public:
    /// Return the only instance of this class.
    static CInterfacesStorage& Instance();
    
    /// Return interface implementation for identifier \a Id_
    plugin_api::IBaseInterface* GetInterface(const std::string& Id_) const;

    /// Set interface implementation \a Impl_ for identifier \a Id_
    void SetInterface(const std::string& Id_, std::unique_ptr<plugin_api::IBaseInterface>&& Impl_);

    template<class T>
    void RegisterImplementation()
    {
        SetInterface(T::GetInterfaceID(), std::make_unique<T>());
    }

private:
    CInterfacesStorage() = default;
    ~CInterfacesStorage() = default;
    
private:
    std::map<std::string, std::unique_ptr<plugin_api::IBaseInterface>> m_Interfaces;
};

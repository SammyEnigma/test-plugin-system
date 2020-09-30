#pragma once
#include <map>
#include <string>


/// Storage for interfaces implementation. Singletone.
class CInterfacesStorage
{
public:
    /// Return the only instance of this class.
    static CInterfacesStorage& Instance();
    
    /// Return interface implementation for identifier \a Id_
    void* GetInterface(const std::string& Id_) const;

    /// Set interface implementation \a Impl_ for identifier \a Id_
    void SetInterface(const std::string& Id_, void* Impl_);

private:
    CInterfacesStorage() = default;
    ~CInterfacesStorage() = default;
    
private:
    std::map<std::string, void*> m_Interfaces;
};

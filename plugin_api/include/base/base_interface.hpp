#pragma once

#define DECL_INTERFACE(__this_class__, __sId__) \
    public: \
        __this_class__() = default; \
        virtual ~__this_class__() = default; \
        static const char* GetInterfaceID() { return (__sId__); } \
        const char* GetID() const override final { return __this_class__::GetInterfaceID(); }


namespace plugin_api
{
    /// Abstract class for interface.
    /// Or interface to a "interface class".
    class IBaseInterface
    {
    public:
        IBaseInterface() = default;
        virtual ~IBaseInterface() = default;

        /// Return indentitier of interface.
        virtual const char* GetID() const = 0;
    };
}

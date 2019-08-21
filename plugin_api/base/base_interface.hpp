#pragma once
#include <string>

#define DECL_INTERFACE(__this_class__, __sId__) \
    public: \
        __this_class__() = default; \
        virtual ~__this_class__() = default; \
        static std::string GetInterfaceID() { return (__sId__); } \
        std::string GetID() const override final { return __this_class__::GetInterfaceID(); }


namespace plugin_api
{
    class IBaseInterface
    {
    public:
        IBaseInterface() = default;
        virtual ~IBaseInterface() = default;

        virtual std::string GetID() const = 0;
    };
}

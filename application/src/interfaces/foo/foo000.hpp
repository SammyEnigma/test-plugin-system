#pragma once
#include "interface/foo_000.hpp"


class CFoo000 final : public plugin_api::IFoo000
{
public:
    CFoo000() = default;
    ~CFoo000() = default;

    void FooA() const override final;
    bool FooB(int I_) const override final;
};

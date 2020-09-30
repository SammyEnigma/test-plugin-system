#pragma once
#include "interface/foo_001.hpp"


class CFoo001 final : public plugin_api::IFoo001
{
public:
    CFoo001() = default;
    ~CFoo001() = default;

    void FooA() const override final;
    bool FooB(int A1_, int A2_) const override final;
};

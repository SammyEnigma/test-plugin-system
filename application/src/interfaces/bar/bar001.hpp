#pragma once
#include "interface/bar_001.hpp"


/// Implementation of IBar001.
class CBar001 final : public plugin_api::IBar001
{
public:
    CBar001() = default;
    ~CBar001() = default;

    void BarA() const override final;
};

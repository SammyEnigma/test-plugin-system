#pragma once
#include "interface/bar_000.hpp"

// Implementation of IBar000.
class CBar000 final : public plugin_api::IBar000
{
public:
    CBar000() = default;
    ~CBar000() = default;

    void BarA() const override final;
};

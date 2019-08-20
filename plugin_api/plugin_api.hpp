#pragma once
#include "plugin_001.hpp"
#include "foo_001.hpp"
#include "bar_001.hpp"

namespace plugin_api
{
    // Type aliases for latest interfaces available.
    using IBar = IBar001;
    using IFoo = IFoo001;
    using IPlugin = IPlugin001;
}
#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IItemManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/InjectLoot_NodeTypeParams.hpp>

namespace RED4ext
{
namespace quest { 
struct InjectLoot_NodeType : quest::IItemManagerNodeType
{
    static constexpr const char* NAME = "questInjectLoot_NodeType";
    static constexpr const char* ALIAS = NAME;

    DynArray<quest::InjectLoot_NodeTypeParams> params; // 30
};
RED4EXT_ASSERT_SIZE(InjectLoot_NodeType, 0x40);
} // namespace quest
} // namespace RED4ext

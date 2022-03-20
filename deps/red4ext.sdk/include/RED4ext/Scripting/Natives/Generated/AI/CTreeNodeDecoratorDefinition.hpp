#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CTreeNodeDefinition.hpp>

namespace RED4ext
{
struct LibTreeINodeDefinition;

namespace AI { 
struct CTreeNodeDecoratorDefinition : AI::CTreeNodeDefinition
{
    static constexpr const char* NAME = "AICTreeNodeDecoratorDefinition";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk30[0x38 - 0x30]; // 30
    Handle<LibTreeINodeDefinition> child; // 38
};
RED4EXT_ASSERT_SIZE(CTreeNodeDecoratorDefinition, 0x48);
} // namespace AI
} // namespace RED4ext

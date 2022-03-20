#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IInventoryListener.hpp>

namespace RED4ext
{
namespace AI::behavior::tweak { 
struct ItemsInInventoryListener : game::IInventoryListener
{
    static constexpr const char* NAME = "AIbehaviortweakItemsInInventoryListener";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk40[0x68 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(ItemsInInventoryListener, 0x68);
} // namespace AI::behavior::tweak
} // namespace RED4ext

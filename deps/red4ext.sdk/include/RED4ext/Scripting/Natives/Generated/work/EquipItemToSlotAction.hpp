#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/IWorkspotItemAction.hpp>

namespace RED4ext
{
namespace work { 
struct EquipItemToSlotAction : work::IWorkspotItemAction
{
    static constexpr const char* NAME = "workEquipItemToSlotAction";
    static constexpr const char* ALIAS = NAME;

    TweakDBID item; // 30
    TweakDBID itemSlot; // 38
};
RED4EXT_ASSERT_SIZE(EquipItemToSlotAction, 0x40);
} // namespace work
} // namespace RED4ext

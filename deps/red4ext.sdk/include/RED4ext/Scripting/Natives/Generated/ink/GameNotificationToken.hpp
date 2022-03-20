#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace ink { 
struct GameNotificationToken : IScriptable
{
    static constexpr const char* NAME = "inkGameNotificationToken";
    static constexpr const char* ALIAS = "inkGameNotificationToken";

    uint8_t unk40[0x88 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(GameNotificationToken, 0x88);
} // namespace ink
} // namespace RED4ext

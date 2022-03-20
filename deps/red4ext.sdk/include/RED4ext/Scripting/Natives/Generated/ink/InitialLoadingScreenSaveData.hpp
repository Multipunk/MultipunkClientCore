#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ILoadingScreenPersistentData.hpp>

namespace RED4ext
{
namespace ink { 
struct InitialLoadingScreenSaveData : ink::ILoadingScreenPersistentData
{
    static constexpr const char* NAME = "inkInitialLoadingScreenSaveData";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk08[0x10 - 0x8]; // 8
};
RED4EXT_ASSERT_SIZE(InitialLoadingScreenSaveData, 0x10);
} // namespace ink
} // namespace RED4ext

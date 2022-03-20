#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CoverSelectionParameters.hpp>

namespace RED4ext
{
namespace AI { 
struct PathLengthCoverSelection : AI::CoverSelectionParameters
{
    static constexpr const char* NAME = "AIPathLengthCoverSelection";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk10[0x20 - 0x10]; // 10
};
RED4EXT_ASSERT_SIZE(PathLengthCoverSelection, 0x20);
} // namespace AI
} // namespace RED4ext

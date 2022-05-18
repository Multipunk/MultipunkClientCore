#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PerformerId.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/events/AttachPropToWorldCachedFallbackBone.hpp>

namespace RED4ext
{
namespace anim { struct AnimSet; }

namespace scn::events { 
struct AttachPropToWorldFallbackData
{
    static constexpr const char* NAME = "scneventsAttachPropToWorldFallbackData";
    static constexpr const char* ALIAS = NAME;

    scn::PerformerId owner; // 00
    uint8_t unk04[0x10 - 0x4]; // 4
    alignas(16) StaticArray<scn::events::AttachPropToWorldCachedFallbackBone, 2> fallbackCachedBones; // 10
    Ref<anim::AnimSet> fallbackAnimset; // 80
    CName fallbackAnimationName; // 98
    float fallbackAnimTime; // A0
    uint8_t unkA4[0xB0 - 0xA4]; // A4
};
RED4EXT_ASSERT_SIZE(AttachPropToWorldFallbackData, 0xB0);
} // namespace scn::events
} // namespace RED4ext

#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/TypedCondition.hpp>

namespace RED4ext
{
namespace quest { struct IPayment_ConditionType; }

namespace quest { 
struct PaymentCondition : quest::TypedCondition
{
    static constexpr const char* NAME = "questPaymentCondition";
    static constexpr const char* ALIAS = NAME;

    Handle<quest::IPayment_ConditionType> type; // 30
};
RED4EXT_ASSERT_SIZE(PaymentCondition, 0x40);
} // namespace quest
} // namespace RED4ext

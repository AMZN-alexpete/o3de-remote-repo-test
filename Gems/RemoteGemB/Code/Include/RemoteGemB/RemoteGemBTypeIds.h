
#pragma once

namespace RemoteGemB
{
    // System Component TypeIds
    inline constexpr const char* RemoteGemBSystemComponentTypeId = "{B0421A12-A517-4D02-A82D-ACFF028A91EB}";
    inline constexpr const char* RemoteGemBEditorSystemComponentTypeId = "{A4BB2196-4F9C-4AD7-A427-BDDE92A1504A}";

    // Module derived classes TypeIds
    inline constexpr const char* RemoteGemBModuleInterfaceTypeId = "{D2529674-B4D4-4C54-934D-7C21ACA68CFB}";
    inline constexpr const char* RemoteGemBModuleTypeId = "{ED714731-5DE4-4A95-AF4B-6157B549B6D0}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* RemoteGemBEditorModuleTypeId = RemoteGemBModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* RemoteGemBRequestsTypeId = "{DF0000A6-A5FD-4FD8-B575-00A5EFA59602}";
} // namespace RemoteGemB

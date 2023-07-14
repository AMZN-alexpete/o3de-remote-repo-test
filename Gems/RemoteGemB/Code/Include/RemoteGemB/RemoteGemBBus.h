
#pragma once

#include <RemoteGemB/RemoteGemBTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RemoteGemB
{
    class RemoteGemBRequests
    {
    public:
        AZ_RTTI(RemoteGemBRequests, RemoteGemBRequestsTypeId);
        virtual ~RemoteGemBRequests() = default;
        // Put your public methods here
    };

    class RemoteGemBBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RemoteGemBRequestBus = AZ::EBus<RemoteGemBRequests, RemoteGemBBusTraits>;
    using RemoteGemBInterface = AZ::Interface<RemoteGemBRequests>;

} // namespace RemoteGemB

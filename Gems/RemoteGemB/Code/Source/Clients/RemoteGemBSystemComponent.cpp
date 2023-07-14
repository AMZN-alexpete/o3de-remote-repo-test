
#include "RemoteGemBSystemComponent.h"

#include <RemoteGemB/RemoteGemBTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace RemoteGemB
{
    AZ_COMPONENT_IMPL(RemoteGemBSystemComponent, "RemoteGemBSystemComponent",
        RemoteGemBSystemComponentTypeId);

    void RemoteGemBSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<RemoteGemBSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void RemoteGemBSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("RemoteGemBService"));
    }

    void RemoteGemBSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("RemoteGemBService"));
    }

    void RemoteGemBSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RemoteGemBSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RemoteGemBSystemComponent::RemoteGemBSystemComponent()
    {
        if (RemoteGemBInterface::Get() == nullptr)
        {
            RemoteGemBInterface::Register(this);
        }
    }

    RemoteGemBSystemComponent::~RemoteGemBSystemComponent()
    {
        if (RemoteGemBInterface::Get() == this)
        {
            RemoteGemBInterface::Unregister(this);
        }
    }

    void RemoteGemBSystemComponent::Init()
    {
    }

    void RemoteGemBSystemComponent::Activate()
    {
        RemoteGemBRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void RemoteGemBSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        RemoteGemBRequestBus::Handler::BusDisconnect();
    }

    void RemoteGemBSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace RemoteGemB

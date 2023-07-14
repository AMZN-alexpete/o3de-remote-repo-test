
#include <AzCore/Serialization/SerializeContext.h>
#include "RemoteGemBEditorSystemComponent.h"

#include <RemoteGemB/RemoteGemBTypeIds.h>

namespace RemoteGemB
{
    AZ_COMPONENT_IMPL(RemoteGemBEditorSystemComponent, "RemoteGemBEditorSystemComponent",
        RemoteGemBEditorSystemComponentTypeId, BaseSystemComponent);

    void RemoteGemBEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<RemoteGemBEditorSystemComponent, RemoteGemBSystemComponent>()
                ->Version(0);
        }
    }

    RemoteGemBEditorSystemComponent::RemoteGemBEditorSystemComponent() = default;

    RemoteGemBEditorSystemComponent::~RemoteGemBEditorSystemComponent() = default;

    void RemoteGemBEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("RemoteGemBEditorService"));
    }

    void RemoteGemBEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("RemoteGemBEditorService"));
    }

    void RemoteGemBEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void RemoteGemBEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void RemoteGemBEditorSystemComponent::Activate()
    {
        RemoteGemBSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void RemoteGemBEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        RemoteGemBSystemComponent::Deactivate();
    }

} // namespace RemoteGemB

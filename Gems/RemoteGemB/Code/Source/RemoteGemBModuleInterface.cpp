
#include "RemoteGemBModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <RemoteGemB/RemoteGemBTypeIds.h>

#include <Clients/RemoteGemBSystemComponent.h>

namespace RemoteGemB
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(RemoteGemBModuleInterface,
        "RemoteGemBModuleInterface", RemoteGemBModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(RemoteGemBModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(RemoteGemBModuleInterface, AZ::SystemAllocator);

    RemoteGemBModuleInterface::RemoteGemBModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            RemoteGemBSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList RemoteGemBModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<RemoteGemBSystemComponent>(),
        };
    }
} // namespace RemoteGemB

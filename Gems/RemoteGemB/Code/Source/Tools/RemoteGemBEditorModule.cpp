
#include <RemoteGemB/RemoteGemBTypeIds.h>
#include <RemoteGemBModuleInterface.h>
#include "RemoteGemBEditorSystemComponent.h"

namespace RemoteGemB
{
    class RemoteGemBEditorModule
        : public RemoteGemBModuleInterface
    {
    public:
        AZ_RTTI(RemoteGemBEditorModule, RemoteGemBEditorModuleTypeId, RemoteGemBModuleInterface);
        AZ_CLASS_ALLOCATOR(RemoteGemBEditorModule, AZ::SystemAllocator);

        RemoteGemBEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                RemoteGemBEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<RemoteGemBEditorSystemComponent>(),
            };
        }
    };
}// namespace RemoteGemB

AZ_DECLARE_MODULE_CLASS(Gem_RemoteGemB, RemoteGemB::RemoteGemBEditorModule)

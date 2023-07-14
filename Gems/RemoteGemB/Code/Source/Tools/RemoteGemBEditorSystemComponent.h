
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/RemoteGemBSystemComponent.h>

namespace RemoteGemB
{
    /// System component for RemoteGemB editor
    class RemoteGemBEditorSystemComponent
        : public RemoteGemBSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = RemoteGemBSystemComponent;
    public:
        AZ_COMPONENT_DECL(RemoteGemBEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        RemoteGemBEditorSystemComponent();
        ~RemoteGemBEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace RemoteGemB

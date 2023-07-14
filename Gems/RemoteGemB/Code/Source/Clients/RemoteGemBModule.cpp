
#include <RemoteGemB/RemoteGemBTypeIds.h>
#include <RemoteGemBModuleInterface.h>
#include "RemoteGemBSystemComponent.h"

namespace RemoteGemB
{
    class RemoteGemBModule
        : public RemoteGemBModuleInterface
    {
    public:
        AZ_RTTI(RemoteGemBModule, RemoteGemBModuleTypeId, RemoteGemBModuleInterface);
        AZ_CLASS_ALLOCATOR(RemoteGemBModule, AZ::SystemAllocator);
    };
}// namespace RemoteGemB

AZ_DECLARE_MODULE_CLASS(Gem_RemoteGemB, RemoteGemB::RemoteGemBModule)

#include "DrAssetForgeEditor.h"
#include "Modules/ModuleManager.h"

class FDRAssetForgeEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FDRAssetForgeEditorModule, DRAssetForgeEditor)

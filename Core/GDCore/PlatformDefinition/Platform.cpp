/*
 * GDevelop Core
 * Copyright 2008-2015 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the MIT License.
 */
#include "Platform.h"
#include "GDCore/PlatformDefinition/PlatformExtension.h"
#include "GDCore/PlatformDefinition/ChangesNotifier.h"
#include "GDCore/IDE/ProjectExporter.h"
#include "GDCore/PlatformDefinition/Object.h"
#include <string>

using namespace std;

#undef CreateEvent

namespace gd
{

#if defined(GD_IDE_ONLY)
gd::ChangesNotifier Platform::defaultEmptyChangesNotifier;
#endif

Platform::Platform()
{
    //ctor
}

Platform::~Platform()
{
    //dtor
}

bool Platform::AddExtension(std::shared_ptr<gd::PlatformExtension> extension)
{
    std::cout << extension->GetName();
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
    	if ( extensionsLoaded[i]->GetName() == extension->GetName() ) {
            std::cout << "(Already loaded!)" << std::endl;
    	    return false;
        }
    }

    //Load all creation/destruction functions for objects provided by the extension
    vector < string > objectsTypes = extension->GetExtensionObjectsTypes();
    for ( unsigned int i = 0; i < objectsTypes.size();++i)
    {
        creationFunctionTable[objectsTypes[i]] = extension->GetObjectCreationFunctionPtr(objectsTypes[i]);
    }

    extensionsLoaded.push_back(extension);
    std::cout << ", ";
    return true;
}

bool Platform::IsExtensionLoaded(const string & name) const
{
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
    	if ( extensionsLoaded[i]->GetName() == name )
    	    return true;
    }

    return false;
}

std::shared_ptr<gd::PlatformExtension> Platform::GetExtension(const string & name) const
{
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
    	if ( extensionsLoaded[i]->GetName() == name )
    	    return extensionsLoaded[i];
    }

    return std::shared_ptr<gd::PlatformExtension> ();
}

std::shared_ptr<gd::Object> Platform::CreateObject(std::string type, const std::string & name) const
{
    if ( creationFunctionTable.find(type) == creationFunctionTable.end() )
    {
        std::cout << "Tried to create an object with an unknown type: " << type << " for platform " << GetName() << "!" << std::endl;
        type = "";
        if ( creationFunctionTable.find("") == creationFunctionTable.end() ) {
            std::cout << "Unable to create a Base object!" << std::endl;
            return std::shared_ptr<gd::Object>();
        }
    }

    //Create a new object with the type we want.
    gd::Object * object = (creationFunctionTable.find(type)->second)(name);
    object->SetType(type);

    return std::shared_ptr<gd::Object> (object);
}

gd::Automatism* Platform::CreateAutomatism(const std::string & automatismType) const
{
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
        Automatism* automatism = extensionsLoaded[i]->CreateAutomatism(automatismType);
        if ( automatism != NULL )
            return automatism;
    }

    return NULL;
}

std::shared_ptr<gd::AutomatismsSharedData> Platform::CreateAutomatismSharedDatas(const std::string & automatismType) const
{
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
        std::shared_ptr<gd::AutomatismsSharedData> automatism = extensionsLoaded[i]->CreateAutomatismSharedDatas(automatismType);
        if ( automatism != std::shared_ptr<gd::AutomatismsSharedData>() )
            return automatism;
    }

    return std::shared_ptr<gd::AutomatismsSharedData>();
}

#if defined(GD_IDE_ONLY)
std::shared_ptr<gd::BaseEvent> Platform::CreateEvent(const std::string & eventType) const
{
    for (unsigned int i =0;i<extensionsLoaded.size();++i)
    {
        std::shared_ptr<gd::BaseEvent> event = extensionsLoaded[i]->CreateEvent(eventType);
        if ( event != std::shared_ptr<gd::BaseEvent>() )
            return event;
    }

    return std::shared_ptr<gd::BaseEvent>();
}

#if !defined(GD_NO_WX_GUI)
std::shared_ptr<gd::LayoutEditorPreviewer> Platform::GetLayoutPreviewer(gd::LayoutEditorCanvas & editor) const
{
    return std::shared_ptr<gd::LayoutEditorPreviewer>(new gd::LayoutEditorPreviewer);
}

std::shared_ptr<gd::ProjectExporter> Platform::GetProjectExporter() const
{
    return std::shared_ptr<gd::ProjectExporter>(new gd::ProjectExporter);
}
#endif

#endif

}

/**
 *  Game Develop
 *      Player
 *
 *  Par Florian "4ian" Rival
 *
 */
/**
 *
 *  Contient une ou plusieurs actions
 */

#include <vector>
#include <string>
#include "GDL/Object.h"
#include <cmath>
#include "GDL/aObjet.h"
#include "GDL/Event.h"
#include <iostream>
#include <sstream>
#include "GDL/Chercher.h"
#include "GDL/algo.h"
#include "GDL/Force.h"
#include <iostream>
#include "GDL/Access.h"
#include "GDL/RuntimeScene.h"
#include "GDL/ObjectsConcerned.h"
#include "GDL/ExtensionsManager.h"
#include <stdexcept>



/**
 * Duplicate an object
 */
bool Object::ActDuplicate( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();

    ObjSPtr newObject = extensionManager->CreateObject(shared_from_this());

    scene->objectsInstances.AddObject(newObject);
    objectsConcerned.objectsPicked.AddObject(newObject); //Object is concerned for future actions

    return true;
}


/**
 * Create a new object
 */
bool ActCreate( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    //On r�cup�re l'ID de l'objet � cr�er
    string objectWanted = eval.EvalTxt(action.GetParameter( 0 ));
    int IDsceneObject = Picker::PickOneObject( &scene->objetsInitiaux, objectWanted );
    int IDglobalObject = Picker::PickOneObject( &scene->game->globalObjects, objectWanted );

    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();
    ObjSPtr newObject = boost::shared_ptr<Object> ();

    if ( IDsceneObject != -1)
        newObject = extensionManager->CreateObject(scene->objetsInitiaux[IDsceneObject]);
    else if ( IDglobalObject != -1)
        newObject = extensionManager->CreateObject(scene->game->globalObjects[IDglobalObject]);
    else
    {
        scene->errors.Add("L'objet � cr�er ("+objectWanted+") n'existe pas dans la liste des objets", "", "", -1, 1);
        return false;
    }

    //Ajout � la liste d'objet et configuration de sa position
    newObject->errors = &scene->errors;
    newObject->SetX( eval.EvalExp( action.GetParameter( 1 ) ) );
    newObject->SetY( eval.EvalExp( action.GetParameter( 2 ) ) );

    //Compatibilit� avec les versions de Game Develop pr�c�dentes
    if ( action.GetParameters().size() > 3 )
        newObject->SetLayer( eval.EvalTxt( action.GetParameter( 3 ) ) );

    //Add object to scene and let it be concerned by futures actions
    scene->objectsInstances.AddObject(newObject);
    objectsConcerned.objectsPicked.AddObject( newObject );
    objectsConcerned.AddAnObjectConcerned(objectWanted);

    return true;
}


/**
 * Delete an object ( renaming it to "" cause it to be deleted by RuntimeScene )
 */
bool Object::ActDelete( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    SetName("");

    return true;
}


////////////////////////////////////////////////////////////
/// Ajouter des objets aux objets concern�s
///
/// Type : AjoutObjConcern
/// Param�tre 1 : Objet(s) � ajouter
////////////////////////////////////////////////////////////
bool ActAjoutObjConcern( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    ObjList list = objectsConcerned.Pick(action.GetParameter( 0 ).GetPlainString(), action.IsGlobal());

	ObjList::iterator obj = list.begin();
	ObjList::const_iterator obj_end = list.end();
    for ( ; obj != obj_end; ++obj )
    {
        objectsConcerned.objectsPicked.AddObject(*obj);
        //TODO : Encore utile ?
    }

    return true;
}

////////////////////////////////////////////////////////////
/// Ajouter des objets aux objets concern�s
///
/// Type : AjoutObjConcern
/// Param�tre 1 : Objet(s) � ajouter
////////////////////////////////////////////////////////////
bool ActAjoutHasard( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    ObjList list = objectsConcerned.PickAndRemove(action.GetParameter( 0 ).GetPlainString(), action.IsGlobal());

    //On en reprend un dans la liste
    if ( !list.empty() )
    {
        int id = sf::Randomizer::Random(0, list.size()-1);
        objectsConcerned.objectsPicked.AddObject(list[id]);
    }

    return true;
}

#undef PARAM
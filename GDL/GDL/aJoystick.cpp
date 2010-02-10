#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iostream>

#include "GDL/Object.h"
#include "GDL/Chercher.h"
#include "GDL/algo.h"
#include "GDL/Access.h"
#include "GDL/RuntimeScene.h"
#include "GDL/ObjectsConcerned.h"

////////////////////////////////////////////////////////////
/// Enregistre la valeur d'un axe d'un joystick dans une variable
///
/// Type : GetJoystickAxis
/// Param�tre 1 : Num�ro du joystick
/// Param�tre 2 : Axe
/// Param�tre 3 : Variable de la sc�ne
////////////////////////////////////////////////////////////
bool ActGetJoystickAxis( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & action, const Evaluateur & eval )
{
    unsigned int joystick = eval.EvalExp( action.GetParameter( 0 ) );
    string axisStr = eval.EvalTxt( action.GetParameter( 1 ) );
    sf::Joy::Axis axis;
    if ( axisStr == "AxisX" ) axis = sf::Joy::AxisX;
    else if ( axisStr == "AxisY" ) axis = sf::Joy::AxisY;
    else if ( axisStr == "AxisZ" ) axis = sf::Joy::AxisZ;
    else if ( axisStr == "AxisR" ) axis = sf::Joy::AxisR;
    else if ( axisStr == "AxisU" ) axis = sf::Joy::AxisU;
    else if ( axisStr == "AxisV" ) axis = sf::Joy::AxisV;
    else if ( axisStr == "AxisPOV" ) axis = sf::Joy::AxisPOV;
    else return false;

    //On cherche la variable
    int ID = scene->variables.FindVariable( eval.EvalTxt( action.GetParameter( 2 ) ) );
    if ( ID == -1 )
    {
        //Si elle n'existe pas, on la cr�er
        scene->variables.variables.push_back( eval.EvalTxt( action.GetParameter( 2 ) ) );

        //On reprend l'identifiant
        ID = scene->variables.variables.size() - 1;

    }

    //On modifie la variable
    scene->variables.variables.at( ID ) = scene->input->GetJoystickAxis(joystick, axis);

    return true;
}
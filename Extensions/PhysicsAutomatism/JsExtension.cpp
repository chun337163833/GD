/**

GDevelop - Physics Automatism Extension
Copyright (c) 2010-2015 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/
#if defined(GD_IDE_ONLY)
#include "GDCore/PlatformDefinition/PlatformExtension.h"
#include "GDCore/Tools/Version.h"

#include <iostream>
#include "GDCore/Tools/Localization.h"

/**
 * \brief This class declares information about the JS extension.
 */
class JsExtension : public gd::PlatformExtension
{
public:

    /**
     * \brief Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    JsExtension()
    {
        SetExtensionInformation("PhysicsAutomatism",
                              _("Physics automatism"),
                              _("Automatism allowing to move objects as if they were subject to the laws of physics."),
                              "Florian Rival",
                              "Open source (MIT License)");
        CloneExtension("GDevelop C++ platform", "PhysicsAutomatism");

        GetAutomatismMetadata("PhysicsAutomatism::PhysicsAutomatism")
            .SetIncludeFile("PhysicsAutomatism/box2djs/box2d.js")
            .AddIncludeFile("PhysicsAutomatism/physicsruntimeautomatism.js");

        std::map<std::string, gd::InstructionMetadata > & autActions = GetAllActionsForAutomatism("PhysicsAutomatism::PhysicsAutomatism");
        std::map<std::string, gd::InstructionMetadata > & autConditions = GetAllConditionsForAutomatism("PhysicsAutomatism::PhysicsAutomatism");
        std::map<std::string, gd::ExpressionMetadata > & autExpressions = GetAllExpressionsForAutomatism("PhysicsAutomatism::PhysicsAutomatism");

        autActions["PhysicsAutomatism::SetStatic"].codeExtraInformation.SetFunctionName("setStatic");
        autActions["PhysicsAutomatism::SetDynamic"].codeExtraInformation.SetFunctionName("setDynamic");
        autConditions["PhysicsAutomatism::SetDynamic"].codeExtraInformation.SetFunctionName("isDynamic");
        autActions["PhysicsAutomatism::SetFixedRotation"].codeExtraInformation.SetFunctionName("setFixedRotation");
        autActions["PhysicsAutomatism::SetFreeRotation"].codeExtraInformation.SetFunctionName("setFreeRotation");
        autActions["PhysicsAutomatism::AddRevoluteJoint"].codeExtraInformation.SetFunctionName("addRevoluteJoint");
        autActions["PhysicsAutomatism::AddRevoluteJointBetweenObjects"].codeExtraInformation.SetFunctionName("addRevoluteJointBetweenObjects");
        autActions["PhysicsAutomatism::ActAddGearJointBetweenObjects"].codeExtraInformation.SetFunctionName("addGearJointBetweenObjects");
        autConditions["PhysicsAutomatism::IsFixedRotation"].codeExtraInformation.SetFunctionName("isFixedRotation");
        autActions["PhysicsAutomatism::SetAsBullet"].codeExtraInformation.SetFunctionName("setAsBullet");
        autActions["PhysicsAutomatism::DontSetAsBullet"].codeExtraInformation.SetFunctionName("dontSetAsBullet");
        autConditions["PhysicsAutomatism::IsBullet"].codeExtraInformation.SetFunctionName("isBullet");
        autActions["PhysicsAutomatism::ApplyImpulse"].codeExtraInformation.SetFunctionName("applyImpulse");
        autActions["PhysicsAutomatism::ApplyImpulseUsingPolarCoordinates"].codeExtraInformation.SetFunctionName("applyImpulseUsingPolarCoordinates");
        autActions["PhysicsAutomatism::ApplyImpulseTowardPosition"].codeExtraInformation.SetFunctionName("applyImpulseTowardPosition");
        autActions["PhysicsAutomatism::ApplyForce"].codeExtraInformation.SetFunctionName("applyForce");
        autActions["PhysicsAutomatism::ApplyForceUsingPolarCoordinates"].codeExtraInformation.SetFunctionName("applyForceUsingPolarCoordinates");
        autActions["PhysicsAutomatism::ApplyForceTowardPosition"].codeExtraInformation.SetFunctionName("applyForceTowardPosition");
        autActions["PhysicsAutomatism::ApplyTorque"].codeExtraInformation.SetFunctionName("applyTorque");
        autActions["PhysicsAutomatism::SetLinearVelocity"].codeExtraInformation.SetFunctionName("setLinearVelocity");
        autConditions["PhysicsAutomatism::LinearVelocityX"].codeExtraInformation.SetFunctionName("getLinearVelocityX");
        autConditions["PhysicsAutomatism::LinearVelocityY"].codeExtraInformation.SetFunctionName("getLinearVelocityY");
        autConditions["PhysicsAutomatism::LinearVelocity"].codeExtraInformation.SetFunctionName("getLinearVelocity");
        autActions["PhysicsAutomatism::SetAngularVelocity"].codeExtraInformation.SetFunctionName("setAngularVelocity");
        autConditions["PhysicsAutomatism::AngularVelocity"].codeExtraInformation.SetFunctionName("getAngularVelocity");
        autConditions["PhysicsAutomatism::CollisionWith"].codeExtraInformation.SetFunctionName("collisionWith");
        autConditions["PhysicsAutomatism::LinearDamping"].codeExtraInformation.SetFunctionName("getLinearDamping");
        autActions["PhysicsAutomatism::SetLinearDamping"].codeExtraInformation.SetFunctionName("setLinearDamping");
        autConditions["PhysicsAutomatism::AngularDamping"].codeExtraInformation.SetFunctionName("getAngularDamping");
        autActions["PhysicsAutomatism::SetAngularDamping"].codeExtraInformation.SetFunctionName("setAngularDamping");
        autActions["PhysicsAutomatism::SetGravity"].codeExtraInformation.SetFunctionName("setGravity");
        autExpressions["LinearVelocity"].codeExtraInformation.SetFunctionName("getLinearVelocity");
        autExpressions["LinearVelocityX"].codeExtraInformation.SetFunctionName("getLinearVelocityX");
        autExpressions["LinearVelocityY"].codeExtraInformation.SetFunctionName("getLinearVelocityY");
        autExpressions["AngularVelocity"].codeExtraInformation.SetFunctionName("getAngularVelocity");
        autExpressions["LinearDamping"].codeExtraInformation.SetFunctionName("getLinearDamping");
        autExpressions["AngularDamping"].codeExtraInformation.SetFunctionName("getAngularDamping");

        /*
            aut.AddAction("SetPolygonScaleX",
                           _("Change collision polygon X scale"),
                           _("Change the X scale of the polygon. Use a value greater than 1 to enlarge the polygon, less than 1 to reduce it."),
                           _("Change collision polygon of _PARAM0_ X scale to _PARAM2_"),
                           _("Collision polygon"),
                           "res/physics24.png",
                           "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddParameter("expression", _("Scale"))
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("SetPolygonScaleX").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");

            aut.AddAction("SetPolygonScaleY",
                           _("Change collision polygon Y scale"),
                           _("Change the Y scale of the polygon. Use a value greater than 1 to enlarge the polygon, less than 1 to reduce it."),
                           _("Change collision polygon of _PARAM0_ Y scale to _PARAM2_"),
                           _("Collision polygon"),
                           "res/physics24.png",
                           "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddParameter("expression", _("Scale"))
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("SetPolygonScaleY").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");

            aut.AddCondition("GetPolygonScaleX",
                           _("Collision polygon X scale"),
                           _("Test the value of the collision polygon X scale."),
                           _("Collision polygon of _PARAM0_ X scale is _PARAM2__PARAM3_"),
                           _("Collision polygon"),
                           "res/physics24.png",
                           "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddParameter("relationalOperator", _("Comparison sign"))
                .AddParameter("expression", _("Value to test"))
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("GetPolygonScaleX").SetManipulatedType("number").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");

            aut.AddCondition("GetPolygonScaleY",
                           _("Collision polygon Y scale"),
                           _("Test the value of the collision polygon Y scale."),
                           _("Collision polygon of _PARAM0_ Y scale is _PARAM2__PARAM3_"),
                           _("Collision polygon"),
                           "res/physics24.png",
                           "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddParameter("relationalOperator", _("Comparison sign"))
                .AddParameter("expression", _("Value to test"))
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("GetPolygonScaleY").SetManipulatedType("number").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");

            aut.AddExpression("PolygonScaleX", _("Collision polygon X scale"), _("Collision polygon X scale"), _("Collision polygon"), "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("GetPolygonScaleX").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");

            aut.AddExpression("PolygonScaleY", _("Collision polygon Y scale"), _("Collision polygon Y scale"), _("Collision polygon"), "res/physics16.png")
                .AddParameter("object", _("Object"))
                .AddParameter("automatism", _("Automatism"), "PhysicsAutomatism")
                .AddCodeOnlyParameter("currentScene", "")
                .codeExtraInformation.SetFunctionName("GetPolygonScaleY").SetIncludeFile("PhysicsAutomatism/PhysicsAutomatism.h");
*/

        StripUnimplementedInstructionsAndExpressions();
    };
};

/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" gd::PlatformExtension * GD_EXTENSION_API CreateGDJSExtension() {
    return new JsExtension;
}
#endif

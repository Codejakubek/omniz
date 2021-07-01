/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_Core.h>



OZ_DECLARE_CLASS_CPP(OZ_Core)

OZ_Core::OZ_Core() {

}

std::shared_ptr<OZ_CoreResult> OZ_Core::Launch() {
    return std::make_shared<OZ_CoreResult_OK>();
}

OZ_Core::~OZ_Core() {

}

std::string OZ_Core::OutputNiceCoreState() {
    //TODO: Incomplete
    return std::string();
}
/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_CoreResult.h>

OZ_DECLARE_CLASS_CPP(OZ_CoreResult)
OZ_DECLARE_CLASS_CPP(OZ_CoreResult_ImplEmpty)
OZ_DECLARE_CLASS_CPP(OZ_CoreResult_OK)

std::string OZ_CoreResult_ImplEmpty::StringInfo() const {
    return std::string(
        "Unable to launch Core - OZ_CoreImpl is empty."
    );
}
std::string OZ_CoreResult_OK::StringInfo() const {
    return std::string(
        "OK! :-) "
    );
}
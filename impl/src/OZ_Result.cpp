/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_Result.h>

OZ_DECLARE_CLASS_CPP(OZ_Result)

const std::string not_available_result_info_string = "Not Available";

std::string OZ_Result::StringInfo() const {
    return not_available_result_info_string;
}
/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_RESULT_H
#define OZ_RESULT_H

#include <OZ_Commons.h>

extern const std::string not_available_result_info_string;
////////////////////////////////////////
class OZ_Result : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()

    virtual std::string StringInfo() const;
protected:

};
////////////////////////////////////////

#endif
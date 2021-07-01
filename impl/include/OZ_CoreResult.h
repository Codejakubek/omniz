/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_Commons.h>
#include <OZ_Result.h>

#ifndef SD_CORE_RESULT
#define SD_CORE_RESULT


////////////////////////////////////////
class OZ_CoreResult : public OZ_Result {
public:
    OZ_DECLARE_CLASS_H()

    virtual std::string StringInfo() const = 0;
protected:
    
};
////////////////////////////////////////
class OZ_CoreResult_ImplEmpty : public OZ_CoreResult {
public:
    OZ_DECLARE_CLASS_H()

    virtual std::string StringInfo() const override;
protected:

};
////////////////////////////////////////
class OZ_CoreResult_OK : public OZ_CoreResult {
public:
    OZ_DECLARE_CLASS_H()

    virtual std::string StringInfo() const override;
protected:

};
////////////////////////////////////////

#endif

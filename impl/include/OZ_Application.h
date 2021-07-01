/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_APPLICATION_H
#define OZ_APPLICATION_H

#include <SigmaDev/Application/Application.h>

#include <OZ_Class.h>

////////////////////////////////////////
class OZ_Application : public SD_Application, public OZ_Class {
public:
    OZ_DECLARE_CLASS_H();

    OZ_Application();
    OZ_Application(const OZ_Application& copy) = delete;
    virtual ~OZ_Application();

    virtual void ExecuteOneTick() override;
    virtual void Start() override;
    virtual void Pause() override;
    virtual void Stop() override;
protected:
    virtual void Preinitialize() override;
    virtual void Initialize() override;
    virtual void Release() override;

};
////////////////////////////////////////


#endif
/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_CORE_IMPLS_H
#define OZ_CORE_IMPLS_H

#include <string>
#include <memory>
#include <OZ_Commons.h>

////////////////////////////////////////
class OZ_Core;
class OZ_Application;
////////////////////////////////////////
class OZ_CoreImpl : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()
    OZ_CoreImpl() = delete;
    OZ_CoreImpl(OZ_Core& core);
    virtual ~OZ_CoreImpl();

    virtual void Init() = 0;
    virtual void CoreTick() = 0;
    virtual void Release() = 0;

    inline const std::unique_ptr<OZ_Application>& GetApplication() const {
        return application;
    }
    inline std::unique_ptr<OZ_Application>& GetApplication() {
        return application;
    }
protected:
    OZ_Core& core;

    virtual void InitializeApplication() = 0;

    std::unique_ptr<OZ_Application> application;
};
////////////////////////////////////////
class OZ_CurrentCoreImpl : public OZ_CoreImpl {
public:
    OZ_DECLARE_CLASS_H();
    OZ_CurrentCoreImpl() = delete;
    OZ_CurrentCoreImpl(OZ_Core& core);
    virtual ~OZ_CurrentCoreImpl();

    virtual void Init() override;
    virtual void CoreTick() override;
    virtual void Release() override;
protected:
    virtual void InitializeApplication() override;

};

#endif
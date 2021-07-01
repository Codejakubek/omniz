/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_CoreImpls.h>
#include <OZ_Application.h>

OZ_CoreImpl::OZ_CoreImpl(OZ_Core& ref) : core(ref) {}
OZ_CoreImpl::~OZ_CoreImpl() {}

OZ_DECLARE_CLASS_CPP(OZ_CoreImpl)

////////////////////////////////////////
OZ_CurrentCoreImpl::OZ_CurrentCoreImpl(OZ_Core& core) 
 : OZ_CoreImpl(core)
{
    
}
OZ_CurrentCoreImpl::~OZ_CurrentCoreImpl() {

}
void OZ_CurrentCoreImpl::Init() {

}
void OZ_CurrentCoreImpl::CoreTick() {

}
void OZ_CurrentCoreImpl::Release() {

}
void OZ_CurrentCoreImpl::InitializeApplication() {
    application = std::make_unique<OZ_Application>();
}

OZ_DECLARE_CLASS_CPP(OZ_CurrentCoreImpl)
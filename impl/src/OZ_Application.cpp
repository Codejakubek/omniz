/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_Application.h>

OZ_DECLARE_CLASS_CPP(OZ_Application)

OZ_Application::OZ_Application() {

}
OZ_Application::~OZ_Application() {

}
void OZ_Application::ExecuteOneTick() {
    SD_Application::ExecuteOneTick();
}
void OZ_Application::Start() {
    SD_Application::Start();
}
void OZ_Application::Pause() {
    SD_Application::Pause();
}
void OZ_Application::Stop() {
    SD_Application::Stop();
}
void OZ_Application::Preinitialize() {
    SD_Application::Preinitialize();
}
void OZ_Application::Initialize() {
    SD_Application::Initialize();
}
void OZ_Application::Release() {
    SD_Application::Release();
}
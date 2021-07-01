////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/src/SigmaDev/GUI/GUIExecutive.cpp
// Description:
// Additional Notes:

#include <SigmaDev/GUI/GUIExecutive.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Resources/Resources.h>

SD_DECLARE_CLASS_CPP(SD_GUIExecutive)
SD_GUIExecutive::SD_GUIExecutive(SD_Application& application) : application(application) {

}
SD_GUIExecutive::~SD_GUIExecutive() {

}
void SD_GUIExecutive::RenderGUI(SD_RenderWindowAccess& window_access) {
    //TODO: GUI_Disable
    /*
    SD_Resources& resources = application.GetResourcesRef();
    SD_GUIObjectResources& gui_object_resources = resources.GetGUIObjectResourcesRef();
    SD_GUIObjectResources::_container& container = gui_object_resources.GetContainer();

    for (auto & object : container) {
        std::unique_ptr<SD_GUIObject>& gui_object = object.second;
        const std::string& window_id = gui_object->GetWindowId();

        if (window_access.window_id.compare(window_id) == 0) {
            gui_object->Render(window_access);
        }
    }
    */
}
void SD_GUIExecutive::ActivityGUI(SD_RenderWindowAccess& window_access) {
    //TODO: GUI_Disable
    /*
    SD_Resources& resources = application.GetResourcesRef();
    SD_GUIObjectResources& gui_object_resources = resources.GetGUIObjectResourcesRef();
    SD_GUIObjectResources::_container& container = gui_object_resources.GetContainer();

    for (auto & object : container) {
        std::unique_ptr<SD_GUIObject>& gui_object = object.second;
        const std::string& window_id = gui_object->GetWindowId();

        if (window_access.window_id.compare(window_id) == 0) {
            gui_object->Activity(window_access);
        }
    }
    */
}
void SD_GUIExecutive::PlayGUI(SD_RenderWindowAccess& window_access) {
    //TODO: GUI_Disable
    /*
    SD_Resources& resources = application.GetResourcesRef();
    SD_GUIObjectResources& gui_object_resources = resources.GetGUIObjectResourcesRef();
    SD_GUIObjectResources::_container& container = gui_object_resources.GetContainer();

    for (auto & object : container) {
        std::unique_ptr<SD_GUIObject>& gui_object = object.second;
        const std::string& window_id = gui_object->GetWindowId();

        if (window_access.window_id.compare(window_id) == 0) {
            gui_object->Audio(window_access);
        }
    }
    */
}
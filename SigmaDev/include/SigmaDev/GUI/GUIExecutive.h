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
// File: /impl/include/SigmaDev/GUI/GUIExecutive.h
// Description:
// Additional Notes:

#ifndef SD_GUI_GUI_EXECUTIVE_H
#define SD_GUI_GUI_EXECUTIVE_H

#include <SigmaDev/Windows/WindowsDefines.h>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////

class SD_Application;

////////////////////////////////////////

/**
 * @brief SD_GUIExecutive is class for managing the activity of SD_GUIObject
 *        in SD_Resources. Please use this class if you want to do things
 *        related to SD_GUIObject activity.
 * 
 */
class SD_GUIExecutive : public SD_Class {
public:  
    SD_DECLARE_CLASS_H()

    SD_GUIExecutive() = delete;
    /**
     * @brief Construct the exetuvie. It must be connected to SD_Application,
     *        so please pass reference to it.
     * 
     * @param application_reference SD_Application non-const reference
     */
    SD_GUIExecutive(SD_Application& application_reference);
    virtual ~SD_GUIExecutive();

    /**
     * @brief Renders all SD_GUIObjects from specified SD_RenderWindowAccess
     *        pointing which window you would want to render with SD_GUIObjects
     * 
     * @param window_access Window access
     */
    virtual void RenderGUI(SD_RenderWindowAccess& window_access);
    /**
     * @brief Activity of all SD_GUIObjects from specifies SD_RenderWindowAccess
     *        pointing which window you would want to do activity ticks with SD_GUIObjects
     * 
     * @param window_access Window access 
     */
    virtual void ActivityGUI(SD_RenderWindowAccess& window_access);
    virtual void PlayGUI(SD_RenderWindowAccess& window_access);
protected:
    SD_Application& application;
};

/**
 * @var SD_GUIExecutive::application
 * @brief Reference to SD_Application
 * 
 */

////////////////////////////////////////

#endif
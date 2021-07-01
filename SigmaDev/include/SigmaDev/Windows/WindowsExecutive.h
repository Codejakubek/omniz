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
// File: /impl/include/SigmaDev/Windows/WindowsExecutive.h
// Description:
// Additional Notes:

#ifndef SD_WINDOWS_WINDOWS_EXECUTIVE_H
#define SD_WINDOWS_WINDOWS_EXECUTIVE_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;
////////////////////////////////////////

/**
 * @brief SD_WindowsExecutive is helper class for sf::RenderWindow
 *        activity (such as polling events)
 * 
 * @todo SD_WindowsExecutive seems to be unimplemented, and the SD_DefaultApplication
 *        is polling events by itself.
 */
class SD_WindowsExecutive : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_WindowsExecutive() = delete;
    SD_WindowsExecutive(SD_Application& application_reference);

    virtual void PollEvents(const std::string& window_id);
    virtual void PollEvents(sf::RenderWindow& render_window);    
protected:
    SD_Application& application;
};

/**
 * @var SD_WindowsExecutive
 * @brief SD_Application reference connected to
 * 
 */

////////////////////////////////////////

#endif
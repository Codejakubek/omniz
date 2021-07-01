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
// File: /impl/src/SigmaDev/Windows/WindowsExecutive.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Windows/WindowsExecutive.h>

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_WindowsExecutive)

SD_WindowsExecutive::SD_WindowsExecutive(SD_Application& application)
: application(application)
{

}
void SD_WindowsExecutive::PollEvents(const std::string& window_id) {

}
void SD_WindowsExecutive::PollEvents(sf::RenderWindow& render_window) {
    
}
////////////////////////////////////////
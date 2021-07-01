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
// File: /impl/src/SigmaDev/Windows/WindowsDefines.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Windows/WindowsDefines.h>

SD_DECLARE_CLASS_CPP(SD_RenderWindowAccess)

SD_RenderWindowAccess::SD_RenderWindowAccess(
    const std::string& window_id, 
    sf::RenderWindow& render_window
) 
    : window_id(window_id), render_window(render_window)
{
    
}
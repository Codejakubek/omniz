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
// File: /impl/src/SigmaDev/Misc/Position.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/Position.h>


sf::Vector2i SD_GetMousePosition(sf::RenderWindow& render_window) {
    return sf::Mouse::getPosition(render_window);
}
bool SD_IsMouseOnThisRectangle(sf::RenderWindow& render_window, const sf::IntRect& rectangle) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(render_window);
    if (rectangle.contains(mouse_pos)) {
        return true;
    } else return false;
}
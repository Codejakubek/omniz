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
// File: /impl/include/SigmaDev/Misc/Position.h
// Description:
// Additional Notes:

#ifndef SD_MISC_POSITION_H
#define SD_MISC_POSITION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/**
 * @brief Returns the position of the mouse in sf::RenderWindow context 
 * 
 * @param render_window sf::RenderWindow
 * @return sf::Vector2i Position of the mouse in sf::RenderWindow context
 */
sf::Vector2i SD_GetMousePosition(sf::RenderWindow& render_window);
/**
 * @brief Returns true if the position of the mouse is in the sf::IntRect.
 * 
 * @param render_window sf::RenderWindow
 * @param rectangle sf::IntRect
 * @return true If it is
 * @return false If it's not
 */
bool SD_IsMouseOnThisRectangle(sf::RenderWindow& render_window, const sf::IntRect& rectangle);

#endif
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
// File: /impl/include/SigmaDev/Windows/WindowsDefines.h
// Description:
// Additional Notes:

#ifndef SD_WINDOWS_WINDOWS_DEFINES_H
#define SD_WINDOWS_WINDOWS_DEFINES_H

#include <SigmaDev/Misc/Class.h>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

////////////////////////////////////////

/**
 * @brief SD_RenderWindowAccess is structure with
 *        information about sf::RenderWindow. Used in many places where
 *        you are handling the SFML sf::RenderWindow.
 * 
 */
struct SD_RenderWindowAccess : public SD_Class {
    SD_DECLARE_CLASS_H()
    /**
     * @brief Construct data using sf::RenderWindow ID and sf::RenderWindow reference
     * 
     * @param window_id sf::RenderWindow ID
     * @param render_window sf::RenderWindow reference
     */
    SD_RenderWindowAccess(const std::string& window_id, sf::RenderWindow& render_window);
    
    std::string window_id;
    sf::RenderWindow& render_window;
};

/**
 * @var SD_RenderWindowAccess::window_id    
 * @brief sf::RenderWindow ID
 * 
 * @var SD_RenderWindowAccess::render_window
 * @brief sf::RenderWindow non-const reference
 * 
 */

////////////////////////////////////////

#endif
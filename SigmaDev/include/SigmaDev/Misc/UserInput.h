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
// File: /impl/include/SigmaDev/Misc/UserInput.h
// Description:
// Additional Notes:

#ifndef SD_MISC_USER_INPUT_H
#define SD_MISC_USER_INPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SigmaDev/Misc/Class.h>

/**
 * @brief Not implemented yet class
 */
class SD_UserInput : public SD_Class {
protected:
    SD_UserInput() = default;
public:
    SD_DECLARE_CLASS_H()
    static SD_UserInput& Instance();
protected:

};

#endif
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
// File: /impl/src/SigmaDev/Misc/UserInput.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/UserInput.h>

SD_DECLARE_CLASS_CPP(SD_UserInput)
SD_UserInput& SD_UserInput::Instance() {
    static SD_UserInput i;
    return i;
}

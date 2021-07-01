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
// File: /impl/src/SigmaDev/Misc/Calculations.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/Calculations.h>
#include <math.h>

bool SD_DiffFloats(float a, float b, float diff) {
    float c = std::fabs(a-b);
    if (c < diff) {
        return true;
    } else return false;
}
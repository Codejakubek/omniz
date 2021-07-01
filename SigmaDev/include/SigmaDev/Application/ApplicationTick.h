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
// File: /impl/include/SigmaDev/Application/ApplicationTick.h
// Description:
// Additional Notes:
////////////////////////////////////////

#ifndef SD_APPLICATION_APPLICATION_TICK_H
#define SD_APPLICATION_APPLICATION_TICK_H

#include <memory>
#include <SigmaDev/Misc/Class.h>

class SD_Application;

class SD_ApplicationTick : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    virtual void Tick(SD_Application& application);
protected:

};

#endif

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
// File: /impl/include/SigmaDev/Application/ApplicationInitialization.h
// Description:
// Additional Notes:
////////////////////////////////////////


#ifndef SD_APPLICATION_APPLICATION_INITIALIZATION_H
#define SD_APPLICATION_APPLICATION_INITIALIZATION_H

#include <memory>
#include <SigmaDev/Misc/Class.h>

class SD_Application;

////////////////////////////////////////
class SD_ApplicationInitialization : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
    virtual void Initialize(SD_Application& application) = 0;
protected:

};
////////////////////////////////////////

#endif

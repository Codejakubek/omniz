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
// File: /impl/include/SigmaDev/Configuration/JsonAccesser.h
// Description:
// Additional Notes:

#ifndef SD_CONFIGURATION_JSON_ACCESSER_H
#define SD_CONFIGURATION_JSON_ACCESSER_H

#include <memory>
#include <SigmaDev/Misc/Class.h>

class SD_Application;

////////////////////////////////////////
/** TODO: SD_JsonAccesser_Implementation */
class SD_JsonAccesser : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_JsonAccesser() = delete;
    SD_JsonAccesser(SD_Application& application_reference);
protected:
    SD_Application& application; ///< Reference to SD_Application.
                                 /// Should point to a memory that shouldn't be
                                 /// changed/moved/copied 
};
////////////////////////////////////////

#endif

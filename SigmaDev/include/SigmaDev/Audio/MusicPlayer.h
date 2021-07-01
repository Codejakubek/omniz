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
// File: /impl/include/SigmaDev/Audio/MusicPlayer.h
// Description:
// Additional Notes:
////////////////////////////////////////


#ifndef SD_AUDIO_MUSIC_PLAYER_H
#define SD_AUDIO_MUSIC_PLAYER_H

#include <memory>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;
////////////////////////////////////////
/** TODO: SD_MusicPlayer_Implementation */
class SD_MusicPlayer : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
    SD_MusicPlayer() = delete;
    SD_MusicPlayer(SD_Application& application_reference);


protected:
    SD_Application& application; ///< Reference to SD_Application.
                                 /// Should point to a memory that shouldn't be
                                 /// changed/moved/copied 
};  
////////////////////////////////////////

#endif
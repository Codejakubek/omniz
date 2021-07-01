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
// File: /impl/include/SigmaDev/Audio/SoundPlayer.h
// Description:
// Additional Notes:

#ifndef SD_AUDIO_SOUND_PLAYER_H
#define SD_AUDIO_SOUND_PLAYER_H

#include <memory>
#include <list>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;
class SD_SoundResources;
////////////////////////////////////////
class SD_SoundStacks : public SD_Class {
public:
    typedef std::map<std::string, sf::Sound*> _container;

    SD_DECLARE_CLASS_H()
    SD_SoundStacks() = default;

    virtual void PlayAndRelease(SD_SoundResources& resources);

    virtual void AddSound(const std::string& sound_id, sf::Sound* sound);

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer();
protected:
    _container container;
};
////////////////////////////////////////    
class SD_SoundPlayer : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
    SD_SoundPlayer() = delete;
    SD_SoundPlayer(SD_Application& application_reference);

    virtual void PlaySound(
        const std::string& id,
        const sf::SoundBuffer* sound_buffer
    );
    virtual void PlaySound(
        const std::string& id,
        const std::string& sound_buffer_res_id
    );
    virtual void Tick();

protected:
    SD_Application& application; ///< Reference to SD_Application.
                                 /// Should point to a memory that shouldn't be
                                 /// changed/moved/copied 

    std::unique_ptr<SD_SoundStacks> sound_stacks;
};
////////////////////////////////////////

#endif

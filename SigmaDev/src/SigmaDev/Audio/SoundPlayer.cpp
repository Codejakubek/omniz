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
// File: /impl/src/SigmaDev/Audio/SoundPlayer.cpp
// Description:
// Additional Notes:


#include <SigmaDev/Audio/SoundPlayer.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Audio/SoundAccesser.h>
#include <SigmaDev/Resources/Resources.h>

SD_DECLARE_CLASS_CPP(SD_SoundStacks)
void SD_SoundStacks::PlayAndRelease(SD_SoundResources& resources) {
    std::list<std::string> list_to_be_removed;

    for (auto & sound : container) {
        const std::string& sound_id = sound.first;
        sf::Sound* sound_val = sound.second;
        if (sound_val->getStatus() == sf::Sound::Status::Stopped || 
            sound_val->getStatus() == sf::Sound::Status::Paused) {
            list_to_be_removed.emplace_back(sound_id);
        }
    }
    /*
    for (auto & id : list_to_be_removed) {
        auto it = container.find(id);
        if (it != container.end()) {
            container.erase(it);
        }        
        try {
            resources.EraseSound(id);
        } catch (...) {}
    }
    */
}
void SD_SoundStacks::AddSound(const std::string& sound_id, sf::Sound* sound) {
    auto insert_pair = container.insert(
        std::make_pair(
            sound_id,
            sound
        )
    );
}

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SoundPlayer)
SD_SoundPlayer::SD_SoundPlayer(SD_Application& application)
 : application(application)
 {
     sound_stacks = std::make_unique<SD_SoundStacks>();
 }
void SD_SoundPlayer::PlaySound(
    const std::string& id,
    const sf::SoundBuffer* sound_buffer
) {
    auto& resources = application.GetResourcesRef();
    auto& audios = resources.GetSoundResourcesRef();

    sf::Sound sound;
    sound.setBuffer(*sound_buffer);
    
    audios.AddSound(id, sound);
    sf::Sound& s = audios.GetSound(id);
    s.play();

    sound_stacks->AddSound(id, &s);
}
void SD_SoundPlayer::PlaySound(
    const std::string& id,
    const std::string& sound_buffer_res_id
) {

}
void SD_SoundPlayer::Tick() {
    sound_stacks->PlayAndRelease(
        application.GetResourcesRef().GetSoundResourcesRef()
    );
}
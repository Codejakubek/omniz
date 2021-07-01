/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_CORE_DATA_H
#define OZ_CORE_DATA_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <OZ_Commons.h>

////////////////////////////////////////
class OZ_Core;
class OZ_CoreData;
////////////////////////////////////////
class OZ_OtherCoreData : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()

    OZ_OtherCoreData() = delete;
    OZ_OtherCoreData(OZ_CoreData& data);
    virtual ~OZ_OtherCoreData() = default;

    virtual bool IsValid() const = 0;
protected:
    OZ_CoreData& data;
};  
class OZ_DefaultOtherCoreData : public OZ_OtherCoreData {
public:
    OZ_DECLARE_CLASS_H()

    OZ_DefaultOtherCoreData() = delete;
    OZ_DefaultOtherCoreData(OZ_CoreData& data);
    virtual ~OZ_DefaultOtherCoreData() = default;

    virtual bool IsValid() const override;
protected:
    
};  
////////////////////////////////////////
class OZ_CoreData : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()

    OZ_CoreData() = delete;
    OZ_CoreData(OZ_Core& ref);
    virtual ~OZ_CoreData();

    virtual bool IsValidAndComplete() const {
        if(
            
            game_window_id.empty() == false &&
            game_window_default_video_mode.isValid() &&
            game_window_framerate > 0 && game_window_framerate <= 120 &&
            //gui_design &&
            //gui_design->IsValid() &&
            //physics_define &&
            //physics_define->IsValid() &&
            //game_rules &&
            //game_rules->IsValid() &&
            //game_graphics_define &&
            //game_graphics_define->IsValid()
            other_core_data &&
            other_core_data->IsValid()

        ) {
            return true;
        } else {
            return false;
        }
    }
protected:

public:
    OZ_Core& ref;

    std::string game_window_id = "omniz_shooters";
    sf::VideoMode game_window_default_video_mode = sf::VideoMode(1280,720);
    unsigned int game_window_framerate = 60;

    //std::shared_ptr<OZ_GUIDesignDefine> gui_design;
    //std::shared_ptr<OZ_PhysicsDefine> physics_define;
    //std::shared_ptr<OZ_GameDefine> game_rules;
    //std::shared_ptr<OZ_GameGraphicsDefine> game_graphics_define;

    std::shared_ptr<OZ_OtherCoreData> other_core_data;
};
////////////////////////////////////////s

#endif
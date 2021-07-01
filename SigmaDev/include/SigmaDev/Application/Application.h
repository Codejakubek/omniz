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
// File: /impl/include/SigmaDev/Application/Application.h
// Description:
// Additional Notes:
////////////////////////////////////////

#ifndef SD_APPLICATION_APPLICATION_H
#define SD_APPLICATION_APPLICATION_H

#include <memory>

#include <SigmaDev/Application/ApplicationInitialization.h>
#include <SigmaDev/Application/ApplicationRelease.h>
#include <SigmaDev/Application/ApplicationTick.h>
#include <SFML/Graphics.hpp>

#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;

class SD_Resources;
class SD_MusicPlayer;
class SD_SoundAccesser;
class SD_SoundPlayer;
class SD_JsonAccesser;
class SD_JsonParser;
class SD_JsonSaver;
class SD_GraphicsAccesser;
class SD_GraphicsRenderer;
class SD_ApplicationTesting;
class SD_WindowsAccesser;
class SD_WindowsExecutive;
class SD_WindowsEvents;
class SD_GUIAccesser;
class SD_GUIExecutive;
////////////////////////////////////////
/** TODO: SD_Application_TickMethodExample&Tutorial */
/** TODO: SD_Application_ReleaseMethodExample&Tutorial */
/** TODO: SD_Application_InitializeMethodExample&Tutorial */
/** TODO: SD_Application_Preinitialize_Issue */
/** TODO: SD_Application_Stop_Tutorial */
/** TODO: SD_Application_Pause_Tutorial */
/** TODO: SD_Application_Start_Tutorial */
//---------------------------------------
class SD_Application : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    friend class SD_WindowsAccesser;
    
    SD_Application();
    SD_Application(const SD_Application& copy) = delete;
    virtual ~SD_Application();

    //---------------------------------------
    // Initializaton functions

    virtual void InitializeApplicationTick(std::unique_ptr<SD_ApplicationTick>&& application_tick);
    virtual void InitializeResources(std::unique_ptr<SD_Resources>&& resources);
    virtual void InitializeMusicPlayer(std::unique_ptr<SD_MusicPlayer>&& music_player);
    virtual void InitializeSoundAccesser(std::unique_ptr<SD_SoundAccesser>&& sound_accesser);
    virtual void InitializeSoundPlayer(std::unique_ptr<SD_SoundPlayer>&& sound_player);
    virtual void InitializeJsonAccesser(std::unique_ptr<SD_JsonAccesser>&& json_accesser);
    virtual void InitializeJsonParser(std::unique_ptr<SD_JsonParser>&& json_parser);
    virtual void InitailizeJsonSaver(std::unique_ptr<SD_JsonSaver>&& json_saver);
    virtual void InitializeGraphicsAccesser(std::unique_ptr<SD_GraphicsAccesser>&& graphics_accesser);
    virtual void InitializeGraphicsRenderer(std::unique_ptr<SD_GraphicsRenderer>&& graphics_renderer);
    virtual void InitializeWindowsAccesser(std::unique_ptr<SD_WindowsAccesser>&& windows_accesser);
    virtual void InitializeWindowsExecutive(std::unique_ptr<SD_WindowsExecutive>&& windows_executive);
    virtual void InitializeWindowsEvents(std::unique_ptr<SD_WindowsEvents>&& windows_events);
    virtual void InitializeGUIAccesser(std::unique_ptr<SD_GUIAccesser>&& gui_accesser);
    virtual void InitializeGUIExecutive(std::unique_ptr<SD_GUIExecutive>&& gui_executive);

    // Initializaton functions
    //---------------------------------------
    // Accessers

    inline const std::unique_ptr<SD_ApplicationInitialization>& GetApplicationInitialization() const {
        return initialization;
    }
    inline std::unique_ptr<SD_ApplicationInitialization>& GetApplicationInitialization() {
        return initialization;
    }
    inline const std::unique_ptr<SD_ApplicationRelease>& GetApplicationRelease() const {
        return release;
    }
    inline std::unique_ptr<SD_ApplicationRelease>& GetApplicationRelease() {
        return release;
    }
    inline const std::unique_ptr<SD_ApplicationTick>& GetApplicationTick() const {
        return tick;
    }
    inline std::unique_ptr<SD_ApplicationTick>& GetApplicationTick() {
        return tick;
    }
    inline const std::unique_ptr<SD_Resources>& GetResources() const {
        return resources;
    }
    inline std::unique_ptr<SD_Resources>& GetResources() {
        return resources;
    }
    inline const SD_Resources& GetResourcesRef() const {
        return *resources.get();
    }
    inline SD_Resources& GetResourcesRef() {
        return *resources.get();
    }
    inline const std::unique_ptr<SD_MusicPlayer>& GetMusicPlayer() const {
        return music_player;
    }
    inline std::unique_ptr<SD_MusicPlayer>& GetMusicPlayer() {
        return music_player;
    }
    inline const std::unique_ptr<SD_SoundAccesser>& GetSoundAccesser() const {
        return sound_accesser;
    }
    inline std::unique_ptr<SD_SoundAccesser>& GetSoundAccesser() {
        return sound_accesser;
    }
    inline const std::unique_ptr<SD_SoundPlayer>& GetSoundPlayer() const {
        return sound_player;
    }
    inline std::unique_ptr<SD_SoundPlayer>& GetSoundPlayer() {
        return sound_player;
    }
    inline const std::unique_ptr<SD_JsonAccesser>& GetJsonAccesser() const {
        return json_accesser;
    }
    inline std::unique_ptr<SD_JsonAccesser>& GetJsonAccesser() {
        return json_accesser;
    }
    inline const std::unique_ptr<SD_JsonParser>& GetJsonParser() const {
        return json_parser;
    }
    inline std::unique_ptr<SD_JsonParser>& GetJsonParser() {
        return json_parser;
    }
    inline const std::unique_ptr<SD_JsonSaver>& GetJsonSaver() const {
        return json_saver;
    }
    inline std::unique_ptr<SD_JsonSaver>& GetJsonSaver() {
        return json_saver;
    }
    inline const std::unique_ptr<SD_GraphicsAccesser>& GetGraphicsAccesser() const {
        return graphics_accesser;
    }
    inline std::unique_ptr<SD_GraphicsAccesser>& GetGraphicsAccesser() {
        return graphics_accesser;
    }
    inline const std::unique_ptr<SD_GraphicsRenderer>& GetGraphicsRenderer() const {
        return graphics_renderer;
    }
    inline std::unique_ptr<SD_GraphicsRenderer>& GetGraphicsRenderer() {
        return graphics_renderer;
    }
    inline const std::unique_ptr<SD_WindowsEvents>& GetWindowsEvents() const {
        return windows_events;
    }
    inline std::unique_ptr<SD_WindowsEvents>& GetWindowsEvents() {
        return windows_events;
    }
    inline const std::unique_ptr<SD_WindowsAccesser>& GetWindowsAccesser() const {
        return windows_accesser;
    }
    inline std::unique_ptr<SD_WindowsAccesser>& GetWindowsAccesser() {
        return windows_accesser;
    }
    inline const std::unique_ptr<SD_WindowsExecutive>& GetWindowsExecutive() const {
        return windows_executive;
    }
    inline std::unique_ptr<SD_WindowsExecutive>& GetWindowsExecutive() {
        return windows_executive;
    }
    //TODO: GUI_Disable
    /*
    inline const std::unique_ptr<SD_GUIAccesser>& GetGUIAccesser() const {
        return gui_accesser;
    }
    inline std::unique_ptr<SD_GUIAccesser>& GetGUIAccesser() {
        return gui_accesser;
    }
    inline const std::unique_ptr<SD_GUIExecutive>& GetGUIExecutive() const {
        return gui_executive;
    }
    inline std::unique_ptr<SD_GUIExecutive>& GetGUIExecutive() {
        return gui_executive;
    }
    */

    // Accessers
    //---------------------------------------
    // SD_Application Control

    virtual void ExecuteOneTick();
    virtual void Start();
    virtual void Pause();
    virtual void Stop();

    // SD_Application Control
    //---------------------------------------
    // Flags Acccess
    
    inline bool IsLaunched() const {
        return launched;
    }
    inline bool IsPaused() const {
        return paused;
    }
    inline bool IsPreinitialized() const {
        return is_preinitialized;
    }
    inline bool IsInitialized() const {
        return is_initialized;
    }
    inline bool AreAllWindowsAreClosed() const {
        return all_windows_are_closed;
    }

    // Flags Access
    //---------------------------------------
    // Init & Release & Tick

protected:
    virtual void Preinitialize();
    virtual void Initialize();
    virtual void Release();
    virtual void Tick();

    std::unique_ptr<SD_ApplicationInitialization> initialization;
    std::unique_ptr<SD_ApplicationRelease> release;
    
    std::unique_ptr<SD_ApplicationTick> tick; 
    std::unique_ptr<SD_Resources> resources; 
    std::unique_ptr<SD_MusicPlayer> music_player;
    std::unique_ptr<SD_SoundAccesser> sound_accesser;
    std::unique_ptr<SD_SoundPlayer> sound_player;
    std::unique_ptr<SD_JsonAccesser> json_accesser;
    std::unique_ptr<SD_JsonParser> json_parser;
    std::unique_ptr<SD_JsonSaver> json_saver;
    std::unique_ptr<SD_GraphicsAccesser> graphics_accesser;
    std::unique_ptr<SD_GraphicsRenderer> graphics_renderer;
    std::unique_ptr<SD_WindowsEvents> windows_events;
    std::unique_ptr<SD_WindowsAccesser> windows_accesser;
    std::unique_ptr<SD_WindowsExecutive> windows_executive;
    //TODO: GUI_Disable
    //std::unique_ptr<SD_GUIAccesser> gui_accesser;
    //std::unique_ptr<SD_GUIExecutive> gui_executive;

    bool launched = false;
    bool paused = false;
    bool is_preinitialized = false;
    bool is_initialized = false;
    bool all_windows_are_closed = false;
};
////////////////////////////////////////
/** TODO: SD_ApplicationInitializationHelper_HandleMoreThanDefaultApplication */
//---------------------------------------
class SD_ApplicationInitializationHelper : public SD_Class{
public:
    SD_DECLARE_CLASS_H()

    SD_ApplicationInitializationHelper(bool default_application = true);
    virtual ~SD_ApplicationInitializationHelper();

    virtual void RunForOneTick();
    virtual void RunTillClosed();
    inline const std::unique_ptr<SD_Application>& GetApplication() const {
        return application;
    }
    inline std::unique_ptr<SD_Application>& GetApplication() {
        return application;
    }
    virtual void CreateWindow(
        const std::string& window_id,
        sf::VideoMode mode, 
        const std::string& title, 
        sf::Uint32 style=sf::Style::Default, 
        const sf::ContextSettings &settings=sf::ContextSettings()
    );
    virtual bool AtLeastOneWindowIsOpen() const;
protected:
    virtual void Initialize(bool default_application);
    virtual void Release();

    std::unique_ptr<SD_Application> application; ///< Direct SD_Application memory management
};
////////////////////////////////////////

#endif
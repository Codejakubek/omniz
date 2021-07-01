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
// File: /impl/src/SigmaDev/Application/Application.cpp
// Description:
// Additional Notes:
////////////////////////////////////////

#include <SigmaDev/Application/Application.h>

#include <SigmaDev/Application/ApplicationTick.h>
#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Audio/MusicPlayer.h>
#include <SigmaDev/Audio/SoundAccesser.h>
#include <SigmaDev/Audio/SoundPlayer.h>
#include <SigmaDev/Configuration/JsonAccesser.h>
#include <SigmaDev/Configuration/JsonParser.h>
#include <SigmaDev/Configuration/JsonSaver.h>
#include <SigmaDev/Graphics/GraphicsAccesser.h>
#include <SigmaDev/Graphics/GraphicsRenderer.h>
#include <SigmaDev/Testing/Testing.h>
#include <SigmaDev/Windows/WindowsAccesser.h>
#include <SigmaDev/Windows/WindowsExecutive.h>
#include <SigmaDev/Windows/WindowsEvents.h>
#include <SigmaDev/GUI/GUIObject.h>
#include <SigmaDev/Graphics/ExpandableSprite.h>

#include <SigmaDev/Application/DefaultApplication.h>


////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_Application)

SD_Application::SD_Application() {
    
}
SD_Application::~SD_Application() {

}
////////////////////////////////////////
////////////////////////////////////////
void SD_Application::InitializeApplicationTick(std::unique_ptr<SD_ApplicationTick>&& tick) {
    this->tick = std::move(tick);
}
void SD_Application::InitializeResources(std::unique_ptr<SD_Resources>&& resources) {
    this->resources = std::move(resources);
}
void SD_Application::InitializeMusicPlayer(std::unique_ptr<SD_MusicPlayer>&& music_player)
{
    this->music_player = std::move(music_player);
}
void SD_Application::InitializeSoundAccesser(std::unique_ptr<SD_SoundAccesser>&& sound_accesser)
{
    this->sound_accesser = std::move(sound_accesser);
}
void SD_Application::InitializeSoundPlayer(std::unique_ptr<SD_SoundPlayer>&& sound_player)
{
    this->sound_player = std::move(sound_player);
}
void SD_Application::InitializeJsonAccesser(std::unique_ptr<SD_JsonAccesser>&& json_accesser)
{
    this->json_accesser = std::move(json_accesser);
}
void SD_Application::InitializeJsonParser(std::unique_ptr<SD_JsonParser>&& json_parser)
{
    this->json_parser = std::move(json_parser);
}
void SD_Application::InitailizeJsonSaver(std::unique_ptr<SD_JsonSaver>&& json_saver)
{
    this->json_saver = std::move(json_saver);
}
void SD_Application::InitializeGraphicsAccesser(std::unique_ptr<SD_GraphicsAccesser>&& graphics_accesser)
{
    this->graphics_accesser = std::move(graphics_accesser);
}
void SD_Application::InitializeGraphicsRenderer(std::unique_ptr<SD_GraphicsRenderer>&& graphics_renderer)
{
    this->graphics_renderer = std::move(graphics_renderer);
}
void SD_Application::InitializeWindowsAccesser(std::unique_ptr<SD_WindowsAccesser>&& windows_accesser) 
{
    this->windows_accesser = std::move(windows_accesser);    
}
void SD_Application::InitializeWindowsExecutive(std::unique_ptr<SD_WindowsExecutive>&& windows_executive) 
{
    this->windows_executive = std::move(windows_executive);
}
void SD_Application::InitializeWindowsEvents(std::unique_ptr<SD_WindowsEvents>&& windows_events) {
    this->windows_events = std::move(windows_events);
}

void SD_Application::InitializeGUIAccesser(std::unique_ptr<SD_GUIAccesser>&& gui_accesser) {
    //this->gui_accesser = std::move(gui_accesser);
}
void SD_Application::InitializeGUIExecutive(std::unique_ptr<SD_GUIExecutive>&& gui_executive) {
    //this->gui_executive = std::move(gui_executive);
}
////////////////////////////////////////

void SD_Application::ExecuteOneTick() {

}
void SD_Application::Start() {
    
}
void SD_Application::Pause() {

}
void SD_Application::Stop() {

}

void SD_Application::Preinitialize() {
    is_preinitialized = true;
}
void SD_Application::Initialize() {
    is_initialized = true;
}
void SD_Application::Release() {
    
}
void SD_Application::Tick() {
    
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ApplicationInitializationHelper)

SD_ApplicationInitializationHelper::SD_ApplicationInitializationHelper(bool default_application) {
    if (default_application) {
        Initialize(default_application);
    }
}
SD_ApplicationInitializationHelper::~SD_ApplicationInitializationHelper() {
    Release();
}
void SD_ApplicationInitializationHelper::RunForOneTick() {
    application->ExecuteOneTick();
}
void SD_ApplicationInitializationHelper::RunTillClosed() {
    application->Start();
} 

void SD_ApplicationInitializationHelper::CreateWindow(
    const std::string& window_id,
    sf::VideoMode mode,
    const std::string& title,
    sf::Uint32 style,
    const sf::ContextSettings& settings
) {
    std::unique_ptr<SD_WindowsAccesser>& window_accesser = application->GetWindowsAccesser();
    if (window_accesser) {
        std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(mode, title, style, settings);
        window->setFramerateLimit(60);

        window_accesser->AddRenderWindow(window_id, std::move(window));
    }
}
bool SD_ApplicationInitializationHelper::AtLeastOneWindowIsOpen() const {
    return (application->AreAllWindowsAreClosed() == false);
}
void SD_ApplicationInitializationHelper::Initialize(bool default_application) {
    application = std::make_unique<SD_DefaultApplication>();
}
void SD_ApplicationInitializationHelper::Release() {
    
}
//////////////////////////////////////// 

#include <SigmaDev/Testing/Testing.h>

SD_DEFINE_REALTIME_TEST(testing_application_initialization)
    SD_ApplicationInitializationHelper helper(true);

    helper.CreateWindow(
        "a",
        sf::VideoMode(200,200),
        "200x200"
    );

    helper.CreateWindow(
        "b",
        sf::VideoMode(100,100),
        "100x100"
    );

    helper.CreateWindow(
        "c",
        sf::VideoMode(150,150),
        "150x150"
    );
    helper.RunTillClosed();

SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(testing_application_initialization)
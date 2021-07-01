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
// File: /impl/src/SigmaDev/Application/DefaultApplication.cpp
// Description:
// Additional Notes:
////////////////////////////////////////

#include <SigmaDev/Application/DefaultApplication.h>
#include <SigmaDev/Exception/Exception.h>

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
#include <SigmaDev/Windows/WindowsEvents.h>
#include <SigmaDev/Windows/WindowsAccesser.h>
#include <SigmaDev/Windows/WindowsExecutive.h>


////////////////////////////////////////
namespace exc 
{
    SD_DefaultApplicationInitializationFailed::SD_DefaultApplicationInitializationFailed(
        const std::string& name,
        const std::string& detailed_desc
    ) : SD_InitializationFailed(name, detailed_description)
    {

    }
    SD_DefaultApplicationInitializationFailed::SD_DefaultApplicationInitializationFailed(
        const std::string& detailed_description
    ) : SD_InitializationFailed("SD_DefaultApplicationInitializationFailed", detailed_description)
    {

    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_DefaultApplicationInitialization)
void SD_DefaultApplicationInitialization::Initialize(SD_Application& application) {
    try {
        SD_DefaultApplication& c_application = dynamic_cast<SD_DefaultApplication&>(application);
        
        c_application.InitializeApplicationTick(
            std::move(
                std::make_unique<SD_DefaultApplicationTick>()
            )
        );

        c_application.InitializeResources(
            std::move(
                std::make_unique<SD_Resources>(application)
            )
        );

        c_application.InitializeMusicPlayer(
            std::move(
                std::make_unique<SD_MusicPlayer>(application)
            )
        );

        c_application.InitializeSoundAccesser(
            std::move(
                std::make_unique<SD_SoundAccesser>(application)
            )
        );

        c_application.InitializeSoundPlayer(
            std::move(
                std::make_unique<SD_SoundPlayer>(application)
            )
        );

        c_application.InitializeJsonAccesser(
            std::move(
                std::make_unique<SD_JsonAccesser>(application)
            )
        );

        c_application.InitailizeJsonSaver(
            std::move(
                std::make_unique<SD_JsonSaver>(application)
            )
        );

        c_application.InitializeGraphicsAccesser(
            std::move(
                std::make_unique<SD_GraphicsAccesser>(application)
            )
        );

        c_application.InitializeGraphicsRenderer(
            std::move(
                std::make_unique<SD_GraphicsRenderer>(application)
            )
        );

//        c_application.InitializeApplicationTesting(
//            std::move(
//                std::make_unique<SD_ApplicationTesting>()
//            )
//        );

//        c_application.InitializeApplicationTesting(
//            std::move(
//                std::make_unique<SD_ApplicationTesting>(application)
//            )
//        );

        c_application.InitializeWindowsEvents(
            std::move(
                std::make_unique<SD_WindowsEvents>(application)
            )
        );

        c_application.InitializeWindowsAccesser(
            std::move(
                std::make_unique<SD_WindowsAccesser>(application)
            )
        );

        c_application.InitializeWindowsExecutive(
            std::move(
                std::make_unique<SD_WindowsExecutive>(application)
            )
        );


        /*
        c_application.InitializeGUIAccesser(
            std::move(
                std::make_unique<SD_GUIAccesser>(application)
            )
        );
        */

       /*
        c_application.InitializeGUIExecutive(
            std::move(
                std::make_unique<SD_GUIExecutive>(application)
            )
        );
        */

    } catch (...) {
        std::throw_with_nested(
            exc::SD_DefaultApplicationInitializationFailed("Unable to initialize SD_DefaultApplication")
        );
    }
}
SD_DECLARE_CLASS_CPP(SD_DefaultApplicationRelease)
void SD_DefaultApplicationRelease::Release(SD_Application& application) {
    try {
        SD_DefaultApplication& c_application = dynamic_cast<SD_DefaultApplication&>(application);

    } catch (...) {
        std::throw_with_nested(
            exc::SD_DefaultApplicationInitializationFailed("Unable to release SD_DefaultApplication")
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_DefaultApplicationTick)
void SD_DefaultApplicationTick::Tick(SD_Application& application) {
    auto& windows_accesser = application.GetWindowsAccesser();
    auto& renderer = application.GetGraphicsRenderer();
    //auto& gui_executive = application.GetGUIExecutive();
    auto& window_events = application.GetWindowsEvents();
    auto& audio_player = application.GetSoundPlayer();

    const std::set<std::string>& active_windows = windows_accesser->GetActiveWindows();

    std::vector<std::string> to_be_closed;

    window_events->ClearEvents();
    window_events->PollEvents();
    for (const auto & active_window : active_windows) {
        auto& render_window = windows_accesser->GetRenderWindow(active_window);
        SD_RenderWindowAccess window_access(active_window, *render_window.get());

        if (render_window->isOpen()) {
            if (IsThereClosedWindowEvent(application, active_window)) {
                to_be_closed.emplace_back(active_window);
            }
            
            render_window->clear();
            
            //TODO: GUI_Disable
            /*
            gui_executive->ActivityGUI(window_access);
            gui_executive->RenderGUI(window_access);
            gui_executive->PlayGUI(window_access);
            */
            renderer->RenderAdded();        
            render_window->display();
            renderer->RemoveResourcesAfterRender();
            renderer->ClearRenderStack();
        }
    }
    audio_player->Tick();
    for (auto & e : to_be_closed) {
        windows_accesser->EraseRenderWindow(e);
    }
    windows_accesser->CheckIfThereAreNoWindowsAndUpdateApplicationIfThereAreNone();
}
bool SD_DefaultApplicationTick::IsThereClosedWindowEvent(
    SD_Application& application,
    const std::string& window_id) {

    auto& window_events = application.GetWindowsEvents();
    std::unique_ptr<SD_WindowEvents>& events = window_events->GetWindowEventsQueueList(window_id);
    SD_WindowEvents::_sorted_events& sorted_events = events->GetSortedEvents();
    auto it = sorted_events.find(sf::Event::EventType::Closed);
    if (it != sorted_events.end()) {
        return true;
    } else return false;
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_DefaultApplication)
SD_DefaultApplication::SD_DefaultApplication() 
    : SD_Application()
{
    Preinitialize();
    Initialize();
}
SD_DefaultApplication::~SD_DefaultApplication() {
    Release();
}
void SD_DefaultApplication::ExecuteOneTick() {
    SD_Application::ExecuteOneTick();

    Tick();
}
void SD_DefaultApplication::Start() {
    SD_Application::Start();

    while (all_windows_are_closed == false) {
        Tick();
    }
}
void SD_DefaultApplication::Pause() {
    SD_Application::Pause();
}
void SD_DefaultApplication::Stop() {
    SD_Application::Stop();
}

void SD_DefaultApplication::Preinitialize() {
    SD_Application::Preinitialize();   

    this->initialization = std::make_unique<SD_DefaultApplicationInitialization>();
    this->release = std::make_unique<SD_DefaultApplicationRelease>();
}
void SD_DefaultApplication::Initialize() {
    SD_Application::Initialize();
    
    this->initialization->Initialize(*this);

}
void SD_DefaultApplication::Release() {
    SD_Application::Release();
}
void SD_DefaultApplication::Tick() {
    SD_Application::Tick();

    this->tick->Tick(*this);
}
////////////////////////////////////////
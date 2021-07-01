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
// File: /impl/src/SigmaDev/Windows/WindowsAccesser.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Windows/WindowsAccesser.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Windows/WindowsEvents.h>
#include <SigmaDev/Exception/WindowsExceptions.h>

#include <exception>

////////////////////////////////////////
inline SD_Resources& SD_GetResources(SD_Application& app) {
    return *app.GetResources().get();
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_WindowsAccesser)

SD_WindowsAccesser::SD_WindowsAccesser(SD_Application& application_reference) 
: application(application_reference)
{

}

const SD_RenderWindowResources& SD_WindowsAccesser::RenderWindows() const {
    return application.GetResourcesRef().GetRenderWindowResourcesRef();
}
SD_RenderWindowResources& SD_WindowsAccesser::RenderWindows() {
    return application.GetResourcesRef().GetRenderWindowResourcesRef();
}
//---------------------------------------
void SD_WindowsAccesser::AddRenderWindow(
    const std::string& id,
    std::unique_ptr<sf::RenderWindow>&& render_window
) {
    try {
        // Add Render Window to Resources,
        SD_Resources& resources = GetResources();
        SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        render_window_resources.AddRenderWindow(id, std::move(render_window));

        // Initialize Window Events Queue
        std::unique_ptr<SD_WindowsEvents>& windows_events = application.GetWindowsEvents();
        windows_events->AddNewWindowEventsQueueList(id);

        //Add to list
        active_windows.insert(id);
    } catch (...) {
        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowInsertionFailed(id)
        );     
    }
}
void SD_WindowsAccesser::AddRenderWindow(
    const std::string& id,
    const sf::VideoMode& video_mode,
    const sf::String& title,
    sf::Uint32 style,
    const sf::ContextSettings& settings 
) {
    try {
        // Add Render Window to Resources,
        SD_Resources& resources = GetResources();
        SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        render_window_resources.AddRenderWindow(id, video_mode, title, style, settings);

        // Initialize Window Events Queue
        std::unique_ptr<SD_WindowsEvents>& windows_events = application.GetWindowsEvents();
        windows_events->AddNewWindowEventsQueueList(id);

        //Add to list
        active_windows.insert(id);
    } catch (...) {
        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowInsertionFailed(id)
        );  
    }
}
void SD_WindowsAccesser::AddRenderWindow(
    const std::string& id,
    sf::WindowHandle handle,
    const sf::ContextSettings& settings 
)
{
    try {
        // Add Render Window to Resources,
        SD_Resources& resources = GetResources();
        SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        render_window_resources.AddRenderWindow(id, handle, settings);

        // Initialize Window Events Queue
        std::unique_ptr<SD_WindowsEvents>& windows_events = application.GetWindowsEvents();
        windows_events->AddNewWindowEventsQueueList(id);

        //Add to list
        active_windows.insert(id);
    } catch (...) {
        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowInsertionFailed(id)
        );  
    }
}
const std::unique_ptr<sf::RenderWindow>& SD_WindowsAccesser::GetRenderWindow(const std::string& id) const {
    try {
        //Find Render Window in Resources
        const SD_Resources& resources = GetResources();
        const SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        //Return it
        return render_window_resources.GetRenderWindow(id);
    } catch (...) {

        std::cout << "Unable to find window\n";

        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowNotFound(id)
        );
    }
}
std::unique_ptr<sf::RenderWindow>& SD_WindowsAccesser::GetRenderWindow(const std::string& id) {
    try {
        //Find Render Window in Resources
        SD_Resources& resources = GetResources();
        SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        return render_window_resources.GetRenderWindow(id);
    } catch (...) {

        std::cout << "Unable to find window\n";

        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowNotFound(id)
        );
    }
}
void SD_WindowsAccesser::EraseRenderWindow(const std::string& id) {
    try {
        //Erase Render window in Resources
        SD_Resources& resources = GetResources();
        SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
        render_window_resources.EraseRenderWindow(id);

        // Remove Event Queue of a window
        std::unique_ptr<SD_WindowsEvents>& windows_events = application.GetWindowsEvents();
        windows_events->EraseWindowEventsQueueList(id);

        //Remove from list
        auto it = active_windows.find(id);
        if (it != active_windows.end()) {
            active_windows.erase(it);
        }
    } catch (...) {
        std::throw_with_nested(
            exc::SD_WindowAccesserRenderWindowErasionFailed(id)
        );
    }
}
bool SD_WindowsAccesser::RenderWindowExists(const std::string& id) const {
    const SD_Resources& resources = GetResources();
    const SD_RenderWindowResources& render_window_resources = resources.GetRenderWindowResourcesRef();
    return render_window_resources.RenderWindowExists(id);
}
//---------------------------------------
SD_Resources& SD_WindowsAccesser::GetResources() {
    return application.GetResourcesRef();
}
const SD_Resources& SD_WindowsAccesser::GetResources() const {
    return application.GetResourcesRef();
}
//---------------------------------------
void SD_WindowsAccesser::CheckIfThereAreNoWindowsAndUpdateApplicationIfThereAreNone() {
    if (active_windows.empty()) {
        application.all_windows_are_closed = true;
    }
}
////////////////////////////////////////
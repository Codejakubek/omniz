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
// File: /impl/src/SigmaDev/Windows/WindowsEvents.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Windows/WindowsEvents.h>
#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Windows/WindowsAccesser.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Exception/WindowsExceptions.h>

SD_DECLARE_CLASS_CPP(SD_WindowEvents)

SD_WindowEvents::SD_WindowEvents(
    const std::string& window_id,
    SD_Application& application
) : window_id(window_id),
    application(application)
{
    
}
void SD_WindowEvents::ClearEvents() {
    events.clear();
    sorted_events.clear();
}
void SD_WindowEvents::PollEvents() {
    sf::RenderWindow& window = GetWindow();
    sf::Event event;
    while (window.pollEvent(event))
    {
        AddEvent(event);
    }
}
void SD_WindowEvents::AddEvent(const sf::Event& event) {
    AddEventToNormalQueue(event);
    AddEventToSortedQueue(event);
}
bool SD_WindowEvents::IsThereEventOfType(const sf::Event::EventType& type) const {
    auto it = sorted_events.find(type);
    if (it != sorted_events.end()) {
        return true;
    } else {
        return false;
    }
}
const std::list<sf::Event>& SD_WindowEvents::GetEventsOfType(const sf::Event::EventType& type) const {
    auto it = sorted_events.find(type);
    if (it != sorted_events.end()) {
        return it->second;
    } else {
        auto e = exc::SD_EventsOfTypeNotFound();
        throw e;
    }
}

const sf::RenderWindow& SD_WindowEvents::GetWindow() const {
    auto& window_accesser = application.GetWindowsAccesser();
    auto& render_window_resources = window_accesser->RenderWindows();
    auto& shared_render_window = render_window_resources.GetRenderWindow(window_id);
    sf::RenderWindow& render_window = *shared_render_window.get();
    return render_window;
}
sf::RenderWindow& SD_WindowEvents::GetWindow() {
    auto& window_accesser = application.GetWindowsAccesser();
    auto& render_window_resources = window_accesser->RenderWindows();
    auto& shared_render_window = render_window_resources.GetRenderWindow(window_id);
    sf::RenderWindow& render_window = *shared_render_window.get();
    return render_window;
}
void SD_WindowEvents::AddEventToNormalQueue(const sf::Event& event) {
    events.emplace_back(event);
}
void SD_WindowEvents::AddEventToSortedQueue(const sf::Event& event) {
    auto it = sorted_events.find(event.type);
    if (it != sorted_events.end()) {
        std::list<sf::Event>& sorted = it->second;
        sorted.emplace_back(event);
    } else {
        auto insert_pair = sorted_events.insert(std::make_pair(event.type, std::list<sf::Event>()));
        std::list<sf::Event>& sorted = insert_pair.first->second;
        sorted.emplace_back(event);
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_WindowsEvents)

SD_WindowsEvents::SD_WindowsEvents(
    SD_Application& application 
) : application(application)
{

}

void SD_WindowsEvents::ClearEvents() {
    for (auto & e : window_events_container) {
        std::unique_ptr<SD_WindowEvents>& events_queue = e.second;
        events_queue->ClearEvents();
    }
}

void SD_WindowsEvents::PollEvents() {
    for (auto & e : window_events_container) {
        std::unique_ptr<SD_WindowEvents>& events_queue = e.second;
        events_queue->PollEvents();
    }
}

void SD_WindowsEvents::AddNewWindowEventsQueueList(const std::string& window_id) {
    auto insert_pair = window_events_container.insert(std::make_pair(
        window_id,
        std::make_unique<SD_WindowEvents>(window_id, application)
    ));
    if (insert_pair.second == false) {
        auto e = exc::SD_WindowEventsQueueListInsertionFailed(window_id);
        throw e;        
    }
}
void SD_WindowsEvents::EraseWindowEventsQueueList(const std::string& window_id) {
    auto it = window_events_container.find(window_id);
    if (it != window_events_container.end()) {
        window_events_container.erase(it);
    } else {
        auto e = exc::SD_WindowEventsQueueListErasionFailed(window_id);
        throw e;
    }
}
const std::unique_ptr<SD_WindowEvents>& SD_WindowsEvents::GetWindowEventsQueueList(const std::string& window_id) const {
    auto it = window_events_container.find(window_id);
    if (it != window_events_container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_WindowEventsQueueListNotFound(window_id);
        throw e;
    }
}
std::unique_ptr<SD_WindowEvents>& SD_WindowsEvents::GetWindowEventsQueueList(const std::string& window_id) {
    auto it = window_events_container.find(window_id);
    if (it != window_events_container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_WindowEventsQueueListNotFound(window_id);
        throw e;
    }
}
bool SD_WindowsEvents::IsThereQueueOfEventsOfWindow(const std::string& window_id) const {
    auto it = window_events_container.find(window_id);
    if (it != window_events_container.end()) {
        return true;
    } else return false;
}
////////////////////////////////////////

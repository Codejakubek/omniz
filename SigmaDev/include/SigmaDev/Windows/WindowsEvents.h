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
// File: /impl/include/SigmaDev/Windows/WindowsEvents.h
// Description:
// Additional Notes:

#ifndef SD_WINDOWS_WINDOWS_EVENTS_H
#define SD_WINDOWS_WINDOWS_EVENTS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <queue>
#include <map>
#include <list>
#include <SigmaDev/Misc/Class.h>

class SD_Application;
////////////////////////////////////////

/**
 * @brief SD_WindowEvents is class for events polling and 
 *        handling
 */
class SD_WindowEvents : public SD_Class{
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Raw list of sf::Event
     */
    typedef std::list<sf::Event> _events;
    /**
     * @brief Raw sorted map of sf::Event
     */
    typedef std::map<sf::Event::EventType, std::list<sf::Event>> _sorted_events;

    SD_WindowEvents() = delete;
    /**
     * @brief Construct SD_WindowEvents using sf::RenderWindow ID and
     *        SD_Application connected reference
     * 
     * @param window_id sf::RenderWindow ID
     * @param application SD_Application reference
     */
    SD_WindowEvents(const std::string& window_id, SD_Application& application);

    /**
     * @brief Clears both raw list and sorted list of sf::Events
     */
    virtual void ClearEvents();
    /**
     * @brief Polls events from the window 
     */
    virtual void PollEvents();
    /**
     * @brief Adds event to both raw list and sorted list of sf::Events
     * 
     * @param event const reference to sf::Event (copy)
     */
    virtual void AddEvent(const sf::Event& event);

    bool IsThereEventOfType(const sf::Event::EventType& type) const;
    const std::list<sf::Event>& GetEventsOfType(const sf::Event::EventType& type) const;
    
 
    inline const _events& GetEvents() const {
        return events;
    }
    inline _events& GetEvents() {
        return events;
    }
    inline const _sorted_events& GetSortedEvents() const {
        return sorted_events;
    }
    inline _sorted_events& GetSortedEvents() {
        return sorted_events;
    }
    inline const std::string& GetWindowId() const {
        return window_id;
    }
protected:
    const sf::RenderWindow& GetWindow() const;
    sf::RenderWindow& GetWindow();

    virtual void AddEventToNormalQueue(const sf::Event& event);
    virtual void AddEventToSortedQueue(const sf::Event& event);

    std::string window_id;

    _events events;
    _sorted_events sorted_events;
    SD_Application& application;
};

/**
 * @var SD_WindowEvents::window_id
 * @brief sf::RenderWindow ID
 * 
 * @var SD_WindowEvents::events
 * @brief Raw container of sf::Events
 * 
 * @var SD_WindowEvents::sorted_events
 * @brief Raw container for @b sorted (by sf::Event::EventType) sf::Events
 * 
 * @var SD_WindowEvents::application
 * @brief Reference to connected SD_Application
 */
////////////////////////////////////////

/**
 * @brief SD_WindowsEvents is class containing all sf::RenderWindows
 *        events list. 
 */
class SD_WindowsEvents : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<SD_WindowEvents>> _window_events_container;

    SD_WindowsEvents() = delete;
    /**
     * @brief Construct SD_WindowsEvents by passing the SD_Application
     *        non-const connected to reference
     * 
     * @param application_reference 
     */
    SD_WindowsEvents(SD_Application& application_reference);
    virtual ~SD_WindowsEvents() = default;

    /**
     * @brief Clears all windows event lists
     */
    virtual void ClearEvents();
    /**
     * @brief Polls all event lists from all sf::RenderWindows
     */
    virtual void PollEvents();
    
    /**
     * @brief Inserts the SD_WindowEvents in SD_WindowsEvents in 
     *        SD_WindowsEvents::window_events_container
     * 
     * @param window_id sf::RenderWindow ID
     */
    virtual void AddNewWindowEventsQueueList(const std::string& window_id);
    /**
     * @brief Erases the SD_WindowEvents in SD_WindowsEvents in
     *        SD_WindowsEvents::window_events_container
     * 
     * @param window_id sf::RenderWindow ID
     */
    virtual void EraseWindowEventsQueueList(const std::string& window_id);
    /**
     * @brief Accesses the SD_WindowEvents in SD_WindowsEvents in
     *        SD_WindowsEvents::window_events_container
     * 
     * @param window_id sf::RenderWindow ID
     * @return const std::unique_ptr<SD_WindowEvents>& const reference to SD_WindowEvents 
     */
    virtual const std::unique_ptr<SD_WindowEvents>& GetWindowEventsQueueList(const std::string& window_id) const;
    /**
     * @brief Accesses the SD_WindowEvents in SD_WindowsEvents in
     *        SD_WindowsEvents::window_events_container
     * 
     * @param window_id sf::RenderWindow ID
     * @return std::unique_ptr<SD_WindowEvents>& non-const reference to SD_WindowEvents 
     */
    virtual std::unique_ptr<SD_WindowEvents>& GetWindowEventsQueueList(const std::string& window_id);
    /**
     * @brief Returns the if the SD_WindowEvents in SD_WindowEvents exists
     * 
     * @param window_id sf::RenderWindow ID
     * @return true If it exists
     */
    virtual bool IsThereQueueOfEventsOfWindow(const std::string& window_id) const;
    

    inline const _window_events_container& GetContainer() const {
        return window_events_container;
    } 
    inline _window_events_container& GetContainer() {
        return window_events_container;
    }
protected:
    _window_events_container window_events_container;
    SD_Application& application;
};

/**
 * @var SD_WindowsEvents::window_events_container
 * @brief Container for all SD_WindowEvents
 * 
 * @var SD_WindowsEvents::application
 * @brief SD_Application reference
 */

////////////////////////////////////////

#endif
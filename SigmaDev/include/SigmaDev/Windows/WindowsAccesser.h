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
// File: /impl/include/SigmaDev/Windows/WindowsAccesser.h
// Description:
// Additional Notes:

#ifndef SD_WINDOWS_WINDOWS_ACCESSER_H
#define SD_WINDOWS_WINDOWS_ACCESSER_H

#include <SigmaDev/Resources/Resources.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;
class SD_Resources;

class SD_RenderWindowResources;
////////////////////////////////////////

/**
 * @brief SD_WindowAccesser class is helper class for sf::Window management in
 *        SD_Resources.
 */
class SD_WindowsAccesser : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_WindowsAccesser() = delete;
    /**
     * @brief Construct SD_WindowAccesser, connect to SD_Application
     * 
     * @param application_reference SD_Application reference
     */
    SD_WindowsAccesser(SD_Application& application_reference);
    virtual ~SD_WindowsAccesser() = default;  

    /**
     * @brief Access the SD_RenderWindowResources from SD_Resources
     * 
     * @return const SD_RenderWindowResources& 
     */
    const SD_RenderWindowResources& RenderWindows() const;
    /**
     * @brief Access the SD_RenderWindowResources from SD_Resources
     * 
     * @return SD_RenderWindowResources& 
     */
    SD_RenderWindowResources& RenderWindows();

    /**
     * @brief Inserts sf::RenderWindow and connects it to all necessary places. 
     *        1. Initializes sf::RenderWindow memory in SD_RenderWindowResources from SD_Resources, 
     *        2. Initializes the SD_WindowEvents in SD_WindowsEvents,
     *        3. Makes window active adds to SD_WindowAccesser::active_windows
     * 
     * @param id sf::RenderWindow ID
     * @param render_window rvalue std::moved() sf::RenderWindow
     * 
     * @throw exc::SD_WindowAccesserRenderWindowInsertionFailed on a failure (as a @b nested)
     */
    virtual void AddRenderWindow(const std::string& id, std::unique_ptr<sf::RenderWindow>&& render_window);
    /**
     * @brief Builds sf::RenderWindow from sf::RenderWindow constructor data 
     *        and connects it to all necessary places.
     *        1. Initializes sf::RenderWindow memory in SD_RenderWindowResources from SD_Resources, 
     *        2. Initializes the SD_WindowEvents in SD_WindowsEvents,
     *        3. Makes window active adds to SD_WindowAccesser::active_windows
     * 
     * @param id sf::RenderWindow ID
     * @param video_mode sf::VideoMode used in sf::RenderWindow construction
     * @param title sf::String title of sf::RenderWindow, used in sf::RenderWindow construction
     * @param style sf::Uint32 style of sf::RenderWindow, used in sf::RenderWindow construction
     * @param settings sf::ContextSettings of sf::RenderWindow, used in sf::RenderWindow construction
     * 
     * @throw exc::SD_WindowAccesserRenderWindowInsertionFailed on a failure (as a @b nested)
     */
    virtual void AddRenderWindow(
        const std::string& id,
        const sf::VideoMode& video_mode,
        const sf::String& title,
        sf::Uint32 style = sf::Style::Default,
        const sf::ContextSettings& settings = sf::ContextSettings()
    );
    /**
     * @brief Builds sf::RenderWindow from sf::RenderWindow constructor data 
     *        and connects it to all necessary places.
     *        1. Initializes sf::RenderWindow memory in SD_RenderWindowResources from SD_Resources, 
     *        2. Initializes the SD_WindowEvents in SD_WindowsEvents,
     *        3. Makes window active - adds to SD_WindowAccesser::active_windows
     * 
     * @param id sf::RenderWindow ID
     * @param handle sf::WindowHandle of sf::RenderWindow, used in sf::RenderWindow construction
     * @param settings sf::ContextSettings of sf::RenderWindow, used in sf::RenderWindow construction
     * 
     * @throw exc::SD_WindowAccesserRenderWindowInsertionFailed on a failure (as a @b nested)
     */
    virtual void AddRenderWindow(
        const std::string& id,
        sf::WindowHandle handle,
        const sf::ContextSettings& settings = sf::ContextSettings()
    );
    /**
     * @brief Access the sf::RenderWindow from SD_RenderWindowResources
     * 
     * @param id sf::RenderWindow ID
     * @return const std::unique_ptr<sf::RenderWindow>& const unique ptr of sf::RenderWindow
     * 
     * @throw exc::SD_WindowAccesserRenderWindowNotFound on failure (as a @b nested) 
     */
    virtual const std::unique_ptr<sf::RenderWindow>& GetRenderWindow(const std::string& id) const;
    /**
     * @brief Access the sf::RenderWindow from SD_RenderWindowResources
     * 
     * @param id sf::RenderWindow ID
     * @return std::unique_ptr<sf::RenderWindow>& unique ptr of sf::RenderWindow
     * 
     * @throw exc::SD_WindowAccesserRenderWindowNotFound on failure (as a @b nested) 
     */
    virtual std::unique_ptr<sf::RenderWindow>& GetRenderWindow(const std::string& id);
    /**
     * @brief Erases and disconnects the sf::RenderWindow from SD_RenderWindowResources and other
     *        necessary places.
     *        1. Removes it from SD_RenderWindowResources resulting in releasing the sf::RenderWindow,
     *        2. Erases the SD_WindowEvents from SD_WindowsEvents connected to sf::RenderWindow,
     *        3. Makes the window inactive removes from SD_WindowAccesser::active_window
     *        if it exists there.
     * 
     * @throw exc::SD_WindowAccesserRenderWindowErasionFailed on failure (as a @b nested)
     * 
     * @param id 
     */
    virtual void EraseRenderWindow(const std::string& id);
    virtual bool RenderWindowExists(const std::string& id) const;

    inline const SD_Application& GetApplicationReference() const {
        return application;
    }
    inline SD_Application& GetApplicationReference() {
        return application;
    }
    SD_Resources& GetResources();
    const SD_Resources& GetResources() const;

    inline const std::set<std::string>& GetActiveWindows() const {
        return active_windows;
    }
    void CheckIfThereAreNoWindowsAndUpdateApplicationIfThereAreNone();
protected:

    std::set<std::string> active_windows;
    SD_Application& application;
};
////////////////////////////////////////

#endif

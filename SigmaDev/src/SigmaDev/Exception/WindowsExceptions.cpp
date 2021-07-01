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
// File: /impl/src/SigmaDev/Exception/WindowsExceptions.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Exception/WindowsExceptions.h>

namespace exc
{
    ////////////////////////////////////////
    SD_WindowEventsQueueListInsertionFailed::SD_WindowEventsQueueListInsertionFailed()
     : SD_Exception("SD_WindowEventsQueueListInsertionFailed", DefaultExceptionDescription()),
       element_id("")
    {
        
    }

    SD_WindowEventsQueueListInsertionFailed::SD_WindowEventsQueueListInsertionFailed(
        const std::string& element_id
    ) : SD_Exception("SD_WindowEventsQueueListInsertionFailed", DefaultExceptionDescription()), 
        element_id(element_id)
    {

    }
    SD_WindowEventsQueueListInsertionFailed::SD_WindowEventsQueueListInsertionFailed(
        const std::string& exception_name,
        const std::string& exception_desc
    ) : SD_Exception(exception_name, exception_desc)
    {

    }
    std::string SD_WindowEventsQueueListInsertionFailed::DefaultExceptionDescription() const {
        return std::string("Unable to insert window events queue list");
    }
    ////////////////////////////////////////
    SD_WindowEventsQueueListErasionFailed::SD_WindowEventsQueueListErasionFailed()
     : SD_Exception("SD_WindowEventsQueueListErasionFailed", DefaultExceptionDescription()),
       element_id("")
    {

    }

    SD_WindowEventsQueueListErasionFailed::SD_WindowEventsQueueListErasionFailed(
        const std::string& element_id
    ) : SD_Exception("SD_WindowEventsQueueListErasionFailed", DefaultExceptionDescription()),
        element_id(element_id)
    {
        
    }
    SD_WindowEventsQueueListErasionFailed::SD_WindowEventsQueueListErasionFailed(
        const std::string& exception_name,
        const std::string& exception_desc
    ) : SD_Exception(exception_name, exception_desc)
    {

    }
    std::string SD_WindowEventsQueueListErasionFailed::DefaultExceptionDescription() const {
        return std::string("Unable to erase window events queue list");
    }
    ////////////////////////////////////////
    SD_WindowEventsQueueListNotFound::SD_WindowEventsQueueListNotFound()
     : SD_Exception(
         "SD_WindowEventsQueueListNotFound",
         DefaultExceptionDescription()
     ) , element_id("")
    {
        
    }

    SD_WindowEventsQueueListNotFound::SD_WindowEventsQueueListNotFound
    (
        const std::string& element_id
    ) : SD_Exception("SD_WindowEventsQueueListNotFound", DefaultExceptionDescription()),
        element_id(element_id)
    {
        
    }
    SD_WindowEventsQueueListNotFound::SD_WindowEventsQueueListNotFound(
        const std::string& exception_name,
        const std::string& exception_desc
    ) : SD_Exception(exception_name, exception_desc)
    {

    }
    std::string SD_WindowEventsQueueListNotFound::DefaultExceptionDescription() const {
        return std::string("Unable to find window events queue list");
    }
    ////////////////////////////////////////
    SD_WindowAccesserRenderWindowInsertionFailed::SD_WindowAccesserRenderWindowInsertionFailed()
     : SD_Exception(
         "SD_WindowAccesserRenderWindowInsertionFailed",
         DefaultExceptionDescription()
     ) , element_id("")
    {
        
    }
    
    SD_WindowAccesserRenderWindowInsertionFailed::SD_WindowAccesserRenderWindowInsertionFailed(
        const std::string& element_id
    ) : SD_Exception("SD_WindowAccesserRenderWindowInsertionFailed", DefaultExceptionDescription()),
        element_id(element_id)
    {
        
    }

    SD_WindowAccesserRenderWindowInsertionFailed::SD_WindowAccesserRenderWindowInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    ) : SD_Exception(exc_name, exc_desc), element_id(element_id)
    {

    }
    std::string SD_WindowAccesserRenderWindowInsertionFailed::DefaultExceptionDescription() const {
        return std::string("Unable to add window to necessary places using SD_WindowAccesser");
    }
    ////////////////////////////////////////
    SD_WindowAccesserRenderWindowNotFound::SD_WindowAccesserRenderWindowNotFound()
     : SD_Exception("SD_WindowAccesserRenderWindowNotFound", DefaultExceptionDescription()),
        element_id("")
    {

    }
    
    SD_WindowAccesserRenderWindowNotFound::SD_WindowAccesserRenderWindowNotFound(
        const std::string& element_id
    ) : SD_Exception("SD_WindowAccesserRenderWindowNotFound", DefaultExceptionDescription()),
        element_id(element_id)
    {

    }
    SD_WindowAccesserRenderWindowNotFound::SD_WindowAccesserRenderWindowNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    ) : SD_Exception(exc_name, exc_desc), element_id(element_id)
    {

    }
    std::string SD_WindowAccesserRenderWindowNotFound::DefaultExceptionDescription() const {
        return std::string("Unable to find window complete data using SD_WindowAccesser");
    }
    ////////////////////////////////////////
    SD_WindowAccesserRenderWindowErasionFailed::SD_WindowAccesserRenderWindowErasionFailed()
     : SD_Exception("SD_WindowAccesserRenderWindowErasionFailed", DefaultExceptionDescription()),
     element_id("")
    {
        
    }

    SD_WindowAccesserRenderWindowErasionFailed::SD_WindowAccesserRenderWindowErasionFailed(
        const std::string& element_id
    ) : SD_Exception("SD_WindowAccesserRenderWindowErasionFailed", DefaultExceptionDescription()),
        element_id(element_id)
    {

    }
    SD_WindowAccesserRenderWindowErasionFailed::SD_WindowAccesserRenderWindowErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    ) : SD_Exception(exc_name,exc_desc),
        element_id(element_id)
    {
        
    }
    std::string SD_WindowAccesserRenderWindowErasionFailed::DefaultExceptionDescription() const {
        return std::string("Unable to erase window complete data using SD_WindowAccesser");
    }
    ////////////////////////////////////////
    SD_EventsOfTypeNotFound::SD_EventsOfTypeNotFound()
     : SD_Exception("SD_EventsOfTypeNotFound", DefaultExceptionDescription())
    {

    }
     SD_EventsOfTypeNotFound::SD_EventsOfTypeNotFound(
         const std::string& exc_name,
         const std::string& exc_desc
    ) : SD_Exception(exc_name, exc_desc)
    {

    }
    std::string SD_EventsOfTypeNotFound::DefaultExceptionDescription() const {
        return std::string("Unable to find event list of that sf::Event::EventType");
    }
    ////////////////////////////////////////
}
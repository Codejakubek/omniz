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
// File: /impl/include/SigmaDev/Exception/WindowsExceptions.h
// Description:
// Additional Notes:

#ifndef SD_EXCEPTION_WINDOWS_EXCEPTIONS_H
#define SD_EXCEPTION_WINDOWS_EXCEPTIONS_H

#include <SigmaDev/Exception/Exception.h>

namespace exc 
{
////////////////////////////////////////
class SD_WindowEventsQueueListInsertionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowEventsQueueListInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     * 
     * @param element_id ID of the SD_WindowEvents (usually window id)
     */
    SD_WindowEventsQueueListInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     */
    SD_WindowEventsQueueListInsertionFailed(const std::string& exception_name, const std::string& exception_desc);
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

    std::string element_id;
};
////////////////////////////////////////   
class SD_WindowEventsQueueListErasionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowEventsQueueListErasionFailed();
    /**
     * @brief Uses default exception name and description
     *        Sets the element_id
     * 
     * @param element_id ID of the SD_WindowEvents (usually window id)
     */
    SD_WindowEventsQueueListErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        element_id is not set.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     */
    SD_WindowEventsQueueListErasionFailed(const std::string& exception_name, const std::string& exception_desc);
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

    std::string element_id;
};
////////////////////////////////////////
class SD_WindowEventsQueueListNotFound : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowEventsQueueListNotFound();
    /**
     * @brief Uses default exception name and description
     *        Sets the element_id.
     * 
     * @param element_id Id of the SD_WindowEvents (usually window id)
     */
    SD_WindowEventsQueueListNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        element_id is not set.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     */
    SD_WindowEventsQueueListNotFound(const std::string& exception_name, const std::string& exception_desc);
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
    
    std::string element_id;
};

////////////////////////////////////////
class SD_WindowAccesserRenderWindowInsertionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowAccesserRenderWindowInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     * 
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

    std::string element_id;
};
////////////////////////////////////////
class SD_WindowAccesserRenderWindowNotFound : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowAccesserRenderWindowNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     * 
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

    std::string element_id;
};
////////////////////////////////////////
class SD_WindowAccesserRenderWindowErasionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     */
    SD_WindowAccesserRenderWindowErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     * 
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id sf::RenderWindow ID
     */
    SD_WindowAccesserRenderWindowErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

    std::string element_id;
};
////////////////////////////////////////
class SD_EventsOfTypeNotFound : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description
     */
    SD_EventsOfTypeNotFound();
    /**
     * @brief Specifies the exception name and description
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     */
    SD_EventsOfTypeNotFound(
        const std::string& exc_name,
        const std::string& exc_desc
    );
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;

};
////////////////////////////////////////
}

#endif

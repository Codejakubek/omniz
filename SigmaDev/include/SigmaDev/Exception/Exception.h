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
// File: /impl/include/SigmaDev/Exception/Exception.h
// Description:
//      Exception.h is contain the base declarations related to broadly-thought exceptions,
//      All exceptions are under exc:: namespace. Base class for the exception is SD_Exception,
//      Every SigmaDev exception (concrete or not) must inherit from SD_Exception.
//      SD_Exception is also inheriting from std::exception.
//            
//      SigmaDev exception handling is using the std::nested_exception mechanisms.
//      I've (Codedemens) decided that nested_exceptions will help exception handling
//      As I prefer nested_exceptions over wrapping & interpreting them in general ways.
//             
//      There are also additional declarations related to exception handling, such as
//      SD_PrintNestedException method which elegantly allows printing nested exceptions.
//
// Additional Notes:
//      (Codedemens, July 26, 2020) Currently this file is under heavy construction 
////////////////////////////////////////

#ifndef SD_EXCEPTION_H
#define SD_EXCEPTION_H

#include <string.h>
#include <memory>
#include <exception>
#include <iostream>
#include <map>

/** TODO: Better_Way_To_Handle_Exceptions */

namespace exc 
{
////////////////////////////////////////

class SD_Exception : public std::exception {
public:
    SD_Exception() = delete;
    SD_Exception(const std::string& exception_name, const std::string& detailed_description);
    virtual ~SD_Exception() = default;

    virtual std::string DefaultExceptionDescription() const = 0;
    //virtual std::string DefaultExceptionName() const = 0;
    inline void OverrideName(const std::string& exception_name) {
        this->exception_name = exception_name;
    }
    inline void OverrideDetailedDescription(const std::string& detailed_description) {
        this->detailed_description = detailed_description;
    }
    inline const std::string& GetName() const {
        return exception_name;
    }
    inline const std::string& GetDetailedDescription() const {
        return detailed_description;
    }
    inline const std::map<std::string, std::string>& GetVariablesMap() const {
        return variables_map;
    }
    inline std::map<std::string, std::string>& GetVariablesMap() {
        return variables_map;
    }
protected:
    std::string exception_name; ///< Should be the same as final exception concretization name
    std::string detailed_description; ///< Should be specified in the final exception concretization class constructor
    std::map<std::string, std::string> variables_map; ///< This map contains converted to string additional variables. These variables usually should be also available in concretization.  
};
////////////////////////////////////////
class SD_APIFailed : public SD_Exception {
public:
    /**
     * @brief Default constructor that automaticly inits the 
     *        exception name and default description
     *        (defined in \link exc::SD_APIFailed::DefaultExceptionDescription() \endlink)
     */
    SD_APIFailed();
    /**
     * @brief Specify the name and description
     * 
     * @param name Exception Name
     * @param detailed_description Exception Detailed Description 
     */
    SD_APIFailed(const std::string& name, const std::string& detailed_description);
    /**
     * @brief Specify the description. Name stays the same. 
     * 
     * @param detailed_description Exception Detailed Description
     */
    SD_APIFailed(const std::string& detailed_description);
    virtual ~SD_APIFailed() = default;

    /**
     * @brief Override the default description
     * 
     * @return std::string Returns description
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
class SD_UninitializedException : public SD_Exception {
public:
    /**
     * @brief Default constructor that automaticly inits the 
     *        exception name and default description
     *        (defined in \link exc::SD_UninitializedException::DefaultExceptionDescription() \endlink)
     */
    SD_UninitializedException();
    /**
     * @brief Specify the name and description
     * 
     * @param name Exception Name
     * @param detailed_description Exception Detailed Description 
     */
    SD_UninitializedException(const std::string& name, const std::string& detailed_description);
    /**
     * @brief Specify the description. Name stays the same. 
     * 
     * @param detailed_description Exception Detailed Description
     */
    SD_UninitializedException(const std::string& detailed_description);
    virtual ~SD_UninitializedException() = default;

    /**
     * @brief Override the default description
     * 
     * @return std::string Returns description
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

class SD_NullPtrException : public SD_Exception {
public:
    /**
     * @brief Default constructor that automaticly inits the
     *        exception name and default description
     *        (defined in \link exc::SD_NullPtrException::DefaultExceptionDescription() \endlink)
     * 
     */
    SD_NullPtrException();
    /**
     * @brief Specify the name and description
     * 
     * @param name Exception Name
     * @param detailed_description Exception Detailed Description 
     */
    SD_NullPtrException(const std::string& name, const std::string& detailed_description);
    /**
     * @brief Specify the description. Name stays the same.
     * 
     * @param detailed_description Exception Detailed Description
     */
    SD_NullPtrException(const std::string& detailed_description);
    virtual ~SD_NullPtrException() = default;

    /**
     * @brief Override the default description
     * 
     * @return std::string Returns description
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

class SD_InitializationFailed : public SD_Exception {
public:

    /**
     * @brief Default constructor that automaticly inits the
     *        exception name and default description
     *        (defined in \link exc::SD_InitializationFailed::DefaultExceptionDescription() \endlink)
     * 
     */
    SD_InitializationFailed();
    /**
     * @brief Specify the name and description
     * 
     * @param name Exception Name
     * @param detailed_description Exception Detailed Description 
     */
    SD_InitializationFailed(const std::string& name, const std::string& detailed_description);
    /**
     * @brief Specify the description. Name stays the same.
     * 
     * @param detailed_description Exception Detailed Description
     */
    SD_InitializationFailed(const std::string& detailed_description);
    virtual ~SD_InitializationFailed() = default;

    /**
     * @brief Override the default description
     * 
     * @return std::string Returns description
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
class SD_ResourceInsertionFailed : public SD_Exception {
public:
    /**
     *  @brief Disallow default constructor. Reason: 
     *         This class is not a concrete representation 
     *         of exception class (it's abstract)
     */
    SD_ResourceInsertionFailed() = delete;

    /**
     * @brief Specifies exception name, description, and resource element id,
     *        But does not pass the resource type.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     */
    SD_ResourceInsertionFailed(
        const std::string& exception_name, 
        const std::string& exception_desc, 
        const std::string& element_id);
    
    /**
     * @brief Specifies exception name, description, resource element id,
     *        and resource element type
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     * @param resource_type Resource Type
     */
    SD_ResourceInsertionFailed(
        const std::string& exception_name, 
        const std::string& exception_desc, 
        const std::string& element_id, 
        const std::string& resource_type);

    virtual ~SD_ResourceInsertionFailed() = default;

    //Do not specify default description, do that in concrete exception classes
    //virtual std::string DefaultExceptionDescription() const override;


    inline void SetElementId(const std::string& element_id) {
        this->element_id = element_id;
    }
    inline const std::string& GetElementId() const {
        return this->element_id;
    }
    inline void SetResourceType(const std::string& resource_type) {
        this->resource_type = resource_type;
    }
    inline const std::string& GetResourceType() const {
        return this->resource_type;
    }
protected:
    std::string element_id;
    std::string resource_type;
};
////////////////////////////////////////
class SD_ResourceNotFound : public SD_Exception {
public:
    /**
     *  @brief Disallow default constructor. Reason: 
     *         This class is not a concrete representation 
     *         of exception class (it's abstract)
     */
    SD_ResourceNotFound() = delete;

    /**
     * @brief Specifies exception name, description, and resource element id,
     *        But does not pass the resource type.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     */
    SD_ResourceNotFound(
        const std::string& exception_name,
        const std::string& exception_desc, 
        const std::string& element_id);

    /**
     * @brief Specifies exception name, description, resource element id,
     *        and resource element type
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     * @param resource_type Resource Type
     */
    SD_ResourceNotFound(
        const std::string& exception_name, 
        const std::string& exception_desc, 
        const std::string& element_id, 
        const std::string& resource_type);

    virtual ~SD_ResourceNotFound() = default;

    //Do not specify default description, do that in concrete exception classes
    //virtual std::string DefaultExceptionDescription() const override;

    inline void SetElementId(const std::string& element_id) {
        this->element_id = element_id;
    }
    inline const std::string& GetElementId() const {
        return this->element_id;
    }
    inline void SetResourceType(const std::string& resource_type) {
        this->resource_type = resource_type;
    }
    inline const std::string& GetResourceType() const {
        return this->resource_type;
    }
protected:
    std::string element_id; ///<Resource Element ID
    std::string resource_type; ///<Resource Element Data Type
};
////////////////////////////////////////
class SD_ResourceErasionFailed : public SD_Exception {
public:
    /**
     *  @brief Disallow default constructor. Reason: 
     *         This class is not a concrete representation 
     *         of exception class (it's abstract)
     */
    SD_ResourceErasionFailed() = delete;
    
    /**
     * @brief Specifies exception name, description, and resource element id,
     *        But does not pass the resource type.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     */
    SD_ResourceErasionFailed(
        const std::string& exception_name, 
        const std::string& detailed_description, 
        const std::string& element_id
    );
    
    /**
     * @brief Specifies exception name, description, resource element id,
     *        and resource element type
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     * @param resource_type Resource Type
     */
    SD_ResourceErasionFailed(
        const std::string& exception_name, 
        const std::string& detailed_description, 
        const std::string& element_id, 
        const std::string& resource_type
    );

    //Do not specify default description, do that in concrete exception classes
    //virtual std::string DefaultExceptionDescription() const override;

    inline void SetElementId(const std::string& element_id) {
        this->element_id = element_id;
    }
    inline const std::string& GetElementId() const {
        return this->element_id;
    }
    inline void SetResourceType(const std::string& resource_type) {
        this->resource_type = resource_type;
    }
    inline const std::string& GetResourceType() const {
        return this->resource_type;
    }
protected:
    std::string element_id; ///< Resource Element ID
    std::string resource_type; ///< Resource Element Data Type
};
////////////////////////////////////////
class SD_ResourceSaveFailed : public SD_Exception {
public:
    /**
     *  @brief Disallow default constructor. Reason: 
     *         This class is not a concrete representation 
     *         of exception class (it's abstract)
     */
    SD_ResourceSaveFailed() = delete;

    /**
     * @brief Specifies exception name, description, and resource element id,
     *        But does not pass the resource type.
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     */
    SD_ResourceSaveFailed(
        const std::string& exception_name,
        const std::string& detailed_description,
        const std::string& element_id
    );

    /**
     * @brief Specifies exception name, description, resource element id,
     *        and resource element type
     * 
     * @param exception_name Exception Name
     * @param exception_desc Exception Description
     * @param element_id Resource Id
     * @param resource_type Resource Type
     */
    SD_ResourceSaveFailed(
        const std::string& exception_name,
        const std::string& detailed_description,
        const std::string& element_id,
        const std::string& resource_type
    );

    //Do not specify default description, do that in concrete exception classes
    //virtual std::string DefaultExceptionDescription() const override;

    inline void SetElementId(const std::string& element_id) {
        this->element_id = element_id;
    }
    inline const std::string& GetElementId() const {
        return this->element_id;
    }
    inline void SetResourceType(const std::string& resource_type) {
        this->resource_type = resource_type;
    }
    inline const std::string& GetResourceType() const {
        return this->resource_type;
    }
protected:
    std::string element_id; ///< Resource Element ID
    std::string resource_type; ///< Resource Element Data Type
};
////////////////////////////////////////
} //namespace exc

/**
 * @brief Prints std::nested_exception (or std::exception) every layer.
 * 
 * @param e Exception Reference (Exception Layer Reference)
 * @param l (Layer Level - used for recursive calls implementation, leave default 0)
 * 
 * @ingroup exception_module
 */
void SD_PrintNestedException(const std::exception& e, int l = 0);

#endif


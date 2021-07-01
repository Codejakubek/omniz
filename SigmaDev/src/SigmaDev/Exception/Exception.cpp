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
// File: /impl/src/SigmaDev/Exception/Exception.cpp
// Description:
//      Exception.cpp contain definitions for all declarations of Exception.h
//
// Additional Notes:
//      (Codedemens, July 26, 2020) Currently this file is under heavy construction 
////////////////////////////////////////

#include <SigmaDev/Exception/Exception.h>

namespace exc
{
SD_Exception::SD_Exception(
    const std::string& exception_name, 
    const std::string& detailed_description
)
:   exception_name(exception_name), 
    detailed_description(detailed_description) 
{

}

////////////////////////////////////////

SD_APIFailed::SD_APIFailed() 
: SD_Exception("SD_APIFailed", DefaultExceptionDescription())
{

}

SD_APIFailed::SD_APIFailed(
    const std::string& exception_name,
    const std::string& detailed_description
) : SD_Exception(
    exception_name, detailed_description
) 
{

}

SD_APIFailed::SD_APIFailed(
    const std::string& detailed_description
) : SD_Exception("SD_APIFailed", detailed_description)
{

}

std::string SD_APIFailed::DefaultExceptionDescription() const {
    return std::string("API execution failed");
}

////////////////////////////////////////

SD_UninitializedException::SD_UninitializedException()
: SD_Exception("SD_UninitializedException", DefaultExceptionDescription())
{

}
SD_UninitializedException::SD_UninitializedException(
    const std::string& exception_name,
    const std::string& detailed_description
) : SD_Exception(
    exception_name, detailed_description
)
{

}

SD_UninitializedException::SD_UninitializedException(
    const std::string& detailed_description
) : SD_Exception("SD_UninitializedException", detailed_description) 
{

}

std::string SD_UninitializedException::DefaultExceptionDescription() const {
    return std::string("Somewhere in the code we detected that memory is not initialized, which shouldn't happen in this context");
}

////////////////////////////////////////

SD_NullPtrException::SD_NullPtrException()
: SD_Exception(
    "SD_NullPtrException", 
    DefaultExceptionDescription()
)
{
    
}

SD_NullPtrException::SD_NullPtrException(
    const std::string& exception_name, 
    const std::string& detailed_description
)
: SD_Exception(
    exception_name,
    detailed_description
)
{
    
}
SD_NullPtrException::SD_NullPtrException(
    const std::string& detailed_description
)
: SD_Exception(
    "SD_NullPtrException", 
    detailed_description
) 
{

}
std::string SD_NullPtrException::DefaultExceptionDescription() const {
    return std::string("Somewhere in the code we detected object null pointer, which shouldn't be null ptr in this context");
}

////////////////////////////////////////

SD_InitializationFailed::SD_InitializationFailed()
 : SD_Exception("SD_InitializationFailed", DefaultExceptionDescription())
 {

 }
SD_InitializationFailed::SD_InitializationFailed(
    const std::string& name, 
    const std::string& detailed_description
) : SD_Exception(name, detailed_description)
{

}
SD_InitializationFailed::SD_InitializationFailed(
    const std::string& detailed_description
) : SD_Exception("SD_InitializationFailed", detailed_description)
{

}
std::string SD_InitializationFailed::DefaultExceptionDescription() const {
    return std::string("Unable to initialize object");
}

////////////////////////////////////////
SD_ResourceInsertionFailed::SD_ResourceInsertionFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id
) : SD_Exception(exception_name, detailed_description) , element_id(element_id) {}

SD_ResourceInsertionFailed::SD_ResourceInsertionFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id,
    const std::string& resource_type
) : SD_Exception(exception_name, detailed_description) , element_id(element_id), resource_type(resource_type) {}
////////////////////////////////////////
SD_ResourceNotFound::SD_ResourceNotFound(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id
) : SD_Exception(exception_name, detailed_description) , element_id(element_id) {}
SD_ResourceNotFound::SD_ResourceNotFound(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id,
    const std::string& resource_type
) : SD_Exception(exception_name, detailed_description) , element_id(element_id), resource_type(resource_type) {}
////////////////////////////////////////
SD_ResourceErasionFailed::SD_ResourceErasionFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id
) : SD_Exception(exception_name, detailed_description) , element_id(element_id) {}
SD_ResourceErasionFailed::SD_ResourceErasionFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id,
    const std::string& resource_type
) : SD_Exception(exception_name, detailed_description), element_id(element_id), resource_type(resource_type) {}
////////////////////////////////////////
SD_ResourceSaveFailed::SD_ResourceSaveFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id
) : SD_Exception(exception_name, detailed_description) , element_id(element_id) {}
SD_ResourceSaveFailed::SD_ResourceSaveFailed(
    const std::string& exception_name,
    const std::string& detailed_description,
    const std::string& element_id,
    const std::string& resource_type
) : SD_Exception(exception_name, detailed_description), element_id(element_id), resource_type(resource_type) {}
////////////////////////////////////////

} //namespace exc
void SD_PrintNestedException(const std::exception& e, int l) {
    
    const std::exception* e_ptr = &e;
    const exc::SD_Exception* e2_ptr = dynamic_cast<const exc::SD_Exception*>(e_ptr);

    if (l == 0) {
        std::cerr << "Caught SigmaDev Library Exception ! " << std::endl;
    }

    if (e2_ptr != nullptr) {
        std::cerr << "NO. |" << l << "|    " << std::string(l, ' ') << "[" <<  e2_ptr->GetName() << "]" << std::endl;
        std::cerr << "NO. |" << l << "|    " << std::string(l+4, ' ') << "(" << e2_ptr->GetDetailedDescription() << ")" << std::endl; 
    } else {
        std::cerr << "NO. |" << l << "|    " << std::string(l, ' ') << "[" << e.what() << "]" << std::endl;
    }

    try {
        std::rethrow_if_nested(e);
    } catch (const std::exception& e) {
        SD_PrintNestedException(e, l+1);
    }
}
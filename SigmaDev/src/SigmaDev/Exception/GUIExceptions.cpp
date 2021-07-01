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
// File: /impl/src/SigmaDev/Exception/GUIExceptions.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Exception/GUIExceptions.h>

namespace exc 
{
////////////////////////////////////////
SD_GUIObjectChildInsertionFailed::SD_GUIObjectChildInsertionFailed() 
    : SD_Exception("SD_GUIObjectChildInsertionFailed", DefaultExceptionDescription())
{

}
SD_GUIObjectChildInsertionFailed::SD_GUIObjectChildInsertionFailed(
    const std::string& id_or_path
)
    :SD_Exception("SD_GUIObjectChildInsertionFailed", DefaultExceptionDescription()),
        id_or_path(id_or_path)
{
    
}
SD_GUIObjectChildInsertionFailed::SD_GUIObjectChildInsertionFailed(
    const std::string& id_or_path,
    const std::string& exc_name,
    const std::string& exc_desc
)
    : SD_Exception(exc_name, exc_desc),
    id_or_path(id_or_path)
{

}
std::string SD_GUIObjectChildInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert SD_GUIObject in SD_GUIObjectChildren");
}
////////////////////////////////////////
SD_GUIObjectChildErasionFailed::SD_GUIObjectChildErasionFailed() 
    : SD_Exception("SD_GUIObjectChildErasionFailed", DefaultExceptionDescription())
{

}
SD_GUIObjectChildErasionFailed::SD_GUIObjectChildErasionFailed(
    const std::string& id_or_path
)   
    :SD_Exception("SD_GUIObjectChildErasionFailed", DefaultExceptionDescription()),
     id_or_path(id_or_path)
{

}
SD_GUIObjectChildErasionFailed::SD_GUIObjectChildErasionFailed(
    const std::string& id_or_path,
    const std::string& exc_name,
    const std::string& exc_desc
)
    : SD_Exception(exc_name, exc_desc),
    id_or_path(id_or_path)
{

}
std::string SD_GUIObjectChildErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase SD_GUIObject in SD_GUIObjetChildren");
}
////////////////////////////////////////
SD_GUIObjectChildNotFound::SD_GUIObjectChildNotFound() 
    : SD_Exception("SD_GUIObjectChildNotFound", DefaultExceptionDescription())
{

}
SD_GUIObjectChildNotFound::SD_GUIObjectChildNotFound(
    const std::string& id_or_path
)
    : SD_Exception("SD_GUIObjectChildNotFound", DefaultExceptionDescription()),
    id_or_path(id_or_path)
{

}
SD_GUIObjectChildNotFound::SD_GUIObjectChildNotFound(
    const std::string& id_or_path,
    const std::string& exc_name,
    const std::string& exc_desc
)
    : SD_Exception(exc_name, exc_desc),
    id_or_path(id_or_path)
{

}
std::string SD_GUIObjectChildNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find SD_GUIObject in SD_GUIObjectChildren");
}
////////////////////////////////////////
SD_GUIAccessFailed::SD_GUIAccessFailed()
: SD_Exception("SD_GUIAccessFailed", DefaultExceptionDescription())
{

}

SD_GUIAccessFailed::SD_GUIAccessFailed(const std::string& exc_desc) 
: SD_Exception("SD_GUIAccessFailed", exc_desc)
{

}

SD_GUIAccessFailed::SD_GUIAccessFailed(
    const std::string& exc_name,
    const std::string& exc_desc
) : SD_Exception(exc_name, exc_desc) 
{

}
std::string SD_GUIAccessFailed::DefaultExceptionDescription() const {
    return std::string("Access in SD_GUIAccesser failed");
}
////////////////////////////////////////
SD_GUIObjectSpecializationPackageInsertionFailed::SD_GUIObjectSpecializationPackageInsertionFailed()
 : SD_Exception("SD_GUIObjectSpecializationPackageInsertionFailed", DefaultExceptionDescription())
{

}
SD_GUIObjectSpecializationPackageInsertionFailed::SD_GUIObjectSpecializationPackageInsertionFailed(
    const std::string& package_id
) : SD_Exception("SD_GUIObjectSpecializationPackageInsertionFailed", DefaultExceptionDescription()),
    package_id(package_id)
{

}
SD_GUIObjectSpecializationPackageInsertionFailed::SD_GUIObjectSpecializationPackageInsertionFailed(
    const std::string& package_id,
    const std::string& exc_name,
    const std::string& exc_desc
) : SD_Exception(exc_name, exc_desc),package_id(package_id)
{

}
std::string SD_GUIObjectSpecializationPackageInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert SD_GUIObjectSpecializationPackage");
}
////////////////////////////////////////
SD_GUIObjectSpecializationPackageErasionFailed::SD_GUIObjectSpecializationPackageErasionFailed()
 : SD_Exception("SD_GUIObjectSpecializationPackageErasionFailed", DefaultExceptionDescription())
 {

 }
SD_GUIObjectSpecializationPackageErasionFailed::SD_GUIObjectSpecializationPackageErasionFailed(
    const std::string& package_id
) : SD_Exception("SD_GUIObjectSpecializationPackageErasionFailed", DefaultExceptionDescription()),
    package_id(package_id)
{

}
SD_GUIObjectSpecializationPackageErasionFailed::SD_GUIObjectSpecializationPackageErasionFailed(
    const std::string& package_id,
    const std::string& exc_name,
    const std::string& exc_desc
) : SD_Exception(exc_name, exc_desc), package_id(package_id)
{

}
std::string SD_GUIObjectSpecializationPackageErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase SD_GUIObjectSpecializationPackage");
}
////////////////////////////////////////
SD_GUIObjectSpecializationPackageNotFound::SD_GUIObjectSpecializationPackageNotFound()
 : SD_Exception("SD_GUIObjectSpecializationPackageNotFound", DefaultExceptionDescription())
{

}
SD_GUIObjectSpecializationPackageNotFound::SD_GUIObjectSpecializationPackageNotFound(
    const std::string& package_id
) : SD_Exception("SD_GUIObjectSpecializationPackageNotFound", DefaultExceptionDescription()),
    package_id(package_id)
{

}
SD_GUIObjectSpecializationPackageNotFound::SD_GUIObjectSpecializationPackageNotFound(
    const std::string& package_id,
    const std::string& exc_name,
    const std::string& exc_desc
) : SD_Exception(exc_name, exc_desc),
    package_id(package_id)
{

}
std::string SD_GUIObjectSpecializationPackageNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to fin SD_GUIObjectSpecializationPackage");
}
////////////////////////////////////////
SD_GUIObjectTypeIsNotSpecialized::SD_GUIObjectTypeIsNotSpecialized()
 : SD_Exception(
     "SD_GUIObjectTypeIsNotSpecialized", DefaultExceptionDescription()
 )
{

}
SD_GUIObjectTypeIsNotSpecialized::SD_GUIObjectTypeIsNotSpecialized(
    const std::string& main_type
) : SD_Exception("SD_GUIObjectTypeIsNotSpecialized", DefaultExceptionDescription()),
    main_type(main_type)
{

}
SD_GUIObjectTypeIsNotSpecialized::SD_GUIObjectTypeIsNotSpecialized(
    const std::string& main_type,
    const std::string& exc_name,
    const std::string& exc_desc
) : SD_Exception(exc_name, exc_desc),
    main_type(main_type)
{

}
std::string SD_GUIObjectTypeIsNotSpecialized::DefaultExceptionDescription() const {
    return std::string ("SD_GUIObjectType::specialized_type is not initialized at the attempt of access");
}
////////////////////////////////////////


SD_GUIObjectInitializationFailed::SD_GUIObjectInitializationFailed(
            const std::string& gui_object_id,
            const std::string& gui_object_type,
            const std::string& exc_description
) : SD_Exception(
    "SD_GUIObjectInitializationFailed",
    exc_description
), gui_object_id(gui_object_id), gui_object_type(gui_object_type) 
{

}
std::string SD_GUIObjectInitializationFailed::DefaultExceptionDescription() const {
    return std::string ("SD_GUIObjectInitialization failed");
}
////////////////////////////////////////
SD_GUIObjectReleaseFailed::SD_GUIObjectReleaseFailed(
    const std::string& gui_object_id,
    const std::string& gui_object_type,
    const std::string& exc_description
) : SD_Exception(
    "SD_GUIObjectReleaseFailed",
    exc_description
) , gui_object_id(gui_object_id), gui_object_type(gui_object_type)
{

}
std::string SD_GUIObjectReleaseFailed::DefaultExceptionDescription() const {
    return std::string ("SD_GUIObjectRelease failed");
}
////////////////////////////////////////
SD_GUIObjectJsonLoadFailed::SD_GUIObjectJsonLoadFailed(
    const std::string& gui_object_type,
    const std::string& exc_desc
) : SD_Exception("SD_GUIObjectJsonLoadFailed", exc_desc),
gui_object_type(gui_object_type) {

}

std::string SD_GUIObjectJsonLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_GUIObjectInitialization::LoadFromJson failed");
}
////////////////////////////////////////
}
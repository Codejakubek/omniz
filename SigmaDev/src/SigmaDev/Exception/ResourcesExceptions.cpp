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
// File: /impl/src/SigmaDev/Exception/ResourcesExceptions.cpp
// Description:
//      ResourcesExceptions.cpp contain the definitions of the concrete exceptions
//      thrown mostly in the resources containers (declared in /impl/include/SigmaDev/Resources.h)
//      
// Additional Notes:
//      (Codedemens, July 26, 2020) These exceptions haven't been tested out ... yet. 
//      I'm working on unit test handling now.
////////////////////////////////////////

#include <SigmaDev/Exception/ResourcesExceptions.h>

namespace exc 
{
////////////////////////////////////////
//
// Exceptions for the resource type: sf::BlendMode
//
////////////////////////////////////////
//
// SD_BlendModeResourceInsertionFailed 
//
SD_BlendModeResourceInsertionFailed::SD_BlendModeResourceInsertionFailed()
    : SD_ResourceInsertionFailed(
        "SD_BlendModeResourceInsertionFailed",
        DefaultExceptionDescription(),
        "",
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceInsertionFailed::SD_BlendModeResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_BlendModeResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::BlendMode"
    )
{
    
}
SD_BlendModeResourceInsertionFailed::SD_BlendModeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceInsertionFailed::SD_BlendModeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_BlendModeResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::BlendMode in SD_Resources");
}
////////////////////////////////////////
//
// SD_BlendModeResourceNotFound
//
SD_BlendModeResourceNotFound::SD_BlendModeResourceNotFound()
 : SD_ResourceNotFound(
     "SD_BlendModeResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::BlendMode"
 )
{
    
}
SD_BlendModeResourceNotFound::SD_BlendModeResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_BlendModeResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceNotFound::SD_BlendModeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceNotFound::SD_BlendModeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_BlendModeResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::BlendMode in SD_Resources");
}
////////////////////////////////////////
//
// SD_BlendModeResourceErasionFailed
//
SD_BlendModeResourceErasionFailed::SD_BlendModeResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_BlendModeResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::BlendMode"
 )
{

}
SD_BlendModeResourceErasionFailed::SD_BlendModeResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_BlendModeResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceErasionFailed::SD_BlendModeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::BlendMode"
    )
{

}
SD_BlendModeResourceErasionFailed::SD_BlendModeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_BlendModeResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::BlendMode in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::CircleShape
//
////////////////////////////////////////
//
// SD_CircleShapeResourceInsertionFailed 
//
SD_CircleShapeResourceInsertionFailed::SD_CircleShapeResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_CircleShapeResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::CircleShape"
 )
{

}
SD_CircleShapeResourceInsertionFailed::SD_CircleShapeResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_CircleShapeResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::CircleShape"
    )
{
    
}
SD_CircleShapeResourceInsertionFailed::SD_CircleShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::CircleShape"
    )
{

}
SD_CircleShapeResourceInsertionFailed::SD_CircleShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_CircleShapeResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::CircleShape in SD_Resources");
}
////////////////////////////////////////
//
// SD_CircleShapeResourceNotFound
//
SD_CircleShapeResourceNotFound::SD_CircleShapeResourceNotFound()
 : SD_ResourceNotFound(
     "SD_CircleShapeResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::CircleShape"
 )
{

}
SD_CircleShapeResourceNotFound::SD_CircleShapeResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_CircleShapeResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::CircleShape"
    )
{

}
SD_CircleShapeResourceNotFound::SD_CircleShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::CircleShape"
    )
{

}
SD_CircleShapeResourceNotFound::SD_CircleShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_CircleShapeResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::CircleShape in SD_Resources");
}
////////////////////////////////////////
//
// SD_CircleShapeResourceErasionFailed
//
SD_CircleShapeResourceErasionFailed::SD_CircleShapeResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_CircleShapeResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::CircleShape"
 )
{

}
SD_CircleShapeResourceErasionFailed::SD_CircleShapeResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_CircleShapeResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::CircleShape"
    )
{

}
SD_CircleShapeResourceErasionFailed::SD_CircleShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::CircleShape"
    )
{

}
SD_CircleShapeResourceErasionFailed::SD_CircleShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_CircleShapeResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::CircleShape in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Color
//
////////////////////////////////////////
//
// SD_ColorResourceInsertionFailed 
//
SD_ColorResourceInsertionFailed::SD_ColorResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_ColorResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Color"
)
{

}
SD_ColorResourceInsertionFailed::SD_ColorResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_ColorResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Color"
    )
{
    
}
SD_ColorResourceInsertionFailed::SD_ColorResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Color"
    )
{

}
SD_ColorResourceInsertionFailed::SD_ColorResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ColorResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Color in SD_Resources");
}
////////////////////////////////////////
//
// SD_ColorResourceNotFound
//
SD_ColorResourceNotFound::SD_ColorResourceNotFound()
: SD_ResourceNotFound(
    "SD_ColorResourceNotFound",
    DefaultExceptionDescription(),
    "",
    "sf::Color"
)
{

}
SD_ColorResourceNotFound::SD_ColorResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_ColorResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Color"
    )
{

}
SD_ColorResourceNotFound::SD_ColorResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Color"
    )
{

}
SD_ColorResourceNotFound::SD_ColorResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ColorResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Color in SD_Resources");
}
////////////////////////////////////////
//
// SD_ColorResourceErasionFailed
//
SD_ColorResourceErasionFailed::SD_ColorResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_ColorResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Color"
 )
{

}
SD_ColorResourceErasionFailed::SD_ColorResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_ColorResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Color"
    )
{

}
SD_ColorResourceErasionFailed::SD_ColorResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Color"
    )
{

}
SD_ColorResourceErasionFailed::SD_ColorResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_ColorResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Color in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::ConvexShape
//
////////////////////////////////////////
//
// SD_ConvexShapeResourceInsertionFailed 
//
SD_ConvexShapeResourceInsertionFailed::SD_ConvexShapeResourceInsertionFailed()
: SD_ResourceInsertionFailed(
    "SD_ConvexShapeResourceInsertionFailed",
    DefaultExceptionDescription(),
    "",
    "sf::ConvexShape"
)
{

}
SD_ConvexShapeResourceInsertionFailed::SD_ConvexShapeResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
    "SD_ConvexShapeResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::ConvexShape"
) {

}
SD_ConvexShapeResourceInsertionFailed::SD_ConvexShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::ConvexShape"
) {

}
SD_ConvexShapeResourceInsertionFailed::SD_ConvexShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
) {

}
std::string SD_ConvexShapeResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert sf::ConvexShape in SD_Resources");
}

////////////////////////////////////////
//
// SD_ConvexShapeResourceNotFound
//
SD_ConvexShapeResourceNotFound::SD_ConvexShapeResourceNotFound()
: SD_ResourceNotFound(
    "SD_ConvexShapeResourceNotFound",
    DefaultExceptionDescription(),
    "",
    "sf::ConvexShape"
)
{

}
SD_ConvexShapeResourceNotFound::SD_ConvexShapeResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_ConvexShapeResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "sf::ConvexShape"
)
{

}
SD_ConvexShapeResourceNotFound::SD_ConvexShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    "sf::ConvexShape"
) {

}

SD_ConvexShapeResourceNotFound::SD_ConvexShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    resource_type
)
{

}

    
std::string SD_ConvexShapeResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::ConvexShape in SD_Resources");
}
////////////////////////////////////////
//
// SD_ConvexShapeResourceErasionFailed
//
SD_ConvexShapeResourceErasionFailed::SD_ConvexShapeResourceErasionFailed()
: SD_ResourceErasionFailed(
    "SD_ConvexShapeResourceErasionFailed",
    DefaultExceptionDescription(),
    "",
    "sf::ConvexShape"
)
{

}
SD_ConvexShapeResourceErasionFailed::SD_ConvexShapeResourceErasionFailed(const std::string& element_id) : SD_ResourceErasionFailed(
    "SD_ConvexShapeResourceErasionFailed",
    DefaultExceptionDescription(),
    element_id,
    "sf::ConvexShape"
) {

}
SD_ConvexShapeResourceErasionFailed::SD_ConvexShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    "sf::ConvexShape" 
) {
    
}
SD_ConvexShapeResourceErasionFailed::SD_ConvexShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    resource_type
)
{

}
std::string SD_ConvexShapeResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase sf::ConvvexShape in SD_Resources");
}

////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Font
//
////////////////////////////////////////
//
// SD_FontResourceInsertionFailed 
//
SD_FontResourceInsertionFailed::SD_FontResourceInsertionFailed(    )
 : SD_ResourceInsertionFailed(
     "SD_FontResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Font"
 )
{

}
SD_FontResourceInsertionFailed::SD_FontResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_FontResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Font"
    )
{
    
}
SD_FontResourceInsertionFailed::SD_FontResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Font"
    )
{

}
SD_FontResourceInsertionFailed::SD_FontResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_FontResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Font in SD_Resources");
}

////////////////////////////////////////
//
// SD_FontResourceNotFound
//
SD_FontResourceNotFound::SD_FontResourceNotFound()
 : SD_ResourceNotFound(
     "SD_FontResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Font"
 )
{

}
SD_FontResourceNotFound::SD_FontResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_FontResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Font"
    )
{

}
SD_FontResourceNotFound::SD_FontResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Font"
    )
{

}
SD_FontResourceNotFound::SD_FontResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_FontResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Font in SD_Resources");
}
////////////////////////////////////////
//
// SD_FontResourceErasionFailed
//
SD_FontResourceErasionFailed::SD_FontResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_FontResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Font"
 )
{

}
SD_FontResourceErasionFailed::SD_FontResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_FontResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Font"
    )
{

}
SD_FontResourceErasionFailed::SD_FontResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Font"
    )
{

}
SD_FontResourceErasionFailed::SD_FontResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_FontResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Font in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Image
//
////////////////////////////////////////
//
// SD_ImageResourceInsertionFailed 
//
SD_ImageResourceInsertionFailed::SD_ImageResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_ImageResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Image"
 )
{
    
}
SD_ImageResourceInsertionFailed::SD_ImageResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_ImageResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Image"
    )
{
    
}
SD_ImageResourceInsertionFailed::SD_ImageResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Image"
    )
{

}
SD_ImageResourceInsertionFailed::SD_ImageResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ImageResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Image in SD_Resources");
}
////////////////////////////////////////
//
// SD_ImageResourceNotFound
//
SD_ImageResourceNotFound::SD_ImageResourceNotFound()
 : SD_ResourceNotFound(
     "SD_ImageResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Image"
 )
{

}
SD_ImageResourceNotFound::SD_ImageResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_ImageResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Image"
    )
{

}
SD_ImageResourceNotFound::SD_ImageResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Image"
    )
{

}
SD_ImageResourceNotFound::SD_ImageResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ImageResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Image in SD_Resources");
}
////////////////////////////////////////
//
// SD_ImageResourceErasionFailed
//
SD_ImageResourceErasionFailed::SD_ImageResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_ImageResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Image"
 )
{

}
SD_ImageResourceErasionFailed::SD_ImageResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_ImageResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Image"
    )
{

}
SD_ImageResourceErasionFailed::SD_ImageResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Image"
    )
{

}
SD_ImageResourceErasionFailed::SD_ImageResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_ImageResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Image in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::RectangleShape
//
////////////////////////////////////////
//
// SD_RectangleShapeResourceInsertionFailed 
//
SD_RectangleShapeResourceInsertionFailed::SD_RectangleShapeResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_RectangleShapeResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RectangleShape"
 )
{
    
}
SD_RectangleShapeResourceInsertionFailed::SD_RectangleShapeResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_RectangleShapeResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::RectangleShape"
    )
{
    
}
SD_RectangleShapeResourceInsertionFailed::SD_RectangleShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RectangleShape"
    )
{

}
SD_RectangleShapeResourceInsertionFailed::SD_RectangleShapeResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RectangleShapeResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::RectangleShape in SD_Resources");
}
////////////////////////////////////////
//
// SD_RectangleShapeResourceNotFound
//
SD_RectangleShapeResourceNotFound::SD_RectangleShapeResourceNotFound()
 : SD_ResourceNotFound(
     "SD_RectangleShapeResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::RectangleShape"
 )
{

}
SD_RectangleShapeResourceNotFound::SD_RectangleShapeResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_RectangleShapeResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::RectangleShape"
    )
{

}
SD_RectangleShapeResourceNotFound::SD_RectangleShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::RectangleShape"
    )
{

}
SD_RectangleShapeResourceNotFound::SD_RectangleShapeResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RectangleShapeResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::RectangleShape in SD_Resources");
}
////////////////////////////////////////
//
// SD_RectangleShapeResourceErasionFailed
//
SD_RectangleShapeResourceErasionFailed::SD_RectangleShapeResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_RectangleShapeResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RectangleShape"
 )
{

}
SD_RectangleShapeResourceErasionFailed::SD_RectangleShapeResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_RectangleShapeResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::RectangleShape"
    )
{

}
SD_RectangleShapeResourceErasionFailed::SD_RectangleShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RectangleShape"
    )
{

}
SD_RectangleShapeResourceErasionFailed::SD_RectangleShapeResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_RectangleShapeResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::RectangleShape in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::RenderStates
//
////////////////////////////////////////
//
// SD_RenderStatesResourceInsertionFailed 
//
SD_RenderStatesResourceInsertionFailed::SD_RenderStatesResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_RenderStatesResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderStates"
 )
{

}
SD_RenderStatesResourceInsertionFailed::SD_RenderStatesResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_RenderStatesResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::RenderStates"
    )
{
    
}
SD_RenderStatesResourceInsertionFailed::SD_RenderStatesResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderStates"
    )
{

}
SD_RenderStatesResourceInsertionFailed::SD_RenderStatesResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderStatesResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::RenderStates in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderStatesResourceNotFound
//
SD_RenderStatesResourceNotFound::SD_RenderStatesResourceNotFound()
 : SD_ResourceNotFound(
     "SD_RenderStatesResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::RenderStates"
 )
{

}
SD_RenderStatesResourceNotFound::SD_RenderStatesResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_RenderStatesResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::RenderStates"
    )
{

}
SD_RenderStatesResourceNotFound::SD_RenderStatesResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderStates"
    )
{

}
SD_RenderStatesResourceNotFound::SD_RenderStatesResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderStatesResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::RenderStates in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderStatesResourceErasionFailed
//
SD_RenderStatesResourceErasionFailed::SD_RenderStatesResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_RenderStatesResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderStates"
 )
{

}
SD_RenderStatesResourceErasionFailed::SD_RenderStatesResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_RenderStatesResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::RenderStates"
    )
{

}
SD_RenderStatesResourceErasionFailed::SD_RenderStatesResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderStates"
    )
{

}
SD_RenderStatesResourceErasionFailed::SD_RenderStatesResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_RenderStatesResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::RenderStates in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::RenderTexture
//
////////////////////////////////////////
//
// SD_RenderTextureResourceInsertionFailed 
//
SD_RenderTextureResourceInsertionFailed::SD_RenderTextureResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_RenderTextureResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderTexture"
 )
{

}
SD_RenderTextureResourceInsertionFailed::SD_RenderTextureResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_RenderTextureResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::RenderTexture"
    )
{
    
}
SD_RenderTextureResourceInsertionFailed::SD_RenderTextureResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderTexture"
    )
{

}
SD_RenderTextureResourceInsertionFailed::SD_RenderTextureResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderTextureResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::RenderTexture in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderTextureResourceNotFound
//
SD_RenderTextureResourceNotFound::SD_RenderTextureResourceNotFound()
 : SD_ResourceNotFound(
     "SD_RenderTextureResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::RenderTexture"
 )
{

}
SD_RenderTextureResourceNotFound::SD_RenderTextureResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_RenderTextureResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::RenderTexture"
    )
{

}
SD_RenderTextureResourceNotFound::SD_RenderTextureResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderTexture"
    )
{

}
SD_RenderTextureResourceNotFound::SD_RenderTextureResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderTextureResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::RenderTexture in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderTextureResourceErasionFailed
//
SD_RenderTextureResourceErasionFailed::SD_RenderTextureResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_RenderTextureResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderTexture"
 )
{

}
SD_RenderTextureResourceErasionFailed::SD_RenderTextureResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_RenderTextureResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::RenderTexture"
    )
{

}
SD_RenderTextureResourceErasionFailed::SD_RenderTextureResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderTexture"
    )
{

}
SD_RenderTextureResourceErasionFailed::SD_RenderTextureResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_RenderTextureResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::RenderTexture in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::RenderWindow
//
////////////////////////////////////////
//
// SD_RenderWindowResourceInsertionFailed 
//
SD_RenderWindowResourceInsertionFailed::SD_RenderWindowResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_RenderWindowResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderWindow"
 )
{

}
SD_RenderWindowResourceInsertionFailed::SD_RenderWindowResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_RenderWindowResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::RenderWindow"
    )
{
    
}
SD_RenderWindowResourceInsertionFailed::SD_RenderWindowResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderWindow"
    )
{

}
SD_RenderWindowResourceInsertionFailed::SD_RenderWindowResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderWindowResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::RenderWindow in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderWindowResourceNotFound
//
SD_RenderWindowResourceNotFound::SD_RenderWindowResourceNotFound()
 : SD_ResourceNotFound(
     "SD_RenderWindowResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::RenderWindow"
 )
{

}
SD_RenderWindowResourceNotFound::SD_RenderWindowResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_RenderWindowResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::RenderWindow"
    )
{

}
SD_RenderWindowResourceNotFound::SD_RenderWindowResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderWindow"
    )
{

}
SD_RenderWindowResourceNotFound::SD_RenderWindowResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_RenderWindowResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::RenderWindow in SD_Resources");
}
////////////////////////////////////////
//
// SD_RenderWindowResourceErasionFailed
//
SD_RenderWindowResourceErasionFailed::SD_RenderWindowResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_RenderWindowResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::RenderWindow"
 )
{

}
SD_RenderWindowResourceErasionFailed::SD_RenderWindowResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_RenderWindowResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::RenderWindow"
    )
{

}
SD_RenderWindowResourceErasionFailed::SD_RenderWindowResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::RenderWindow"
    )
{

}
SD_RenderWindowResourceErasionFailed::SD_RenderWindowResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_RenderWindowResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::RenderWindow in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Shader
//
////////////////////////////////////////
//
// SD_ShaderResourceInsertionFailed 
//
SD_ShaderResourceInsertionFailed::SD_ShaderResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_ShaderResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Shader"
 )
{

}
SD_ShaderResourceInsertionFailed::SD_ShaderResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_ShaderResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Shader"
    )
{
    
}
SD_ShaderResourceInsertionFailed::SD_ShaderResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Shader"
    )
{

}
SD_ShaderResourceInsertionFailed::SD_ShaderResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ShaderResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Shader in SD_Resources");
}
////////////////////////////////////////
//
// SD_ShaderResourceNotFound
//
SD_ShaderResourceNotFound::SD_ShaderResourceNotFound()
 : SD_ResourceNotFound(
     "SD_ShaderResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Shader"
 )
{

}
SD_ShaderResourceNotFound::SD_ShaderResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_ShaderResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Shader"
    )
{

}
SD_ShaderResourceNotFound::SD_ShaderResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Shader"
    )
{

}
SD_ShaderResourceNotFound::SD_ShaderResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_ShaderResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Shader in SD_Resources");
}
////////////////////////////////////////
//
// SD_ShaderResourceErasionFailed
//
SD_ShaderResourceErasionFailed::SD_ShaderResourceErasionFailed() 
 : SD_ResourceErasionFailed(
     "SD_ShaderResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Shader"
 )
{

}
SD_ShaderResourceErasionFailed::SD_ShaderResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_ShaderResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Shader"
    )
{

}
SD_ShaderResourceErasionFailed::SD_ShaderResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Shader"
    )
{

}
SD_ShaderResourceErasionFailed::SD_ShaderResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_ShaderResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Shader in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Sprite
//
////////////////////////////////////////
//
// SD_SpriteResourceInsertionFailed 
//
SD_SpriteResourceInsertionFailed::SD_SpriteResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_SpriteResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Sprite"
 )
{

}
SD_SpriteResourceInsertionFailed::SD_SpriteResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_SpriteResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Sprite"
    )
{
    
}
SD_SpriteResourceInsertionFailed::SD_SpriteResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Sprite"
    )
{

}
SD_SpriteResourceInsertionFailed::SD_SpriteResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_SpriteResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Sprite in SD_Resources");
}
////////////////////////////////////////
//
// SD_SpriteResourceNotFound
//
SD_SpriteResourceNotFound::SD_SpriteResourceNotFound()
 : SD_ResourceNotFound(
     "SD_SpriteResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Sprite"
 )
{

}
SD_SpriteResourceNotFound::SD_SpriteResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_SpriteResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Sprite"
    )
{

}
SD_SpriteResourceNotFound::SD_SpriteResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Sprite"
    )
{

}
SD_SpriteResourceNotFound::SD_SpriteResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_SpriteResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Sprite in SD_Resources");
}
////////////////////////////////////////
//
// SD_SpriteResourceErasionFailed
//
SD_SpriteResourceErasionFailed::SD_SpriteResourceErasionFailed()
: SD_ResourceErasionFailed(
    "SD_SpriteResourceErasionFailed",
    DefaultExceptionDescription(),
    "",
    "sf::Sprite"
)
{

}
SD_SpriteResourceErasionFailed::SD_SpriteResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_SpriteResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Sprite"
    )
{

}
SD_SpriteResourceErasionFailed::SD_SpriteResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Sprite"
    )
{

}
SD_SpriteResourceErasionFailed::SD_SpriteResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_SpriteResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Sprite in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Texture
//
////////////////////////////////////////
//
// SD_TextureResourceInsertionFailed 
//
SD_TextureResourceInsertionFailed::SD_TextureResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_TextureResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Texture"
 )
{

}
SD_TextureResourceInsertionFailed::SD_TextureResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_TextureResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::Texture"
    )
{
    
}
SD_TextureResourceInsertionFailed::SD_TextureResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Texture"
    )
{

}
SD_TextureResourceInsertionFailed::SD_TextureResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_TextureResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Texture in SD_Resources");
}
////////////////////////////////////////
//
// SD_TextureResourceNotFound
//
SD_TextureResourceNotFound::SD_TextureResourceNotFound()
 : SD_ResourceNotFound(
     "SD_TextureResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Texture"
 )
{

}
SD_TextureResourceNotFound::SD_TextureResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_TextureResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::Texture"
    )
{

}
SD_TextureResourceNotFound::SD_TextureResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::Texture"
    )
{

}
SD_TextureResourceNotFound::SD_TextureResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_TextureResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Texture in SD_Resources");
}
////////////////////////////////////////
//
// SD_TextureResourceErasionFailed
//
SD_TextureResourceErasionFailed::SD_TextureResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_TextureResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Texture"
 )
{

}
SD_TextureResourceErasionFailed::SD_TextureResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_TextureResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::Texture"
    )
{

}
SD_TextureResourceErasionFailed::SD_TextureResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::Texture"
    )
{

}
SD_TextureResourceErasionFailed::SD_TextureResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_TextureResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::Texture in SD_Resources");
}
////////////////////////////////////////
////////////////////////////////////////
//
// Exceptions for the resource type: sf::Text
//
////////////////////////////////////////
//
// SD_TextResourceInsertionFailed
//
SD_TextResourceInsertionFailed::SD_TextResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_TextResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Text"
 )
{

}
SD_TextResourceInsertionFailed::SD_TextResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
    "SD_TextResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::Text"
) {

}
SD_TextResourceInsertionFailed::SD_TextResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    id,
    "sf::Text"
) {

}
SD_TextResourceInsertionFailed::SD_TextResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    id,
    resource_type
) {

}
std::string SD_TextResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert sf::Text to SD_Resrouces");
}
////////////////////////////////////////
SD_TextResourceNotFound::SD_TextResourceNotFound()
 : SD_ResourceNotFound(
     "SD_TextResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Text"
 )
{

}
SD_TextResourceNotFound::SD_TextResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_TextResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "sf::Text"
) {

}
SD_TextResourceNotFound::SD_TextResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    "sf::Text"
) {

}
SD_TextResourceNotFound::SD_TextResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    resource_type 
) {

}
std::string SD_TextResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::Text in SD_Resources");
}
////////////////////////////////////////
//
// SD_TextResourceErasionFailed
//
SD_TextResourceErasionFailed::SD_TextResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_TextResourceErasionFailed",
     DefaultExceptionDescription(),
     "", 
     "sf::Text"
 )
{

}
SD_TextResourceErasionFailed::SD_TextResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
    "SD_TextResourceErasionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::Text"
) {

}
SD_TextResourceErasionFailed::SD_TextResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    "sf::Text"
) {

}
SD_TextResourceErasionFailed::SD_TextResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    resource_type
) {

}
std::string SD_TextResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase sf::Text in SD_Resources");
}
////////////////////////////////////////
//
// Exceptions for the resource type: sf::VertexArray
//
////////////////////////////////////////
//
// SD_VertexArrayResourceInsertionFailed 
//
SD_VertexArrayResourceInsertionFailed::SD_VertexArrayResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_VertexArrayResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::VertexArray"
 )
{

}
SD_VertexArrayResourceInsertionFailed::SD_VertexArrayResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
        "SD_VertexArrayResourceInsertionFailed", 
        DefaultExceptionDescription(),
        id,
        "sf::VertexArray"
    )
{
    
}
SD_VertexArrayResourceInsertionFailed::SD_VertexArrayResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::VertexArray"
    )
{

}
SD_VertexArrayResourceInsertionFailed::SD_VertexArrayResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_VertexArrayResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::VertexArray in SD_Resources");
}
////////////////////////////////////////
//
// SD_VertexArrayResourceNotFound
//
SD_VertexArrayResourceNotFound::SD_VertexArrayResourceNotFound()
 : SD_ResourceNotFound(
     "SD_VertexArrayResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::VertexArray"
 )
{

}
SD_VertexArrayResourceNotFound::SD_VertexArrayResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
        "SD_VertexArrayResourceNotFound",
        DefaultExceptionDescription(),
        id,
        "sf::VertexArray"
    )
{

}
SD_VertexArrayResourceNotFound::SD_VertexArrayResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        "sf::VertexArray"
    )
{

}
SD_VertexArrayResourceNotFound::SD_VertexArrayResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{

}
std::string SD_VertexArrayResourceNotFound::DefaultExceptionDescription() const {
    return std::string ("Unable to find sf::VertexArray in SD_Resources");
}
////////////////////////////////////////
//
// SD_VertexArrayResourceErasionFailed
//
SD_VertexArrayResourceErasionFailed::SD_VertexArrayResourceErasionFailed()
 : SD_ResourceErasionFailed (
     "SD_VertexArrayResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::VertexArray"
 )
{

}
SD_VertexArrayResourceErasionFailed::SD_VertexArrayResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
        "SD_VertexArrayResourceErasionFailed",
        DefaultExceptionDescription(),
        id,
        "sf::VertexArray"
    )
{

}
SD_VertexArrayResourceErasionFailed::SD_VertexArrayResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        "sf::VertexArray"
    )
{

}
SD_VertexArrayResourceErasionFailed::SD_VertexArrayResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
        exc_name,
        exc_desc,
        element_id,
        resource_type
    )
{
    
}
std::string SD_VertexArrayResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase sf::VertexArray in SD_Resources");
}

////////////////////////////////////////
//
// SD_ExpandableSpriteResourceInsertionFailed
//
SD_ExpandableSpriteResourceInsertionFailed::SD_ExpandableSpriteResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_ExpandableSpriteResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "SD_ExpandableSprite"
)
{

}
SD_ExpandableSpriteResourceInsertionFailed::SD_ExpandableSpriteResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
    "SD_ExpandableSpriteResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "SD_ExpandableSprite"
)
{

}
SD_ExpandableSpriteResourceInsertionFailed::SD_ExpandableSpriteResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    id,
    "SD_ExpandableSprite"
)
{

}
SD_ExpandableSpriteResourceInsertionFailed::SD_ExpandableSpriteResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    id,
    resource_type 
) 
{

}
std::string SD_ExpandableSpriteResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert SD_ExpandableSprite in SD_Resources");
}

////////////////////////////////////////
//
// SD_ExpandableSpriteResourceNotFound
//
SD_ExpandableSpriteResourceNotFound::SD_ExpandableSpriteResourceNotFound()
 : SD_ResourceNotFound(
     "SD_ExpandableSpriteResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "SD_ExpandableSprite"
 )
{

}
SD_ExpandableSpriteResourceNotFound::SD_ExpandableSpriteResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_ExpandableSpriteResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "SD_ExpandableSprite"
)
{

}
SD_ExpandableSpriteResourceNotFound::SD_ExpandableSpriteResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    "SD_ExpandableSprite"
)
{

}
SD_ExpandableSpriteResourceNotFound::SD_ExpandableSpriteResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    id,
    resource_type
)
{

}
std::string SD_ExpandableSpriteResourceNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find SD_ExpandableSprite in SD_Resources");
}

////////////////////////////////////////
//
// SD_ExpandableSpriteResourceErasionFailed
//
SD_ExpandableSpriteResourceErasionFailed::SD_ExpandableSpriteResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_ExpandableSpriteResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "SD_ExpandableSprite"
 )
{

}
SD_ExpandableSpriteResourceErasionFailed::SD_ExpandableSpriteResourceErasionFailed(
    const std::string& id
) : SD_ResourceErasionFailed(
    "SD_ExpandableSpriteResourceErasionFailed",
    DefaultExceptionDescription(),
    id,
    "SD_ExpandableSprite"
) 
{

}
SD_ExpandableSpriteResourceErasionFailed::SD_ExpandableSpriteResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    "SD_ExpandableSprite"
) {

}

SD_ExpandableSpriteResourceErasionFailed::SD_ExpandableSpriteResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    id,
    resource_type

)
{

}
std::string SD_ExpandableSpriteResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to erase SD_ExpandableSprite in SD_Resources");
}

////////////////////////////////////////
//
// SD_MusicResourceInsertionFailed
//
SD_MusicResourceInsertionFailed::SD_MusicResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_MusicResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Music"
 )
{

}
SD_MusicResourceInsertionFailed::SD_MusicResourceInsertionFailed(
    const std::string& id
) : SD_ResourceInsertionFailed(
    "SD_MusicResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::Music"
) 
{

}

SD_MusicResourceInsertionFailed::SD_MusicResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::Music"
) 
{

}

SD_MusicResourceInsertionFailed::SD_MusicResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_MusicResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert sf::Music in SD_Resources");
}

////////////////////////////////////////
//
// SD_MusicResourceNotFound
//
SD_MusicResourceNotFound::SD_MusicResourceNotFound()
 : SD_ResourceNotFound(
     "SD_MusicResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Music"
)
{

}

SD_MusicResourceNotFound::SD_MusicResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_MusicResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "sf::Music"
)
{

}

SD_MusicResourceNotFound::SD_MusicResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    "sf::Music"
)
{

}

SD_MusicResourceNotFound::SD_MusicResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_MusicResourceNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find sf::Music in SD_Resources");
}

////////////////////////////////////////
//
// SD_MusicResourceErasionFailed
//
SD_MusicResourceErasionFailed::SD_MusicResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_MusicResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Music"
 )
{

}

SD_MusicResourceErasionFailed::SD_MusicResourceErasionFailed(
    const std::string& id 
) : SD_ResourceErasionFailed(
    "SD_MusicResourceErasionFailed",
    DefaultExceptionDescription(),
    id,
    "sd::Music"
)
{

}

SD_MusicResourceErasionFailed::SD_MusicResourceErasionFailed
(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::Music"
)
{

}

SD_MusicResourceErasionFailed::SD_MusicResourceErasionFailed
(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_MusicResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase sf::Music in SD_Resources");
}

////////////////////////////////////////
//
// SD_SoundResourceInsertionFailed
//
SD_SoundResourceInsertionFailed::SD_SoundResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_SoundResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::Sound"
 )
{

}

SD_SoundResourceInsertionFailed::SD_SoundResourceInsertionFailed(
    const std::string& id 
) : SD_ResourceInsertionFailed(
    "SD_SoundResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::Sound"
)
{

}

SD_SoundResourceInsertionFailed::SD_SoundResourceInsertionFailed
(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::Sound"
)
{

}

SD_SoundResourceInsertionFailed::SD_SoundResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::Sound in SD_Resources");
}

////////////////////////////////////////
//
// SD_SoundResourceNotFound
//

SD_SoundResourceNotFound::SD_SoundResourceNotFound()
 : SD_ResourceNotFound(
     "SD_SoundResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::Sound"
 )
{

}
SD_SoundResourceNotFound::SD_SoundResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_SoundResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "sf::Sound"
) 
{

}

SD_SoundResourceNotFound::SD_SoundResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    "sf::Sound"
)
{

}

SD_SoundResourceNotFound::SD_SoundResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundResourceNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find sf::Sound in SD_Resources");
}

////////////////////////////////////////
//
// SD_SoundResourceErasionFailed
//

SD_SoundResourceErasionFailed::SD_SoundResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_SoundResourceErasionFailed",
     DefaultExceptionDescription (),
     "",
     "sf::Sound"
 )
 {

 }
SD_SoundResourceErasionFailed::SD_SoundResourceErasionFailed(
    const std::string& id 
) : SD_ResourceErasionFailed(
    "SD_SoundResourceErasionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::Sound"
)
{

}

SD_SoundResourceErasionFailed::SD_SoundResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::Sound"
)
{

}

SD_SoundResourceErasionFailed::SD_SoundResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase sf::Sound in SD_Resources");
}


////////////////////////////////////////
//
// SD_SoundBufferResourceInsertionFailed
//

SD_SoundBufferResourceInsertionFailed::SD_SoundBufferResourceInsertionFailed()
 : SD_ResourceInsertionFailed(
     "SD_SoundBufferResourceInsertionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::SoundBuffer"
 )
{

}

SD_SoundBufferResourceInsertionFailed::SD_SoundBufferResourceInsertionFailed(
    const std::string& id 
) : SD_ResourceInsertionFailed(
    "SD_SoundBufferResourceInsertionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceInsertionFailed::SD_SoundBufferResourceInsertionFailed
(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceInsertionFailed::SD_SoundBufferResourceInsertionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceInsertionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundBufferResourceInsertionFailed::DefaultExceptionDescription() const {
    return std::string ("Unable to insert sf::SoundBuffer in SD_Resources");
}

////////////////////////////////////////
//
// SD_SoundBufferResourceNotFound
//

SD_SoundBufferResourceNotFound::SD_SoundBufferResourceNotFound()
 : SD_ResourceNotFound(
     "SD_SoundBufferResourceNotFound",
     DefaultExceptionDescription(),
     "",
     "sf::SoundBuffer"
 )
{

}

SD_SoundBufferResourceNotFound::SD_SoundBufferResourceNotFound(
    const std::string& id
) : SD_ResourceNotFound(
    "SD_SoundBufferResourceNotFound",
    DefaultExceptionDescription(),
    id,
    "sf::SoundBuffer"
) 
{

}

SD_SoundBufferResourceNotFound::SD_SoundBufferResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceNotFound::SD_SoundBufferResourceNotFound(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceNotFound(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundBufferResourceNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find sf::SoundBuffer in SD_Resources");
}

////////////////////////////////////////
//
// SD_SoundBufferResourceErasionFailed
//

SD_SoundBufferResourceErasionFailed::SD_SoundBufferResourceErasionFailed()
 : SD_ResourceErasionFailed(
     "SD_SoundBufferResourceErasionFailed",
     DefaultExceptionDescription(),
     "",
     "sf::SoundBuffer"
 )
{

}

SD_SoundBufferResourceErasionFailed::SD_SoundBufferResourceErasionFailed(
    const std::string& id 
) : SD_ResourceErasionFailed(
    "SD_SoundBufferResourceErasionFailed",
    DefaultExceptionDescription(),
    id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceErasionFailed::SD_SoundBufferResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceErasionFailed::SD_SoundBufferResourceErasionFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceErasionFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundBufferResourceErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase sf::SoundBuffer in SD_Resources");
}

////////////////////////////////////////

SD_SoundBufferResourceSaveFailed::SD_SoundBufferResourceSaveFailed()
 : SD_ResourceSaveFailed(
     "SD_SoundBufferResourceSaveFailed",
     DefaultExceptionDescription(),
     "",
     "sf::SoundBuffer"
 )
{
    
}

SD_SoundBufferResourceSaveFailed::SD_SoundBufferResourceSaveFailed(
    const std::string& id 
) : SD_ResourceSaveFailed(
    "SD_SoundBufferResourceSaveFailed",
    DefaultExceptionDescription(),
    id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceSaveFailed::SD_SoundBufferResourceSaveFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id
) : SD_ResourceSaveFailed(
    exc_name,
    exc_desc,
    element_id,
    "sf::SoundBuffer"
)
{

}

SD_SoundBufferResourceSaveFailed::SD_SoundBufferResourceSaveFailed(
    const std::string& exc_name,
    const std::string& exc_desc,
    const std::string& element_id,
    const std::string& resource_type
) : SD_ResourceSaveFailed(
    exc_name,
    exc_desc,
    element_id,
    resource_type
)
{

}

std::string SD_SoundBufferResourceSaveFailed::DefaultExceptionDescription() const {
    return std::string("Unable to save sf::SoundBuffer from SD_Resources");
}

////////////////////////////////////////
}
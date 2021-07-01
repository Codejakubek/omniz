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
// File: /impl/include/SigmaDev/Exception/ResourcesExceptions.h
// Description:
//      ResourcesExceptions.h contain the declarations of the concrete exceptions
//      thrown mostly in the resources containers (declared in /impl/include/SigmaDev/Resources.h)
//      
// Additional Notes:
//      (Codedemens, July 26, 2020) These exceptions haven't been tested out ... yet. 
//      I'm working on unit test handling now.
//      
//      (Codedemens, March 17, 2021) There are too many exceptions. I believe I could
//      Optimize it a bit. And I'm not going to spend time moving docs from this file
//      to doc/pages/ files.
////////////////////////////////////////

#ifndef SD_RESOURCES_EXCEPTIONS_H
#define SD_RESOURCES_EXCEPTIONS_H

#include <SigmaDev/Exception/Exception.h>


namespace exc 
{
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_BlendModeResourceInsertionFailed is thrown when insertion
 *        of sf::Texture in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_BlendModeResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::BlendMode
     */
    SD_BlendModeResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * @param element_id Resource (sf::BlendMode) id
     */
    SD_BlendModeResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::BlendMode) id 
     */
    SD_BlendModeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_BlendModeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_BlendModeResourceNotFound is thrown when sf::BlendMode
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_BlendModeResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::BlendMode
     */
    SD_BlendModeResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * @param element_id Resource (sf::BlendMode) id
     */
    SD_BlendModeResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::BlendMode) id 
     */
    SD_BlendModeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_BlendModeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_BlendModeResourceErasionFailed is thrown when sf::BleneMode
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_BlendModeResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::BlendMode
     */
    SD_BlendModeResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * @param element_id Resource (sf::BlendMode) id
     */
    SD_BlendModeResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::BlendMode
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::BlendMode) id 
     */
    SD_BlendModeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_BlendModeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_CircleShapeResourceInsertionFailed is thrown when insertion
 *        of sf::CircleShape in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_CircleShapeResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::CircleShape
     */
    SD_CircleShapeResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * @param element_id Resource (sf::CircleShape) id
     */
    SD_CircleShapeResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::CircleShape) id 
     */
    SD_CircleShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_CircleShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_CircleShapeResourceNotFound is thrown when sf::CircleShape
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 * 
 */
class SD_CircleShapeResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::CircleShape
     */
    SD_CircleShapeResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * @param element_id Resource (sf::CircleShape) id
     */
    SD_CircleShapeResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::CircleShape) id 
     */
    SD_CircleShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_CircleShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_CircleShapeResourceErasionFailed is thrown when sf::CircleShape
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_CircleShapeResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description. 
     *        element_id is not set.
     *        resource_type is set to sf::CircleShape
     */
    SD_CircleShapeResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * @param element_id Resource (sf::CircleShape) id
     */
    SD_CircleShapeResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::CircleShape
     * 
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::CircleShape) id 
     */
    SD_CircleShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_CircleShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_ColorResourceInsertionFailed is thrown when insertion
 *        of sf::Color in SD_Resources fails
 * 
 * @ingroup resource_exception_module
 */
class SD_ColorResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:

    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Color
     */
    SD_ColorResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::Color
     * 
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::Color
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ColorResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ColorResourceNotFound is thrown when the sf::Color
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_ColorResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::Color
     */
    SD_ColorResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Color
     * 
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Color
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ColorResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
} ;
////////////////////////////////////////
/**
 * @brief exc::SD_ColorResourceErasionFailed is thrown when sf::Color
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module 
 */
class SD_ColorResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::Color
     */
    SD_ColorResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Color
     * 
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Color
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Color) id
     */
    SD_ColorResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ColorResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_ConvexShapeResourceInsertionFailed is thrown when insertion
 *        of sf::ConvexShape in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_ConvexShapeResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::ConvexShape
     */
    SD_ConvexShapeResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::ConvexShape
     * 
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::ConvexShape
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ConvexShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ConvexShapeResourceNotFound is thrown when the sf::ConvexShape
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module 
 */
class SD_ConvexShapeResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::ConvexShape
     */
    SD_ConvexShapeResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::ConvexShape
     * 
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::ConvexShape
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ConvexShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ConvexShapeResourceErasionFailed is thrown when sf::ConvexShape
 *        erasion fromn SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_ConvexShapeResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::ConvexShape
     */
    SD_ConvexShapeResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::ConvexShape
     * 
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Color
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::ConvexShape) id
     */
    SD_ConvexShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ConvexShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_FontResourceInsertionFailed is thrown when insertion
 *        of sf::Font in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_FontResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Font
     */
    SD_FontResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::Font
     * 
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::Font
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_FontResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_FontResourceNotFound is thrown when the sf::Font
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_FontResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Font
     */
    SD_FontResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Font
     * 
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Font
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_FontResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_FontResourceErasionFailoed is thrown when sf::Font
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_FontResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Font
     */
    SD_FontResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Font
     * 
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Font
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Font) id
     */
    SD_FontResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_FontResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_ImageResourceInsertionFailed is thrown when insertion
 *        of sf::Image in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_ImageResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Image
     */
    SD_ImageResourceInsertionFailed() ;
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Image
     * 
     * @param element_id Resource (sf::Image) id
     */
    SD_ImageResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::Image
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Image) id
     */
    SD_ImageResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ImageResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ImageResourceNotFound is thrown when the sf::Image
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_ImageResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::Image
     */
    SD_ImageResourceNotFound() ;
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Image
     * 
     * @param element_id Resource (sf::Image) id
     */
    SD_ImageResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Image
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Image) id
     */
    SD_ImageResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ImageResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ImageResourceErasionFailed is thrown when sf::Image
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_ImageResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Image
     */
    SD_ImageResourceErasionFailed() ;
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Image
     * 
     * @param element_id Resource (sf::Image) id
     */
    SD_ImageResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Image
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Image) id 
     */
    SD_ImageResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ImageResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_RectangleShapeResourceInsertionFailed is thrown when insertion
 *        of sf::RectangleShape in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RectangleShapeResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::RectangleShape
     */
    SD_RectangleShapeResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RectangleShape.
     * 
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::ConvexShape
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RectangleShapeResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RectangleShapeResourceNotFound is thrown when the sf::RectangleShape
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RectangleShapeResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::RectangleShape
     */
    SD_RectangleShapeResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RectangleShape
     * 
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RectangleShape
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RectangleShapeResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RectangleShapeResourceErasionFailed is thrown when sf::RectangleShape
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_RectangleShapeResourceErasionFailed : public SD_ResourceErasionFailed {
public:

    /**
     * @brief Uses defualt exception name and description.
     *        element_id is not set.
     *        resource_typoe is set to sf::RectangleShape
     */
    SD_RectangleShapeResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RectangleShape
     * 
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RectangleShape
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RectangleShape) id
     */
    SD_RectangleShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RectangleShapeResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_RenderStatesResourceInsertionFailed is thrown when insertion
 *        of sf::RenderStates in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_RenderStatesResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderStates
     */
    SD_RenderStatesResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::RenderStates
     * 
     * @param element_id Resource (sf::RenderStates) id
     */
    SD_RenderStatesResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderStates
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderStates) id
     */
    SD_RenderStatesResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderStatesResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderStatesResourceNotFound is thrown when
 *        sf::RenderStates access in SD_Resources fails. 
 * @ingroup resource_exception_module
 */
class SD_RenderStatesResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_Type is set to sf::RenderStates
     * 
     */
    SD_RenderStatesResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderStates
     * 
     * @param element_id Resource (sf::RenderStates) id
     */
    SD_RenderStatesResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderStates
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderStates) id 
     */
    SD_RenderStatesResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderStatesResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderStatesResourceErasionFailed is thrown when sf::RenderStates
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RenderStatesResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default excepton name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderStates
     */
    SD_RenderStatesResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderStates
     * 
     * @param element_id Resource (sf::RenderStates) id
     */
    SD_RenderStatesResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderStates
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderStates) id 
     */
    SD_RenderStatesResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderStatesResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_RenderTextureResourceInsertionFailed is thrown when insertion
 *        of sf::RenderTexture in SD_Resources fails
 * @ingroup resource_exception_module 
 */
class SD_RenderTextureResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderTexture
     */
    SD_RenderTextureResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderTexture
     * 
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::RenderTexture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderTextureResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderTextureResourceNotFound is thrown when the sf::RenderTexture
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RenderTextureResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::RenderTexture
     */
    SD_RenderTextureResourceNotFound();
    /**
     * @brief Uses default exception name and description
     *        Sets the element_id.
     *        resource_type is set to sf::RenderTexture
     * 
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderTexture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderTextureResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderTextureResourceErasionFailed is thrown when sf::RenderTexture
 *        erasion from SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_RenderTextureResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set
     *        resource_type is set to sf::RenderTexture
     */
    SD_RenderTextureResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id
     *        resource_type is set to sf::RenderTexture
     * 
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resouce_type is set to sf::RenderTexture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderTexture) id
     */
    SD_RenderTextureResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderTextureResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_RenderWindowResourceInsertionFailed is thrown when insertion
 *        of sf::RenderWindow in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RenderWindowResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::RenderWindow
     */
    SD_RenderWindowResourceInsertionFailed();
    /**
     * @brief Uses default exception name and descripton.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderWindowResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderWindowResourceNotFound is thrown when the sf::RenderWindow
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RenderWindowResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderWindow
     */
    SD_RenderWindowResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderWindowResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_RenderWindowResourceErasionFailed is thrown when sf::RenderWindow
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_RenderWindowResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::RenderWindow
     * 
     */
    SD_RenderWindowResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::RenderWindow
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::RenderWindow) id
     */
    SD_RenderWindowResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_RenderWindowResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_ShaderResourceInsertionFailed is thrown when insertion
 *        of sf::Shader in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_ShaderResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Shader
     */
    SD_ShaderResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_Type is set to sf::Shader
     * 
     * @param element_id Resource (sf::Shader) id 
     */
    SD_ShaderResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Shader
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Shader) id
     */
    SD_ShaderResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ShaderResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ShaderResourceNotFound is thrown when
 *        sf::Shader access in SD_Resources fails.
 * @ingroup resource_exception_module 
 */
class SD_ShaderResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Shader
     */
    SD_ShaderResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Shader
     * 
     * @param element_id Resource (sf::Shader) id
     */
    SD_ShaderResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Shader
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Shader) id
     */
    SD_ShaderResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ShaderResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ShaderResourceErasionFailed is thrown when sf::Shader
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_ShaderResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Shader
     */
    SD_ShaderResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Shader
     * 
     * @param element_id Resource (sf::Shader) id
     */
    SD_ShaderResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Shader
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Shader) id 
     */
    SD_ShaderResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ShaderResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_SpriteResourceInsertionFailed is thrown when insertion
 *        of sf::Sprite in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_SpriteResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Sprite
     */
    SD_SpriteResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Sprite
     * 
     * @param element_id Resource (Sf::Sprite) id
     */
    SD_SpriteResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Sprite.
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resrouce (sf::Sprite) id
     */
    SD_SpriteResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SpriteResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SpriteResourceNotFound is thrown when the sf::Sprite
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SpriteResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Sprite
     */
    SD_SpriteResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Sprite
     * 
     * @param element_id Resource (sf::Sprite) id
     */
    SD_SpriteResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Sprite
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Sprite) id
     */
    SD_SpriteResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SpriteResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SpriteResourceErasionFailed is thrown when sf::Sprite
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SpriteResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses defualt exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Sprite
     * 
     */
    SD_SpriteResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Sprite
     * 
     * @param element_id Resource (sf::Sprite) id
     */
    SD_SpriteResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_Type is set to sf::Sprite
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Sprite) id
     */
    SD_SpriteResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SpriteResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_TextureResourceInsertionFailed is thrown when insertion
 *        of sf::Texture in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_TextureResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Texture
     */
    SD_TextureResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Texture
     * 
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and descripton.
     *        Sets the element_id.
     *        resource_type is set to sf::Texture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextureResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_TextureResourceNotFound is thrown when the sf::Texture
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_TextureResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Texture
     */
    SD_TextureResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Texture
     * 
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Texture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextureResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_TextureResourceErasionFailed is thrown when sf::Texture
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_TextureResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Texture
     */
    SD_TextureResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the elemnet_id.
     *        resource_type is set to sf::Texture
     * 
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Texture
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Texture) id
     */
    SD_TextureResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextureResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_TextResourceInsertionFailed is thrown when insertion
 *        of sf::Text in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_TextResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Text
     * 
     */
    SD_TextResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Text
     * 
     * @param element_id Resource (sf::Text) id
     */
    SD_TextResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Text
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Text) id
     */
    SD_TextResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_TextResourceNotFound is thrown when sf::Text
 *        access in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_TextResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Text
     */
    SD_TextResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Text
     * 
     * @param element_id Resource (sf::Text) id 
     */
    SD_TextResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Text
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Text) id
     */
    SD_TextResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_TextResourceErasionFailed is thrown when sf::Text
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_TextResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::Text
     */
    SD_TextResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Text
     * 
     * @param element_id Resource (sf::Text) id
     */
    SD_TextResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description
     *        Sets the element_id.
     *        resource_type is set to sf::Text
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Text) id
     */
    SD_TextResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_TextResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_VertexArrayResourceInsertionFailed is thrown when insertion
 *        of sf::VertexArray in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_VertexArrayResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::VertexArray
     */
    SD_VertexArrayResourceInsertionFailed();
    /**
     * @brief Uses default description name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::VertexArray
     * 
     * @param element_id Resource (sf::VertexArray) id 
     */
    SD_VertexArrayResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::VertexArray.
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::VertexArray) id
     */
    SD_VertexArrayResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_VertexArrayResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_VertexArrayResourceNotFound is thrown when the sf::VertexArray
 *        access in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_VertexArrayResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::VertexArray
     */
    SD_VertexArrayResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::VertexArray.
     * 
     * @param element_id Resource (sf::VertexArray) id
     */
    SD_VertexArrayResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::VertexArray
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::VertexArray) id
     */
    SD_VertexArrayResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_VertexArrayResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_VertexArrayResourceErasionFailed is thrown when sf::VertexArray
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_VertexArrayResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::VerteXarray
     * 
     */
    SD_VertexArrayResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Set the element_id.
     *        resource_type is set to sf::VertexArray
     * 
     * @param element_id Resource (sf::VertexArray) id
     */
    SD_VertexArrayResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and descripton
     *        Sets the element_id.
     *        resource_type is set to sf::VertexArray
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::VertexArray) id
     */
    SD_VertexArrayResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_VertexArrayResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_ExpandableSpriteResourceInsertionFailed is thrown when insertion
 *        of SD_ExpandableSprite in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_ExpandableSpriteResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to SD_ExpandableSprite
     */
    SD_ExpandableSpriteResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ExpandableSpriteResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ExpandableSpriteResourceNotFound is thrown when the SD_ExpandableSprite
 *        access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_ExpandableSpriteResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to SD_ExpandableSprite.
     */
    SD_ExpandableSpriteResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param exc_name Exception Nam
     * @param exc_desc Exception Description
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ExpandableSpriteResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
protected:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_ExpandableSpriteResourceErasionFailed is 
 *        thrown when SD_ExpandableSprite erasion form SD_Resources
 *        fails.
 * @ingroup resource_exception_module
 */
class SD_ExpandableSpriteResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to SD_ExpandableSprite
     */
    SD_ExpandableSpriteResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to SD_ExpandableSprite
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (SD_ExpandableSprite) id
     */
    SD_ExpandableSpriteResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_ExpandableSpriteResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
protected:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_MusicResourceInsertionFailed is thrown when insertion
 *        of sf::Music in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_MusicResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Music
     * 
     */
    SD_MusicResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Music
     * 
     * @param element_id Resource (sf::Music) id
     */
    SD_MusicResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Music
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Music) id
     */
    SD_MusicResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_MusicResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_MusicResourceNotFound is thrown when sf::Music
 *        access in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_MusicResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::Music
     */
    SD_MusicResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the elemnet_id.
     *        resource_type is set to sf::Music
     * 
     * @param element_id Resource (sf::Music) id
     */
    SD_MusicResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::Music
     * 
     * @param exc_name 
     * @param exc_desc 
     * @param element_id 
     */
    SD_MusicResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_MusicResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_MusicResourceErasion Failed is thrown when sf::Music
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_MusicResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::Music
     */
    SD_MusicResourceErasionFailed();
    /**
     * @brief Uses default exception name anddescription.
     *        Sets the element_id.
     *        resource_Type is set to sf::Music
     * 
     * @param element_id Resource (sf::Music) id
     */
    SD_MusicResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description
     *        Sets the element_id.
     *        resource_type is set to sf::Music
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::Music) id
     */
    SD_MusicResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_MusicResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_SoundResourceInsertionFailed is thrown when insertion
 *        of sf::SoundSounrce in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SoundResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::SoundSource
     */
    SD_SoundResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param element_id Resource (sf::SoundSource) id 
     */
    SD_SoundResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundSource) id
     */
    SD_SoundResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type  
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SoundSourceNotFound is thrown when the sf::SoundSource
 *        access in SD_Resources fails
 * @ingroup resource_exception_module
 */
class SD_SoundResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::SoundSource 
     */
    SD_SoundResourceNotFound();
    /**
     * @brief Uses default exception name and descripton.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param element_id Resource (sf::SoundSource) id
     */
    SD_SoundResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundSource) id
     */
    SD_SoundResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SoundSourceErasionFailed is thrown when sf::SoundSource
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SoundResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *       element_id is not set.
     *       resource_type is set to sf::SoundSource
     */
    SD_SoundResourceErasionFailed();
    /**
     * @brief Uses defualt exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param element_id Resource (sf::SoundSource) id
     */
     SD_SoundResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the default exception name and description
     *        Sets the element_id.
     *        resource_type is set to sf::SoundSource
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundSource) id
     */
    SD_SoundResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////
////////////////////////////////////////

/**
 * @brief exc::SD_SoundBufferResourceInsertionFailed is thrown when insertion
 *        of sf::SoundBuffer in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SoundBufferResourceInsertionFailed : public SD_ResourceInsertionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::SoundBuffer
     */
    SD_SoundBufferResourceInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceInsertionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundBufferResourceInsertionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SoundBufferResourceNotFound is thrown when
 *        sf::SoundBuffer access in SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SoundBufferResourceNotFound : public SD_ResourceNotFound {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::SoundBuffer
     */
    SD_SoundBufferResourceNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceNotFound(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_Type is set to sf::SoundBuffer
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource sf::SoundBuffer) id
     */
    SD_SoundBufferResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundBufferResourceNotFound(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SoundBufferErasionFailed is thrown when the sf::SoundBuffer
 *        erasion from SD_Resources fails.
 * @ingroup resource_exception_module
 */
class SD_SoundBufferResourceErasionFailed : public SD_ResourceErasionFailed {
public:
    /**
     * @brief Uses default exception name and description.
     *        element_id is not set.
     *        resource_type is set to sf::SoundBuffer
     */
    SD_SoundBufferResourceErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceErasionFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundBufferResourceErasionFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
};
////////////////////////////////////////

/**
 * @brief exc::SD_SoundBufferResourceSaveFailed is thrown when attempt to save
 *        the sf::SoundBuffer to a file fails.
 * @ingroup resource_exception_module
 */
class SD_SoundBufferResourceSaveFailed : public SD_ResourceSaveFailed {
public:
    /**
     * @brief Uses default exception name and description
     *        element_id is not set.
     *        resource_type is set to sf::SoundBuffer
     */
    SD_SoundBufferResourceSaveFailed();
    /**
     * @brief Uses default exception name and description
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceSaveFailed(const std::string& element_id);
protected:
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        resource_type is set to sf::SoundBuffer
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource (sf::SoundBuffer) id
     */
    SD_SoundBufferResourceSaveFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id
    );
    /**
     * @brief Specifies the exception name and description.
     *        Sets the element_id.
     *        Specifies (overrides) the resource_type
     * 
     * @param exc_name Exception Name
     * @param exc_desc Exception Description
     * @param element_id Resource id
     * @param resource_type Resource Type Name Override
     */
    SD_SoundBufferResourceSaveFailed(
        const std::string& exc_name,
        const std::string& exc_desc,
        const std::string& element_id,
        const std::string& resource_type
    );
public:
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

////////////////////////////////////////

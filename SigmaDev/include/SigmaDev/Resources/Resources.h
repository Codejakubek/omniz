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
// File: /impl/include/SigmaDev/Resources.h
// Description:
//      Resources.h contain declarations for broadly-thought resources.
//      Resource in this context means - any object that represent.:
//      graphic, sound, music, configuration, window, JSON, or other variables
//      containing information used by SigmaDev
//      and (or) game/software run under SigmaDev.
//      
//      SD_Resources is the class containing all default resources used by SigmaDev Library. 
//      But it can be extended by the user enabling it to contain other types of resources than just default ones.
//      
//      Syntax of addition, erasion, or element access is pretty straightforward and self-explanatory. 
//      If the addition, erasion, or element access failed - the proper exception is thrown. 
//      Exceptions for the default resources are defined in /impl/include/SigmaDev/ResourcesExceptions.h
//      (they are easily found in the Doxygen documentation - under exc:: namespace)
//      
// Additional Notes:
//      (Codedemens, July 26, 2020) Resources.h is mostly finished, but it's untested. I'm working now on
//      implementation of the unit tests, so I can test the logic code correctness
////////////////////////////////////////

#ifndef SD_RESOURCES_H
#define SD_RESOURCES_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SigmaDev/GUI/GUIObject.h>
#include <SigmaDev/Graphics/ExpandableSprite.h>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
/**
 * @brief Standard SFML resource types
 * 
 */
enum SD_ResourceType {
    SD_RESOURCETYPE_UNKNOWN = 0,
    SD_RESOURCETYPE_BLEND_MODE,
    SD_RESOURCETYPE_CIRCLE_SHAPE,
    SD_RESOURCETYPE_COLOR,
    SD_RESOURCETYPE_CONVEX_SHAPE,
    SD_RESOURCETYPE_FONT,
    SD_RESOURCETYPE_IMAGE,
    SD_RESOURCETYPE_RECTANGLE_SHAPE,
    SD_RESOURCETYPE_RENDER_STATES,
    SD_RESOURCETYPE_RENDER_TEXTURE,
    SD_RESOURCETYPE_RENDER_WINDOW,
    SD_RESOURCETYPE_SHADER,
    SD_RESOURCETYPE_SPRITE,
    SD_RESOURCETYPE_TEXT,
    SD_RESOURCETYPE_TEXTURE,
    SD_RESOURCETYPE_VERTEX_ARRAY,
    SD_RESOURCETYPE_MUSIC,
    SD_RESOURCETYPE_SOUND,
    SD_RESOURCETYPE_SOUNDBUFFER
};
/**
 * @brief Standard SFML sf::Drawable resource types
 */
enum SD_DrawableResourceType {
    SD_DRAWABLE_RESOURCETYPE_UNKNOWN = 0,
    SD_DRAWABLE_RESOURCETYPE_CIRCLE_SHAPE,
    SD_DRAWABLE_RESOURCETYPE_CONVEX_SHAPE,
    SD_DRAWABLE_RESOURCETYPE_RECTANGLE_SHAPE,
    SD_DRAWABLE_RESOURCETYPE_SPRITE,
    SD_DRAWABLE_RESOURCETYPE_TEXT,
    SD_DRAWABLE_RESOURCETYPE_VERTEX_ARRAY
};
/**
 * @brief SigmaDev Lib resource types
 */
enum SD_ComplexDrawableResourceType {
    SD_COMPLEX_DRAWABLE_RESOURCETYPE_UNKNOWN = 0,
    SD_COMPLEX_DRAWABLE_RESOURCETYPE_EXPANDABLE_SPRITE
};

class SD_StringPath;
class SD_ExpandableSprite;
class SD_Resources;
class SD_TextureResources;
class SD_ExpandableSpriteGenericCreator;
////////////////////////////////////////


////////////////////////////////////////
/**
 * @brief SD_BlendModeResources is a container class for sf::BlendModes
 */
class SD_BlendModeResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::BlendMode> _container;

    SD_BlendModeResources(SD_Resources& resources_reference);

    virtual void AddBlendMode(const std::string& id, const sf::BlendMode& blend_mode);
    virtual void AddBlendMode(
        const std::string& id, 
        const sf::BlendMode::Factor& source_factor,
        const sf::BlendMode::Factor& dest_factor,
        const sf::BlendMode::Equation& blend_equation = sf::BlendMode::Equation::Add
        );
    virtual void AddBlendMode(
        const std::string& id,
        const sf::BlendMode::Factor& color_source_factor,
        const sf::BlendMode::Factor& color_destination_factor,
        const sf::BlendMode::Equation& color_blend_equation,
        const sf::BlendMode::Factor& alpha_source_factor,
        const sf::BlendMode::Factor& alpha_destination_factor,
        const sf::BlendMode::Equation& alpha_blend_equation
    );
    virtual const sf::BlendMode& GetBlendMode(const std::string& id) const;
    virtual sf::BlendMode& GetBlendMode(const std::string& id);
    virtual void EraseBlendMode(const std::string& id);
    virtual bool BlendModeExists(const std::string& id) const;
    

    inline const _container& GetContainer() const { 
       return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_CircleShapeResources is a container class for sf::CircleShapes
 */
class SD_CircleShapeResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::CircleShape> _container;

    SD_CircleShapeResources(SD_Resources& resources_reference);

    virtual void AddCircleShape(const std::string& id, const sf::CircleShape& circle_shape);
    virtual void AddCircleShape(const std::string& id, float radius = 0, std::size_t point_couint = 30);
    virtual const sf::CircleShape& GetCircleShape(const std::string& id) const;
    virtual sf::CircleShape& GetCircleShape(const std::string& id);
    virtual void EraseCircleShape(const std::string& id);
    virtual bool CircleShapeExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_ColorResources is a container class for sf::Color
 * 
 */
class SD_ColorResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::Color> _container;

    SD_ColorResources(SD_Resources& resources_reference);

    virtual void AddColor(const std::string& id);
    virtual void AddColor(const std::string& id, const sf::Color& color);
    virtual void AddColor(const std::string& id, sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha=255);
    virtual void AddColor(const std::string& id, const sf::Uint32& color);
    virtual const sf::Color& GetColor(const std::string& id) const;
    virtual sf::Color& GetColor(const std::string& id);
    virtual void EraseColor(const std::string& id);
    virtual bool ColorExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_ConvexShapeResources is a container class for sf::ConvexShape 
 * 
 */
class SD_ConvexShapeResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::ConvexShape> _container;

    SD_ConvexShapeResources(SD_Resources& resources_reference);

    virtual void AddConvexShape(const std::string& id, const sf::ConvexShape& convex_shape);
    virtual void AddConvexShape(const std::string& id, const std::size_t& point_count = 0);
    virtual const sf::ConvexShape& GetConvexShape(const std::string& id) const;
    virtual sf::ConvexShape& GetConvexShape(const std::string& id);
    virtual void EraseConvexShape(const std::string& id);
    virtual bool ConvexShapeExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_FontResources is a container class for sf::Font
 */
class SD_FontResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::Font> _container;

    SD_FontResources(SD_Resources& resources_reference);

    virtual void AddFont(const std::string& id, const sf::Font& font);
    virtual bool LoadFont(const std::string& id, const std::string& filepath_to_font);
    virtual bool LoadFont(const std::string& id, const void* data, std::size_t size_in_bytes);
    virtual bool LoadFont(const std::string& id, sf::InputStream& stream);
    virtual const sf::Font& GetFont(const std::string& id) const;
    virtual sf::Font& GetFont(const std::string& id);
    virtual void EraseFont(const std::string& id);
    virtual bool FontExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_ImageResources is a container class for sf::Image
 */
class SD_ImageResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::Image> _container;

    SD_ImageResources(SD_Resources& resources_reference);

    virtual void AddImage(const std::string& id);
    virtual void CreateImage(const std::string& id, unsigned int width, unsigned int height, const sf::Color& color = sf::Color(0,0,0));
    virtual void CreateImage(const std::string& id, unsigned int width, unsigned int height, sf::Uint8* pixels);
    virtual bool LoadImage(const std::string& id, const std::string& filepath_to_image);
    virtual bool LoadImage(const std::string& id, sf::InputStream& input_stream);
    virtual const sf::Image& GetImage(const std::string& id) const;
    virtual sf::Image& GetImage(const std::string& id);
    virtual void EraseImage(const std::string& id);
    virtual bool ImageExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_RectangleShapeResources is a container class for sf::RectangleShape
 */
class SD_RectangleShapeResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::RectangleShape> _container;

    SD_RectangleShapeResources(SD_Resources& resources_reference);

    virtual void AddRectangleShape(const std::string& id);
    virtual void AddRectangleShape(const std::string& id, const sf::RectangleShape& rect_shape);
    virtual void AddRectangleShape(const std::string& id, const sf::Vector2f& size = sf::Vector2f(0,0));
    virtual const sf::RectangleShape& GetRectangleShape(const std::string& id) const;
    virtual sf::RectangleShape& GetRectangleShape(const std::string& id);
    virtual void EraseRectangleShape(const std::string& id);
    virtual bool RectangleShapeExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_RenderStatesResources is a container class for sf::RenderState
 */
class SD_RenderStatesResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::RenderStates> _container;

    SD_RenderStatesResources(SD_Resources& resources_reference);

    virtual void AddRenderStates(const std::string& id);
    virtual void AddRenderStates(const std::string& id, const sf::RenderStates& render_states);
    virtual void AddRenderStates(const std::string& id, const sf::BlendMode& blend_mode);
    virtual void AddRenderStates(const std::string& id, const sf::Transform& trasnform);
    virtual void AddRenderStates(const std::string& id, const sf::Texture* texture);
    virtual void AddRenderStates(const std::string& id, const sf::Shader* shader);
    virtual void AddRenderStates(
        const std::string& id,
        const sf::BlendMode& blend_mode,
        const sf::Transform& transform,
        const sf::Texture* texture,
        const sf::Shader* shader
    );
    virtual const sf::RenderStates& GetRenderStates(const std::string& id) const;
    virtual sf::RenderStates& GetRenderStates(const std::string& id);
    virtual void EraseRenderStates(const std::string& id);
    virtual bool RenderStatesExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////
/**
 * @brief SD_RenderTextureResources is a container class for sf::RenderTexture
 * 
 */
class SD_RenderTextureResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::RenderTexture>> _container;

    SD_RenderTextureResources(SD_Resources& resources_reference);

    virtual void AddRenderTexture(const std::string& id, std::unique_ptr<sf::RenderTexture>&& render_texture);
    virtual bool CreateRenderTexture(const std::string& id, unsigned int width, unsigned int height, const sf::ContextSettings& settings = sf::ContextSettings());
    virtual const std::unique_ptr<sf::RenderTexture>& GetRenderTexture(const std::string& id) const;
    virtual std::unique_ptr<sf::RenderTexture>& GetRenderTexture(const std::string& id);
    virtual void EraseRenderTexture(const std::string& id);
    virtual bool RenderTextureExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_RenderWindowResources is a container class for sf::RenderWindow
 */
class SD_RenderWindowResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::RenderWindow>> _container;

    SD_RenderWindowResources(SD_Resources& resources_reference);

    virtual void AddRenderWindow(const std::string& id, std::unique_ptr<sf::RenderWindow>&& render_window);
    virtual void AddRenderWindow(
        const std::string& id,
        const sf::VideoMode& video_mode,
        const sf::String& title,
        sf::Uint32 style = sf::Style::Default,
        const sf::ContextSettings& settings = sf::ContextSettings()
        );;
    virtual void AddRenderWindow(
        const std::string& id,
        sf::WindowHandle handle,
        const sf::ContextSettings& settings = sf::ContextSettings()
    );
    virtual const std::unique_ptr<sf::RenderWindow>& GetRenderWindow(const std::string& id) const;
    virtual std::unique_ptr<sf::RenderWindow>& GetRenderWindow(const std::string& id);
    virtual void EraseRenderWindow(const std::string& id);
    virtual bool RenderWindowExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_ShaderResources is a container class for sf::Shader
 * 
 */
class SD_ShaderResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::Shader>> _container;

    SD_ShaderResources(SD_Resources& resources_reference);

    virtual void AddShader(const std::string& id);
    virtual bool LoadShader(
        const std::string& id, 
        const std::string& filepath_to_shader, 
        sf::Shader::Type type);
    virtual bool LoadShader(
        const std::string& id,
        const std::string& filepath_to_vertex_shader,
        const std::string& filepath_to_fragment_shader
    );
    virtual bool LoadShader(
        const std::string& id,
        const std::string& filepath_to_vertex_shader,
        const std::string& filepath_to_geometry_shader,
        const std::string& filepath_to_fragment_shader
    );
    virtual bool LoadShaderFromMemory(
        const std::string& id,
        const std::string& shader,
        sf::Shader::Type type
    );
    virtual bool LoadShaderFromMemory(
        const std::string& id,
        const std::string& vertex_shader,
        const std::string& fragment_shader
    );
    virtual bool LoadShaderFromMemory(
        const std::string& id,
        const std::string& vertex_shader,
        const std::string& geometry_shader,
        const std::string& fragment_shader
    );
    virtual bool LoadShaderFromStream(
        const std::string& id,
        sf::InputStream& input_stream,
        sf::Shader::Type type
    );
    virtual bool LoadShaderFromStream(
        const std::string& id,
        sf::InputStream& vertex_shader_input_stream,
        sf::InputStream& fragment_shader_input_stream
    );
    virtual bool LoadShaderFromStream(
        const std::string& id,
        sf::InputStream& vertex_shader_input_stream,
        sf::InputStream& geometry_shader_input_stream,
        sf::InputStream& fragment_shader_input_stream
    );
    virtual const std::unique_ptr<sf::Shader>& GetShader(const std::string& id) const;
    virtual std::unique_ptr<sf::Shader>& GetShader(const std::string& id);
    virtual void EraseShader(const std::string& id);
    virtual bool ShaderExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_SpriteResources is a container class for sf::Sprite
 * 
 */
class SD_SpriteResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::Sprite>> _container;

    SD_SpriteResources(SD_Resources& resources_reference);

    virtual void AddSprite(const std::string& id);
    virtual void AddSprite(const std::string& id, const sf::Texture& texture);
    virtual void AddSprite(const std::string& id, const sf::Texture& texture, const sf::IntRect& rectangle);
    virtual const std::unique_ptr<sf::Sprite>& GetSprite(const std::string& id) const;
    virtual std::unique_ptr<sf::Sprite>& GetSprite(const std::string& id);
    virtual void EraseSprite(const std::string& id);
    virtual bool SpriteExists(const std::string& id) const;

    inline _container& GetContainer() {
        return container;
    }
    inline const _container& GetContainer() const {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_TextResources is a container class for sf::Text
 * 
 */
class SD_TextResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::Text> _container;

    SD_TextResources(SD_Resources& resources_reference);

    virtual void AddText(const std::string& id);
    virtual void AddText(const std::string& id, const sf::Text& text);
    virtual void AddText(const std::string& id, 
        const std::string& text, 
        const sf::Font& font, 
        unsigned int character_Size = 30);

    virtual const sf::Text& GetText(const std::string& id) const;
    virtual sf::Text& GetText(const std::string& id);
    virtual void EraseText(const std::string& id);
    virtual bool TextExists(const std::string& id) const;

    inline _container& GetContainer() {
        return container;
    }
    inline const _container& GetContainer() const {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_TextureResources is a container class for sf::Texture
 * 
 */
class SD_TextureResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::Texture>> _container;

    SD_TextureResources(SD_Resources& resources_reference);

    virtual void AddTexture(const std::string& id);
    virtual void AddTexture(const std::string& id, const sf::Texture& cpy);
    virtual bool CreateTexture(const std::string& id, unsigned int width, unsigned int height);
    virtual bool LoadTexture(
        const std::string& id, 
        const std::string& filepath_to_texture, 
        const sf::IntRect& area = sf::IntRect());
    virtual bool LoadTexture(
        const std::string& id,
        const void* data,
        std::size_t size,
        const sf::IntRect& area = sf::IntRect()
    );
    virtual bool LoadTexture(
        const std::string& id,
        sf::InputStream& imput_stream,
        const sf::IntRect& area = sf::IntRect()
    );
    virtual bool LoadTexture(
        const std::string& id,
        const sf::Image& iamge,
        const sf::IntRect& area = sf::IntRect()
    );
    virtual const std::unique_ptr<sf::Texture>& GetTexture(const std::string& id) const;
    virtual std::unique_ptr<sf::Texture>& GetTexture(const std::string& id);
    virtual void EraseTexture(const std::string& id);
    virtual bool TextureExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_VertexArrayResources is a container class for sf::VertexArray
 * 
 */
class SD_VertexArrayResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::VertexArray> _container;

    SD_VertexArrayResources(SD_Resources& resources_reference);

    virtual void AddVertexArray(const std::string& id);
    virtual void AddVertexArray(const std::string& id, const sf::VertexArray& vertex_array);
    virtual void AddVertexArray(const std::string&  id, sf::PrimitiveType type, std::size_t vertex_count = 0);
    virtual const sf::VertexArray& GetVertexArray(const std::string& id) const;
    virtual sf::VertexArray& GetVertexArray(const std::string& id);
    virtual void EraseVertexArray(const std::string& id);
    virtual bool VertexArrayExists(const std::string& id) const;
 
    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_ExpandableSpriteResources is a container class for SD_ExpandableSprite
 * 
 */
class SD_ExpandableSpriteResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<SD_ExpandableSprite>> _container;

    SD_ExpandableSpriteResources(SD_Resources& resources_reference);

    virtual void AddExpandableSprite(const std::string& id, std::unique_ptr<SD_ExpandableSprite>&& sprite);

    virtual void Load_Nine_ExpandableSprite(const std::string& id,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right);
    virtual void Load_SixTop_ExpandableSprite(const std::string& id,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void Load_SixBottom_ExpandableSprite(const std::string& id,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void Load_SixLeft_ExpandableSprite(const std::string& id,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
    );
    virtual void Load_SixRight_ExpandableSprite(const std::string& id,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void Load_FourTopLeft_ExpandableSprite(const std::string& id,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle
    );
    virtual void Load_FourTopRight_ExpandableSprite(const std::string& id,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void Load_FourBottomLeft_ExpandableSprite(const std::string& id,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
    );
    virtual void Load_FourBottomRight_ExpandableSprite(const std::string& id,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void Load_ThreeHorizontal_ExpandableSprite(const std::string& id,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void Load_ThreeVertical_ExpandableSprite(const std::string& id,
        const sf::Texture& top,
        const sf::Texture& middle,
        const sf::Texture& bottom
    );

    virtual const std::unique_ptr<SD_ExpandableSprite>& GetExpandableSprite(const std::string& id) const ;
    virtual std::unique_ptr<SD_ExpandableSprite>& GetExpandableSprite(const std::string& id);
    virtual void EraseExpandableSprite(const std::string& id);
    virtual bool ExpandableSpriteExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_MusicResources is a container class for sf::Music
 */
class SD_MusicResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<sf::Music>> _container;

    SD_MusicResources(SD_Resources& resources_reference);

    virtual void AddMusic(const std::string& id);
    virtual void AddMusic(const std::string& id, std::unique_ptr<sf::Music>&& music);
    virtual bool LoadMusic(const std::string& id, const std::string& filepath);
    virtual bool LoadMusic(const std::string& id, const void* data, std::size_t size_in_bytes);
    virtual bool LoadMusic(const std::string& id, sf::InputStream& input_stream);
    virtual const std::unique_ptr<sf::Music>& GetMusic(const std::string& id) const;
    virtual std::unique_ptr<sf::Music>& GetMusic(const std::string& id);
    virtual void EraseMusic(const std::string& id);
    virtual bool MusicExists(const std::string& id) const;

     inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_SoundResources is a container class for sf::Sound
 */
class SD_SoundResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::Sound> _container;

    SD_SoundResources(SD_Resources& resources_reference);

    virtual void AddSound(const std::string& id, const sf::Sound& sound);
    virtual void AddSound(const std::string& id, const sf::SoundBuffer& buffer);
    virtual const sf::Sound& GetSound(const std::string& id) const;
    virtual sf::Sound& GetSound(const std::string& id);
    virtual void EraseSound(const std::string& id);
    virtual bool SoundExists(const std::string& id) const;

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////

/**
 * @brief SD_SoundBufferResources is a container class for sf::SoundBuffer
 */
class SD_SoundBufferResources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, sf::SoundBuffer> _container;

    SD_SoundBufferResources(SD_Resources& resources_reference);

    virtual void AddSoundBuffer(const std::string& id, const sf::SoundBuffer& buffer);
    virtual bool LoadSoundBuffer(const std::string& id, const std::string& filepath);
    virtual bool LoadSoundBuffer(const std::string& id, const void* data, std::size_t size_in_bytes);
    virtual bool LoadSoundBuffer(const std::string& id, sf::InputStream& stream);
    virtual bool LoadSoundBuffer(
        const std::string& id, 
        const sf::Int16* samples, 
        sf::Uint64 sample_count,
        unsigned int channel_count,
        unsigned int sample_rate
    );
    virtual bool SaveSoundBuffer(const std::string& id, const std::string& filepath);
    virtual const sf::SoundBuffer& GetSoundBuffer(const std::string& id) const;
    virtual sf::SoundBuffer& GetSoundBuffer(const std::string& id);
    virtual void EraseSoundBuffer(const std::string& id);
    virtual bool SoundBufferExists(const std::string& id) const;
 
    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
    inline const SD_Resources& GetResources() const {
        return resources;
    }
    inline SD_Resources& GetResources() {
        return resources;
    }
protected:
    _container container;
    SD_Resources& resources;
};

////////////////////////////////////////




////////////////////////////////////////

/**
 * @brief SD_Resources is a container class that allows you to store any 
 *        defined by SigmaDev and SFML resources. 
 */
class SD_Resources : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Construct SD_Resources, and connect to SD_Application
     * 
     * @param app SD_Application reference connected to
     */
    SD_Resources(SD_Application& app);

    inline const std::unique_ptr<SD_BlendModeResources>& GetBlendModeResources() const { 
       return blend_modes;
    }
    inline std::unique_ptr<SD_BlendModeResources  >& GetBlendModeResources() {
        return blend_modes;
    }
    inline const std::unique_ptr<SD_CircleShapeResources>& GetCircleShapeResources() const { 
       return circle_shapes;
    }
    inline std::unique_ptr<SD_CircleShapeResources>& GetCircleShapeResources() {
        return circle_shapes;
    }
    inline const std::unique_ptr<SD_ColorResources>& GetColorResources() const { 
       return colors;
    }
    inline std::unique_ptr<SD_ColorResources>& GetColorResources() {
        return colors;
    }
    inline const std::unique_ptr<SD_ConvexShapeResources>& GetConvexShapeResources() const {
        return convex_shapes;
    }
    inline std::unique_ptr<SD_ConvexShapeResources>& GetConvexShapeResources() {
        return convex_shapes;
    }
    inline const std::unique_ptr<SD_FontResources>& GetFontResources() const { 
       return fonts;
    }
    inline std::unique_ptr<SD_FontResources>& GetFontResources() {
        return fonts;
    }
    inline const std::unique_ptr<SD_ImageResources>& GetImageResources() const { 
       return images;
    }
    inline std::unique_ptr<SD_ImageResources>& GetImageResources() {
        return images;
    }
    inline const std::unique_ptr<SD_RectangleShapeResources>& GetRectangleShapeResources() const { 
       return rectangle_shapes;
    }
    inline std::unique_ptr<SD_RectangleShapeResources>& GetRectangleShapeResources() {
        return rectangle_shapes;
    }
    inline const std::unique_ptr<SD_RenderStatesResources>& GetRenderStatesResources() const { 
       return render_states;
    }
    inline std::unique_ptr<SD_RenderStatesResources>& GetRenderStatesResources() {
        return render_states;
    }
    inline const std::unique_ptr<SD_RenderTextureResources>& GetRenderTextureResources() const { 
       return render_textures;
    }
    inline std::unique_ptr<SD_RenderTextureResources>& GetRenderTextureResources() {
        return render_textures;
    }
    inline const std::unique_ptr<SD_RenderWindowResources>& GetRenderWindowResources() const { 
       return render_windows;
    }
    inline std::unique_ptr<SD_RenderWindowResources>& GetRenderWindowResources() {
        return render_windows;
    }
    inline const std::unique_ptr<SD_ShaderResources>& GetShaderResources() const { 
       return shaders;
    }
    inline std::unique_ptr<SD_ShaderResources>& GetShaderResources() {
        return shaders;
    }
    inline const std::unique_ptr<SD_SpriteResources>& GetSpriteResources() const { 
       return sprites;
    }
    inline std::unique_ptr<SD_SpriteResources>& GetSpriteResources() {
        return sprites;
    }
    inline const std::unique_ptr<SD_TextureResources>& GetTextureResources() const { 
       return textures;
    }
    inline std::unique_ptr<SD_TextureResources>& GetTextureResources() {
        return textures;
    }
    inline const std::unique_ptr<SD_TextResources>& GetTextResources() const {
        return text;
    }
    inline std::unique_ptr<SD_TextResources>& GetTextResources() {
        return text;
    }
    inline const std::unique_ptr<SD_VertexArrayResources>& GetVertexArrayResources() const { 
       return vertex_arrays;
    }
    inline std::unique_ptr<SD_VertexArrayResources>& GetVertexArrayResources() {
        return vertex_arrays;
    }
    inline const std::unique_ptr<SD_ExpandableSpriteResources>& GetExpandableSpriteResources() const {
        return expandable_sprites;
    }
    inline std::unique_ptr<SD_ExpandableSpriteResources>& GetExpandableSpriteResources() {
        return expandable_sprites;
    }
    inline const std::unique_ptr<SD_MusicResources>& GetMusicResources() const {
        return musics_resources;
    }
    inline std::unique_ptr<SD_MusicResources>& GetMusicResources() {
        return musics_resources;
    }
    inline const std::unique_ptr<SD_SoundResources>& GetSoundResources() const {
        return sounds_resources;
    }
    inline std::unique_ptr<SD_SoundResources>& GetSoundResources() {
        return sounds_resources;
    }
    inline const std::unique_ptr<SD_SoundBufferResources>& GetSoundBufferResources() const {
        return sound_buffers_resources;
    }
    inline std::unique_ptr<SD_SoundBufferResources>& GetSoundBufferResources() {
        return sound_buffers_resources;
    }


    inline const SD_BlendModeResources& GetBlendModeResourcesRef() const { 
       return *blend_modes.get();
    }
    inline SD_BlendModeResources& GetBlendModeResourcesRef() {
        return *blend_modes.get();
    }
    inline const SD_CircleShapeResources& GetCircleShapeResourcesRef() const { 
       return *circle_shapes.get();
    }
    inline SD_CircleShapeResources& GetCircleShapeResourcesRef() {
        return *circle_shapes.get();
    }
    inline const SD_ColorResources& GetColorResourcesRef() const { 
       return *colors.get();
    }
    inline SD_ColorResources& GetColorResourcesRef() {
        return *colors.get();
    }
    inline const SD_ConvexShapeResources& GetConvexShapeResourcesRef() const {
        return *convex_shapes.get();
    }
    inline SD_ConvexShapeResources& GetConvexShapeResourcesRef() {
        return *convex_shapes.get();
    }
    inline const SD_FontResources& GetFontResourcesRef() const { 
       return *fonts.get();
    }
    inline SD_FontResources& GetFontResourcesRef() {
        return *fonts.get();
    }
    inline const SD_ImageResources& GetImageResourcesRef() const { 
       return *images.get();
    }
    inline SD_ImageResources& GetImageResourcesRef() {
        return *images.get();
    }
    inline const SD_RectangleShapeResources& GetRectangleShapeResourcesRef() const { 
       return *rectangle_shapes.get();
    }
    inline SD_RectangleShapeResources& GetRectangleShapeResourcesRef() {
        return *rectangle_shapes.get();
    }
    inline const SD_RenderStatesResources& GetRenderStatesResourcesRef() const { 
       return *render_states.get();
    }
    inline SD_RenderStatesResources& GetRenderStatesResourcesRef() {
        return *render_states.get();
    }
    inline const SD_RenderTextureResources& GetRenderTextureResourcesRef() const { 
       return *render_textures.get();
    }
    inline SD_RenderTextureResources& GetRenderTextureResourcesRef() {
        return *render_textures.get();
    }
    inline const SD_RenderWindowResources& GetRenderWindowResourcesRef() const { 
       return *render_windows.get();
    }
    inline SD_RenderWindowResources& GetRenderWindowResourcesRef() {
        return *render_windows.get();
    }
    inline const SD_ShaderResources& GetShaderResourcesRef() const { 
       return *shaders.get();
    }
    inline SD_ShaderResources& GetShaderResourcesRef() {
        return *shaders.get();
    }
    inline const SD_SpriteResources& GetSpriteResourcesRef() const { 
       return *sprites.get();
    }
    inline SD_SpriteResources& GetSpriteResourcesRef() {
        return *sprites.get();
    }
    inline const SD_TextureResources& GetTextureResourcesRef() const { 
       return *textures.get();
    }
    inline SD_TextureResources& GetTextureResourcesRef() {
        return *textures.get();
    }
    inline const SD_TextResources& GetTextResourcesRef() const {
        return *text.get();
    }
    inline SD_TextResources& GetTextResourcesRef() {
        return *text.get();
    }
    inline const SD_VertexArrayResources& GetVertexArrayResourcesRef() const { 
       return *vertex_arrays.get();
    }
    inline SD_VertexArrayResources& GetVertexArrayResourcesRef() {
        return *vertex_arrays.get();
    }
    inline const SD_ExpandableSpriteResources& GetExpandableSpriteResourcesRef() const {
        return *expandable_sprites.get();
    }
    inline SD_ExpandableSpriteResources& GetExpandableSpriteResourcesRef() {
        return *expandable_sprites.get();
    }
    inline const SD_MusicResources& GetMusicsResourcesRef() const {
        return *musics_resources.get();
    }
    inline SD_MusicResources& GetMusicsResourcesRef() {
        return *musics_resources.get();
    }
    inline const SD_SoundResources& GetSoundResourcesRef() const {
        return *sounds_resources.get();
    }
    inline SD_SoundResources& GetSoundResourcesRef() {
        return *sounds_resources.get();
    }
    inline const SD_SoundBufferResources& GetSoundBufferResourcesRef() const {
        return *sound_buffers_resources.get();
    }
    inline SD_SoundBufferResources& GetSoundBufferResourcesRef() {
        return *sound_buffers_resources.get();
    }


    inline const SD_Application& GetApplicationRef() const {
        return application;
    }
    inline SD_Application& GetApplicationRef() {
        return application;
    }
protected:
    virtual void InitResources();

    std::unique_ptr<SD_BlendModeResources> blend_modes;
    std::unique_ptr<SD_CircleShapeResources> circle_shapes;
    std::unique_ptr<SD_ColorResources> colors;
    std::unique_ptr<SD_ConvexShapeResources> convex_shapes;
    std::unique_ptr<SD_FontResources> fonts;
    std::unique_ptr<SD_ImageResources> images;
    std::unique_ptr<SD_RectangleShapeResources> rectangle_shapes;
    std::unique_ptr<SD_RenderStatesResources> render_states;
    std::unique_ptr<SD_RenderTextureResources> render_textures;
    std::unique_ptr<SD_RenderWindowResources> render_windows;
    std::unique_ptr<SD_ShaderResources> shaders;
    std::unique_ptr<SD_SpriteResources> sprites;
    std::unique_ptr<SD_TextureResources> textures;
    std::unique_ptr<SD_TextResources> text;
    std::unique_ptr<SD_VertexArrayResources> vertex_arrays;
    std::unique_ptr<SD_ExpandableSpriteResources> expandable_sprites;

    std::unique_ptr<SD_MusicResources> musics_resources;
    std::unique_ptr<SD_SoundResources> sounds_resources;
    std::unique_ptr<SD_SoundBufferResources> sound_buffers_resources;



    SD_Application& application;
};

/**
 * @var SD_Resources::application
 * @brief SD_Application reference connected to 
 * 
 */

////////////////////////////////////////

#endif

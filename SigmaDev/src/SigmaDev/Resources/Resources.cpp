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
// File: /impl/src/SigmaDev/Resources.cpp
// Description:
//      Resources.cpp contains definitions for the Resources.h declarations.
//      
// Additional Notes:
//      (Codedemens, July 26, 2020) Resources.cpp is mostly finished, but it's untested. I'm working now on
//      implementation of the unit tests, so I can test the logic code correctness
////////////////////////////////////////

#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Exception/ResourcesExceptions.h>
#include <SigmaDev/Exception/GUIExceptions.h>
#include <SigmaDev/Graphics/ExpandableSprite.h>

////////////////////////////////////////
#include <SigmaDev/Graphics/SigmaDevDefaultTextures.h>

////////////////////////////////////////

////////////////////////////////////////


SD_DECLARE_CLASS_CPP(SD_BlendModeResources)

SD_BlendModeResources::SD_BlendModeResources(SD_Resources& resources) : resources(resources) {

}

void SD_BlendModeResources::AddBlendMode(const std::string& id, const sf::BlendMode& blend_mode) {
    auto insert_pair = container.insert(std::make_pair(id, blend_mode));
    if (insert_pair.second == false) {
        auto e = exc::SD_BlendModeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_BlendModeResources::AddBlendMode(
    const std::string& id,
    const sf::BlendMode::Factor& source_factor,
    const sf::BlendMode::Factor& dest_fact,
    const sf::BlendMode::Equation& blend_equation
) {
    auto insert_pair = container.insert(std::make_pair(id, sf::BlendMode(source_factor, dest_fact, blend_equation)));
    if (insert_pair.second == false) {
        auto e = exc::SD_BlendModeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_BlendModeResources::AddBlendMode(
    const std::string& id,
    const sf::BlendMode::Factor& color_source_factor,
    const sf::BlendMode::Factor& color_destination_factor,
    const sf::BlendMode::Equation& color_blend_equation,
    const sf::BlendMode::Factor& alpha_source_factor,
    const sf::BlendMode::Factor& alpha_destination_factor,
    const sf::BlendMode::Equation& alpha_blend_equation
) {
    auto insert_pair = container.insert(std::make_pair(id, sf::BlendMode(color_source_factor, color_destination_factor, color_blend_equation, alpha_source_factor, alpha_destination_factor, alpha_blend_equation)));
    if (insert_pair.second == false) {
        auto e = exc::SD_BlendModeResourceInsertionFailed(id);
        throw e;
    }
}
const sf::BlendMode& SD_BlendModeResources::GetBlendMode(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_BlendModeResourceNotFound(id);
        throw e;
    }
}
sf::BlendMode& SD_BlendModeResources::GetBlendMode(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_BlendModeResourceNotFound(id);
        throw e;
    }
}
void SD_BlendModeResources::EraseBlendMode(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_BlendModeResourceErasionFailed(id);
        throw e;
    }
}
bool SD_BlendModeResources::BlendModeExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_CircleShapeResources)


SD_CircleShapeResources::SD_CircleShapeResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_CircleShapeResources::AddCircleShape(const std::string& id, const sf::CircleShape& circle_shape) {
    auto insert_pair = container.insert(std::make_pair(id, circle_shape));
    if (insert_pair.second == false) {
        auto e = exc::SD_CircleShapeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_CircleShapeResources::AddCircleShape(const std::string& id, float radius, std::size_t point_count) {
    auto insert_pair = container.insert(std::make_pair(id, sf::CircleShape(radius, point_count)));
    if (insert_pair.second == false) {
        auto e = exc::SD_CircleShapeResourceInsertionFailed(id);
        throw e;
    }
}
const sf::CircleShape& SD_CircleShapeResources::GetCircleShape(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_CircleShapeResourceNotFound(id);
        throw e;
    }
}
sf::CircleShape& SD_CircleShapeResources::GetCircleShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_CircleShapeResourceNotFound(id);
        throw e;
    }
}
void SD_CircleShapeResources::EraseCircleShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_CircleShapeResourceErasionFailed(id);
        throw e;
    }
}
bool SD_CircleShapeResources::CircleShapeExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_ColorResources)

SD_ColorResources::SD_ColorResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_ColorResources::AddColor(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Color()));
    if (insert_pair.second == false ){
        auto e = exc::SD_ColorResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ColorResources::AddColor(const std::string& id, const sf::Color& color) {
    auto insert_pair = container.insert(std::make_pair(id, color));
    if (insert_pair.second == false) {
        auto e = exc::SD_ColorResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ColorResources::AddColor(const std::string& id, sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Color(red,green,blue,alpha)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ColorResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ColorResources::AddColor(const std::string& id, const sf::Uint32& color) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Color(color)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ColorResourceInsertionFailed(id);
        throw e;
    }
}
const sf::Color& SD_ColorResources::GetColor(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ColorResourceNotFound(id);
        throw e;
    }
}
sf::Color& SD_ColorResources::GetColor(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ColorResourceNotFound(id);
        throw e;
    }
}
void SD_ColorResources::EraseColor(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_ColorResourceErasionFailed(id);
        throw e;
    }
}
bool SD_ColorResources::ColorExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_ConvexShapeResources)

SD_ConvexShapeResources::SD_ConvexShapeResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_ConvexShapeResources::AddConvexShape(const std::string& id, const sf::ConvexShape& convex_shape) {
    auto insert_pair = container.insert(std::make_pair(id, convex_shape));
    if (insert_pair.second == false) {
        auto e = exc::SD_ConvexShapeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ConvexShapeResources::AddConvexShape(const std::string& id, const std::size_t& point_count) {
    auto insert_pair = container.insert(std::make_pair(id, sf::ConvexShape(point_count)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ConvexShapeResourceInsertionFailed(id);
        throw e;
    }
}
const sf::ConvexShape& SD_ConvexShapeResources::GetConvexShape(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ConvexShapeResourceNotFound(id);
        throw e;
    }
}
sf::ConvexShape& SD_ConvexShapeResources::GetConvexShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ConvexShapeResourceNotFound(id);
        throw e;
    }
}
void SD_ConvexShapeResources::EraseConvexShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_ConvexShapeResourceErasionFailed(id);
        throw e;
    }
}
bool SD_ConvexShapeResources::ConvexShapeExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else {
        return false;
    }
}

SD_DECLARE_CLASS_CPP(SD_FontResources)

SD_FontResources::SD_FontResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_FontResources::AddFont(const std::string& id, const sf::Font& font) {
    auto insert_pair = container.insert(std::make_pair(id, font));
    if (insert_pair.second == false) {
        auto e = exc::SD_FontResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_FontResources::LoadFont(const std::string& id, const std::string& filepath_to_font) {
    sf::Font font;
    bool success = font.loadFromFile(filepath_to_font);
    auto insert_pair = container.insert(std::make_pair(id, font));
    if (insert_pair.second == false) {
        auto e = exc::SD_FontResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_FontResources::LoadFont(const std::string& id, const void* data, std::size_t size_in_bytes) {
    sf::Font font;
    bool success = font.loadFromMemory(data, size_in_bytes);
    auto insert_pair = container.insert(std::make_pair(id, font));
    if (insert_pair.second == false) {
        auto e = exc::SD_FontResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_FontResources::LoadFont(const std::string& id, sf::InputStream& stream ){
    sf::Font font;
    bool success = font.loadFromStream(stream);
    auto insert_pair = container.insert(std::make_pair(id, font));
    if (insert_pair.second == false) {
        auto e = exc::SD_FontResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
const sf::Font& SD_FontResources::GetFont(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_FontResourceNotFound(id);
        throw e;
    }
}
sf::Font& SD_FontResources::GetFont(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_FontResourceNotFound(id);
        throw e;
    }
}
void SD_FontResources::EraseFont(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_FontResourceErasionFailed(id);
        throw e;
    }
}
bool SD_FontResources::FontExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_ImageResources)

SD_ImageResources::SD_ImageResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_ImageResources::AddImage(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Image()));
    if (insert_pair.second == false) {
        auto e = exc::SD_ImageResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ImageResources::CreateImage(const std::string& id, unsigned int width, unsigned int height, const sf::Color& color) {
    sf::Image image;
    image.create(width, height, color);
    auto insert_pair = container.insert(std::make_pair(id, image));
    if (insert_pair.second == false) {
        auto e = exc::SD_ImageResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ImageResources::CreateImage(const std::string& id, unsigned int width, unsigned int height, sf::Uint8* pixels) {
    sf::Image image;
    image.create(width, height, pixels);
    auto insert_pair = container.insert(std::make_pair(id, image));
    if (insert_pair.second == false) {
        auto e = exc::SD_ImageResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_ImageResources::LoadImage(const std::string& id, const std::string& filepath_to_image) {
    sf::Image image;
    bool success = image.loadFromFile(filepath_to_image);
    auto insert_pair = container.insert(std::make_pair(id, image));
    if (insert_pair.second == false) {
        auto e = exc::SD_ImageResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ImageResources::LoadImage(const std::string& id, sf::InputStream& input_stream) {
    sf::Image image;
    bool success = image.loadFromStream(input_stream);
    auto insert_pair = container.insert(std::make_pair(id,image));
    if (insert_pair.second == false) {
        auto e = exc::SD_ImageResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
const sf::Image& SD_ImageResources::GetImage(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ImageResourceNotFound(id);
        throw e;
    }
}
sf::Image& SD_ImageResources::GetImage(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ImageResourceNotFound(id);
        throw e;
    }
}
void SD_ImageResources::EraseImage(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_ImageResourceErasionFailed(id);
        throw e;
    }
}
bool SD_ImageResources::ImageExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_RectangleShapeResources)

SD_RectangleShapeResources::SD_RectangleShapeResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_RectangleShapeResources::AddRectangleShape(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RectangleShape()));
    if (insert_pair.second == false) {
        auto e = exc::SD_RectangleShapeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RectangleShapeResources::AddRectangleShape(const std::string& id, const sf::RectangleShape& rect_shape) {
    auto insert_pair = container.insert(std::make_pair(id, rect_shape));
    if (insert_pair.second == false) {
        auto e = exc::SD_RectangleShapeResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RectangleShapeResources::AddRectangleShape(const std::string& id, const sf::Vector2f& size) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RectangleShape(size)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RectangleShapeResourceInsertionFailed(id);
        throw e;
    }    
}
const sf::RectangleShape& SD_RectangleShapeResources::GetRectangleShape(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RectangleShapeResourceNotFound(id);
        throw e;
    }
}
sf::RectangleShape& SD_RectangleShapeResources::GetRectangleShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RectangleShapeResourceNotFound(id);
        throw e;
    }
}
void SD_RectangleShapeResources::EraseRectangleShape(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_RectangleShapeResourceErasionFailed(id);
        throw e;
    }
}
bool SD_RectangleShapeResources::RectangleShapeExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_RenderStatesResources)

SD_RenderStatesResources::SD_RenderStatesResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_RenderStatesResources::AddRenderStates(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RenderStates()));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(const std::string& id, const sf::RenderStates& render_states) {
    auto insert_pair = container.insert(std::make_pair(id, render_states));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(const std::string& id, const sf::BlendMode& blend_mode) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RenderStates(blend_mode)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(const std::string& id, const sf::Transform& transform) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RenderStates(transform)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(const std::string& id, const sf::Texture* texture) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RenderStates(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(const std::string& id, const sf::Shader* shader) {
    auto insert_pair = container.insert(std::make_pair(id, sf::RenderStates(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderStatesResources::AddRenderStates(
    const std::string& id,
    const sf::BlendMode& blend_mode,
    const sf::Transform& transform,
    const sf::Texture* texture,
    const sf::Shader* shader
) {
    auto insert_pair = container.insert(
        std::make_pair(
            id, 
            sf::RenderStates(blend_mode,transform,texture,shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderStatesResourceInsertionFailed(id);
        throw e;
    }
}
const sf::RenderStates& SD_RenderStatesResources::GetRenderStates(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderStatesResourceNotFound(id);
        throw e;
    }
}
sf::RenderStates& SD_RenderStatesResources::GetRenderStates(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderStatesResourceNotFound(id);
        throw e;
    }
}
void SD_RenderStatesResources::EraseRenderStates(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_RenderStatesResourceErasionFailed(id);
        throw e;
    }
}
bool SD_RenderStatesResources::RenderStatesExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_RenderTextureResources)

SD_RenderTextureResources::SD_RenderTextureResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_RenderTextureResources::AddRenderTexture(const std::string& id, std::unique_ptr<sf::RenderTexture>&& render_texture) {
    auto insert_pair = container.insert(std::make_pair(id, std::move(render_texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderTextureResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_RenderTextureResources::CreateRenderTexture(const std::string& id, unsigned int width, unsigned int height, const sf::ContextSettings& settings) {
    std::unique_ptr<sf::RenderTexture> render_texture = std::make_unique<sf::RenderTexture>();
    bool success = render_texture->create(width, height, settings);
    auto insert_pair = container.insert(std::make_pair(id, std::move(render_texture )));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderTextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
const std::unique_ptr<sf::RenderTexture>& SD_RenderTextureResources::GetRenderTexture(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderTextureResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::RenderTexture>& SD_RenderTextureResources::GetRenderTexture(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderTextureResourceNotFound(id);
        throw e;
    }
}
void SD_RenderTextureResources::EraseRenderTexture(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_RenderTextureResourceErasionFailed(id);
        throw e;
    }
}
bool SD_RenderTextureResources::RenderTextureExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_RenderWindowResources)

SD_RenderWindowResources::SD_RenderWindowResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_RenderWindowResources::AddRenderWindow(const std::string& id, std::unique_ptr<sf::RenderWindow>&& render_window) {
    auto insert_pair = container.insert(std::make_pair(id, std::move(render_window)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderWindowResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderWindowResources::AddRenderWindow(
    const std::string& id,
    const sf::VideoMode& video_mode,
    const sf::String& title,
    sf::Uint32 style,
    const sf::ContextSettings& settings
) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::RenderWindow>(video_mode, title, style, settings)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderWindowResourceInsertionFailed(id);
        throw e;
    }
}
void SD_RenderWindowResources::AddRenderWindow(
    const std::string& id,
    sf::WindowHandle handle,
    const sf::ContextSettings& settings
) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::RenderWindow>(handle, settings)));
    if (insert_pair.second == false) {
        auto e = exc::SD_RenderWindowResourceInsertionFailed(id);
        throw e;
    }
}
const std::unique_ptr<sf::RenderWindow>& SD_RenderWindowResources::GetRenderWindow(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderWindowResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::RenderWindow>& SD_RenderWindowResources::GetRenderWindow(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_RenderWindowResourceNotFound(id);
        throw e;
    }
}
void SD_RenderWindowResources::EraseRenderWindow(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_RenderWindowResourceErasionFailed(id);
        throw e;
    }
}
bool SD_RenderWindowResources::RenderWindowExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_ShaderResources)

SD_ShaderResources::SD_ShaderResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_ShaderResources::AddShader(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Shader>()));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_ShaderResources::LoadShader(
    const std::string& id,
    const std::string& filepath_to_shader,
    sf::Shader::Type type
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromFile(filepath_to_shader, type);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShader(
    const std::string& id,
    const std::string& filepath_to_vertex_shader,
    const std::string& filepath_to_fragment_shader
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromFile(filepath_to_vertex_shader, filepath_to_fragment_shader);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) 
    {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShader(
    const std::string& id,
    const std::string& filepath_to_vertex_shader,
    const std::string& filepath_to_geometry_shader,
    const std::string& filepath_to_fragment_shader
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromFile(filepath_to_vertex_shader, filepath_to_geometry_shader,filepath_to_fragment_shader);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromMemory(
    const std::string& id,
    const std::string& shader_,
    sf::Shader::Type type 
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromMemory(shader_, type);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromMemory(
    const std::string& id,
    const std::string& vertex_shader,
    const std::string& fragment_shader
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromMemory(vertex_shader, fragment_shader);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromMemory(
    const std::string& id,
    const std::string& vertex_shader,
    const std::string& geometry_shader,
    const std::string& fragment_shader
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromMemory(vertex_shader, geometry_shader, fragment_shader);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromStream(
    const std::string& id,
    sf::InputStream& input_stream,
    sf::Shader::Type type
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromStream(input_stream,type);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second ==false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromStream(
    const std::string& id,
    sf::InputStream& vertex_shader_input_stream,
    sf::InputStream& fragment_shader_input_stream
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromStream(vertex_shader_input_stream, fragment_shader_input_stream);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_ShaderResources::LoadShaderFromStream(
    const std::string& id,
    sf::InputStream& vertex_shader_input_stream,
    sf::InputStream& geometry_shader_input_stream,
    sf::InputStream& fragment_shader_input_stream
) {
    std::unique_ptr<sf::Shader> shader = std::make_unique<sf::Shader>();
    bool success = shader->loadFromStream(vertex_shader_input_stream, geometry_shader_input_stream, fragment_shader_input_stream);
    auto insert_pair = container.insert(std::make_pair(id, std::move(shader)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ShaderResourceInsertionFailed(id);
        throw e;
    } else {
        return success; 
    }
}
const std::unique_ptr<sf::Shader>& SD_ShaderResources::GetShader(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ShaderResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::Shader>& SD_ShaderResources::GetShader(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ShaderResourceNotFound(id);
        throw e;
    }
}
void SD_ShaderResources::EraseShader(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_ShaderResourceErasionFailed(id);
        throw e;
    }
}
bool SD_ShaderResources::ShaderExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_SpriteResources)

SD_SpriteResources::SD_SpriteResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_SpriteResources::AddSprite(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Sprite>()));
    if (insert_pair.second == false) {
        auto e = exc::SD_SpriteResourceInsertionFailed(id);
        throw e;
    }
}
void SD_SpriteResources::AddSprite(const std::string& id, const sf::Texture& texture) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Sprite>(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_SpriteResourceInsertionFailed(id);
        throw e;
    }
}
void SD_SpriteResources::AddSprite(const std::string& id, const sf::Texture& texture, const sf::IntRect& rectangle) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Sprite>(texture, rectangle)));
    if (insert_pair.second == false) {
        auto e = exc::SD_SpriteResourceInsertionFailed(id);
        throw e;
    }
}
const std::unique_ptr<sf::Sprite>& SD_SpriteResources::GetSprite(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SpriteResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::Sprite>& SD_SpriteResources::GetSprite(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SpriteResourceNotFound(id);
        throw e;
    }
}
void SD_SpriteResources::EraseSprite(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_SpriteResourceErasionFailed(id);
        throw e;
    }
}
bool SD_SpriteResources::SpriteExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_TextResources)

SD_TextResources::SD_TextResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_TextResources::AddText(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Text()));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextResourceInsertionFailed(id);
        throw e;
    }
}
void SD_TextResources::AddText(const std::string& id, const sf::Text& text) {
    auto insert_pair = container.insert(std::make_pair(id, text));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextResourceInsertionFailed(id);
        throw e;
    }
}
void SD_TextResources::AddText(
    const std::string& id,
    const std::string& text,
    const sf::Font& font,
    unsigned int character_size
) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Text(text, font, character_size)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextResourceInsertionFailed(id);
        throw e;
    }
}
const sf::Text& SD_TextResources::GetText(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TextResourceNotFound(id);
        throw e;
    }
}
sf::Text& SD_TextResources::GetText(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
         return it->second;
    } else {
        auto e = exc::SD_TextResourceNotFound(id);
        throw e;
    }
}
void SD_TextResources::EraseText(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_TextResourceErasionFailed(id);
        throw e;
    }
}
bool SD_TextResources::TextExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) return true;
    else return false;
}


SD_DECLARE_CLASS_CPP(SD_TextureResources)

SD_TextureResources::SD_TextureResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_TextureResources::AddTexture(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Texture>()));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    }
}
void SD_TextureResources::AddTexture(const std::string& id, const sf::Texture& cpy) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Texture>(cpy)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_TextureResources::CreateTexture(const std::string& id, unsigned int width, unsigned int height) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    bool success = texture->create(width,height);
    auto insert_pair = container.insert(std::make_pair(id, std::move(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_TextureResources::LoadTexture(
    const std::string& id,
    const std::string& filepath_to_texture,
    const sf::IntRect& area
) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    bool success = texture->loadFromFile(filepath_to_texture, area);
    auto insert_pair = container.insert(std::make_pair(id, std::move(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_TextureResources::LoadTexture(
    const std::string& id,
    const void* data,
    std::size_t size,
    const sf::IntRect& area
) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    bool success = texture->loadFromMemory(data, size, area);
    auto insert_pair = container.insert(std::make_pair(id, std::move(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success; 
    }
}
bool SD_TextureResources::LoadTexture(
    const std::string& id,
    sf::InputStream& input_stream,
    const sf::IntRect& area
) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    bool success = texture->loadFromStream(input_stream, area);
    auto insert_pair = container.insert(std::make_pair(id, std::move(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
bool SD_TextureResources::LoadTexture(
    const std::string& id,
    const sf::Image& image,
    const sf::IntRect& area
) {
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    bool success = texture->loadFromImage(image, area);
    auto insert_pair = container.insert(std::make_pair(id, std::move(texture)));
    if (insert_pair.second == false) {
        auto e = exc::SD_TextureResourceInsertionFailed(id);
        throw e;
    } else {
        return success;
    }
}
const std::unique_ptr<sf::Texture>& SD_TextureResources::GetTexture(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TextureResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::Texture>& SD_TextureResources::GetTexture(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TextureResourceNotFound(id);
        throw e;
    }
}
void SD_TextureResources::EraseTexture(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_TextureResourceErasionFailed(id);
        throw e;
    }
}
bool SD_TextureResources::TextureExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else {
        return false;
    }
}



SD_DECLARE_CLASS_CPP(SD_VertexArrayResources)

SD_VertexArrayResources::SD_VertexArrayResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_VertexArrayResources::AddVertexArray(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, sf::VertexArray()));
    if (insert_pair.second == false) {
        auto e = exc::SD_VertexArrayResourceInsertionFailed(id);
        throw e;
    }
}
void SD_VertexArrayResources::AddVertexArray(const std::string& id, const sf::VertexArray& vertex_array) {
    auto insert_pair = container.insert(std::make_pair(id, vertex_array));
    if (insert_pair.second == false) {
        auto e = exc::SD_VertexArrayResourceInsertionFailed(id);
        throw e;
    }
}
void SD_VertexArrayResources::AddVertexArray(const std::string& id, sf::PrimitiveType type, std::size_t vertex_count) {
    auto insert_pair = container.insert(std::make_pair(id, sf::VertexArray(type, vertex_count)));
    if (insert_pair.second == false) {
        auto e = exc::SD_VertexArrayResourceInsertionFailed(id);
        throw e;
    }
}
const sf::VertexArray& SD_VertexArrayResources::GetVertexArray(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_VertexArrayResourceNotFound(id);
        throw e;
    }
}
sf::VertexArray& SD_VertexArrayResources::GetVertexArray(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_VertexArrayResourceNotFound(id);
        throw e;
    }
}
void SD_VertexArrayResources::EraseVertexArray(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_VertexArrayResourceErasionFailed(id);
        throw e;
    }
}
bool SD_VertexArrayResources::VertexArrayExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true; 
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_ExpandableSpriteResources)

SD_ExpandableSpriteResources::SD_ExpandableSpriteResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_ExpandableSpriteResources::AddExpandableSprite(
    const std::string& id,
    std::unique_ptr<SD_ExpandableSprite>&& sprite
) {
    auto insert_pair = container.insert(std::make_pair(id, std::move(sprite)));
    if (insert_pair.second == false) {
        auto e = exc::SD_ExpandableSpriteResourceInsertionFailed(id);
        throw e;
    }
}
void SD_ExpandableSpriteResources::Load_Nine_ExpandableSprite(
    const std::string& id,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>(
    );
    expandable_sprite->InitializeAsNine(
        top_left,
        top,
        top_right,
        left,
        middle,
        right,
        bottom_left,
        bottom,
        bottom_right
    );
    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_SixTop_ExpandableSprite(const std::string& id,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeAsSixTop(
        top_left,
        top,
        top_right,
        left,
        middle,
        right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_SixBottom_ExpandableSprite(const std::string& id,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeAsSixBottom(
        left,
        middle,
        right,
        bottom_left,
        bottom,
        bottom_right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_SixLeft_ExpandableSprite(const std::string& id,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeAsSixLeft(
        top_left,
        top,
        left,
        middle,
        bottom_left,
        bottom
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_SixRight_ExpandableSprite(const std::string& id,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeAsSixRight(
        top,
        top_right,
        middle,
        right,
        bottom,
        bottom_right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_FourTopLeft_ExpandableSprite(const std::string& id,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& left,
    const sf::Texture& middle
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeFourTopLeft(
        top_left,
        top,
        left,
        middle
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_FourTopRight_ExpandableSprite(const std::string& id,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& middle,
    const sf::Texture& right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeFourTopRight(
        top,
        top_right,
        middle,
        right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_FourBottomLeft_ExpandableSprite(const std::string& id,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeFourBottomLeft(
        left,
        middle,
        bottom_left,
        bottom
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_FourBottomRight_ExpandableSprite(const std::string& id,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeFourBottomRight(
        middle,
        right,
        bottom,
        bottom_right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_ThreeHorizontal_ExpandableSprite(const std::string& id,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeHorizontal(
        left,
        middle,
        right
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}
void SD_ExpandableSpriteResources::Load_ThreeVertical_ExpandableSprite(const std::string& id,
    const sf::Texture& top,
    const sf::Texture& middle,
    const sf::Texture& bottom
) {
    std::unique_ptr<SD_ExpandableSprite> expandable_sprite = std::make_unique<SD_ExpandableSprite>();

    expandable_sprite->InitializeVertical(
        top,
        middle,
        bottom
    );

    AddExpandableSprite(id, std::move(expandable_sprite));
}

const std::unique_ptr<SD_ExpandableSprite>& SD_ExpandableSpriteResources::GetExpandableSprite(
    const std::string& id
) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ExpandableSpriteResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<SD_ExpandableSprite>& SD_ExpandableSpriteResources::GetExpandableSprite(
    const std::string& id
) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_ExpandableSpriteResourceNotFound(id);
        throw e;
    }
} 
void SD_ExpandableSpriteResources::EraseExpandableSprite(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);         
    } else {
        auto e = exc::SD_ExpandableSpriteResourceErasionFailed(id);
        throw e;
    }
}
bool SD_ExpandableSpriteResources::ExpandableSpriteExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_MusicResources)

SD_MusicResources::SD_MusicResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_MusicResources::AddMusic(const std::string& id) {
    auto insert_pair = container.insert(std::make_pair(id, std::make_unique<sf::Music>()));
    
    if (insert_pair.second == false) {
        auto e = exc::SD_MusicResourceInsertionFailed(id);
        throw e;
    }
}
void SD_MusicResources::AddMusic(const std::string& id, std::unique_ptr<sf::Music>&& music) {
    auto insert_pair = container.insert(std::make_pair(id, std::move(music)));
    if (insert_pair.second == false) {
        auto e = exc::SD_MusicResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_MusicResources::LoadMusic(const std::string& id, const std::string& filepath) {
    std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
    bool success = music->openFromFile(filepath);
    AddMusic(id, std::move(music));
    return success;
}
bool SD_MusicResources::LoadMusic(const std::string& id, const void* data, std::size_t size_in_bytes) {
    std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
    bool success = music->openFromMemory(data, size_in_bytes);
    AddMusic(id, std::move(music));
    return success;
}
bool SD_MusicResources::LoadMusic(const std::string& id, sf::InputStream& input_stream) {
    std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
    bool success =music->openFromStream(input_stream);
    AddMusic(id, std::move(music));
    return success;
}
const std::unique_ptr<sf::Music>& SD_MusicResources::GetMusic(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_MusicResourceNotFound(id);
        throw e;
    }
}
std::unique_ptr<sf::Music>& SD_MusicResources::GetMusic(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_MusicResourceNotFound(id);
        throw e;
    }
}
void SD_MusicResources::EraseMusic(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_MusicResourceErasionFailed(id);
    }
}
bool SD_MusicResources::MusicExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}


SD_DECLARE_CLASS_CPP(SD_SoundResources)

SD_SoundResources::SD_SoundResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_SoundResources::AddSound(const std::string& id, const sf::Sound& sound) {
    auto insert_pair = container.insert(std::make_pair(id, sound));
    if (insert_pair.second == false) {
        auto e = exc::SD_SoundResourceInsertionFailed(id);
        throw e;
    }
}
void SD_SoundResources::AddSound(const std::string& id, const sf::SoundBuffer& buffer) {
    auto insert_pair = container.insert(std::make_pair(id, sf::Sound(buffer)));
    if (insert_pair.second == false) {
        auto e = exc::SD_SoundResourceInsertionFailed(id);
        throw e;
    }
}
const sf::Sound& SD_SoundResources::GetSound(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SoundResourceNotFound(id);
        throw e;
    }
}
sf::Sound& SD_SoundResources::GetSound(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SoundResourceNotFound(id);
        throw e;
    }
}
void SD_SoundResources::EraseSound(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e = exc::SD_SoundResourceErasionFailed(id);
        throw e;
    }
}
bool SD_SoundResources::SoundExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}

SD_DECLARE_CLASS_CPP(SD_SoundBufferResources)

SD_SoundBufferResources::SD_SoundBufferResources(SD_Resources& resources) : resources(resources) {
    
}

void SD_SoundBufferResources::AddSoundBuffer(const std::string& id, const sf::SoundBuffer& buffer) {
    auto insert_pair = container.insert(std::make_pair(id, buffer));
    if (insert_pair.second == false) {
        auto e = exc::SD_SoundBufferResourceInsertionFailed(id);
        throw e;
    }
}
bool SD_SoundBufferResources::LoadSoundBuffer(const std::string& id, const std::string& filepath) {
    sf::SoundBuffer buffer;
    bool success =buffer.loadFromFile(filepath);
    AddSoundBuffer(id,buffer);
    return success;
}
bool SD_SoundBufferResources::LoadSoundBuffer(const std::string& id, const void* data, std::size_t size_in_bytes) {
    sf::SoundBuffer buffer;
    bool success = buffer.loadFromMemory(data, size_in_bytes);
    AddSoundBuffer(id,buffer);
    return success;
}
bool SD_SoundBufferResources::LoadSoundBuffer(const std::string& id, sf::InputStream& stream) {
    sf::SoundBuffer buffer;
    bool success = buffer.loadFromStream(stream);
    AddSoundBuffer(id, buffer);
    return success;
}
bool SD_SoundBufferResources::LoadSoundBuffer(
    const std::string& id, 
    const sf::Int16* samples, 
    sf::Uint64 sample_count,
    unsigned int channel_count,
    unsigned int sample_rate
) {
    sf::SoundBuffer buffer;
    bool success = buffer.loadFromSamples(samples, sample_count, channel_count, sample_rate);
    AddSoundBuffer(id, buffer);
    return success;
}
bool SD_SoundBufferResources::SaveSoundBuffer(const std::string& id, const std::string& filepath) {
    try {
        const sf::SoundBuffer& buffer = GetSoundBuffer(id);
        bool success = buffer.saveToFile(filepath);
        return success; 
    } catch (...) {
        std::throw_with_nested(exc::SD_SoundBufferResourceSaveFailed(id));
    }
}
const sf::SoundBuffer& SD_SoundBufferResources::GetSoundBuffer(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SoundBufferResourceNotFound(id);
        throw e;
    }
}
sf::SoundBuffer& SD_SoundBufferResources::GetSoundBuffer(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        return it->second;
    } else {
        auto e = exc::SD_SoundBufferResourceNotFound(id);
        throw e;
    }
}
void SD_SoundBufferResources::EraseSoundBuffer(const std::string& id) {
    auto it = container.find(id);
    if (it != container.end()) {
        container.erase(it);
    } else {
        auto e =exc::SD_SoundBufferResourceErasionFailed(id);
        throw e;
    }
}
bool SD_SoundBufferResources::SoundBufferExists(const std::string& id) const {
    auto it = container.find(id);
    if (it != container.end()) {
        return true;
    } else return false;
}
////////////////////////////////////////

//////////////////////////////////////// 
SD_DECLARE_CLASS_CPP(SD_Resources)

SD_Resources::SD_Resources(SD_Application& application) : application(application) {
    InitResources();
}
void SD_Resources::InitResources() {
    blend_modes = std::make_unique<SD_BlendModeResources>(*this);
    circle_shapes = std::make_unique<SD_CircleShapeResources>(*this);
    colors = std::make_unique<SD_ColorResources>(*this);
    convex_shapes = std::make_unique<SD_ConvexShapeResources>(*this);
    fonts = std::make_unique<SD_FontResources>(*this);
    images = std::make_unique<SD_ImageResources>(*this);
    rectangle_shapes = std::make_unique<SD_RectangleShapeResources>(*this);
    render_states = std::make_unique<SD_RenderStatesResources>(*this);
    render_textures = std::make_unique<SD_RenderTextureResources>(*this);
    render_windows = std::make_unique<SD_RenderWindowResources>(*this);
    shaders = std::make_unique<SD_ShaderResources>(*this);
    sprites = std::make_unique<SD_SpriteResources>(*this);
    textures = std::make_unique<SD_TextureResources>(*this);
    text = std::make_unique<SD_TextResources>(*this);
    vertex_arrays = std::make_unique<SD_VertexArrayResources>(*this);
    expandable_sprites = std::make_unique<SD_ExpandableSpriteResources>(*this);

    musics_resources = std::make_unique<SD_MusicResources>(*this);
    sounds_resources = std::make_unique<SD_SoundResources>(*this);
    sound_buffers_resources = std::make_unique<SD_SoundBufferResources>(*this);



}
////////////////////////////////////////
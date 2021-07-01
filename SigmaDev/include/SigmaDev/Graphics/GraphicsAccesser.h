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
// File: /impl/include/SigmaDev/Graphics/GraphicsAccesser.h
// Description:
// Additional Notes:

#ifndef SD_GRAPHICS_GRAPHICS_ACCESSER_H
#define SD_GRAPHICS_GRAPHICS_ACCESSER_H

#include <string>
#include <memory>
#include <map>

#include <SFML/Graphics/Texture.hpp>

#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////
class SD_Application;
class SD_Resources;

class SD_BlendModeResources;
class SD_CircleShapeResources;
class SD_ColorResources;
class SD_FontResources;
class SD_ImageResources;
class SD_RectangleShapeResources;
class SD_RenderStatesResources;
class SD_RenderTextureResources;
class SD_ShaderResources;
class SD_SpriteResources;
class SD_TextureResources;
class SD_VertexArrayResources;
class SD_ExpandableSpriteResources;
////////////////////////////////////////


////////////////////////////////////////
/**
 * @brief SD_GraphicsAccesser is helper accesser class for all graphics resources.
 *        Please use it if you want to insert, erase, of access graphics.  
 * 
 */
class SD_GraphicsAccesser : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_GraphicsAccesser() = delete;
    /**
     * @brief application_reference is necessary to connect this class
     *        to SD_Application
     * 
     * @param application_reference SD_Application non-const reference 
     */
    SD_GraphicsAccesser(SD_Application& application_reference);

    // Access to resources
    const SD_BlendModeResources& BlendModes() const;
    SD_BlendModeResources& BlendModes();

    const SD_CircleShapeResources& CircleShapes() const;
    SD_CircleShapeResources& CircleShapes();
    
    const SD_ColorResources& Colors() const;
    SD_ColorResources& Colors();
    
    const SD_FontResources& Fonts() const;
    SD_FontResources& Fonts();

    const SD_ImageResources& Images() const;
    SD_ImageResources& Images();

    const SD_RectangleShapeResources& RectangleShapes() const;
    SD_RectangleShapeResources& RectangleShapes();

    const SD_RenderStatesResources& RenderStates() const;
    SD_RenderStatesResources& RenderStates();

    const SD_RenderTextureResources& RenderTextures() const;
    SD_RenderTextureResources& RenderTextures();

    const SD_ShaderResources& Shaders() const;
    SD_ShaderResources& Shaders();

    const SD_SpriteResources& Sprites() const;
    SD_SpriteResources& Sprites();

    const SD_TextureResources& Textures() const;
    SD_TextureResources& Textures();

    const SD_VertexArrayResources& VertexArrays() const;
    SD_VertexArrayResources& VertexArrays();

    const SD_ExpandableSpriteResources& ExpandableSprites() const;
    SD_ExpandableSpriteResources& ExpandableSprites();

    // Direct SD_Resources access
    SD_Resources& GetResourcesAccess();

protected:
    SD_Application& application; ///< Nececcary to access SD_Resources in SD_Application
    
};
////////////////////////////////////////

#endif

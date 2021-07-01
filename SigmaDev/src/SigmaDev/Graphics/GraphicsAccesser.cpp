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
// File: /impl/src/SigmaDev/Graphics/GraphicsAccesser.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Graphics/GraphicsAccesser.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Resources/Resources.h>


////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_GraphicsAccesser)
SD_GraphicsAccesser::SD_GraphicsAccesser(SD_Application& application)
 : application(application)
 {
     
 }
 //---------------------------------------
const SD_BlendModeResources& SD_GraphicsAccesser::BlendModes() const {
    return application.GetResourcesRef().GetBlendModeResourcesRef();
}
SD_BlendModeResources& SD_GraphicsAccesser::BlendModes() {
    return application.GetResourcesRef().GetBlendModeResourcesRef();
}

const SD_CircleShapeResources& SD_GraphicsAccesser::CircleShapes() const {
    return application.GetResourcesRef().GetCircleShapeResourcesRef();
}
SD_CircleShapeResources& SD_GraphicsAccesser::CircleShapes() {
    return application.GetResourcesRef().GetCircleShapeResourcesRef();
}

const SD_ColorResources& SD_GraphicsAccesser::Colors() const {
    return application.GetResourcesRef().GetColorResourcesRef();
}
SD_ColorResources& SD_GraphicsAccesser::Colors() {
    return application.GetResourcesRef().GetColorResourcesRef();
}

const SD_FontResources& SD_GraphicsAccesser::Fonts() const {
    return application.GetResourcesRef().GetFontResourcesRef();
}
SD_FontResources& SD_GraphicsAccesser::Fonts() {
    return application.GetResourcesRef().GetFontResourcesRef();
}

const SD_ImageResources& SD_GraphicsAccesser::Images() const {
    return application.GetResourcesRef().GetImageResourcesRef();
}
SD_ImageResources& SD_GraphicsAccesser::Images() {
    return application.GetResourcesRef().GetImageResourcesRef();
}

const SD_RectangleShapeResources& SD_GraphicsAccesser::RectangleShapes() const {
    return application.GetResourcesRef().GetRectangleShapeResourcesRef();
}
SD_RectangleShapeResources& SD_GraphicsAccesser::RectangleShapes() {
    return application.GetResourcesRef().GetRectangleShapeResourcesRef();
}

const SD_RenderStatesResources& SD_GraphicsAccesser::RenderStates() const {
    return application.GetResourcesRef().GetRenderStatesResourcesRef();
}
SD_RenderStatesResources& SD_GraphicsAccesser::RenderStates() {
    return application.GetResourcesRef().GetRenderStatesResourcesRef();
}

const SD_RenderTextureResources& SD_GraphicsAccesser::RenderTextures() const {
    return application.GetResourcesRef().GetRenderTextureResourcesRef();
}
SD_RenderTextureResources& SD_GraphicsAccesser::RenderTextures() {
    return application.GetResourcesRef().GetRenderTextureResourcesRef();
}

const SD_ShaderResources& SD_GraphicsAccesser::Shaders() const {
    return application.GetResourcesRef().GetShaderResourcesRef();
}
SD_ShaderResources& SD_GraphicsAccesser::Shaders() {
    return application.GetResourcesRef().GetShaderResourcesRef();
}

const SD_SpriteResources& SD_GraphicsAccesser::Sprites() const {
    return application.GetResourcesRef().GetSpriteResourcesRef();
}
SD_SpriteResources& SD_GraphicsAccesser::Sprites() {
    return application.GetResourcesRef().GetSpriteResourcesRef();
}

const SD_TextureResources& SD_GraphicsAccesser::Textures() const {
    return application.GetResourcesRef().GetTextureResourcesRef();
}
SD_TextureResources& SD_GraphicsAccesser::Textures() {
    return application.GetResourcesRef().GetTextureResourcesRef();
}

const SD_VertexArrayResources& SD_GraphicsAccesser::VertexArrays() const {
    return application.GetResourcesRef().GetVertexArrayResourcesRef();
}
SD_VertexArrayResources& SD_GraphicsAccesser::VertexArrays() {
    return application.GetResourcesRef().GetVertexArrayResourcesRef();
}
const SD_ExpandableSpriteResources& SD_GraphicsAccesser::ExpandableSprites() const {
    return application.GetResourcesRef().GetExpandableSpriteResourcesRef();
}
SD_ExpandableSpriteResources& SD_GraphicsAccesser::ExpandableSprites() {
    return application.GetResourcesRef().GetExpandableSpriteResourcesRef();
}
SD_Resources& SD_GraphicsAccesser::GetResourcesAccess() {
    return application.GetResourcesRef();
}

 ////////////////////////////////////////
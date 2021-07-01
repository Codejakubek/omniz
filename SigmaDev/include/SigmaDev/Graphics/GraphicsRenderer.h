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
// File: /impl/include/SigmaDev/Graphics/GraphicsRenderer.h
// Description:
// Additional Notes:

#ifndef SD_GRAPHICS_GRAPHICS_RENDERER_H
#define SD_GRAPHICS_GRAPHICS_RENDERER_H

#include <functional>
#include <string>
#include <list>
#include <memory.h>
#include <SFML/Graphics.hpp>
#include <boost/optional.hpp>
#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Graphics/GraphicsDefines.h>
#include <SigmaDev/Misc/Class.h>

class SD_Application;

////////////////////////////////////////
class SD_RenderStackDrawableBase : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_RenderStackDrawableBase();
    virtual ~SD_RenderStackDrawableBase();
protected:

};
////////////////////////////////////////
class SD_RenderStackDrawable : public SD_RenderStackDrawableBase {
public:
    SD_DECLARE_CLASS_H()

    SD_RenderStackDrawable() = delete;
    SD_RenderStackDrawable(const sf::Drawable& drawable);
    SD_RenderStackDrawable(
        const std::string& resource_id,
        SD_DrawableResourceType type,
        bool remove_from_resources_after_render = false
    );

    inline const boost::optional<std::reference_wrapper<const sf::Drawable>>& GetDrawable() const {
        return drawable;
    }
    inline boost::optional<std::reference_wrapper<const sf::Drawable>>& GetDrawable() {
        return drawable;
    }
    inline SD_DrawableResourceType GetDrawableResourceType() const {
        return resource_type;
    }
    inline const std::string& GetResourceId() const {
        return resource_id;
    }
    inline bool IsFromResources() const {
        return is_from_resources;
    }
    inline bool RemoveFromResourcesAfterRender() const {
        return remove_from_resources_after_render;
    }
protected:
    virtual void DeduceType(const sf::Drawable& drawable);
    template <typename TYPE>
    bool _DeduceType(const sf::Drawable& drawable) {
        try {
            const TYPE& type = dynamic_cast<const TYPE&>(drawable);
            return true;
        } catch (const std::bad_cast& e) {
            return false;
        }
    } 

    boost::optional<std::reference_wrapper<const sf::Drawable>> drawable;
    SD_DrawableResourceType resource_type;
    std::string resource_id; 
    bool is_from_resources = false; 
    bool remove_from_resources_after_render = false; 
};


////////////////////////////////////////

class SD_RenderStackComplexDrawable : public SD_RenderStackDrawableBase {
public:
    SD_DECLARE_CLASS_H()

    SD_RenderStackComplexDrawable() = delete;
    SD_RenderStackComplexDrawable(const SD_ComplexDrawable& drawable);
    SD_RenderStackComplexDrawable(
        const std::string& resource_id,
        SD_ComplexDrawableResourceType type,
        bool remove_from_resources_after_render = false
    );
    virtual ~SD_RenderStackComplexDrawable();


    inline const boost::optional<std::reference_wrapper<const SD_ComplexDrawable>>& GetDrawable() const {
        return complex_drawable;
    }
    inline boost::optional<std::reference_wrapper<const SD_ComplexDrawable>>& GetDrawable() {
        return complex_drawable;
    }
    inline SD_ComplexDrawableResourceType GetComplexDrawableResourceType() const {
        return resource_type;
    }
    inline const std::string& GetResourceId() const {
        return resource_id;
    }
    inline bool IsFromResources() const {
        return is_from_resources;
    }
    inline bool RemoveFromResourcesAfterRender() const {
        return remove_from_resources_after_render;
    }
protected:
    virtual void DeduceType(const SD_ComplexDrawable& drawable);
    template <typename TYPE>
    bool _DeduceType(const SD_ComplexDrawable& drawable) {
        try {
            const TYPE& type = dynamic_cast<const TYPE&>(drawable);
            return true;    
        } catch (const std::bad_cast& e) {
            return false;
        }
    }

    boost::optional<std::reference_wrapper<const SD_ComplexDrawable>> complex_drawable;
    SD_ComplexDrawableResourceType resource_type = SD_COMPLEX_DRAWABLE_RESOURCETYPE_UNKNOWN;
    std::string resource_id;
    bool is_from_resources = false;
    bool remove_from_resources_after_render = false;
};


////////////////////////////////////////
class SD_RenderStacks : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef std::list<std::unique_ptr<SD_RenderStackDrawableBase>> _sublayer;
    typedef std::map<SD_RenderLayerLevel, _sublayer> _sublayers;
    typedef std::map<SD_RenderLayerLevel, _sublayers> _layers;
    typedef std::map<std::string, _layers> _container;
    
    /**

     */
    virtual void AddDrawable(
        const std::string& window_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        const sf::Drawable& drawable
    );
    virtual void AddDrawableFromResources(
        const std::string& window_id,
        const std::string& resource_id,
        SD_DrawableResourceType type,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    virtual void AddComplexDrawable(
        const std::string& window_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        const SD_ComplexDrawable& drawable
    );
    virtual void AddComplexDrawableFromResources(
        const std::string& window_id,
        const std::string& resource_id,
        SD_ComplexDrawableResourceType type,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    /**
     * @brief Clears the Render Stack
     */
    virtual void ClearDrawables();

    inline const _container& GetContainer() const {
        return container;
    }
    inline _container& GetContainer() {
        return container;
    }
protected:
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddDrawable(
        _layers& layers,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        const sf::Drawable& drawable
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddDrawable(
        _sublayers& sublayers,
        SD_RenderLayerLevel sub_render_level,
        const sf::Drawable& drawable
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddDrawable(
        _layers& layers,
        const std::string& resource_id,
        SD_DrawableResourceType type,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddDrawable(
        _sublayers& sublayers,
        const std::string& resource_id,
        SD_DrawableResourceType type,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddComplexDrawable(
        _layers& layers,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        const SD_ComplexDrawable& drawable
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddComplexDrawable(
        _sublayers& sublayers,
        SD_RenderLayerLevel sub_render_level,
        const SD_ComplexDrawable& drawable
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddComplexDrawable(
        _layers& layers,
        const std::string& resource_id,
        SD_ComplexDrawableResourceType type,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    /**
     * @brief (Implementation Method, use only inside SD_RenderStacks or its inheritances)
     */
    virtual void AddComplexDrawable(
        _sublayers& sublayers,
        const std::string& resource_id,
        SD_ComplexDrawableResourceType type,
        SD_RenderLayerLevel sub_render_level,
        bool remove_from_resources_after_render = false
    );
    _container container;
};
////////////////////////////////////////
class SD_GraphicsRenderer : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_GraphicsRenderer() = delete;
    SD_GraphicsRenderer(SD_Application& application_reference);

    virtual void RenderCircleShape(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderCircleShape(
        const std::string& window_id,
        const sf::CircleShape& res,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderConvexShape(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderConvexShape(
        const std::string& window_id,
        const sf::ConvexShape& res,
        SD_RenderLayerLevel render_leve,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderRectangleShape(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderRectangleShape(
        const std::string& window_id,
        const sf::RectangleShape& res,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderSprite(
        const std::string& window_id,
        const std::string& sprite_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderSprite(
        const std::string& window_id,
        const sf::Sprite& sprite_id,
        SD_RenderLayerLevel rende_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderText(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderText(
        const std::string& window_id,
        const sf::Text& text,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderVertexArray(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderVertexArray(
        const std::string& window_id,
        const sf::VertexArray& res,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderExpandableSprite(
        const std::string& window_id,
        const std::string& res_id,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0,
        bool remove_from_resources_after_render = false
    );
    virtual void RenderExpandableSprite(
        const std::string& window_id,
        const SD_ExpandableSprite& sprite,
        SD_RenderLayerLevel render_level,
        SD_RenderLayerLevel sub_render_level = 0
    );
    virtual void RenderAdded();
    virtual void ClearRenderStack();
    virtual void RemoveResourcesAfterRender();

protected:
    virtual void RenderAdded(const std::string& window_id, SD_RenderStacks::_layers& layers);
    virtual void RenderAdded(const std::string& window_id, SD_RenderStacks::_sublayers& sublayers);
    virtual void RenderAdded(const std::string& window_id, SD_RenderStacks::_sublayer& sublayer);
    virtual void RenderAdded(const std::string& window_id, SD_RenderStackDrawable& drawable);
    virtual void RenderAdded(const std::string& window_id, SD_RenderStackComplexDrawable& complex_drawable);
    virtual void RenderAdded(sf::RenderWindow& render_window, SD_DrawableResourceType type, const std::string& resource_id);
    virtual void RenderAdded(SD_RenderWindowAccess access, SD_ComplexDrawableResourceType type, const std::string& resource_id);

    virtual void RemoveResourcesAfterRender(SD_RenderStacks::_layers& layers);
    virtual void RemoveResourcesAfterRender(SD_RenderStacks::_sublayers& sublayers);
    virtual void RemoveResourcesAfterRender(SD_RenderStacks::_sublayer& sublayer);
    virtual void RemoveResourcesAfterRender(SD_RenderStackDrawable& drawable);
    virtual void RemoveResourcesAfterRender(SD_RenderStackComplexDrawable& complex_drawable);

    virtual sf::RenderWindow& GetWindow(const std::string& window_id);

    

    SD_Application& application;
    std::unique_ptr<SD_RenderStacks> render_stacks;
};



////////////////////////////////////////

#endif

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
// File: /impl/src/SigmaDev/Graphics/GraphicsRenderer.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Graphics/GraphicsRenderer.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Windows/WindowsAccesser.h>

SD_DECLARE_CLASS_CPP(SD_RenderStackDrawableBase)

SD_RenderStackDrawableBase::SD_RenderStackDrawableBase() {

}
SD_RenderStackDrawableBase::~SD_RenderStackDrawableBase() {

}

SD_DECLARE_CLASS_CPP(SD_RenderStackDrawable)
SD_RenderStackDrawable::SD_RenderStackDrawable(const sf::Drawable& drawable) {
    this->drawable = drawable;
    DeduceType(drawable);
}
SD_RenderStackDrawable::SD_RenderStackDrawable(
    const std::string& resource_id,
    SD_DrawableResourceType type,
    bool remove_from_resources_after_render
) {
    this->resource_id = resource_id;
    this->resource_type = type;
    this->is_from_resources = true;
    this->remove_from_resources_after_render = remove_from_resources_after_render;
}

void SD_RenderStackDrawable::DeduceType(const sf::Drawable& drawable) {
    if(_DeduceType<sf::CircleShape>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_CIRCLE_SHAPE;
    } else if(_DeduceType<sf::ConvexShape>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_CONVEX_SHAPE;
    } else if (_DeduceType<sf::RectangleShape>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_RECTANGLE_SHAPE;
    } else if (_DeduceType<sf::Sprite>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_SPRITE;
    } else if (_DeduceType<sf::Text>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_TEXT;
    } else if (_DeduceType<sf::VertexArray>(drawable)) {
        resource_type = SD_DRAWABLE_RESOURCETYPE_VERTEX_ARRAY;
    } else {
        resource_type = SD_DRAWABLE_RESOURCETYPE_UNKNOWN;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_RenderStackComplexDrawable)

SD_RenderStackComplexDrawable::SD_RenderStackComplexDrawable(const SD_ComplexDrawable& complex_drawable) {
    this->complex_drawable = complex_drawable;
    DeduceType(complex_drawable);
}
SD_RenderStackComplexDrawable::SD_RenderStackComplexDrawable(
    const std::string& resource_id,
    SD_ComplexDrawableResourceType type,
    bool remove_from_resources_after_render
) {
    this->resource_id = resource_id;
    this->resource_type = type;
    this->is_from_resources = true;
    this->remove_from_resources_after_render = remove_from_resources_after_render;
}
SD_RenderStackComplexDrawable::~SD_RenderStackComplexDrawable() {
    
}
void SD_RenderStackComplexDrawable::DeduceType(const SD_ComplexDrawable& complex_drawable) {
    if (_DeduceType<SD_ExpandableSprite>(complex_drawable)) {
        resource_type = SD_COMPLEX_DRAWABLE_RESOURCETYPE_EXPANDABLE_SPRITE;
    } else {
        resource_type = SD_COMPLEX_DRAWABLE_RESOURCETYPE_UNKNOWN;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_RenderStacks)

void SD_RenderStacks::AddDrawable(
    const std::string& window_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    const sf::Drawable& drawable 
) {
    auto it = container.find(window_id);
    if (it != container.end()) {
        _layers& layers = it->second;
        AddDrawable(layers, render_level, sub_render_level, drawable);
    } else {    
        auto insert_pair = container.insert(std::make_pair(
            window_id,
            _layers()
        ));
        _layers& layers = insert_pair.first->second;
        AddDrawable(layers, render_level, sub_render_level, drawable);
    }
}
void SD_RenderStacks::AddDrawableFromResources(
    const std::string& window_id,
    const std::string& resource_id,
    SD_DrawableResourceType type,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = container.find(window_id);
    if (it != container.end()) {
        _layers& layers = it->second;
        AddDrawable(
            layers, 
            resource_id, 
            type, 
            render_level, 
            sub_render_level, 
            remove_from_resources_after_render);
    } else {
        auto insert_pair = container.insert(std::make_pair(
            window_id,
            _layers()
        ));
        _layers& layers = insert_pair.first->second;
        AddDrawable(
            layers, 
            resource_id, 
            type, 
            render_level, 
            sub_render_level, 
            remove_from_resources_after_render);
    }
}
void SD_RenderStacks::AddComplexDrawable(
    const std::string& window_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    const SD_ComplexDrawable& drawable
) {
    auto it = container.find(window_id);
    if (it != container.end()) {
        _layers& layers = it->second;
        AddComplexDrawable(layers, render_level, sub_render_level, drawable);
    } else {    
        auto insert_pair = container.insert(std::make_pair(
            window_id,
            _layers()
        ));
        _layers& layers = insert_pair.first->second;
        AddComplexDrawable(layers, render_level, sub_render_level, drawable);
    }
}
void SD_RenderStacks::AddComplexDrawableFromResources(
    const std::string& window_id,
    const std::string& resource_id,
    SD_ComplexDrawableResourceType type,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = container.find(window_id);
    if (it != container.end()) {
        _layers& layers = it->second;
        AddComplexDrawable(
            layers, 
            resource_id, 
            type, 
            render_level, 
            sub_render_level, 
            remove_from_resources_after_render);
    } else {
        auto insert_pair = container.insert(std::make_pair(
            window_id,
            _layers()
        ));
        _layers& layers = insert_pair.first->second;
        AddComplexDrawable(
            layers, 
            resource_id, 
            type, 
            render_level, 
            sub_render_level, 
            remove_from_resources_after_render);
    }
}

void SD_RenderStacks::ClearDrawables() {
    container.clear();
}
void SD_RenderStacks::AddDrawable(
    _layers& layers,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    const sf::Drawable& drawable
) {
    auto it = layers.find(render_level);
    if (it != layers.end()) {
        _sublayers& sublayers = it->second;
        AddDrawable(sublayers, sub_render_level, drawable);
    } else {
        auto insert_pair = layers.insert(std::make_pair(
            render_level,
            _sublayers()
        ));
        _sublayers& sublayers = insert_pair.first->second;
        AddDrawable(sublayers, sub_render_level, drawable);
    }
}
void SD_RenderStacks::AddDrawable(
    _sublayers& sublayers,
    SD_RenderLayerLevel sub_render_level,
    const sf::Drawable& drawable
) {
    auto it = sublayers.find(sub_render_level);
    if (it != sublayers.end()) {
        _sublayer& sublayer = it->second;   
        sublayer.emplace_back(
            std::make_unique<SD_RenderStackDrawable>(drawable)
        );
    } else {
        auto insert_pair = sublayers.insert(std::make_pair(
            sub_render_level,
            _sublayer()
        ));
        _sublayer& sublayer = insert_pair.first->second;
        sublayer.emplace_back(
            std::make_unique<SD_RenderStackDrawable>(drawable)
        );
    }
}
void SD_RenderStacks::AddDrawable(
    _layers& layers,
    const std::string& resource_id,
    SD_DrawableResourceType type,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = layers.find(render_level);
    if (it != layers.end()) {
        _sublayers& sublayers = it->second;
        AddDrawable(
            sublayers, 
            resource_id, 
            type, 
            sub_render_level, 
            remove_from_resources_after_render); 
    } else {
        auto insert_pair = layers.insert(std::make_pair(
            render_level,
            _sublayers()
        ));
        _sublayers& sublayers = insert_pair.first->second;
        AddDrawable(
            sublayers, 
            resource_id, 
            type, 
            sub_render_level, 
            remove_from_resources_after_render); 
    }
}
void SD_RenderStacks::AddDrawable(
    _sublayers& sublayers,
    const std::string& resource_id,
    SD_DrawableResourceType type,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = sublayers.find(sub_render_level);
    if (it != sublayers.end()) {
        _sublayer& sublayer = it->second;
        sublayer.emplace_back(
            std::move(std::make_unique<SD_RenderStackDrawable>(resource_id, type, remove_from_resources_after_render))
        );
    } else {
        auto insert_pair = sublayers.insert(std::make_pair(
            sub_render_level,
            _sublayer()
        ));
        _sublayer& sublayer = insert_pair.first->second;
        sublayer.emplace_back(
            std::move(std::make_unique<SD_RenderStackDrawable>(resource_id, type, remove_from_resources_after_render))
        );
    }
}
//---------------------------------------
void SD_RenderStacks::AddComplexDrawable(
    _layers& layers,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    const SD_ComplexDrawable& drawable 
) {
    auto it = layers.find(render_level);
    if (it != layers.end()) {
        _sublayers& sublayers = it->second;
        AddComplexDrawable(sublayers, sub_render_level, drawable);
    } else {
        auto insert_pair = layers.insert(
            std::make_pair(
                render_level,
                _sublayers()
            )
        );
        _sublayers& sublayers = insert_pair.first->second;
        AddComplexDrawable(sublayers, sub_render_level, drawable);
    }
}
void SD_RenderStacks::AddComplexDrawable(
    _sublayers& sublayers,
    SD_RenderLayerLevel sub_render_level,
    const SD_ComplexDrawable& drawable
) {
    auto it = sublayers.find(sub_render_level);
    if (it != sublayers.end()) {
        _sublayer& sublayer = it->second;
        sublayer.emplace_back(
            std::make_unique<SD_RenderStackComplexDrawable>(drawable)
        );
    } else {
        auto insert_pair = sublayers.insert(std::make_pair(
            sub_render_level,
            _sublayer()
        ));
        _sublayer& sublayer = insert_pair.first->second;
        sublayer.emplace_back(
            std::make_unique<SD_RenderStackComplexDrawable>(drawable)
        );
    }
}
void SD_RenderStacks::AddComplexDrawable(
    _layers& layers,
    const std::string& resource_id,
    SD_ComplexDrawableResourceType type,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = layers.find(render_level);
    if (it != layers.end()) {
        _sublayers& sublayers = it->second;
        AddComplexDrawable(
            sublayers,
            resource_id,
            type,
            sub_render_level,
            remove_from_resources_after_render
        );
    } else {
        auto insert_pair = layers.insert(std::make_pair(
            render_level,
            _sublayers()
        ));
        _sublayers& sublayers = insert_pair.first->second;
        AddComplexDrawable(
            sublayers,
            resource_id,
            type,
            sub_render_level,
            remove_from_resources_after_render
        );
    }
}
void SD_RenderStacks::AddComplexDrawable(
    _sublayers& sublayers,
    const std::string& resource_id,
    SD_ComplexDrawableResourceType type,
    SD_RenderLayerLevel sub_render_level,
    bool remove_from_resources_after_render
) {
    auto it = sublayers.find(sub_render_level);
    if (it != sublayers.end()) {
        _sublayer& sublayer = it->second;
        sublayer.emplace_back(
            std::move(std::make_unique<SD_RenderStackComplexDrawable>(resource_id, type, remove_from_resources_after_render))
        );
    } else {
        auto insert_pair = sublayers.insert(std::make_pair(
            sub_render_level,
            _sublayer()
        ));
        _sublayer& sublayer = insert_pair.first->second;
        sublayer.emplace_back(
            std::move(std::make_unique<SD_RenderStackComplexDrawable>(resource_id, type, remove_from_resources_after_render))
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_GraphicsRenderer)

SD_GraphicsRenderer::SD_GraphicsRenderer(SD_Application& application)
 : application(application)
 {
     render_stacks = std::make_unique<SD_RenderStacks>();
 }
void SD_GraphicsRenderer::RenderCircleShape(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_CIRCLE_SHAPE, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderCircleShape(
    const std::string& window_id,
    const sf::CircleShape& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderConvexShape(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_CONVEX_SHAPE, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderConvexShape(
    const std::string& window_id,
    const sf::ConvexShape& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderRectangleShape(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_RECTANGLE_SHAPE, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderRectangleShape(
    const std::string& window_id,
    const sf::RectangleShape& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderSprite(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_SPRITE, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderSprite(
    const std::string& window_id,
    const sf::Sprite& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderText(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_TEXT, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderText(
    const std::string& window_id,
    const sf::Text& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderVertexArray(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawableFromResources(
        window_id, 
        res_id, 
        SD_DRAWABLE_RESOURCETYPE_VERTEX_ARRAY, 
        render_level, 
        sub_render_level, 
        remove_after_render);
}
void SD_GraphicsRenderer::RenderVertexArray(
    const std::string& window_id,
    const sf::VertexArray& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderExpandableSprite(
    const std::string& window_id,
    const std::string& res_id,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level,
    bool remove_after_render
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddComplexDrawableFromResources(
        window_id,
        res_id,
        SD_COMPLEX_DRAWABLE_RESOURCETYPE_EXPANDABLE_SPRITE,
        render_level,
        sub_render_level,
        remove_after_render
    );
}
void SD_GraphicsRenderer::RenderExpandableSprite(
    const std::string& window_id,
    const SD_ExpandableSprite& res,
    SD_RenderLayerLevel render_level,
    SD_RenderLayerLevel sub_render_level
) {
    SD_RenderStacks& stacks = *render_stacks.get();
    stacks.AddComplexDrawable(
        window_id,
        render_level,
        sub_render_level,
        res
    );
}
void SD_GraphicsRenderer::RenderAdded() {
    SD_RenderStacks& stacks = *render_stacks.get();
    SD_RenderStacks::_container& container = stacks.GetContainer();
    for (auto& el : container) {
        const std::string& window_id = el.first;
        SD_RenderStacks::_layers& layers = el.second;
        RenderAdded(window_id, layers);
    }
}
void SD_GraphicsRenderer::ClearRenderStack() {
    SD_RenderStacks& stacks = * render_stacks.get();
    SD_RenderStacks::_container& container = stacks.GetContainer();
    container.clear();
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender() {
    SD_RenderStacks& stacks = *render_stacks.get();
    SD_RenderStacks::_container& container = stacks.GetContainer();
    for (auto& el : container) {
        const std::string& window_id = el.first;
        SD_RenderStacks::_layers& layers = el.second;
        RemoveResourcesAfterRender(layers);
    }
}
void SD_GraphicsRenderer::RenderAdded(const std::string& window_id, SD_RenderStacks::_layers& layers) {
    for (auto& el : layers) {
        SD_RenderStacks::_sublayers& sublayers = el.second;
        RenderAdded(window_id, sublayers);
    }
}
void SD_GraphicsRenderer::RenderAdded(const std::string& window_id, SD_RenderStacks::_sublayers& sublayers) {
    for (auto& el : sublayers) {
        SD_RenderStacks::_sublayer& sublayer = el.second;
        RenderAdded(window_id, sublayer);
    }
}
void SD_GraphicsRenderer::RenderAdded(const std::string& window_id, SD_RenderStacks::_sublayer& sublayer) {
    for (std::unique_ptr<SD_RenderStackDrawableBase>& drawable : sublayer) {
        try {
            SD_RenderStackDrawableBase& d = *drawable.get();
            SD_RenderStackDrawable& casted = dynamic_cast<SD_RenderStackDrawable&>(d);
            RenderAdded(window_id, casted);
        } catch (const std::bad_cast& bad_cast_exc) {

        }
        try {
            SD_RenderStackDrawableBase& d = *drawable.get();
            SD_RenderStackComplexDrawable& casted = dynamic_cast<SD_RenderStackComplexDrawable&>(d);
            RenderAdded(window_id, casted);
        } catch (const std::bad_cast& bad_cast_exc) {

        }
    }
}
void SD_GraphicsRenderer::RenderAdded(const std::string& window_id, SD_RenderStackDrawable& drawable) {
    sf::RenderWindow& render_window = GetWindow(window_id);
    if (drawable.IsFromResources()) {
        const std::string& resource_id = drawable.GetResourceId();
        SD_DrawableResourceType resource_type = drawable.GetDrawableResourceType();
        RenderAdded(render_window, resource_type, resource_id);
    } else {
        boost::optional<std::reference_wrapper<const sf::Drawable>>& opt_drawable_ref = drawable.GetDrawable();
        if (opt_drawable_ref.is_initialized()) {
            std::reference_wrapper<const sf::Drawable>& drawable_ref = opt_drawable_ref.get();
            const sf::Drawable& drawable = drawable_ref.get();
            render_window.draw(drawable);
        }
    }
}
void SD_GraphicsRenderer::RenderAdded(const std::string& window_id, SD_RenderStackComplexDrawable& complex_drawable) {
    sf::RenderWindow& render_window = GetWindow(window_id);
    if (complex_drawable.IsFromResources()) {
        const std::string& resource_id = complex_drawable.GetResourceId();
        SD_ComplexDrawableResourceType resource_type = complex_drawable.GetComplexDrawableResourceType();
        RenderAdded(SD_RenderWindowAccess(window_id, render_window), resource_type, resource_id);
    } else {
        boost::optional<std::reference_wrapper<const SD_ComplexDrawable>>& opt_drawable_ref = complex_drawable.GetDrawable();
        if (opt_drawable_ref.is_initialized()) {
            std::reference_wrapper<const SD_ComplexDrawable>& drawable_ref = opt_drawable_ref.get();
            const SD_ComplexDrawable& d = drawable_ref.get();
            d.Render(SD_RenderWindowAccess(window_id, render_window));
        } 
    }
}
void SD_GraphicsRenderer::RenderAdded(sf::RenderWindow& render_window, SD_DrawableResourceType type, const std::string& resource_id) {
    std::unique_ptr<SD_Resources>& resources = application.GetResources();
    
    if (type == SD_DRAWABLE_RESOURCETYPE_UNKNOWN) {
        //Render nothing
    } else if (type == SD_DRAWABLE_RESOURCETYPE_CIRCLE_SHAPE) {
        auto& circle_shapes = resources->GetCircleShapeResourcesRef();
        sf::CircleShape& resource = circle_shapes.GetCircleShape(resource_id);
        render_window.draw(resource);
    } else if (type == SD_DRAWABLE_RESOURCETYPE_CONVEX_SHAPE) {
        auto& convex_shapes = resources->GetConvexShapeResourcesRef();
        sf::ConvexShape& resource = convex_shapes.GetConvexShape(resource_id);
        render_window.draw(resource);
    } else if (type == SD_DRAWABLE_RESOURCETYPE_RECTANGLE_SHAPE) {
        auto& rectangle_shapes = resources->GetRectangleShapeResourcesRef();
        sf::RectangleShape& resource = rectangle_shapes.GetRectangleShape(resource_id);
        render_window.draw(resource);
    } else if (type == SD_DRAWABLE_RESOURCETYPE_SPRITE) {
        auto& sprites = resources->GetSpriteResourcesRef();
        std::unique_ptr<sf::Sprite>& resource = sprites.GetSprite(resource_id);
        render_window.draw(*resource.get());
    } else if (type == SD_DRAWABLE_RESOURCETYPE_TEXT) {
        auto& texts = resources->GetTextResourcesRef();
        sf::Text& resource = texts.GetText(resource_id);
        render_window.draw(resource);
    } else if (type == SD_DRAWABLE_RESOURCETYPE_VERTEX_ARRAY) {
        auto& vertex_arrays = resources->GetVertexArrayResourcesRef();
        sf::VertexArray& resource = vertex_arrays.GetVertexArray(resource_id);
        render_window.draw(resource);
    }
}
void SD_GraphicsRenderer::RenderAdded(SD_RenderWindowAccess access, SD_ComplexDrawableResourceType type, const std::string& resource_id) {
    std::unique_ptr<SD_Resources>& resources = application.GetResources();

    if (type == SD_COMPLEX_DRAWABLE_RESOURCETYPE_UNKNOWN) {

    } else if (type == SD_COMPLEX_DRAWABLE_RESOURCETYPE_EXPANDABLE_SPRITE) {
        auto& expandable_sprites = resources->GetExpandableSpriteResourcesRef();
        std::unique_ptr<SD_ExpandableSprite>& resource = expandable_sprites.GetExpandableSprite(resource_id);
        resource->Render(access);
    }
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender(SD_RenderStacks::_layers& layers) {
    for (auto& el : layers) {
        SD_RenderStacks::_sublayers& sublayers = el.second;
        RemoveResourcesAfterRender(sublayers);
    }
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender(SD_RenderStacks::_sublayers& sublayers) {
    for (auto & el : sublayers) {
        SD_RenderStacks::_sublayer& sublayer = el.second;
        RemoveResourcesAfterRender(sublayer);
    }
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender(SD_RenderStacks::_sublayer& sublayer) {
    for (std::unique_ptr<SD_RenderStackDrawableBase>& drawable : sublayer) {
        SD_RenderStackDrawableBase& b = *drawable.get();
        try {
            SD_RenderStackDrawable& casted = dynamic_cast<SD_RenderStackDrawable&>(b);
            RemoveResourcesAfterRender(casted);
            break;
        } catch (const std::bad_cast& bad_cast_exc) {
            
        }
        try {
            SD_RenderStackComplexDrawable& casted = dynamic_cast<SD_RenderStackComplexDrawable&>(b);
            RemoveResourcesAfterRender(casted);
            break;
        } catch (const std::bad_cast& bad_cast_exc) {
            
        }
    }
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender(SD_RenderStackDrawable& drawable) {
    if (drawable.IsFromResources() && drawable.RemoveFromResourcesAfterRender()) {
        auto& resources = application.GetResourcesRef();
        SD_DrawableResourceType type = drawable.GetDrawableResourceType();
        if (type == SD_DRAWABLE_RESOURCETYPE_UNKNOWN) {

        } else if (type == SD_DRAWABLE_RESOURCETYPE_CIRCLE_SHAPE) {
            const std::string& res_id = drawable.GetResourceId();
            auto& circle_shapes = resources.GetCircleShapeResourcesRef();
            if (circle_shapes.CircleShapeExists(res_id)) {
                circle_shapes.EraseCircleShape(res_id);
            }
        } else if (type == SD_DRAWABLE_RESOURCETYPE_CONVEX_SHAPE) {
            const std::string& res_id = drawable.GetResourceId();
            auto& convex_shapes = resources.GetConvexShapeResourcesRef();
            if(convex_shapes.ConvexShapeExists(res_id)) {
                convex_shapes.EraseConvexShape(res_id);
            }
        } else if (type == SD_DRAWABLE_RESOURCETYPE_RECTANGLE_SHAPE) {
            const std::string& res_id = drawable.GetResourceId();
            auto& rectangle_shapes = resources.GetRectangleShapeResourcesRef();
            if (rectangle_shapes.RectangleShapeExists(res_id)) {
                rectangle_shapes.EraseRectangleShape(res_id);
            }
        } else if (type == SD_DRAWABLE_RESOURCETYPE_SPRITE) {
            const std::string& res_id = drawable.GetResourceId();
            auto& sprites = resources.GetSpriteResourcesRef();
            if(sprites.SpriteExists(res_id)) {
                sprites.EraseSprite(res_id);
            }
        } else if (type == SD_DRAWABLE_RESOURCETYPE_TEXT) {
            const std::string& res_id = drawable.GetResourceId();
            auto& texts = resources.GetTextResourcesRef();
            if(texts.TextExists(res_id)) {
                texts.EraseText(res_id);
            }
        } else if (type == SD_DRAWABLE_RESOURCETYPE_VERTEX_ARRAY) {
            const std::string& res_id = drawable.GetResourceId();
            auto& vertex_arrays = resources.GetVertexArrayResourcesRef();
            if(vertex_arrays.VertexArrayExists(res_id)) {
                vertex_arrays.EraseVertexArray(res_id);
            }
        }
    }
}
void SD_GraphicsRenderer::RemoveResourcesAfterRender(SD_RenderStackComplexDrawable& drawable) {
    if (drawable.IsFromResources() && drawable.RemoveFromResourcesAfterRender()) {
        auto& resources = application.GetResourcesRef();
        SD_ComplexDrawableResourceType type = drawable.GetComplexDrawableResourceType();
        if (type == SD_COMPLEX_DRAWABLE_RESOURCETYPE_UNKNOWN) {

        } else if (type == SD_COMPLEX_DRAWABLE_RESOURCETYPE_EXPANDABLE_SPRITE) {
            const std::string& res_id = drawable.GetResourceId();
            auto& expandable_sprites = resources.GetExpandableSpriteResourcesRef();
            if (expandable_sprites.ExpandableSpriteExists(res_id)) {                 
                expandable_sprites.EraseExpandableSprite(res_id);
            }
        }
    }
}

sf::RenderWindow& SD_GraphicsRenderer::GetWindow(const std::string& window_id) {
    auto& windows_acccesser = application.GetWindowsAccesser();
    std::unique_ptr<sf::RenderWindow>& render_window = windows_acccesser->GetRenderWindow(window_id);   
    return *render_window.get();
}

#include <SigmaDev/Testing/Testing.h>

SD_DEFINE_REALTIME_TEST(rendering_testing_1)
    SD_ApplicationInitializationHelper helper;

    const std::string window_name = "rendering_window";

    helper.CreateWindow(window_name, sf::VideoMode(800,600), "SigmaDev Rendering Testings Test NO.1", sf::Style::Close);

    auto& app = helper.GetApplication();
    auto& renderer = app->GetGraphicsRenderer();
    auto& resources = app->GetResourcesRef();

    auto& text_resources = resources.GetTextResourcesRef();
    auto& font_resources = resources.GetFontResourcesRef();
    auto& sprite_resources = resources.GetSpriteResourcesRef();
    auto& texture_resources = resources.GetTextureResourcesRef();
    auto& circle_shape_resources = resources.GetCircleShapeResourcesRef(); 
    auto& convex_shape_resources = resources.GetConvexShapeResourcesRef();
    auto& rectangle_shape_resources = resources.GetRectangleShapeResourcesRef();
    auto& vertex_array_resources = resources.GetVertexArrayResourcesRef();    

    sf::CircleShape circle_shape;
    circle_shape.setRadius(100);
    circle_shape.setOutlineColor(sf::Color(200,200,50,100));
    circle_shape.setOutlineThickness(5.0f);
    circle_shape.setFillColor(sf::Color(150,150,150,255));
    circle_shape.setPosition(sf::Vector2f(20.0f, 400.0f));

    circle_shape_resources.AddCircleShape("circle_shape", circle_shape);

    sf::ConvexShape convex_shape;
    convex_shape.setOutlineColor(sf::Color(200,200,50,100));
    convex_shape.setOutlineThickness(10.0f);
    convex_shape.setFillColor(sf::Color(150,150,150,255));
    convex_shape.setPointCount(6);
    convex_shape.setPosition(450.0f, 20.0f);
    convex_shape.setPoint(0, sf::Vector2f(10,10));
    convex_shape.setPoint(1, sf::Vector2f(40,10));
    convex_shape.setPoint(2, sf::Vector2f(60, 30));
    convex_shape.setPoint(3, sf::Vector2f(50, 50));
    convex_shape.setPoint(4, sf::Vector2f(10, 60));

    convex_shape_resources.AddConvexShape("convex_shape", convex_shape);

    sf::RectangleShape rectangle_shape;
    rectangle_shape.setSize(sf::Vector2f(100,140));
    rectangle_shape.setPosition(20.0f, 200.0f);
    rectangle_shape.setFillColor(sf::Color(150,150,150,255));
    rectangle_shape.setOutlineColor(sf::Color(200,200,50,100));
    rectangle_shape.setOutlineThickness(6);

    rectangle_shape_resources.AddRectangleShape("rectangle_shape", rectangle_shape);

    
    vertex_array_resources.AddVertexArray("vertex_array", sf::PrimitiveType::LinesStrip, 0);
    sf::VertexArray& vertex_array = vertex_array_resources.GetVertexArray("vertex_array");
    

    vertex_array.append(sf::Vertex(sf::Vector2f(400,200), sf::Color(200,200,50,100)));
    vertex_array.append(sf::Vertex(sf::Vector2f(500,200), sf::Color(200,200,50,100)));
    vertex_array.append(sf::Vertex(sf::Vector2f(550,300), sf::Color(200,200,50,150)));
    vertex_array.append(sf::Vertex(sf::Vector2f(400, 350), sf::Color(200,200,50,200)));


    texture_resources.LoadTexture("texture", "./Base/NEO.jpg");
    std::unique_ptr<sf::Texture>& texture = texture_resources.GetTexture("texture");

    sprite_resources.AddSprite("sprite", *texture.get());
    std::unique_ptr<sf::Sprite>& sprite = sprite_resources.GetSprite("sprite");
    sprite->scale(0.16f, 0.16f);

    sprite->setPosition(300.0f, 20.0f);

    sf::Font font;
    font.loadFromFile("./Base/SourceSansPro-ExtraLight.otf");

    font_resources.AddFont("font", font);
    sf::Font& font_reference = font_resources.GetFont("font");

    text_resources.AddText("text", "0", font, 40);
    sf::Text& text_ref = text_resources.GetText("text");
    text_ref.setFillColor(sf::Color::Yellow);
    text_ref.setPosition(sf::Vector2f(20.0f, 20.0f));

    

    for (int i = 0; i < 5000 && helper.AtLeastOneWindowIsOpen(); ++i) {
        
        text_ref.setString(std::string()+"Frame NO. " + std::to_string(i));

        renderer->RenderText(window_name, text_ref, 1, 1);
        
        if (i % 50 < 40) {
            renderer->RenderSprite(window_name, "sprite", 1, 1);
            renderer->RenderCircleShape(window_name, "circle_shape", 1, 1);
            renderer->RenderConvexShape(window_name, "convex_shape", 1, 1);
            renderer->RenderRectangleShape(window_name, "rectangle_shape", 1, 1);
            renderer->RenderVertexArray(window_name, "vertex_array", 1, 1);
        }   


        helper.RunForOneTick();
    }



SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(rendering_testing_1)

SD_DEFINE_REALTIME_TEST(rendering_testing_2)
SD_ApplicationInitializationHelper helper;

    const std::string window_name = "rendering_window";

    helper.CreateWindow(window_name, sf::VideoMode(800,600), "SigmaDev Rendering Testings Test NO.2", sf::Style::Close);

    auto& app = helper.GetApplication();
    auto& renderer = app->GetGraphicsRenderer();
    auto& resources = app->GetResourcesRef();

    auto& text_resources = resources.GetTextResourcesRef();
    auto& font_resources = resources.GetFontResourcesRef();
    auto& sprite_resources = resources.GetSpriteResourcesRef();
    auto& texture_resources = resources.GetTextureResourcesRef();
    auto& circle_shape_resources = resources.GetCircleShapeResourcesRef(); 
    auto& convex_shape_resources = resources.GetConvexShapeResourcesRef();
    auto& rectangle_shape_resources = resources.GetRectangleShapeResourcesRef();
    auto& vertex_array_resources = resources.GetVertexArrayResourcesRef(); 

    sf::Text text;
    sf::Font font;
    sf::CircleShape circle_shape;
    sf::ConvexShape convex_shape;
    sf::RectangleShape rectangle_shape;
    sf::VertexArray vertex_array;

    font.loadFromFile("./Base/SourceSansPro-ExtraLight.otf");

    font_resources.AddFont("font", font);
    sf::Font& font_reference = font_resources.GetFont("font");

    circle_shape.setRadius(100);
    circle_shape.setOutlineColor(sf::Color(250,250,100,180));
    circle_shape.setOutlineThickness(5.0f);
    circle_shape.setFillColor(sf::Color(250,250,50,50));
    circle_shape.setPosition(sf::Vector2f(20.0f, 400.0f));

    convex_shape.setOutlineColor(sf::Color(250,250,100,180));
    convex_shape.setOutlineThickness(10.0f);
    convex_shape.setFillColor(sf::Color(250,250,50,50));
    convex_shape.setPointCount(6);
    convex_shape.setPosition(450.0f, 20.0f);
    convex_shape.setPoint(0, sf::Vector2f(10,10));
    convex_shape.setPoint(1, sf::Vector2f(40,10));
    convex_shape.setPoint(2, sf::Vector2f(60, 30));
    convex_shape.setPoint(3, sf::Vector2f(50, 50));
    convex_shape.setPoint(4, sf::Vector2f(10, 60));

    rectangle_shape.setSize(sf::Vector2f(100,140));
    rectangle_shape.setPosition(20.0f, 200.0f);
    rectangle_shape.setFillColor(sf::Color(250,250,50,50));
    rectangle_shape.setOutlineColor(sf::Color(250,250,100,180));
    rectangle_shape.setOutlineThickness(6);

    vertex_array.append(sf::Vertex(sf::Vector2f(400,200), sf::Color(250,250,100,180)));
    vertex_array.append(sf::Vertex(sf::Vector2f(500,200), sf::Color(250,150,100,180)));
    vertex_array.append(sf::Vertex(sf::Vector2f(550,300), sf::Color(250,50,100,180)));
    vertex_array.append(sf::Vertex(sf::Vector2f(400, 350), sf::Color(250,0,0,180)));



    texture_resources.LoadTexture("texture", "./Base/NEO.jpg");
    std::unique_ptr<sf::Texture>& texture = texture_resources.GetTexture("texture");

    text.setFillColor(sf::Color::White);
    text.setFont(font);

    for (int i = 0; i < 5000 && helper.AtLeastOneWindowIsOpen(); ++i) {
        text.setString(std::string()+"Frame NO. " + std::to_string(i));
        text_resources.AddText("text", text);

        renderer->RenderText(window_name, "text", 2, 2, true);

        if (i % 50 < 40) {
            sprite_resources.AddSprite("sprite");
            std::unique_ptr<sf::Sprite>& sprite = sprite_resources.GetSprite("sprite");
            sprite->setTexture(*texture.get());
            sprite->setScale(0.2f, 0.2f);
            sprite->setColor(sf::Color(i%255, i%255, 255, 255));
            sprite->setPosition(200.0f, 20.0f);
            circle_shape_resources.AddCircleShape("circle_shape", circle_shape);
            convex_shape_resources.AddConvexShape("convex_shape", convex_shape);
            rectangle_shape_resources.AddRectangleShape("rectangle_shape", rectangle_shape);
            vertex_array_resources.AddVertexArray("vertex_array", vertex_array);

            renderer->RenderSprite(window_name, "sprite", 1, 1, true);
            renderer->RenderCircleShape(window_name, "circle_shape", 1, 1, true);
            renderer->RenderConvexShape(window_name, "convex_shape", 1, 1, true);
            renderer->RenderRectangleShape(window_name, "rectangle_shape", 1, 1, true);
            renderer->RenderVertexArray(window_name, "vertex_array", 1, 1, true);
    
        }   
        helper.RunForOneTick();
    }

SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(rendering_testing_2)
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
// File: /impl/src/SigmaDev/Json/JsonLoader.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Json/JsonLoader.h>
#include <SigmaDev/Resources/Resources.h>
#include <SigmaDev/Graphics/ExpandableSprite.h>
////////////////////////////////////////

namespace exc {

////////////////////////////////////////

SD_JsonLoaderLoadFailed::SD_JsonLoaderLoadFailed(const std::string& exc_name) 
 : SD_Exception(exc_name, DefaultExceptionDescription())
{

}

SD_JsonLoaderLoadFailed::SD_JsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_Exception(exc_name, exc_description)
{

}
std::string SD_JsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string ("SD_JsonLoader Load has failed");
}

////////////////////////////////////////


SD_FontJsonLoaderLoadFailed::SD_FontJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_FontJsonLoaderLoadFailed", exc_description)
{

}
SD_FontJsonLoaderLoadFailed::SD_FontJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_FontJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_FontJsonLoaderLoadFailed Load has failed");
}


////////////////////////////////////////

SD_TextJsonLoaderLoadFailed::SD_TextJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_TextJsonLoaderLoadFailed", exc_description)
{

}
SD_TextJsonLoaderLoadFailed::SD_TextJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_TextJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_TextJsonLoaderLoadFailed Load has failed");
}

////////////////////////////////////////

SD_TextureJsonLoaderLoadFailed::SD_TextureJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_TextureJsonLoaderLoadFailed", exc_description)
{

}
SD_TextureJsonLoaderLoadFailed::SD_TextureJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_TextureJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_TextureJsonLoaderLoadFailed Load has failed");
}

////////////////////////////////////////

SD_SpriteJsonLoaderLoadFailed::SD_SpriteJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_SpriteJsonLoaderLoadFailed", exc_description)
{

}
SD_SpriteJsonLoaderLoadFailed::SD_SpriteJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_SpriteJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_SpriteJsonLoaderLoadFailed Load has failed");
}

////////////////////////////////////////

SD_ExpandableSpriteJsonLoaderLoadFailed::SD_ExpandableSpriteJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_ExpandableSpriteJsonLoaderLoadFailed", exc_description)
{

}
SD_ExpandableSpriteJsonLoaderLoadFailed::SD_ExpandableSpriteJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_ExpandableSpriteJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_ExpandableSpriteJsonLoaderLoadFailed Load has failed");
}

////////////////////////////////////////


SD_SoundBufferJsonLoaderLoadFailed::SD_SoundBufferJsonLoaderLoadFailed(
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed("SD_SoundBufferJsonLoaderLoadFailed", exc_description)
{

}
SD_SoundBufferJsonLoaderLoadFailed::SD_SoundBufferJsonLoaderLoadFailed(
    const std::string& exc_name,
    const std::string& exc_description
) : SD_JsonLoaderLoadFailed(exc_name, exc_description) 
{

}
std::string SD_SoundBufferJsonLoaderLoadFailed::DefaultExceptionDescription() const {
    return std::string("SD_SoundBufferJsonLoaderLoadFailed Load has failed");
}

////////////////////////////////////////


}

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_JsonLoader)
SD_JsonLoader::SD_JsonLoader(
    SD_Resources& resources_ref,
    const std::string& type 
) : type(type), resources_ref(resources_ref)
{

}
void SD_JsonLoader::LoadFromJson(const nlohmann::json& json) {

}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_FontJsonLoader)
SD_FontJsonLoader::SD_FontJsonLoader(SD_Resources& ref)
 : SD_JsonLoader(ref, "sf::Font") 
{
    
}
void SD_FontJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("type");
    if (it != json.end()) {
        std::string str_type = *it;

        if (str_type.compare("already_loaded") == 0) {
            JsonLoad_LoadAlreadyLoaded(json);
        } else if (str_type.compare("load_to_resources") == 0) {
            JsonLoad_LoadFromFile(json);
        } else {
            font=nullptr;

            auto e = exc::SD_FontJsonLoaderLoadFailed(
                "type in SD_FontJsonLoader is not \"already_loaded\", nor \"load_to_resources\", but it's \n"
                "= " + str_type
            );
            throw e;
        }
    } else {
        font = nullptr;

        auto e = exc::SD_FontJsonLoaderLoadFailed(
            "type in SD_FontJsonLoader is not found"
        );
        throw e;
    }
}
void SD_FontJsonLoader::JsonLoad_LoadFromFile(const nlohmann::json& json) {
    auto it = json.find("filepath");
    if (it != json.end()) {
        std::string filepath_str = *it;
        auto it2 = json.find("resource_id");
        if (it2 != json.end()) {
            std::string res_id = *it2;

            auto& fonts = resources_ref.GetFontResourcesRef();

            bool loaded = fonts.LoadFont(res_id, filepath_str);

            if (loaded) {
                font = &fonts.GetFont(res_id);
            } else {
                font = nullptr;

                auto e = exc::SD_FontJsonLoaderLoadFailed(
                "Unable to load font (sf::Font) to SD_FontResources from SD_FontJsonLoader"
                );
                throw e;
            }
        } else {
            font = nullptr;

            auto e = exc::SD_FontJsonLoaderLoadFailed(
                "resource_id in SD_FontJsonLoader is not found"
            );
            throw e;
        }
    } else {
        font = nullptr;

        auto e = exc::SD_FontJsonLoaderLoadFailed(
            "filepath in SD_FontJsonLoader is not found"
        );
        throw e;
    }
}
void SD_FontJsonLoader::JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json) {
    auto it = json.find("resource_id");
    if (it != json.end()) {
        std::string id = *it;

        auto& fonts = resources_ref.GetFontResourcesRef();

        if(fonts.FontExists(id)) {
            font = &fonts.GetFont(id);
        } else {
            font = nullptr;

            auto e = exc::SD_FontJsonLoaderLoadFailed(
                "Unable to find font in SD_FontResources with the id of " + id
            );
            throw e;
        }
    } else {
        font = nullptr;

        auto e = exc::SD_FontJsonLoaderLoadFailed(
            "resource_id in SD_FontJsonLoader is not found"
        );
        throw e;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_TextJsonLoader)
SD_TextJsonLoader::SD_TextJsonLoader(SD_Resources& ref)
 : SD_JsonLoader(ref, "sf::Text")
{
    
}
void SD_TextJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("type");
    if (it != json.end()) {
         std::string str_type = *it;

         if (str_type.compare("already_loaded") ==0) {
              JsonLoad_LoadAlreadyLoaded(json);
         } else if (str_type.compare("load_to_resources") ==0) {
             JsonLoad_LoadFromFile(json);
         } else {
            text = nullptr;
            auto e = exc::SD_TextJsonLoaderLoadFailed(
                "type in SD_TextJsonLoader is not \"already_loaded\", nor \"load_to_resources\", but it's \n"
                "= " + str_type
            );
            throw e;
            
         }
    } else {
        text = nullptr;
        auto e = exc::SD_TextJsonLoaderLoadFailed(
            "type in SD_TextJsonLoader is not found"
        );
        throw e;
        
    }
}
void SD_TextJsonLoader::JsonLoad_LoadFromFile(const nlohmann::json& json) {
    auto it = json.find("font");
    if (it != json.end()) {
        const nlohmann::json& font_json = *it;
        auto it2 = json.find("resource_id");

        if (it2 != json.end()) {
            std::string res_id = *it2;
            auto& texts = resources_ref.GetTextResourcesRef();
            SD_FontJsonLoader font_loader(resources_ref);

            font_loader.LoadFromJson(font_json);
            if (font_loader.GetFont() == nullptr) {
                text = nullptr;
                auto e = exc::SD_TextJsonLoaderLoadFailed(
                    "Unable to load font in SD_FontJsonLoader from SD_TextJsonLoader"
                );
                throw e;
            } else {
                const sf::Font* font = font_loader.GetFont();

                sf::Text text;
                text.setFont(*font);

                JsonLoad_LoadTextParams(text, json);

                texts.AddText(res_id, text);         
                this->text = &texts.GetText(res_id);
            }
        } else {
            text = nullptr;
            auto e = exc::SD_TextJsonLoaderLoadFailed(
                "resource_id in SD_TextFontLoader is not found"
            );
            throw e;
        }
    } else {
        text = nullptr;
        auto e = exc::SD_TextJsonLoaderLoadFailed(
            "filepath in SD_TextJsonLoader is not found"
        );
        throw e;
    }
}
void SD_TextJsonLoader::JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json) {
    auto it = json.find("resource_id");
    if (it != json.end()) {
        std::string id = *it;

        auto& texts = resources_ref.GetTextResourcesRef();

        if (texts.TextExists(id)) {
            text = &texts.GetText(id);
        } else {
            text = nullptr;

            auto e =exc::SD_TextJsonLoaderLoadFailed(
                "Unable to find texture in SD_TextureResources with the id of " + id
            );
            throw e;
        }
    } else {    
        text = nullptr;

        auto e = exc::SD_TextJsonLoaderLoadFailed(
            "resource_id in SD_TextJsonLoader is not found"
        );
        throw e;
    }
}
void SD_TextJsonLoader::JsonLoad_LoadTextParams(sf::Text& text, const nlohmann::json& json ){
    auto character_size_it = json.find("character_size");
    auto fill_color_it = json.find("fill_color");
    auto string_it = json.find("string_text");

    if (character_size_it != json.end()) {
        text.setCharacterSize((int)*character_size_it);
    } else {
        text.setCharacterSize(12);
    }
    if (fill_color_it != json.end()) {

    } else {
        text.setFillColor(sf::Color::White);
    }
    if (string_it != json.end()) {
        text.setString(std::string(*string_it));
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_TextureJsonLoader)
SD_TextureJsonLoader::SD_TextureJsonLoader(SD_Resources& ref) 
 : SD_JsonLoader(ref, "sf::Texture") 
{

}
void SD_TextureJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("type");
    if (it != json.end()) {
        std::string str_type = *it;

        if (str_type.compare("already_loaded") == 0) {
            JsonLoad_LoadAlreadyLoaded(json);
        } else if (str_type.compare("load_to_resources") == 0) {
            JsonLoad_LoadFromFile(json);
        } else {
            texture = nullptr;   
            auto e = exc::SD_TextureJsonLoaderLoadFailed(
                "type in SD_TextureJsonLoader is not \"already_loaded\", nor \"load_to_resources\", but it's \n"
                "= " + str_type
            );
            throw e;
        }
    } else {
        texture = nullptr;
        auto e = exc::SD_TextureJsonLoaderLoadFailed(
            "type in SD_TextureJsonLoader is not found"
        );
        throw e;
    }
}
void SD_TextureJsonLoader::JsonLoad_LoadFromFile(const nlohmann::json& json) {
    auto it = json.find("filepath");
    if (it != json.end()) {
        std::string filepath_str = *it;
        auto it2 = json.find("resource_id");
        if (it2 != json.end()) {
            std::string res_id = *it2;

            auto& textures = resources_ref.GetTextureResourcesRef();

            bool loaded = textures.LoadTexture(res_id, filepath_str);

            if (loaded) {
                texture = textures.GetTexture(res_id).get();
            } else {
                texture = nullptr;

                auto e = exc::SD_FontJsonLoaderLoadFailed(
                "Unable to load texture (sf::Texture) to SD_TextureResources from SD_TextureJsonLoader"
                );
                throw e;
            }
        } else {
            texture = nullptr;
        
            auto e = exc::SD_TextureJsonLoaderLoadFailed(
                "resource_id in SD_TextureJsonLoader is not found"
            );
            throw e;
        }
    } else {
        texture = nullptr;

        auto e = exc::SD_TextureJsonLoaderLoadFailed(
            "filepath in SD_TextureJsonLoader is not found"
        );
        throw e;
    }
}
void SD_TextureJsonLoader::JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json) {
    auto it = json.find("resource_id");
    if (it != json.end()) {
        std::string id = *it;

        auto& textures = resources_ref.GetTextureResourcesRef();

        if (textures.TextureExists(id)) {
            texture = textures.GetTexture(id).get();
        } else {
            texture = nullptr;
        
            auto e = exc::SD_TextureJsonLoaderLoadFailed(
                "Unable to find texture in SD_TextureResources with the id of " + id
            );
            throw e;
        }
    } else {
        texture = nullptr;
    
        auto e = exc::SD_TextureJsonLoaderLoadFailed(
            "resource_id in SD_TextureJsonLoader is not found"
        );
        throw e;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SpriteJsonLoader)
SD_SpriteJsonLoader::SD_SpriteJsonLoader(SD_Resources& ref) 
: SD_JsonLoader(ref, "sf::Sprite")
{

}
void SD_SpriteJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("type");
    if (it != json.end()) {
        std::string str_type = *it;

        if (str_type.compare("already_loaded") == 0) {
            JsonLoad_LoadAlreadyLoaded(json);
        } else if (str_type.compare("load_to_resources") ==0) {
            JsonLoad_LoadFromFile(json);
        } else {
            sprite = nullptr;

            auto e = exc::SD_SpriteJsonLoaderLoadFailed(
                "type in SD_SpriteJsonLoader is not \"already_loaded\", nor \"load_to_resources\", but it's \n"
                "= " + str_type
            );
            throw e;
        }
    } else {
        sprite = nullptr;

        auto e = exc::SD_SpriteJsonLoaderLoadFailed(
            "type in SD_SpriteJsonLoader is not found"
        );
        throw e;
    }
}

void SD_SpriteJsonLoader::JsonLoad_LoadFromFile(const nlohmann::json& json) {
    auto it = json.find("texture");
    if (it != json.end()) {
        auto it2 = json.find("resource_id");
        const nlohmann::json& t = *it;

        if (it2 != json.end()) {
            std::string res_id = *it2;
            SD_TextureJsonLoader loader(resources_ref);
            loader.LoadFromJson(t);

            if(loader.GetTexture() != nullptr) {
                const sf::Texture* texture = loader.GetTexture();

                auto& sprites = resources_ref.GetSpriteResourcesRef();

                sprites.AddSprite(res_id, *texture);
                this->sprite = &sprites.GetSprite(res_id);
            } else {

                sprite = nullptr;
                auto e = exc::SD_SpriteJsonLoaderLoadFailed(
                    "Unable to load texture (sf::Texture) using SD_TextureJsonLoader in SD_SpriteJsonLoader"
                );
                throw e;
            }
        } else {
            sprite = nullptr;

            auto e = exc::SD_SpriteJsonLoaderLoadFailed(
                "resource_id in SD_SpriteJsonLoader is not found"
            );
            throw e;
        }
    } else {
        sprite = nullptr;

        auto e = exc::SD_SpriteJsonLoaderLoadFailed(
            "texture in SD_SpriteJsonLoader is not found"
        );
        throw e;
    }
}
void SD_SpriteJsonLoader::JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json) {
    auto it = json.find("resource_id");
    if (it != json.end()) {
        std::string res_id = *it;

        auto& sprites = resources_ref.GetSpriteResourcesRef();

        if (sprites.SpriteExists(res_id)) {
            this->sprite = &sprites.GetSprite(res_id);
        } else {
            sprite = nullptr;

            auto e = exc::SD_SpriteJsonLoaderLoadFailed(
                "Unable to find sprite in SD_SpriteResources with the id of " + res_id
            );
            throw e;
        }
    } else {
        sprite = nullptr;

        auto e = exc::SD_SpriteJsonLoaderLoadFailed(
            "resource_id in SD_SpriteJsonLoader is not found"
        );
        throw e;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ExpandableSpriteJsonLoader)
SD_ExpandableSpriteJsonLoader::SD_ExpandableSpriteJsonLoader(SD_Resources& ref)
 : SD_JsonLoader(ref, "SD_ExpandableSprite")
{

}
void SD_ExpandableSpriteJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("expandable_sprite_type");
    auto type_it = json.find("type");
    auto res_it = json.find("resource_id");
    if (it != json.end() && res_it != json.end() && type_it != json.end()) {
        std::string expandable_sprite_type_str = *it;
        std::string res_id = *res_it;
        std::string type = *type_it;
        if (type.compare("load_to_resources") == 0) {
            if (expandable_sprite_type_str.compare("nine") == 0) {
                auto it2 = json.find("textures");
                if (it2 != json.end()) {
                    const nlohmann::json& textures_json = *it2;

                    JsonLoad_LoadNineTextures(res_id, textures_json);
                } else {    
                    auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                        "textures in SD_ExpandableSpriteJsonLoader is not found"
                    );
                    throw e;
                }
            } else if (expandable_sprite_type_str.compare("six_top") == 0) {
                //TODO
            } else if (expandable_sprite_type_str.compare("six_bottom") == 0) {
                //TODO
            } else if (expandable_sprite_type_str.compare("six_left") == 0) {
                //TODO
            } else if (expandable_sprite_type_str.compare("six_right") == 0) {
                //TODO
            } else if (expandable_sprite_type_str.compare("three_horizontal") == 0) {
                auto it2 = json.find("textures");
                if (it2 != json.end()) {
                    const nlohmann::json& textures_json = *it2;

                    JsonLoad_LoadThreeHorizontalTextures(res_id, textures_json);
                } else {
                    auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                        "textures in SD_ExpandableSpriteJsonLoader is not found"
                    );
                    throw e;
                }
            } else if (expandable_sprite_type_str.compare("three_vertical") == 0) {
                auto it2 = json.find("textures");
                if (it != json.end()) {
                    const nlohmann::json& textures_json = *it2;

                    JsonLoad_LoadThreeVerticalTextures(res_id, textures_json);
                } else {
                    auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                        "textures in SD_ExpandableSpriteJsonLoader is not found"
                    );
                    throw e;
                }
            }
        } else if (type.compare("already_loaded") == 0) {
            //TODO
        }
    } else {

        sprite = nullptr;

        if (it == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "expandable_sprite_type in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (res_it == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "type in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (type_it == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "resource_id in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } 

        
    }
}
void SD_ExpandableSpriteJsonLoader::JsonLoad_LoadThreeVerticalTextures(
    const std::string& res_id, const nlohmann::json& json
) {
    auto it_top = json.find("top");
    auto it_mid = json.find("mid");
    auto it_bottom = json.find("bottom");

    if (it_top != json.end() && it_mid != json.end() && it_bottom != json.end()) {
        SD_TextureJsonLoader top_loader(resources_ref);
        SD_TextureJsonLoader mid_loader(resources_ref);
        SD_TextureJsonLoader bottom_loader(resources_ref);

        const nlohmann::json& top_json = *it_top;
        const nlohmann::json& mid_json = *it_mid;
        const nlohmann::json& bottom_json = *it_bottom;

        top_loader.LoadFromJson(top_json);
        mid_loader.LoadFromJson(mid_json);
        bottom_loader.LoadFromJson(bottom_json);

        bool top_loaded = top_loader.TextureLoaded();
        bool mid_loaded = mid_loader.TextureLoaded();
        bool bottom_loaded = bottom_loader.TextureLoaded();

        if (top_loaded && mid_loaded && bottom_loaded) {
            const sf::Texture* top_texture = top_loader.GetTexture();
            const sf::Texture* mid_texture = mid_loader.GetTexture();
            const sf::Texture* bottom_texture = bottom_loader.GetTexture();

            auto& expandable_sprites = resources_ref.GetExpandableSpriteResourcesRef();

            std::unique_ptr<SD_ExpandableSprite> sprite;
            sprite = std::make_unique<SD_ExpandableSprite>();
            sprite->InitializeVertical(
                *top_texture,
                *mid_texture,
                *bottom_texture
            );
            expandable_sprites.AddExpandableSprite(res_id, std::move(sprite));
            this->sprite = &expandable_sprites.GetExpandableSprite(res_id);
        } else {
            if (top_loaded == false ){
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::top using SD_TextureJsonLoader"
                );
                throw e;
            } else if (mid_loaded == false) {
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::mid using SD_TextureJsonLoader"
                );
                throw e;
            } else if (bottom_loaded == false) {
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::bottom using SD_TextureJsonLoader"
                );
                throw e;
            }
            sprite = nullptr;
        }
    } else {
        if (it_top == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::top in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (it_mid == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::mid in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (it_bottom == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::bottom in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        }
    }
}
void SD_ExpandableSpriteJsonLoader::JsonLoad_LoadThreeHorizontalTextures(
    const std::string& res_id, const nlohmann::json& json
 ){
    auto it_left = json.find("left");
    auto it_mid = json.find("mid");
    auto it_right = json.find("right");

    if (it_left != json.end() && it_mid != json.end() && it_right != json.end()) {
        SD_TextureJsonLoader left_loader(resources_ref);
        SD_TextureJsonLoader mid_loader(resources_ref);
        SD_TextureJsonLoader right_loader(resources_ref);

        const nlohmann::json& left_json = *it_left;
        const nlohmann::json& mid_json = *it_mid;
        const nlohmann::json& right_json = *it_right;

        left_loader.LoadFromJson(left_json);
        mid_loader.LoadFromJson(mid_json);
        right_loader.LoadFromJson(right_json);

        bool left_loaded = left_loader.TextureLoaded();
        bool mid_loaded = mid_loader.TextureLoaded();
        bool right_loaded = right_loader.TextureLoaded();

        if (left_loaded && mid_loaded && right_loaded) {
            const sf::Texture* left_texture = left_loader.GetTexture();
            const sf::Texture* mid_texture = mid_loader.GetTexture();
            const sf::Texture* right_texture = right_loader.GetTexture();

            auto& expandable_sprites = resources_ref.GetExpandableSpriteResourcesRef();
        
            std::unique_ptr<SD_ExpandableSprite> sprite;
            sprite = std::make_unique<SD_ExpandableSprite>();
            sprite->InitializeHorizontal(
                *left_texture,
                *mid_texture,
                *right_texture
            );

            expandable_sprites.AddExpandableSprite(res_id, std::move(sprite));
            this->sprite = &expandable_sprites.GetExpandableSprite(res_id);
        } else {    
            if(left_loaded == false) {
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::left using SD_TextureJsonLoader"
                );
                throw e;
            } else if (mid_loaded == false) {
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::mid using SD_TextureJsonLoader"
                );
                throw e;
            } else if (right_loaded == false) {
                auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                    "Unable to build texture from textures::right using SD_TextureJsonLoader"
                );
                throw e;
            }

            sprite = nullptr;
        }
    } else {
        if (it_left == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::left in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (it_mid == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::mid in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        } else if (it_right == json.end()) {
            auto e = exc::SD_ExpandableSpriteJsonLoaderLoadFailed(
                "textures::right in SD_ExpandableSpriteJsonLoader is not found"
            );
            throw e;
        }

        sprite = nullptr;
    }
}
void SD_ExpandableSpriteJsonLoader::JsonLoad_LoadNineTextures(
    const std::string& res_id, const nlohmann::json& json
) {
    auto it_top_left = json.find("top_left");
    auto it_top = json.find("top");
    auto it_top_right = json.find("top_right");
    auto it_left = json.find("left");
    auto it_mid = json.find("mid");
    auto it_right = json.find("right");
    auto it_bottom_left = json.find("bottom_left");
    auto it_bottom = json.find("bottom");
    auto it_bottom_right = json.find("bottom_right");

    if (
        it_top_left != json.end() &&
        it_top != json.end() &&
        it_top_right != json.end() &&
        it_left != json.end() &&
        it_mid != json.end() &&
        it_right != json.end() &&
        it_bottom_left != json.end() &&
        it_bottom != json.end() &&
        it_bottom_right != json.end()
    ) {
        SD_TextureJsonLoader top_left_loader(resources_ref);
        SD_TextureJsonLoader top_loader(resources_ref);
        SD_TextureJsonLoader top_right_loader(resources_ref);
        SD_TextureJsonLoader left_loader(resources_ref);
        SD_TextureJsonLoader mid_loader(resources_ref);
        SD_TextureJsonLoader right_loader(resources_ref);
        SD_TextureJsonLoader bottom_left_loader(resources_ref);
        SD_TextureJsonLoader bottom_loader(resources_ref);
        SD_TextureJsonLoader bottom_right_loader(resources_ref);

        const nlohmann::json& top_left_json = *it_top_left;
        const nlohmann::json& top_json = *it_top;
        const nlohmann::json& top_right_json = *it_top_right;
        const nlohmann::json& left_json = *it_left;
        const nlohmann::json& mid_json = *it_mid;
        const nlohmann::json& right_json = *it_right;
        const nlohmann::json& bottom_left_json = *it_bottom_left;
        const nlohmann::json& bottom_json = *it_bottom;
        const nlohmann::json& bottom_right_json = *it_bottom_right;

        top_left_loader.LoadFromJson(top_left_json);
        top_loader.LoadFromJson(top_json);
        top_right_loader.LoadFromJson(top_right_json);
        left_loader.LoadFromJson(left_json);
        mid_loader.LoadFromJson(mid_json);
        right_loader.LoadFromJson(right_json);
        bottom_left_loader.LoadFromJson(bottom_left_json);
        bottom_loader.LoadFromJson(bottom_json);
        bottom_right_loader.LoadFromJson(bottom_right_json);

        bool top_left_loaded = top_left_loader.TextureLoaded();
        bool top_loaded = top_loader.TextureLoaded();
        bool top_right_loaded = top_right_loader.TextureLoaded();
        bool left_loaded = left_loader.TextureLoaded();
        bool mid_loaded = mid_loader.TextureLoaded();
        bool right_loaded = right_loader.TextureLoaded();
        bool bottom_left_loaded = bottom_left_loader.TextureLoaded();
        bool bottom_loaded = bottom_loader.TextureLoaded();
        bool bottom_right_loaded = bottom_right_loader.TextureLoaded();

        if (
            top_left_loaded &&
            top_loaded &&
            top_right_loaded &&
            left_loaded &&
            mid_loaded &&
            right_loaded &&
            bottom_left_loaded &&
            bottom_loaded && 
            bottom_right_loaded
        ) {
            const sf::Texture* top_left_texture = top_left_loader.GetTexture();
            const sf::Texture* top_texture = top_loader.GetTexture();
            const sf::Texture* top_right_texture = top_right_loader.GetTexture();
            const sf::Texture* left_texture = left_loader.GetTexture();
            const sf::Texture* mid_texture = mid_loader.GetTexture();
            const sf::Texture* right_texture = right_loader.GetTexture();
            const sf::Texture* bottom_left_texture = bottom_left_loader.GetTexture();
            const sf::Texture* bottom_texture = bottom_loader.GetTexture();
            const sf::Texture* bottom_right_texture = bottom_right_loader.GetTexture();

            auto& expandable_sprites = resources_ref.GetExpandableSpriteResourcesRef();

            std::unique_ptr<SD_ExpandableSprite> sprite;
            sprite = std::make_unique<SD_ExpandableSprite>();
            sprite->InitializeAsNine(
                *top_left_texture,
                *top_texture,
                *top_right_texture,
                *left_texture,
                *mid_texture,
                *right_texture,
                *bottom_left_texture,
                *bottom_texture,
                *bottom_right_texture
            );
            expandable_sprites.AddExpandableSprite(res_id, std::move(sprite));
            this->sprite = &expandable_sprites.GetExpandableSprite(res_id);
        } else {
            //Exception
        }
    } else {
        //Exception
    }
}
////////////////////////////////////////

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SoundBufferJsonLoader)
SD_SoundBufferJsonLoader::SD_SoundBufferJsonLoader(SD_Resources& ref)
 : SD_JsonLoader(ref, "sf::SoundBuffer")
{

}
void SD_SoundBufferJsonLoader::LoadFromJson(const nlohmann::json& json) {
    auto it = json.find("type");
    if (it != json.end()) {
        std::string str_type = *it;

        if (str_type.compare("already_loaded") == 0) {
            JsonLoad_LoadAlreadyLoaded(json);
        } else if (str_type.compare("load_to_resources") == 0) {
            JsonLoad_LoadFromFile(json);
        } else {
            sound_buffer = nullptr;
            auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
                "type in SoundBufferJsonLoader is not \"already_loaded\", nor \"load_to_resources\", but it's \n"
                "= " + str_type
            );
            throw e;
        }
    } else {
        sound_buffer = nullptr;
        auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
            "type in SD_SoundBufferJsonLoader is not found"
        );
        throw e;
    }
}
void SD_SoundBufferJsonLoader::JsonLoad_LoadFromFile(const nlohmann::json& json) {
    auto it = json.find("filepath");
    if (it != json.end()) {
        std::string filepath_str = *it;
        auto it2 = json.find("resource_id");
        if (it2 != json.end()) {
            std::string res_id = *it2;

            auto& sound_buffers = resources_ref.GetSoundBufferResourcesRef();
            bool loaded = sound_buffers.LoadSoundBuffer(res_id, filepath_str);

            if (loaded) {
                sound_buffer = &sound_buffers.GetSoundBuffer(res_id);
            } else {
                sound_buffer = nullptr;

                auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
                    "Unable to load sound_buffer (sf::SoundBuffer) in SD_SoundBufferResources from SD_SoundBufferJsonLoader"
                );
                throw e;
            }
        } else {
            sound_buffer = nullptr;
        
            auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
                "resource_id in SD_SoundBufferJsonLoader is not found"
            );
            throw e;
        }
    } else {
        sound_buffer = nullptr;

        auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
            "filepath in SD_SoundBufferJsonLoader is not found"
        );
        throw e;
    }
}
void SD_SoundBufferJsonLoader::JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json) {
    auto it = json.find("resource_id");
    if (it != json.end()) {
        std::string id = *it;

        auto& sound_buffers = resources_ref.GetSoundBufferResourcesRef();
        
        if (sound_buffers.SoundBufferExists(id)) {
            sound_buffer = &sound_buffers.GetSoundBuffer(id);
        } else {
            sound_buffer = nullptr;

            auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
                "Unable to find sound_buffer in SD_SoundBufferResources with the id of " + id
            );
            throw e;
        }
    } else {
        sound_buffer = nullptr;

        auto e = exc::SD_SoundBufferJsonLoaderLoadFailed(
            "resource_id in SD_SoundBufferJsonLoader is not found"
        );
        throw e;
    }
}
////////////////////////////////////////

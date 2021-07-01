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
// File: /impl/include/SigmaDev/Json/JsonLoader.h
// Description:
// Additional Notes:

#ifndef SD_SIGMADEV_JSON_LOADER_H
#define SD_SIGMADEV_JSON_LOADER_H

#include <string>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SigmaDev/Exception/Exception.h>
#include <SigmaDev/Misc/Class.h>

class SD_Resources;
class SD_ExpandableSprite;

namespace exc {

////////////////////////////////////////

class SD_JsonLoaderLoadFailed : public SD_Exception {
public:
    SD_JsonLoaderLoadFailed() = delete;
protected:
    SD_JsonLoaderLoadFailed(
        const std::string& exc_name
    );
    SD_JsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_JsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////

class SD_FontJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_FontJsonLoaderLoadFailed() = delete;
    SD_FontJsonLoaderLoadFailed(const std::string& description);
protected:
    SD_FontJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_FontJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////

class SD_TextJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_TextJsonLoaderLoadFailed() = delete;
    SD_TextJsonLoaderLoadFailed(const std::string& description);
protected:
    SD_TextJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_TextJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////

class SD_TextureJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_TextureJsonLoaderLoadFailed() = delete;
    SD_TextureJsonLoaderLoadFailed(const std::string& description);
protected:
    SD_TextureJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_TextureJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////

class SD_SpriteJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_SpriteJsonLoaderLoadFailed() = delete;
    SD_SpriteJsonLoaderLoadFailed(const std::string& description);
protected:
    SD_SpriteJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_SpriteJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};


////////////////////////////////////////

class SD_ExpandableSpriteJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_ExpandableSpriteJsonLoaderLoadFailed() = delete;
    SD_ExpandableSpriteJsonLoaderLoadFailed(const std::string& description);
protected:
    SD_ExpandableSpriteJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_ExpandableSpriteJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////

class SD_SoundBufferJsonLoaderLoadFailed : public SD_JsonLoaderLoadFailed {
public:
    SD_SoundBufferJsonLoaderLoadFailed() = delete;
    SD_SoundBufferJsonLoaderLoadFailed(const std::string& exc_description);
protected:
    SD_SoundBufferJsonLoaderLoadFailed(
        const std::string& exc_name,
        const std::string& exc_description
    );
public:
    virtual ~SD_SoundBufferJsonLoaderLoadFailed() = default;
    virtual std::string DefaultExceptionDescription() const override;
};

////////////////////////////////////////
}

////////////////////////////////////////
class SD_JsonLoader : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
    SD_JsonLoader() = delete;
    SD_JsonLoader(SD_Resources& resources_ref, const std::string& type);
    virtual ~SD_JsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json);

    inline const std::string& GetType() const {
        return type;
    }
protected:
    std::string type;
    SD_Resources& resources_ref;
};
////////////////////////////////////////
class SD_FontJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_FontJsonLoader(SD_Resources& ref);
    virtual ~SD_FontJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool FontLoaded() const {
        if (font == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    inline const sf::Font* GetFont() const {
        return font;
    }
protected:
    virtual void JsonLoad_LoadFromFile(const nlohmann::json& json);
    virtual void JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json);

    const sf::Font* font = nullptr;
};
////////////////////////////////////////
class SD_TextJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_TextJsonLoader(SD_Resources& ref);
    virtual ~SD_TextJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool TextLoaded() const {
        if (text == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    inline const sf::Text* GetText() const {
        return text;
    }
protected:
    virtual void JsonLoad_LoadFromFile(const nlohmann::json& json);
    virtual void JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json);
    
    virtual void JsonLoad_LoadTextParams(sf::Text& text, const nlohmann::json& json);

    const sf::Text* text = nullptr;
};
////////////////////////////////////////
class SD_TextureJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_TextureJsonLoader(SD_Resources& ref);
    virtual ~SD_TextureJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool TextureLoaded() const {
        if (texture == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    inline const sf::Texture* GetTexture() const {
        return texture;
    }
protected:
    virtual void JsonLoad_LoadFromFile(const nlohmann::json& json);
    virtual void JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json); 

    const sf::Texture* texture = nullptr;
};
////////////////////////////////////////
class SD_SpriteJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_SpriteJsonLoader(SD_Resources& ref);
    virtual ~SD_SpriteJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool SpriteInitialized() const {
        if (sprite == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    inline const std::unique_ptr<sf::Sprite>* GetSprite() const {
        return sprite;
    }
protected:
    virtual void JsonLoad_LoadFromFile(const nlohmann::json& json);
    virtual void JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json); 

    std::unique_ptr<sf::Sprite>* sprite = nullptr;
};  
////////////////////////////////////////
class SD_ExpandableSpriteJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_ExpandableSpriteJsonLoader(SD_Resources& ref);
    virtual ~SD_ExpandableSpriteJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool SpriteLoaded() const {
        if (sprite == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    inline std::unique_ptr<SD_ExpandableSprite>* GetSprite() const {
        return sprite;
    }
protected:
    virtual void JsonLoad_LoadThreeVerticalTextures(
        const std::string& res_id,
        const nlohmann::json& json);

    virtual void JsonLoad_LoadThreeHorizontalTextures(
        const std::string& res_id, 
        const nlohmann::json& json);
        
    virtual void JsonLoad_LoadNineTextures(
        const std::string& res_id,
        const nlohmann::json& json);


    std::unique_ptr<SD_ExpandableSprite>* sprite = nullptr;
};
////////////////////////////////////////
class SD_SoundBufferJsonLoader : public SD_JsonLoader {
public:
    SD_DECLARE_CLASS_H()

    SD_SoundBufferJsonLoader(SD_Resources& ref);
    virtual ~SD_SoundBufferJsonLoader() = default;

    virtual void LoadFromJson(const nlohmann::json& json) override;

    inline bool SoundBufferLoaded() const {
        if (sound_buffer == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    inline const sf::SoundBuffer* GetSoundBuffer() const {
        return sound_buffer;
    }
protected:
    virtual void JsonLoad_LoadFromFile(const nlohmann::json& json);
    virtual void JsonLoad_LoadAlreadyLoaded(const nlohmann::json& json); 

    const sf::SoundBuffer* sound_buffer = nullptr;
};  
////////////////////////////////////////

#endif
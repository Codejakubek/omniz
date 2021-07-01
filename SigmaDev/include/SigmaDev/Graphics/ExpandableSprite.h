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
// File: /impl/include/SigmaDev/Graphics/ExpandableSprite.h
// Description:
// Additional Notes:

#ifndef SD_GRAPHICS_EXPANDABLE_SPRITE_H
#define SD_GRAPHICS_EXPANDABLE_SPRITE_H

#include <SFML/Graphics.hpp>
#include <memory.h>
#include <array>
#include <functional>
#include <SigmaDev/Graphics/ComplexDrawable.h>
#include <SigmaDev/Misc/Class.h>

class SD_Application;
class SD_ExpandableSprite;
class SD_TextureResources;

////////////////////////////////////////
/**
 * @brief Specify the graphic layout of SD_ExpandableSprite 
 * @ingroup graphics_module
 */
enum SD_ExpandableSpriteType {
    SD_EXPANDABLE_SPRITE_UNKNOWN_TYPE,
    SD_EXPANDABLE_SPRITE_NINE,
    SD_EXPANDABLE_SPRITE_SIX_TOP,
    SD_EXPANDABLE_SPRITE_SIX_BOTTOM,
    SD_EXPANDABLE_SPRITE_SIX_LEFT,
    SD_EXPANDABLE_SPRITE_SIX_RIGHT,
    SD_EXPANDABLE_SPRITE_FOUR_TOP_LEFT,
    SD_EXPANDABLE_SPRITE_FOUR_TOP_RIGHT,
    SD_EXPANDABLE_SPRITE_FOUR_BOTTOM_LEFT,
    SD_EXPANDABLE_SPRITE_FOUR_BOTTOM_RIGHT,
    SD_EXPANDABLE_SPRITE_THREE_HORIZONTAL,
    SD_EXPANDABLE_SPRITE_THREE_VERTICAL
};
////////////////////////////////////////
class SD_ExpandableSpriteMatrix : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_ExpandableSpriteMatrix() = delete;
    SD_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const SD_ExpandableSpriteType& type);
    SD_ExpandableSpriteMatrix(
        const SD_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& base
    );
    SD_ExpandableSpriteMatrix(
        const SD_ExpandableSpriteMatrix& cpy
    ) = delete;
    virtual ~SD_ExpandableSpriteMatrix() = default;

    virtual void Render(SD_RenderWindowAccess& window_access) = 0;

    inline const SD_ExpandableSpriteType& GetType() const {
        return type;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const = 0;
protected:
    virtual bool VerifySizes() = 0;
public:
    virtual void Update() = 0;
protected:
    const sf::Vector2i& GetPosition() const;
    const sf::Vector2i& GetSize() const;
    const sf::Vector2i& GetOrigin() const; 

    const SD_ExpandableSpriteType type;

    SD_ExpandableSprite& base;
};
////////////////////////////////////////
class SD_Nine_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()
    SD_Nine_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
        );
    SD_Nine_ExpandableSpriteMatrix(
        const SD_Nine_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& base    
    );
    SD_Nine_ExpandableSpriteMatrix(
        const SD_Nine_ExpandableSpriteMatrix& cpy
    ) = delete;

    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTopLeft() const {
        return top_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTopRight() const {
        return top_right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomLeft() const {
        return bottom_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomRight() const {
        return bottom_right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> top_left;
    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> top_right;
    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
    std::unique_ptr<sf::Sprite> bottom_left;
    std::unique_ptr<sf::Sprite> bottom;
    std::unique_ptr<sf::Sprite> bottom_right;
};
////////////////////////////////////////
class SD_SixTop_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_SixTop_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    SD_SixTop_ExpandableSpriteMatrix(
        const SD_SixTop_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTopLeft() const {
        return top_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTopRight() const {
        return top_right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }

    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> top_left;
    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> top_right;
    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
};
////////////////////////////////////////
class SD_SixBottom_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_SixBottom_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    SD_SixBottom_ExpandableSpriteMatrix(
        const SD_SixBottom_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomLeft() const {
        return bottom_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomRight() const {
        return bottom_right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;


    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
    std::unique_ptr<sf::Sprite> bottom_left;
    std::unique_ptr<sf::Sprite> bottom;
    std::unique_ptr<sf::Sprite> bottom_right;
};
////////////////////////////////////////
class SD_SixLeft_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_SixLeft_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
    );
    SD_SixLeft_ExpandableSpriteMatrix(
        const SD_SixLeft_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTopLeft() const {
        return top_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomLeft() const {
        return bottom_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> top_left;
    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> bottom_left;
    std::unique_ptr<sf::Sprite> bottom;
};
////////////////////////////////////////
class SD_SixRight_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()
    SD_SixRight_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    SD_SixRight_ExpandableSpriteMatrix(
        const SD_SixRight_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTopRight() const {
        return top_right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomRight() const {
        return bottom_right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> top_right;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
    std::unique_ptr<sf::Sprite> bottom;
    std::unique_ptr<sf::Sprite> bottom_right;
};
////////////////////////////////////////
class SD_FourTopLeft_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()
    SD_FourTopLeft_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle
    );
    SD_FourTopLeft_ExpandableSpriteMatrix(
        const SD_FourTopLeft_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTopLeft() const {
        return top_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;


    std::unique_ptr<sf::Sprite> top_left;
    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
};
////////////////////////////////////////
class SD_FourTopRight_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_FourTopRight_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    SD_FourTopRight_ExpandableSpriteMatrix(
        const SD_FourTopRight_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetTopRight() const {
        return top_right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;


    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> top_right;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
};
////////////////////////////////////////
class SD_FourBottomLeft_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_FourBottomLeft_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
    );
    SD_FourBottomLeft_ExpandableSpriteMatrix(
        const SD_FourBottomLeft_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomLeft() const {
        return bottom_left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }

    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> bottom_left;
    std::unique_ptr<sf::Sprite> bottom;
};
////////////////////////////////////////
class SD_FourBottomRight_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_FourBottomRight_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    SD_FourBottomRight_ExpandableSpriteMatrix(
        const SD_FourBottomRight_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottomRight() const {
        return bottom_right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
    std::unique_ptr<sf::Sprite> bottom;
    std::unique_ptr<sf::Sprite> bottom_right;
};
////////////////////////////////////////
class SD_ThreeHorizontal_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()

    SD_ThreeHorizontal_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    SD_ThreeHorizontal_ExpandableSpriteMatrix(
        const SD_ThreeHorizontal_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetLeft() const {
        return left;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetRight() const {
        return right;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;


    std::unique_ptr<sf::Sprite> left;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> right;
};
////////////////////////////////////////
class SD_ThreeVertical_ExpandableSpriteMatrix : public SD_ExpandableSpriteMatrix {
public:
    SD_DECLARE_CLASS_H()
    SD_ThreeVertical_ExpandableSpriteMatrix(
        SD_ExpandableSprite& base,
        const sf::Texture& top,
        const sf::Texture& middle,
        const sf::Texture& bottom
    );
    SD_ThreeVertical_ExpandableSpriteMatrix(
        const SD_ThreeVertical_ExpandableSpriteMatrix& cpy,
        SD_ExpandableSprite& rebase
    );
    virtual void Render(SD_RenderWindowAccess& window__access) override;

    inline const std::unique_ptr<sf::Sprite>& GetTop() const {
        return top;
    }
    inline const std::unique_ptr<sf::Sprite>& GetMiddle() const {
        return middle;
    }
    inline const std::unique_ptr<sf::Sprite>& GetBottom() const {
        return bottom;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteMatrix> Clone(SD_ExpandableSprite& rebase) const override;
protected:
    virtual bool VerifySizes() override;
    virtual void Update() override;

    std::unique_ptr<sf::Sprite> top;
    std::unique_ptr<sf::Sprite> middle;
    std::unique_ptr<sf::Sprite> bottom;
};
////////////////////////////////////////
class SD_ExpandableSpriteGenericCreator : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_ExpandableSpriteGenericCreator() = delete;
    SD_ExpandableSpriteGenericCreator(
        std::function<std::unique_ptr<SD_ExpandableSprite>(SD_TextureResources&)> call_func
    );
    SD_ExpandableSpriteGenericCreator(const SD_ExpandableSpriteGenericCreator& cpy);

    inline std::function<std::unique_ptr<SD_ExpandableSprite>(SD_TextureResources&)>& CallFunc() {
        return call_func;
    }
    inline const std::function<std::unique_ptr<SD_ExpandableSprite>(SD_TextureResources&)>& CallFunc() const {
        return call_func;
    }
    virtual std::unique_ptr<SD_ExpandableSpriteGenericCreator> Clone() const;

    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_Nine(
        SD_TextureResources& texture_resources,
        const std::string& top_left,
        const std::string& top,
        const std::string& top_right,
        const std::string& left,
        const std::string& mid,
        const std::string& right,
        const std::string& bottom_left,
        const std::string& bottom,
        const std::string& bottom_right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_SixTop(
        SD_TextureResources& texture_resources,
        const std::string& top_left,
        const std::string& top,
        const std::string& top_right,
        const std::string& left,
        const std::string& mid,
        const std::string& right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_SixBottom(
        SD_TextureResources& texture_resources,
        const std::string& left,
        const std::string& mid,
        const std::string& right,
        const std::string& bottom_left,
        const std::string& bottom,
        const std::string& bottom_right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_SixLeft(
        SD_TextureResources& texture_resources,
        const std::string& top_left,
        const std::string& top,
        const std::string& left,
        const std::string& mid,
        const std::string& bottom_left,
        const std::string& bottom
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_SixRight(
        SD_TextureResources& texture_resources,
        const std::string& top,
        const std::string& top_right,
        const std::string& mid,
        const std::string& right,
        const std::string& bottom,
        const std::string& bottom_right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_FourTopLeft(
        SD_TextureResources& texture_resources,
        const std::string& top_left,
        const std::string& top,
        const std::string& left,
        const std::string& mid
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_FourTopRight(
        SD_TextureResources& texture_resources,
        const std::string& top,
        const std::string& top_right,
        const std::string& mid,
        const std::string& right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_FourBottomLeft(
        SD_TextureResources& texture_resources,
        const std::string& left,
        const std::string& mid,
        const std::string& bottom_left,
        const std::string& bottom
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_FourBottomRight(
        SD_TextureResources& texture_resources,
        const std::string& mid,
        const std::string& right,
        const std::string& bottom,
        const std::string& bottom_right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_Horizontal(
        SD_TextureResources& texture_resources,
        const std::string& left,
        const std::string& mid,
        const std::string& right
    );
    static std::unique_ptr<SD_ExpandableSpriteGenericCreator> CreateFromTextures_Vertical(
        SD_TextureResources& texture_resources,
        const std::string& top,
        const std::string& mid,
        const std::string& bottom
    );
protected:
    std::function<std::unique_ptr<SD_ExpandableSprite>(SD_TextureResources&)> call_func;
};
////////////////////////////////////////

////////////////////////////////////////
class SD_ExpandableSprite : public SD_ComplexDrawable {
public:
    SD_DECLARE_CLASS_H()

    SD_ExpandableSprite() = default;
    SD_ExpandableSprite(const SD_ExpandableSprite& cpy);
    SD_ExpandableSprite(SD_ExpandableSprite&& move);

    virtual void InitializeAsNine(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void InitializeAsSixTop(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void InitializeAsSixBottom(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void InitializeAsSixLeft(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottomn
    );
    virtual void InitializeAsSixRight(
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void InitializeFourTopLeft(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle
    );
    virtual void InitializeFourTopRight(
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void InitializeFourBottomLeft(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
    );
    virtual void InitializeFourBottomRight(
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
    );
    virtual void InitializeHorizontal(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
    );
    virtual void InitializeVertical(
        const sf::Texture& top,
        const sf::Texture& middle,
        const sf::Texture& bottom
    );

    virtual void Render(SD_RenderWindowAccess access) const override;

    inline const sf::Vector2i& GetPosition() const {
        return position;
    }
    inline const sf::Vector2i& GetSize() const {
        return size;
    }
    inline const sf::Vector2i& GetOrigin() const {
        return origin;
    }
    inline void SetPosition(const sf::Vector2i& position) {
        this->position = position;
        this->matrix->Update();
    }
    inline void SetSize(const sf::Vector2i& size) {
        this->size = size;
        this->matrix->Update();
    }
    inline void SetOrigin(const sf::Vector2i& ogigin) {
        this->origin = origin;
        this->matrix->Update();
    }
    inline const std::unique_ptr<SD_ExpandableSpriteMatrix>& GetMatrix() const {
        return matrix;
    }
    inline std::unique_ptr<SD_ExpandableSpriteMatrix>& GetMatrix() {
        return matrix;
    }
    inline bool IsValidAndInitialized() const {
        return (final_initialization && matrix);
    }
    inline bool GetFinalInitializationFlag() const {
        return final_initialization;
    }
    inline sf::Vector2i CalculateFinalPosition() const {
        return sf::Vector2i(
            position.x - origin.x,
            position.y - origin.y
        );
    }
    virtual std::unique_ptr<SD_ExpandableSprite> Clone() const;
protected:
    std::unique_ptr<SD_ExpandableSpriteMatrix> matrix;
    sf::Vector2i position;
    sf::Vector2i size;
    sf::Vector2i origin;
    bool final_initialization = false;
};

////////////////////////////////////////

#endif

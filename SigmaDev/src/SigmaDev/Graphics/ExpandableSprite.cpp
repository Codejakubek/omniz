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
// File: /impl/src/SigmaDev/Graphics/ExpandableSprite.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Graphics/ExpandableSprite.h>
#include <SigmaDev/Application/Application.h>
#include <SigmaDev/Misc/Calculations.h>
#include <SigmaDev/Graphics/GraphicsAccesser.h>
#include <SigmaDev/Graphics/GraphicsRenderer.h>


////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ExpandableSpriteMatrix)

SD_ExpandableSpriteMatrix::SD_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const SD_ExpandableSpriteType& type
) : type(type), base(base)
{

}
SD_ExpandableSpriteMatrix::SD_ExpandableSpriteMatrix(
    const SD_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& base
) : type(cpy.GetType()), base(base)
{

}
const sf::Vector2i& SD_ExpandableSpriteMatrix::GetPosition() const {
    return base.GetPosition();
}
const sf::Vector2i& SD_ExpandableSpriteMatrix::GetSize() const {
    return base.GetSize();
}
const sf::Vector2i& SD_ExpandableSpriteMatrix::GetOrigin() const {
    return base.GetOrigin();
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_Nine_ExpandableSpriteMatrix)

SD_Nine_ExpandableSpriteMatrix::SD_Nine_ExpandableSpriteMatrix(
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
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_NINE)
{
    this->top_left = std::make_unique<sf::Sprite>(top_left);
    this->top = std::make_unique<sf::Sprite>(top);
    this->top_right = std::make_unique<sf::Sprite>(top_right);
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
    this->bottom_left = std::make_unique<sf::Sprite>(bottom_left);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
    this->bottom_right = std::make_unique<sf::Sprite>(bottom_right);
}
SD_Nine_ExpandableSpriteMatrix::SD_Nine_ExpandableSpriteMatrix(
    const SD_Nine_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase)
{
    this->top_left = std::make_unique<sf::Sprite>(*cpy.GetTopLeft().get());
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->top_right = std::make_unique<sf::Sprite>(*cpy.GetTopRight().get());
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
    this->bottom_left = std::make_unique<sf::Sprite>(*cpy.GetBottomLeft().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
    this->bottom_right = std::make_unique<sf::Sprite>(*cpy.GetBottomRight().get());
}
void SD_Nine_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*top_left.get());
    render_window.draw(*top.get());
    render_window.draw(*top_right.get());
    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
    render_window.draw(*bottom_left.get());
    render_window.draw(*bottom.get());
    render_window.draw(*bottom_right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_Nine_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_Nine_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_Nine_ExpandableSpriteMatrix::VerifySizes() {
    if (
        top_left &&
        top &&
        top_right &&
        left &&
        middle &&
        right &&
        bottom_left &&
        bottom &&
        bottom_right
    ) {
        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();

        bool check_1 = (top_left_b.y == top_b.y) && (top_b.y == top_right_b.y);
        bool check_2 = (bottom_left_b.y == bottom_b.y) && (bottom_b.y == bottom_right_b.y);
        bool check_3 = (top_left_b.x == left_b.x) && (left_b.x == bottom_left_b.x);
        bool check_4 = (top_right_b.x == right_b.x) && (right_b.x == bottom_right_b.x);

        if (check_1 && check_2 && check_3 && check_4) {
            return true;
        }
    }
    return false;
}
void SD_Nine_ExpandableSpriteMatrix::Update() {
    if (
        top_left &&
        top &&
        top_right &&
        left &&
        middle &&
        right &&
        bottom_left &&
        bottom &&
        bottom_right
    ) {
/*
        sf::FloatRect top_left_bounds = top_left->getLocalBounds();
        sf::FloatRect top_bounds = top->getLocalBounds();
        sf::FloatRect top_right_bounds = top_right->getLocalBounds();

        sf::FloatRect left_bounds = left->getLocalBounds();
        sf::FloatRect middle_bounds = middle->getLocalBounds();
        sf::FloatRect right_bounds = right->getLocalBounds();

        sf::FloatRect bottom_left_bounds = bottom_left->getLocalBounds();
        sf::FloatRect bottom_bounds = bottom->getLocalBounds();
        sf::FloatRect bottom_right_bounds = bottom_right->getLocalBounds();
*/

        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();


        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();


        sf::Vector2f size_without_corners(
            size.x - (top_left_b.x + top_right_b.x),
            size.y - (top_left_b.y + bottom_left_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );



        top_left->setPosition(
            sf::Vector2f(
                final_pos.x, final_pos.y
            )
        );
        top->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y
            )
        );
        top_right->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x + size_without_corners.x,
                final_pos.y
            )
        );
        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x + size_without_corners.x,
                final_pos.y + top_left_b.y
            )
        );
        bottom_left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.y + size_without_corners.y
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y + size_without_corners.y
            )
        );
        bottom_right->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x + size_without_corners.x,
                final_pos.y + top_left_b.y + size_without_corners.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SixTop_ExpandableSpriteMatrix)

SD_SixTop_ExpandableSpriteMatrix::SD_SixTop_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_SIX_TOP)
{
    this->top_left = std::make_unique<sf::Sprite>(top_left);
    this->top = std::make_unique<sf::Sprite>(top);
    this->top_right = std::make_unique<sf::Sprite>(top_right);
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
}
SD_SixTop_ExpandableSpriteMatrix::SD_SixTop_ExpandableSpriteMatrix(
    const SD_SixTop_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase)
{
    this->top_left = std::make_unique<sf::Sprite>(*cpy.GetTopLeft().get());
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->top_right = std::make_unique<sf::Sprite>(*cpy.GetTopRight().get());
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
}
void SD_SixTop_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*top_left.get());
    render_window.draw(*top.get());
    render_window.draw(*top_right.get());
    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_SixTop_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_SixTop_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_SixTop_ExpandableSpriteMatrix::VerifySizes() {
    if (
        top_left &&
        top &&
        top_right &&
        left &&
        middle &&
        right 
    ) {
        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        bool check_1 = (top_left_b.y == top_b.y) && (top_b.y == top_right_b.y);
        bool check_2 = (top_left_b.x == left_b.x);
        bool check_3 = (top_right_b.x == right_b.x);

        if (check_1 && check_2 && check_3) {
            return true;
        }
    }
    return false;
}
void SD_SixTop_ExpandableSpriteMatrix::Update() {
    if (
        top_left &&
        top &&
        top_right &&
        left &&
        middle &&
        right 
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();

        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2f size_without_corners(
            size.x - (top_left_b.x + top_right_b.x),
            size.y - (top_left_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top_left->setPosition(
            sf::Vector2f(
                final_pos.x, final_pos.y
            )
        );
        top->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y
            )
        );
        top_right->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x + size_without_corners.x,
                final_pos.y
            )
        );
        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x + size_without_corners.x,
                final_pos.y + top_left_b.y
            )
        );

    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SixBottom_ExpandableSpriteMatrix)

SD_SixBottom_ExpandableSpriteMatrix::SD_SixBottom_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_SIX_BOTTOM) {
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
    this->bottom_left = std::make_unique<sf::Sprite>(bottom_left);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
    this->bottom_right = std::make_unique<sf::Sprite>(bottom_right);
}
SD_SixBottom_ExpandableSpriteMatrix::SD_SixBottom_ExpandableSpriteMatrix(
    const SD_SixBottom_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
    this->bottom_left = std::make_unique<sf::Sprite>(*cpy.GetBottomLeft().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
    this->bottom_right = std::make_unique<sf::Sprite>(*cpy.GetBottomRight().get());
}
void SD_SixBottom_ExpandableSpriteMatrix::Render(
    SD_RenderWindowAccess& window_access
) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
    render_window.draw(*bottom_left.get());
    render_window.draw(*bottom.get());
    render_window.draw(*bottom_right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_SixBottom_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_SixBottom_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_SixBottom_ExpandableSpriteMatrix::VerifySizes() {
    if (
        left &&
        middle &&
        right&&
        bottom_left &&
        bottom &&
        bottom_right
    ) {
        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();

        bool check_1 = (bottom_left_b.y == bottom_b.y) && (bottom_b.y == bottom_right_b.y);
        bool check_2 = (bottom_left_b.x == left_b.x);
        bool check_3 = (bottom_right_b.x == right_b.x);

        if (check_1 && check_2 && check_3) {
            return true;
        }
    }
    return false;
}
void SD_SixBottom_ExpandableSpriteMatrix::Update() {
    if (
        left &&
        middle &&
        right&&
        bottom_left &&
        bottom &&
        bottom_right
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();

        sf::Vector2f size_without_corners(
            size.x - (bottom_left_b.x + bottom_right_b.x),
            size.y - (bottom_left_b.y)
        );

        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        left->setPosition(
            sf::Vector2f(
                final_pos.x, 
                final_pos.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x,
                final_pos.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x  + size_without_corners.x,
                final_pos.y
            )
        );
        bottom_left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + size_without_corners.y
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x,
                final_pos.y + size_without_corners.y
            )
        );
        bottom_right->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x + size_without_corners.x,
                final_pos.y + size_without_corners.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SixLeft_ExpandableSpriteMatrix)

SD_SixLeft_ExpandableSpriteMatrix::SD_SixLeft_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_SIX_LEFT)
{
    this->top_left = std::make_unique<sf::Sprite>(top_left);
    this->top = std::make_unique<sf::Sprite>(top);
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->bottom_left = std::make_unique<sf::Sprite>(bottom_left);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
}
SD_SixLeft_ExpandableSpriteMatrix::SD_SixLeft_ExpandableSpriteMatrix(
    const SD_SixLeft_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->top_left = std::make_unique<sf::Sprite>(*cpy.GetTopLeft().get());
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->bottom_left = std::make_unique<sf::Sprite>(*cpy.GetBottomLeft().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
}
void SD_SixLeft_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*top_left.get());
    render_window.draw(*top.get());
    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*bottom_left.get());
    render_window.draw(*bottom.get());
}

std::unique_ptr<SD_ExpandableSpriteMatrix> SD_SixLeft_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_SixLeft_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_SixLeft_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_SixLeft_ExpandableSpriteMatrix::Update() {
    if (
        top_left &&
        top &&
        left &&
        middle &&
        bottom_left &&
        bottom
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();
        
        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();

        sf::Vector2f size_without_corners(
            size.x - (top_left_b.x),
            size.y - (top_left_b.y + bottom_left_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top_left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y
            )
        );
        top->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y
            )
        );
        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y
            )
        );
        bottom_left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.y + size_without_corners.y
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y + size_without_corners.y
            )
        );
    }
}

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_SixRight_ExpandableSpriteMatrix)

SD_SixRight_ExpandableSpriteMatrix::SD_SixRight_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_SIX_RIGHT)
{
    this->top = std::make_unique<sf::Sprite>(top);
    this->top_right  = std::make_unique<sf::Sprite>(top_right);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
    this->bottom_right = std::make_unique<sf::Sprite>(bottom_right);
}
SD_SixRight_ExpandableSpriteMatrix::SD_SixRight_ExpandableSpriteMatrix(
    const SD_SixRight_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->top_right = std::make_unique<sf::Sprite>(*cpy.GetTopRight().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
    this->bottom_right = std::make_unique<sf::Sprite>(*cpy.GetBottomRight().get());
}
void SD_SixRight_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*top.get());
    render_window.draw(*top_right.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
    render_window.draw(*bottom.get());
    render_window.draw(*bottom_right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_SixRight_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_SixRight_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_SixRight_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_SixRight_ExpandableSpriteMatrix::Update() {
    if (
        top &&
        top_right && 
        middle &&
        right &&
        bottom && 
        bottom_right
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();


        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();

        sf::Vector2f size_without_corners(
            size.x - (top_right_b.x),
            size.y - (top_right_b.y + bottom_right_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top->setPosition(
            sf::Vector2f(
                final_pos.x, final_pos.y
            )
        );
        top_right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_right_b.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y + top_right_b.y      
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_right_b.y + size_without_corners.y
            )
        );
        bottom_right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y + top_right_b.y + size_without_corners.y
            )
        );
    } 
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_FourTopLeft_ExpandableSpriteMatrix)

SD_FourTopLeft_ExpandableSpriteMatrix::SD_FourTopLeft_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top_left,
    const sf::Texture& top,
    const sf::Texture& left,
    const sf::Texture& middle
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_FOUR_TOP_LEFT)
{
    this->top_left = std::make_unique<sf::Sprite>(top_left);
    this->top = std::make_unique<sf::Sprite>(top);
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
}
SD_FourTopLeft_ExpandableSpriteMatrix::SD_FourTopLeft_ExpandableSpriteMatrix(
    const SD_FourTopLeft_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) 
{
   this->top_left = std::make_unique<sf::Sprite>(*cpy.GetTopLeft().get());
   this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
   this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
   this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
}
void SD_FourTopLeft_ExpandableSpriteMatrix::Render(
    SD_RenderWindowAccess& window_access
) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*top_left.get());
    render_window.draw(*top.get());
    render_window.draw(*left.get());
    render_window.draw(*middle.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_FourTopLeft_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_FourTopLeft_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_FourTopLeft_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_FourTopLeft_ExpandableSpriteMatrix::Update() {
    if (
        top_left &&
        top &&
        left &&
        middle
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();


        sf::Vector2u top_left_b = top_left->getTexture()->getSize();
        sf::Vector2u top_b = top->getTexture()->getSize();

        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();



        sf::Vector2f size_without_corners(
            size.x - (top_left_b.x),
            size.y - (top_left_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top_left->setPosition(
            sf::Vector2f(
                final_pos.x, final_pos.y
            )
        );
        top->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y
            )
        );
        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_left_b.x
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + top_left_b.x,
                final_pos.y + top_left_b.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_FourTopRight_ExpandableSpriteMatrix)

SD_FourTopRight_ExpandableSpriteMatrix::SD_FourTopRight_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top,
    const sf::Texture& top_right,
    const sf::Texture& middle,
    const sf::Texture& right
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_FOUR_TOP_RIGHT)
{
    this->top = std::make_unique<sf::Sprite>(top);
    this->top_right = std::make_unique<sf::Sprite>(top_right);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
}
SD_FourTopRight_ExpandableSpriteMatrix::SD_FourTopRight_ExpandableSpriteMatrix(
    const SD_FourTopRight_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->top_right = std::make_unique<sf::Sprite>(*cpy.GetTopRight().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
}
void SD_FourTopRight_ExpandableSpriteMatrix::Render(
    SD_RenderWindowAccess& window_access
) {
    sf::RenderWindow& render_window = window_access.render_window;
    
    render_window.draw(*top.get());
    render_window.draw(*top_right.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_FourTopRight_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_FourTopRight_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_FourTopRight_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_FourTopRight_ExpandableSpriteMatrix::Update() {
    if (
        top &&
        top_right &&
        middle &&
        right
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();


        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u top_right_b = top_right->getTexture()->getSize();

        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();



        sf::Vector2f size_without_corners(
            size.x - (top_right_b.x),
            size.y - (top_right_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top->setPosition(
            sf::Vector2f(
                final_pos.x, final_pos.y
            )
        );
        top_right->setPosition(
            sf::Vector2f(final_pos.x + size_without_corners.x, final_pos.y)
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_right_b.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y + top_right_b.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_FourBottomLeft_ExpandableSpriteMatrix)

SD_FourBottomLeft_ExpandableSpriteMatrix::SD_FourBottomLeft_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& bottom_left,
    const sf::Texture& bottom
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_FOUR_BOTTOM_LEFT)
{
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->bottom_left = std::make_unique<sf::Sprite>(bottom_left);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
}
SD_FourBottomLeft_ExpandableSpriteMatrix::SD_FourBottomLeft_ExpandableSpriteMatrix(
    const SD_FourBottomLeft_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase)
{
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->bottom_left = std::make_unique<sf::Sprite>(*cpy.GetBottomLeft().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
}
void SD_FourBottomLeft_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*bottom_left.get());
    render_window.draw(*bottom.get());
} 
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_FourBottomLeft_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_FourBottomLeft_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_FourBottomLeft_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_FourBottomLeft_ExpandableSpriteMatrix::Update() {
    if (
        left &&
        middle &&
        bottom_left &&
        bottom
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();



        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();

        sf::Vector2u bottom_left_b = bottom_left->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();


        sf::Vector2f size_without_corners(
            size.x - (bottom_left_b.x),
            size.y - (bottom_left_b.y)
        );

        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + bottom_left_b.x,
                final_pos.y
            )
        );
        bottom_left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + size_without_corners.y 
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x + bottom_left_b.x,
                final_pos.y + size_without_corners.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_FourBottomRight_ExpandableSpriteMatrix)

SD_FourBottomRight_ExpandableSpriteMatrix::SD_FourBottomRight_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& middle,
    const sf::Texture& right,
    const sf::Texture& bottom,
    const sf::Texture& bottom_right
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_FOUR_BOTTOM_RIGHT)
{
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
    this->bottom_right = std::make_unique<sf::Sprite>(bottom_right);
}
SD_FourBottomRight_ExpandableSpriteMatrix::SD_FourBottomRight_ExpandableSpriteMatrix(
    const SD_FourBottomRight_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
    this->bottom_right = std::make_unique<sf::Sprite>(*cpy.GetBottomRight().get());
}
void SD_FourBottomRight_ExpandableSpriteMatrix::Render(
    SD_RenderWindowAccess& window_access
) {
    sf::RenderWindow& render_window = window_access.render_window;
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
    render_window.draw(*bottom.get());
    render_window.draw(*bottom_right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_FourBottomRight_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_FourBottomRight_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_FourBottomRight_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_FourBottomRight_ExpandableSpriteMatrix::Update() {
    if (
        middle &&
        right &&
        bottom &&
        bottom_right
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();



        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();

        sf::Vector2u bottom_b = bottom->getTexture()->getSize();
        sf::Vector2u bottom_right_b = bottom_right->getTexture()->getSize();


        sf::Vector2f size_without_corners(
            size.x - (bottom_right_b.x),
            size.y - (bottom_right_b.y)
        );


        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        middle->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + size_without_corners.y
            )
        );
        bottom_right->setPosition(
            sf::Vector2f(
                final_pos.x + size_without_corners.x,
                final_pos.y + size_without_corners.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ThreeHorizontal_ExpandableSpriteMatrix)

SD_ThreeHorizontal_ExpandableSpriteMatrix::SD_ThreeHorizontal_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& left,
    const sf::Texture& middle,
    const sf::Texture& right
)  : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_THREE_HORIZONTAL)
{
    this->left = std::make_unique<sf::Sprite>(left);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->right = std::make_unique<sf::Sprite>(right);
}
SD_ThreeHorizontal_ExpandableSpriteMatrix::SD_ThreeHorizontal_ExpandableSpriteMatrix(
    const SD_ThreeHorizontal_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->left = std::make_unique<sf::Sprite>(*cpy.GetLeft().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->right = std::make_unique<sf::Sprite>(*cpy.GetRight().get());
}
void SD_ThreeHorizontal_ExpandableSpriteMatrix::Render(
    SD_RenderWindowAccess& window_access
) {
    sf::RenderWindow& render_window = window_access.render_window;

    render_window.draw(*left.get());
    render_window.draw(*middle.get());
    render_window.draw(*right.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_ThreeHorizontal_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_ThreeHorizontal_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_ThreeHorizontal_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_ThreeHorizontal_ExpandableSpriteMatrix::Update() {
    if (
        left &&
        middle &&
        right
    ) {
        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();
        sf::Vector2u left_b = left->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u right_b = right->getTexture()->getSize();


        sf::Vector2f size_without_corners(
            size.x - (left_b.x + right_b.x),
            size.y
        );


        left->setScale(
            1.0f,
            size_without_corners.y / left_b.y
        );
        right->setScale(
            1.0f,
            size_without_corners.y / right_b.y
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );
        
        left->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x,
                final_pos.y
            )
        );
        right->setPosition(
            sf::Vector2f(
                final_pos.x + left_b.x + size_without_corners.x,
                final_pos.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ThreeVertical_ExpandableSpriteMatrix)

SD_ThreeVertical_ExpandableSpriteMatrix::SD_ThreeVertical_ExpandableSpriteMatrix(
    SD_ExpandableSprite& base,
    const sf::Texture& top,
    const sf::Texture& middle,
    const sf::Texture& bottom
) : SD_ExpandableSpriteMatrix(base, SD_EXPANDABLE_SPRITE_THREE_VERTICAL)
{
    this->top = std::make_unique<sf::Sprite>(top);
    this->middle = std::make_unique<sf::Sprite>(middle);
    this->bottom = std::make_unique<sf::Sprite>(bottom);
}
SD_ThreeVertical_ExpandableSpriteMatrix::SD_ThreeVertical_ExpandableSpriteMatrix(
    const SD_ThreeVertical_ExpandableSpriteMatrix& cpy,
    SD_ExpandableSprite& rebase
) : SD_ExpandableSpriteMatrix(cpy, rebase) {
    this->top = std::make_unique<sf::Sprite>(*cpy.GetTop().get());
    this->middle = std::make_unique<sf::Sprite>(*cpy.GetMiddle().get());
    this->bottom = std::make_unique<sf::Sprite>(*cpy.GetBottom().get());
}
void SD_ThreeVertical_ExpandableSpriteMatrix::Render(SD_RenderWindowAccess& window_access) {
    sf::RenderWindow& render_window = window_access.render_window;
    
    render_window.draw(*top.get());
    render_window.draw(*middle.get());
    render_window.draw(*bottom.get());
}
std::unique_ptr<SD_ExpandableSpriteMatrix> SD_ThreeVertical_ExpandableSpriteMatrix::Clone(SD_ExpandableSprite& rebase) const {
    return std::make_unique<SD_ThreeVertical_ExpandableSpriteMatrix>(*this, rebase);
}
bool SD_ThreeVertical_ExpandableSpriteMatrix::VerifySizes() {
    //TODO
}
void SD_ThreeVertical_ExpandableSpriteMatrix::Update (){
    if (
        top &&
        middle &&
        bottom  
    ) {

        sf::Vector2i final_pos = this->base.CalculateFinalPosition();
        const sf::Vector2i& size = GetSize();


        sf::Vector2u top_b = top->getTexture()->getSize();
        sf::Vector2u middle_b = middle->getTexture()->getSize();
        sf::Vector2u bottom_b = bottom->getTexture()->getSize();


        sf::Vector2f size_without_corners(
            size.x,
            size.y - (top_b.y + bottom_b.y)
        );

        top->setScale(
            size_without_corners.x / top_b.x,
            1.0f
        );
        bottom->setScale(
            size_without_corners.x / bottom_b.x,
            1.0f
        );
        middle->setScale(
            size_without_corners.x / middle_b.x,
            size_without_corners.y / middle_b.y
        );

        top->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y
            )
        );
        middle->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_b.y
            )
        );
        bottom->setPosition(
            sf::Vector2f(
                final_pos.x,
                final_pos.y + top_b.y + size_without_corners.y
            )
        );
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ExpandableSpriteGenericCreator)

SD_ExpandableSpriteGenericCreator::SD_ExpandableSpriteGenericCreator(
    const SD_ExpandableSpriteGenericCreator& cpy
) : call_func(cpy.CallFunc())
{

}
SD_ExpandableSpriteGenericCreator::SD_ExpandableSpriteGenericCreator(
    std::function<std::unique_ptr<SD_ExpandableSprite>(SD_TextureResources&)> call_func 
) : call_func(call_func)
{

}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::Clone() const {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(*this);
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_Nine(
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
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite =
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top_left =
            texture_resources.GetTexture(top_left);

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);

            std::unique_ptr<sf::Texture>& texture_top_right =
            texture_resources.GetTexture(top_right);

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right =
            texture_resources.GetTexture(right);

            std::unique_ptr<sf::Texture>& texture_bottom_left =
            texture_resources.GetTexture(bottom_left);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            std::unique_ptr<sf::Texture>& texture_bottom_right =
            texture_resources.GetTexture(bottom_right);

            final_expandable_sprite->InitializeAsNine(
                *texture_top_left.get(),
                *texture_top.get(),
                *texture_top_right.get(),
                *texture_left.get(),
                *texture_mid.get(),
                *texture_right.get(),
                *texture_bottom_left.get(),
                *texture_bottom.get(),
                *texture_bottom_right.get()
            );

            return final_expandable_sprite;
        }
    );
    
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_SixTop(
    SD_TextureResources& texture_resources,
    const std::string& top_left,
    const std::string& top,
    const std::string& top_right,
    const std::string& left,
    const std::string& mid,
    const std::string& right
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top_left =
            texture_resources.GetTexture(top_left);

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);
            
            std::unique_ptr<sf::Texture>& texture_top_right =
            texture_resources.GetTexture(top_right);

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right = 
            texture_resources.GetTexture(right);

            final_expandable_sprite->InitializeAsSixTop(
                *texture_top_left.get(),
                *texture_top.get(),
                *texture_top_right.get(),
                *texture_left.get(),
                *texture_mid.get(),
                *texture_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_SixBottom(
    SD_TextureResources& texture_resources,
    const std::string& left,
    const std::string& mid,
    const std::string& right,
    const std::string& bottom_left,
    const std::string& bottom,
    const std::string& bottom_right
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right =
            texture_resources.GetTexture(right);

            std::unique_ptr<sf::Texture>& texture_bottom_left =
            texture_resources.GetTexture(bottom_left);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            std::unique_ptr<sf::Texture>& texture_bottom_right =
            texture_resources.GetTexture(bottom_right);

            final_expandable_sprite->InitializeAsSixBottom(
                *texture_left.get(),
                *texture_mid.get(),
                *texture_right.get(),
                *texture_bottom_left.get(),
                *texture_bottom.get(),
                *texture_bottom_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_SixLeft(
    SD_TextureResources& texture_resources,
    const std::string& top_left,
    const std::string& top,
    const std::string& left,
    const std::string& mid,
    const std::string& bottom_left,
    const std::string& bottom
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top_left =
            texture_resources.GetTexture(top_left);

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_bottom_left =
            texture_resources.GetTexture(bottom_left);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            final_expandable_sprite->InitializeAsSixLeft(
                *texture_top_left.get(),
                *texture_top.get(),
                *texture_left.get(),
                *texture_mid.get(),
                *texture_bottom_left.get(),
                *texture_bottom.get()
            );

            return final_expandable_sprite;
        }
    );

}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_SixRight(
    SD_TextureResources& texture_resources,
    const std::string& top,
    const std::string& top_right,
    const std::string& mid,
    const std::string& right,
    const std::string& bottom,
    const std::string& bottom_right
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);

            std::unique_ptr<sf::Texture>& texture_top_right =
            texture_resources.GetTexture(top_right);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right =
            texture_resources.GetTexture(right);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            std::unique_ptr<sf::Texture>& texture_bottom_right = 
            texture_resources.GetTexture(bottom_right);

            final_expandable_sprite->InitializeAsSixRight(
                *texture_top.get(),
                *texture_top_right.get(),
                *texture_mid.get(),
                *texture_right.get(),
                *texture_bottom.get(),
                *texture_bottom_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_FourTopLeft(
    SD_TextureResources& texture_resources,
    const std::string& top_left,
    const std::string& top,
    const std::string& left,
    const std::string& mid
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top_left =
            texture_resources.GetTexture(top_left);

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);
            
            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            final_expandable_sprite->InitializeFourTopLeft(
                *texture_top_left.get(),
                *texture_top.get(),
                *texture_left.get(),
                *texture_mid.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_FourTopRight(
    SD_TextureResources& texture_resources,
    const std::string& top,
    const std::string& top_right,
    const std::string& mid,
    const std::string& right
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top = 
            texture_resources.GetTexture(top);

            std::unique_ptr<sf::Texture>& texture_top_right =
            texture_resources.GetTexture(top_right);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right =
            texture_resources.GetTexture(right);

            final_expandable_sprite->InitializeFourTopRight(
                *texture_top.get(),
                *texture_top_right.get(),
                *texture_mid.get(),
                *texture_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_FourBottomLeft(
    SD_TextureResources& texture_resources,
    const std::string& left,
    const std::string& mid,
    const std::string& bottom_left,
    const std::string& bottom
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_bottom_left =
            texture_resources.GetTexture(bottom_left);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            final_expandable_sprite->InitializeFourBottomLeft(
                *texture_left.get(),
                *texture_mid.get(),
                *texture_bottom_left.get(),
                *texture_bottom.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_FourBottomRight(
    SD_TextureResources& texture_resources,
    const std::string& mid,
    const std::string& right,
    const std::string& bottom,
    const std::string& bottom_right 
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right = 
            texture_resources.GetTexture(right);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            std::unique_ptr<sf::Texture>& texture_bottom_right =
            texture_resources.GetTexture(bottom_right);

            final_expandable_sprite->InitializeFourBottomRight(
                *texture_mid.get(),
                *texture_right.get(),
                *texture_bottom.get(),
                *texture_bottom_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_Horizontal(
    SD_TextureResources& texture_resources,
    const std::string& left,
    const std::string& mid,
    const std::string& right
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_left =
            texture_resources.GetTexture(left);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_right =
            texture_resources.GetTexture(right);

            final_expandable_sprite->InitializeHorizontal(
                *texture_left.get(),
                *texture_mid.get(),
                *texture_right.get()
            );

            return final_expandable_sprite;
        }
    );
}
std::unique_ptr<SD_ExpandableSpriteGenericCreator> SD_ExpandableSpriteGenericCreator::CreateFromTextures_Vertical(
    SD_TextureResources& texture_resources,
    const std::string& top,
    const std::string& mid,
    const std::string& bottom
) {
    return std::make_unique<SD_ExpandableSpriteGenericCreator>(
        [&](SD_TextureResources& texture_resources) {
            std::unique_ptr<SD_ExpandableSprite> final_expandable_sprite = 
            std::make_unique<SD_ExpandableSprite>();

            std::unique_ptr<sf::Texture>& texture_top =
            texture_resources.GetTexture(top);

            std::unique_ptr<sf::Texture>& texture_mid =
            texture_resources.GetTexture(mid);

            std::unique_ptr<sf::Texture>& texture_bottom =
            texture_resources.GetTexture(bottom);

            final_expandable_sprite->InitializeVertical(
                *texture_top.get(),
                *texture_mid.get(),
                *texture_bottom.get()
            );

            return final_expandable_sprite;
        }
    );
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ExpandableSprite)

SD_ExpandableSprite::SD_ExpandableSprite(const SD_ExpandableSprite& cpy) {
    if (cpy.GetMatrix()) {

        //Rebase!
        this->matrix = cpy.GetMatrix()->Clone(*this);
    }
    this->position = cpy.GetPosition();
    this->size = cpy.GetSize();
    this->origin = cpy.GetOrigin();
    this->final_initialization = cpy.GetFinalInitializationFlag();    
}
SD_ExpandableSprite::SD_ExpandableSprite(SD_ExpandableSprite&& move) {
    if (move.GetMatrix()) {
        this->matrix = move.GetMatrix()->Clone(*this);
    }
    this->position = move.GetPosition();
    this->size = move.GetSize();
    this->origin = move.GetOrigin();
    this->final_initialization = move.GetFinalInitializationFlag();
}
void SD_ExpandableSprite::InitializeAsNine(
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
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_Nine_ExpandableSpriteMatrix>(
            *this,
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
        final_initialization = true;
    } else {
        //Exception
    }
} 
void SD_ExpandableSprite::InitializeAsSixTop(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_SixTop_ExpandableSpriteMatrix>(
            *this,
            top_left,
            top,
            top_right,
            left,
            middle,
            right
        );
        final_initialization = true;
    } else {
        //Exception
    }
}
void SD_ExpandableSprite::InitializeAsSixBottom(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_SixBottom_ExpandableSpriteMatrix>(
            *this,
            left,
            middle,
            right,
            bottom_left,
            bottom,
            bottom_right
        );
        final_initialization = true;
    } else {
        //Exception
    }
}
void SD_ExpandableSprite::InitializeAsSixLeft(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_SixLeft_ExpandableSpriteMatrix>(
            *this,
            top_left,
            top,
            left,
            middle,
            bottom_left,
            bottom
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeAsSixRight(
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_SixRight_ExpandableSpriteMatrix>(
            *this,
            top,
            top_right,
            middle,
            right,
            bottom,
            bottom_right
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeFourTopLeft(
        const sf::Texture& top_left,
        const sf::Texture& top,
        const sf::Texture& left,
        const sf::Texture& middle
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_FourTopLeft_ExpandableSpriteMatrix>(
            *this,
            top_left,
            top,
            left,
            middle
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeFourTopRight(
        const sf::Texture& top,
        const sf::Texture& top_right,
        const sf::Texture& middle,
        const sf::Texture& right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_FourTopRight_ExpandableSpriteMatrix>(
            *this,
            top,
            top_right,
            middle,
            right
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeFourBottomLeft(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& bottom_left,
        const sf::Texture& bottom
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_FourBottomLeft_ExpandableSpriteMatrix>(
            *this,
            left,
            middle,
            bottom_left,
            bottom
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeFourBottomRight(
        const sf::Texture& middle,
        const sf::Texture& right,
        const sf::Texture& bottom,
        const sf::Texture& bottom_right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_FourBottomRight_ExpandableSpriteMatrix>(
            *this,
            middle,
            right,
            bottom,
            bottom_right
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeHorizontal(
        const sf::Texture& left,
        const sf::Texture& middle,
        const sf::Texture& right
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_ThreeHorizontal_ExpandableSpriteMatrix>(
            *this,
            left,
            middle,
            right
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::InitializeVertical(
        const sf::Texture& top,
        const sf::Texture& middle,
        const sf::Texture& bottom
) {
    if(final_initialization == false) {
        this->matrix = std::make_unique<SD_ThreeVertical_ExpandableSpriteMatrix>(
            *this,
            top,
            middle,
            bottom
        );
        final_initialization = true;
    } else {
        //Exception  
    } 
}
void SD_ExpandableSprite::Render(SD_RenderWindowAccess window_access) const {
    this->matrix->Render(window_access);
}
std::unique_ptr<SD_ExpandableSprite> SD_ExpandableSprite::Clone() const {
    return std::make_unique<SD_ExpandableSprite>(*this);
}
////////////////////////////////////////


#include <SigmaDev/Testing/Testing.h>



SD_DEFINE_REALTIME_TEST(expandable_sprite_testing_1)
    SD_ApplicationInitializationHelper helper;
    const std::string window_name = "expandable_sprite_testing_window";

    helper.CreateWindow(window_name, sf::VideoMode(800,600), "SigmaDev Expandable Sprite Rendering Testing", sf::Style::Close);

    std::unique_ptr<SD_Application>& app = helper.GetApplication();
    std::unique_ptr<SD_GraphicsAccesser>& graphics_accesser = app->GetGraphicsAccesser();
    std::unique_ptr<SD_GraphicsRenderer>& graphics_renderer = app->GetGraphicsRenderer();

    auto& textures_access = graphics_accesser->Textures();
    auto& expandable_sprites_access = graphics_accesser->ExpandableSprites();

    textures_access.LoadTexture("expandable_sprite_top_left", "./Base/expandable_sprite_top_left.png");
    textures_access.LoadTexture("expandable_sprite_top", "./Base/expandable_sprite_top.png");
    textures_access.LoadTexture("expandable_sprite_top_right", "./Base/expandable_sprite_top_right.png");
    textures_access.LoadTexture("expandable_sprite_left", "./Base/expandable_sprite_left.png");
    textures_access.LoadTexture("expandable_sprite_mid", "./Base/expandable_sprite_middle.png");
    textures_access.LoadTexture("expandable_sprite_right", "./Base/expandable_sprite_right.png");
    textures_access.LoadTexture("expandable_sprite_bottom_left", "./Base/expandable_sprite_bottom_left.png");
    textures_access.LoadTexture("expandable_sprite_bottom", "./Base/expandable_sprite_bottom.png");
    textures_access.LoadTexture("expandable_sprite_bottom_right", "./Base/expandable_sprite_bottom_right.png");

    std::unique_ptr<sf::Texture>& top_left_texture = textures_access.GetTexture("expandable_sprite_top_left");
    std::unique_ptr<sf::Texture>& top_texture = textures_access.GetTexture("expandable_sprite_top");
    std::unique_ptr<sf::Texture>& top_right_texture = textures_access.GetTexture("expandable_sprite_top_right");
    std::unique_ptr<sf::Texture>& left_texture = textures_access.GetTexture("expandable_sprite_left");
    std::unique_ptr<sf::Texture>& middle_texture = textures_access.GetTexture("expandable_sprite_mid");
    std::unique_ptr<sf::Texture>& right_texture = textures_access.GetTexture("expandable_sprite_right");
    std::unique_ptr<sf::Texture>& bottom_left_texture = textures_access.GetTexture("expandable_sprite_bottom_left");
    std::unique_ptr<sf::Texture>& bottom_texture = textures_access.GetTexture("expandable_sprite_bottom");
    std::unique_ptr<sf::Texture>& bottom_right_texture = textures_access.GetTexture("expandable_sprite_bottom_right");

    expandable_sprites_access.Load_Nine_ExpandableSprite(
        "expandable_sprite",
        *top_left_texture.get(),
        *top_texture.get(),
        *top_right_texture.get(),
        *left_texture.get(),
        *middle_texture.get(),
        *right_texture.get(),
        *bottom_left_texture.get(),
        *bottom_texture.get(),
        *bottom_right_texture.get()
    );


    std::unique_ptr<SD_ExpandableSprite>& sprite = expandable_sprites_access.GetExpandableSprite("expandable_sprite");
    sprite->SetPosition(sf::Vector2i(50,50));
    sprite->SetSize(sf::Vector2i(200,200));
    sprite->SetOrigin(sf::Vector2i(10,10));

    for (int i = 0; i < 3000 && helper.AtLeastOneWindowIsOpen(); ++i ){
        sprite->SetSize(sf::Vector2i(90+i/7,90+i/5));

        expandable_sprites_access.Load_Nine_ExpandableSprite(
            "expandable_sprite_2",
            *top_left_texture.get(),
            *top_texture.get(),
            *top_right_texture.get(),
            *left_texture.get(),
            *middle_texture.get(),
            *right_texture.get(),
            *bottom_left_texture.get(),
            *bottom_texture.get(),
            *bottom_right_texture.get()
        );

        std::unique_ptr<SD_ExpandableSprite>& sprite_2 = expandable_sprites_access.GetExpandableSprite("expandable_sprite_2");
        sprite_2->SetPosition(sf::Vector2i(200,50));
        sprite_2->SetSize(sf::Vector2i(sf::Vector2i(50+i/7,50+i/5)));
        sprite_2->SetOrigin(sf::Vector2i(10,10));

        graphics_renderer->RenderExpandableSprite(window_name, "expandable_sprite", 2, 3, false);
        graphics_renderer->RenderExpandableSprite(window_name, "expandable_sprite_2", 2, 1, true);
        helper.RunForOneTick();


        
    }


SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(expandable_sprite_testing_1)

SD_DEFINE_REALTIME_TEST(expandable_sprite_testing_2)
    SD_ApplicationInitializationHelper helper;
    const std::string window_name = "expandable_sprite_testing_window2";

    helper.CreateWindow(window_name, sf::VideoMode(800,600), "SigmaDev Expandable Sprite Rendering Testing", sf::Style::Close);

    std::unique_ptr<SD_Application>& app = helper.GetApplication();
    std::unique_ptr<SD_GraphicsAccesser>& graphics_accesser = app->GetGraphicsAccesser();
    std::unique_ptr<SD_GraphicsRenderer>& graphics_renderer = app->GetGraphicsRenderer();

    auto& textures_access = graphics_accesser->Textures();
    auto& expandable_sprites_access = graphics_accesser->ExpandableSprites();

    textures_access.LoadTexture("expandable_sprite_top_left", "./Base/expandable_sprite_top_left.png");
    textures_access.LoadTexture("expandable_sprite_top", "./Base/expandable_sprite_top.png");
    textures_access.LoadTexture("expandable_sprite_top_right", "./Base/expandable_sprite_top_right.png");
    textures_access.LoadTexture("expandable_sprite_left", "./Base/expandable_sprite_left.png");
    textures_access.LoadTexture("expandable_sprite_mid", "./Base/expandable_sprite_middle.png");
    textures_access.LoadTexture("expandable_sprite_right", "./Base/expandable_sprite_right.png");
    textures_access.LoadTexture("expandable_sprite_bottom_left", "./Base/expandable_sprite_bottom_left.png");
    textures_access.LoadTexture("expandable_sprite_bottom", "./Base/expandable_sprite_bottom.png");
    textures_access.LoadTexture("expandable_sprite_bottom_right", "./Base/expandable_sprite_bottom_right.png");


    std::unique_ptr<sf::Texture>& top_left_texture = textures_access.GetTexture("expandable_sprite_top_left");
    std::unique_ptr<sf::Texture>& top_texture = textures_access.GetTexture("expandable_sprite_top");
    std::unique_ptr<sf::Texture>& top_right_texture = textures_access.GetTexture("expandable_sprite_top_right");
    std::unique_ptr<sf::Texture>& left_texture = textures_access.GetTexture("expandable_sprite_left");
    std::unique_ptr<sf::Texture>& middle_texture = textures_access.GetTexture("expandable_sprite_mid");
    std::unique_ptr<sf::Texture>& right_texture = textures_access.GetTexture("expandable_sprite_right");
    std::unique_ptr<sf::Texture>& bottom_left_texture = textures_access.GetTexture("expandable_sprite_bottom_left");
    std::unique_ptr<sf::Texture>& bottom_texture = textures_access.GetTexture("expandable_sprite_bottom");
    std::unique_ptr<sf::Texture>& bottom_right_texture = textures_access.GetTexture("expandable_sprite_bottom_right");

    expandable_sprites_access.Load_Nine_ExpandableSprite(
        "nine",
        *top_left_texture.get(),
        *top_texture.get(),
        *top_right_texture.get(),
        *left_texture.get(),
        *middle_texture.get(),
        *right_texture.get(),
        *bottom_left_texture.get(),
        *bottom_texture.get(),
        *bottom_right_texture.get()
    );

    expandable_sprites_access.Load_SixTop_ExpandableSprite(
        "six_top",
        *top_left_texture.get(),
        *top_texture.get(),
        *top_right_texture.get(),
        *left_texture.get(),
        *middle_texture.get(),
        *right_texture.get()
    );

    expandable_sprites_access.Load_SixBottom_ExpandableSprite(
        "six_bottom",
        *left_texture.get(),
        *middle_texture.get(),
        *right_texture.get(),
        *bottom_left_texture.get(),
        *bottom_texture.get(),
        *bottom_right_texture.get()
    );

    expandable_sprites_access.Load_SixLeft_ExpandableSprite(
        "six_left",
        *top_left_texture.get(),
        *top_texture.get(),
        *left_texture.get(),
        *middle_texture.get(),
        *bottom_left_texture.get(),
        *bottom_texture.get()
    );

    expandable_sprites_access.Load_SixRight_ExpandableSprite(
        "six_right",
        *top_texture.get(),
        *top_right_texture.get(),
        *middle_texture.get(),
        *right_texture.get(),
        *bottom_texture.get(),
        *bottom_right_texture.get()
    );

    expandable_sprites_access.Load_FourTopLeft_ExpandableSprite(
        "four_top_left",
        *top_left_texture.get(),
        *top_texture.get(),
        *left_texture.get(),
        *middle_texture.get()
    );

    expandable_sprites_access.Load_FourTopRight_ExpandableSprite(
        "four_top_right",
        *top_texture.get(),
        *top_right_texture.get(),
        *middle_texture.get(),
        *right_texture.get()
    );

    expandable_sprites_access.Load_FourBottomLeft_ExpandableSprite(
        "four_bottom_left",
        *left_texture.get(),
        *middle_texture.get(),
        *bottom_left_texture.get(),
        *bottom_texture.get()
    );

    expandable_sprites_access.Load_FourBottomRight_ExpandableSprite(
        "four_bottom_right",
        *middle_texture.get(),
        *right_texture.get(),
        *bottom_texture.get(),
        *bottom_right_texture.get()
    );

    expandable_sprites_access.Load_ThreeHorizontal_ExpandableSprite(
        "three_horizontal",
        *left_texture.get(),
        *middle_texture.get(),
        *right_texture.get()
    );

    expandable_sprites_access.Load_ThreeVertical_ExpandableSprite(
        "three_vertical",
        *top_texture.get(),
        *middle_texture.get(),
        *bottom_texture.get()
    );

    std::unique_ptr<SD_ExpandableSprite>&
        nine = expandable_sprites_access.GetExpandableSprite("nine");

    std::unique_ptr<SD_ExpandableSprite>&
        six_top = expandable_sprites_access.GetExpandableSprite("six_top");

    std::unique_ptr<SD_ExpandableSprite>&
        six_bottom = expandable_sprites_access.GetExpandableSprite("six_bottom");

    std::unique_ptr<SD_ExpandableSprite>&
        six_left = expandable_sprites_access.GetExpandableSprite("six_left");

    std::unique_ptr<SD_ExpandableSprite>&
        six_right = expandable_sprites_access.GetExpandableSprite("six_right");

    std::unique_ptr<SD_ExpandableSprite>&
        four_top_left = expandable_sprites_access.GetExpandableSprite("four_top_left");

    std::unique_ptr<SD_ExpandableSprite>&
        four_top_right = expandable_sprites_access.GetExpandableSprite("four_top_right");

    std::unique_ptr<SD_ExpandableSprite>&
        four_bottom_left = expandable_sprites_access.GetExpandableSprite("four_bottom_left");

    std::unique_ptr<SD_ExpandableSprite>&
        four_bottom_right = expandable_sprites_access.GetExpandableSprite("four_bottom_right");

    std::unique_ptr<SD_ExpandableSprite>&
        three_horizontal = expandable_sprites_access.GetExpandableSprite("three_horizontal");
    
    std::unique_ptr<SD_ExpandableSprite>&
        three_vertical = expandable_sprites_access.GetExpandableSprite("three_vertical");


    nine->SetPosition(sf::Vector2i(10,10));
    
    six_top->SetPosition(sf::Vector2i(100,10));
    six_bottom->SetPosition(sf::Vector2i(190,10));
    six_left->SetPosition(sf::Vector2i(280, 10));
    six_right->SetPosition(sf::Vector2i(370,10));

    four_top_left->SetPosition(sf::Vector2i(100,100));
    four_top_right->SetPosition(sf::Vector2i(190,100));
    four_bottom_left->SetPosition(sf::Vector2i(280,100));
    four_bottom_right->SetPosition(sf::Vector2i(370,100));

    three_horizontal->SetPosition(sf::Vector2i(100,190));
    three_vertical->SetPosition(sf::Vector2i(190,190));

    nine->SetSize(sf::Vector2i(80,80));
    
    six_top->SetSize(sf::Vector2i(80, 80));
    six_bottom->SetSize(sf::Vector2i(80, 80));
    six_left->SetSize(sf::Vector2i(80, 80));
    six_right->SetSize(sf::Vector2i(80, 80));

    four_top_left->SetSize(sf::Vector2i(80, 80));
    four_top_right->SetSize(sf::Vector2i(80, 80));
    four_bottom_left->SetSize(sf::Vector2i(80, 80));
    four_bottom_right->SetSize(sf::Vector2i(80, 80));

    three_horizontal->SetSize(sf::Vector2i(80, 80));
    three_vertical->SetSize(sf::Vector2i(80, 80));

    for (int i = 0; i < 999999999 && helper.AtLeastOneWindowIsOpen(); ++i) {
        graphics_renderer->RenderExpandableSprite(window_name, *nine.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *six_top.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *six_bottom.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *six_left.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *six_right.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *four_top_left.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *four_top_right.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *four_bottom_left.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *four_bottom_right.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *three_horizontal.get(), 1, 1);   
        graphics_renderer->RenderExpandableSprite(window_name, *three_vertical.get(), 1, 1); 
        helper.RunForOneTick();  
    }

SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(expandable_sprite_testing_2)

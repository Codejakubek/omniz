/**
 * OmniZShooters private source code, under no license.
 * Copyright © 2021 Dawid Jakubowski (Codedemens)
 * 
 * 
 * Authors:
 * Lead Programmer, Graphic Designer, Audio Engineer, Voice Actor:
 *     - Dawid (Codedemens) Jakubowski
 */
 
#include <string>
#include <iostream>

#include <OZ_Core.h>

#include <SigmaDev/Misc/GenericContainer.h>
#include <SigmaDev/Testing/Testing.h>
#include <SigmaDev/Main/Main.h>


//#define OZ_GLSL_TEST
//#define OZ_STANDARD_CORE_INITIALIZATION
#define OZ_SIGMADEV_TESTING
//#define OTHER_LUA_TESTING

#ifdef OTHER_LUA_TESTING
#include <Other_LuaTesting.h>
#endif

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>


void GLSLTest() {
    sf::RenderWindow w;
    w.create(sf::VideoMode(600,400), "zzz");
    sf::Sprite sprite;
    sf::Sprite sprite2;

    sprite.setPosition(sf::Vector2f(0,0));
    sprite2.setPosition(sf::Vector2f(0,0));

    sf::Texture texture;
    texture.loadFromFile("test.png");
    sprite.setTexture(texture);

    sf::RenderTexture render_texture_;
    render_texture_.create(600,400);
    render_texture_.clear(sf::Color(0,0,0,0));
    render_texture_.draw(sprite);
    sprite2.setTexture(render_texture_.getTexture());


    sf::Shader shader;
    shader.loadFromFile("shader.glsl", sf::Shader::Type::Fragment);
    

    sf::RenderStates render_states;
    render_states.shader = &shader;

    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    sprite.setPosition(300,200);
    

    w.setFramerateLimit(60);
    float x = 0.0f;
    float y = 0.0f;
    
    float angle = 0;
    float opacity = 1.0f;
    while (w.isOpen()) {
        opacity *= 0.994f;
        angle += 0.60f;
      
        sprite.setRotation(angle);
        if (angle > 360.0f) {
            angle = angle-360.0f;
        }
        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }
        x += 0.00002f;
        y += 0.00002f;
        shader.setUniform("blur_offset", sf::Vector2f(x, y));
        shader.setUniform("opacity", opacity);

        
        w.clear();
        w.draw(sprite, render_states);
        //w.draw(sprite2, render_states);
        w.display();
    }
}

int main(int argc, char* argv[]) {
#ifdef OZ_GLSL_TEST
    GLSLTest();
#endif
#ifdef OTHER_LUA_TESTING
    Other_LuaTesting1();
#endif

#ifdef OZ_SIGMADEV_TESTING
    SD_Main main(argc, argv);
#endif

#ifdef OZ_STANDARD_CORE_INITIALIZATION
    OZ_Core core;
    core.BuildImpl<OZ_CurrentCoreImpl>();

    
#endif

    return 0;
}
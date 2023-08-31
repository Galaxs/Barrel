#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "TextureHolder.h"
class Enemy
{
    private:
    
    public:
    // enum m_Type{Box, Pig};
    float m_Speed = 280.f;
    sf::Vector2f m_Position;
    sf::Texture m_TextureEnemy;
    sf::Sprite m_SpriteEnemy ;
    bool m_isActive = true;
    Enemy();
    Enemy(sf::RenderWindow&);
    void init(sf::RenderWindow&);

    void setPos(sf::Vector2f& value);
    sf::Vector2f& getPos();
    void update(float dt);
    void draw(sf::RenderWindow& renderWindow);
    // bool getIsActive();
    sf::Sprite& getSprite();
};
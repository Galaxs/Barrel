#include <SFML/Graphics.hpp>
#include "iostream"
#include "TextureHandler.h"
class Enemy
{
    private:
    // enum m_Type{Box, Pig};
    float m_Speed;
    sf::Vector2f m_Position;
    sf::Sprite m_SpriteEnemy;
    bool m_isActive = true;
    public:
    Enemy(sf::RenderWindow&);

    void setPos(sf::Vector2f& value);
    sf::Vector2f& getPos();
    sf::Sprite& getSprite();
    void update(float dt);
    void draw(sf::RenderWindow& renderWindow);
    bool getIsActive();
};
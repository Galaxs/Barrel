#include "Enemy.h"
Enemy::Enemy(sf::RenderWindow& rWindwo)
{
    m_isActive = true;
    TextureHandler::addTexture("box.png");
    m_SpriteEnemy.setTexture(TextureHandler::getTexture("box.png"));
    m_Position = sf::Vector2f(0, rWindwo.getSize().y - 200);
    m_Speed = 18.f;
    m_SpriteEnemy.setPosition(m_Position);
}

sf::Vector2f& Enemy::getPos()
{
    return m_Position;
}

sf::Sprite& Enemy::getSprite()
{
    return m_SpriteEnemy;
}

bool Enemy::getIsActive()
{
    return m_isActive;
}

void Enemy::update(float dt)
{
    // Move the enemy entity to the right if has left the screen, else deActivate it
    
    m_Position.x < 2500.f ? m_Position.x += m_Speed * dt : m_isActive = false;
    
    //move the sprite
    m_SpriteEnemy.setPosition(m_Position);

    if (m_Position.x > 2500)
    {
        m_Position.x = -200;
    }
    
}

void Enemy::draw(sf::RenderWindow& renderWindow)
{
    // if (m_isActive)
    renderWindow.draw(m_SpriteEnemy);
}

#include "Enemy.h"
Enemy::Enemy()
{
    // init();
}
Enemy::Enemy(sf::RenderWindow& rWindow) 
{   
    m_SpriteEnemy.setTexture(TextureHolder::GetTexture("graphcis/box.png"));
        // m_TextureEnemy.loadFromFile("graphics/box.png");//TextureHandler::getTexture("../graphics/box.png");
        // m_SpriteEnemy.setTexture(m_TextureEnemy);
   Enemy::init(rWindow);
}
void Enemy::init(sf::RenderWindow& rWindow)
{
    m_SpriteEnemy.setScale(0.08f, 0.08f);
    m_Position.y =  rWindow.getSize().y - 190;
    m_Position.x = 300;
    m_SpriteEnemy.setPosition(m_Position);  // TEST
    std::cout << m_SpriteEnemy.getPosition().y;
}
// sf::Vector2f& Enemy::getPos()
// {
//     // return m_Position;
// }

// sf::Sprite& Enemy::getSprite()
// {
//     return m_SpriteEnemy;
// }

// bool Enemy::getIsActive()
// {
//     return m_isActive;
// }

void Enemy::update(float dt)
{
    // Move the enemy entity to the right if has left the screen, else deActivate it
    
    m_Position.x < 2000.f ? m_Position.x += m_Speed * dt : m_isActive = false;
    m_Position.y = m_Position.y;
    // std::cout << dt << std::endl;
    //move the sprite
    m_SpriteEnemy.setPosition(m_Position);

    if (m_Position.x > 1980)
    {
        m_Position.x = -100;
    }
    
}

void Enemy::draw(sf::RenderWindow& renderWindow)
{
    // if (m_isActive)
    renderWindow.draw(m_SpriteEnemy);
}
sf::Sprite& Enemy::getSprite()
{
    return m_SpriteEnemy;
}

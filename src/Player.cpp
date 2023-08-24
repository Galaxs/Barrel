#include "Player.h"

Player::Player(sf::RenderWindow& renderWindow)
{
    m_Position.x = VideoMode::getDesktopMode().width - 200;
    m_Position.y = VideoMode::getDesktopMode().height - 200;
    m_StartPos.y = m_Position.y;
    m_Speed.y = 4592;
    m_TexturePlayer.loadFromFile("../graphics/king.png");
    
    m_SpritePlayer.setTexture(m_TexturePlayer);
    m_SpritePlayer.setPosition(m_Position);
    m_SpritePlayer.setScale(-1, 1);
}

void Player::jump(float dt)
{
        if(m_Gound && m_CanJump)
        {
            // m_JumpStarted = true;
            m_Velocity.y = m_Speed.y;
            m_Gound = false;
            // m_CanJump = false;
            // m_JumpFinished = true;
        }
}

sf::Vector2f Player::getSpeed()
{
    return m_Speed;
}

bool Player::canJump() const{return m_CanJump;}
void Player::setCanJump(bool value)
{
    m_CanJump = value;
}
void Player::update(float dt, float const gravity)
{
    // going up after jump and applying gravity
     if( !m_Gound )
    {
        m_Position.y -= m_Velocity.y *  dt; // Move the sprite

        // Going down because of Gravity cost
        m_Velocity.y -= gravity;

    }


    if (m_Position.y >= m_StartPos.y) // Is on ground
    {
        m_Position.y = m_StartPos.y;
        m_Gound = true;
        m_JumpStarted = false;
        // m_CanJump = true;

        
    }

    // if (handleInput)
    // {

    //     // play sound
    // }

    m_SpritePlayer.setPosition(m_Position); // moving the sprite
}

sf::Sprite& Player::getSprite()
{
    return m_SpritePlayer;
}

bool Player::getGround(){return m_Gound;}
bool Player::getJumpFinished(){return m_JumpFinished;}
void Player::setJump(bool valueA, bool valueB)
{
    m_JumpStarted = valueA;
    m_JumpFinished = valueB;
}
void Player::setGround(bool value){m_Gound = value;}

sf::Vector2f& Player::getVelocity()
{
    return m_Velocity;
}
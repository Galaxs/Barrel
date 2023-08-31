#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
    private:
    Sprite m_SpritePlayer;
    Texture m_TexturePlayer;
    sf::Vector2f m_StartPos, m_Position, m_Speed, m_Velocity;

    
    bool m_Gound, m_JumpStarted, m_JumpFinished, m_CanJump;


    
    public:
    Player(sf::RenderWindow& renderWindow);
    void update(float dt, float const gravity);
    void draw(RenderWindow& renderWindow);
    sf::Vector2f getPosition();
    sf::Vector2f getSpeed();

    // JUMP
    void jump(float);
    bool canJump() const;
    void setCanJump(bool);
    void setJump(bool,bool);
    bool getJumpFinished();

    
    bool getGround();
    void setGround(bool);
    void setPosition();
    bool handleInput(RenderWindow& renderWindow, float dt);
    void jump();
    Sprite& getSprite();
    sf::Vector2f& getVelocity();
};
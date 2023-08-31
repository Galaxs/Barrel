#include "GameBarrel.h"
#include "Enemy.h"


GameBarrel::GameBarrel() : m_RenderWindow(sf::VideoMode(VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Barrel!") //: m_NumEnemies(2000)
{
    TextureHolder textureHolder;

    init();
}

//  THE INIT OF THE ENGINE  //
void GameBarrel::init()
{
    m_Player = make_shared<Player>(m_RenderWindow);
    m_Enemy = make_shared<Enemy>(m_RenderWindow);
    
    m_Enviroment.init(m_RenderWindow);
    // m_Enemy->init(m_RenderWindow);
    m_GroundPos = Vector2f(0.f, VideoMode::getDesktopMode().width - 200);
}

//  THE INPUT SECTION OF THE ENGINE  //
void GameBarrel::handleInput(RenderWindow& renderWindow, float dt)
{
    // TO DO: CHANGE ALL OF THIS NESTED IF FOR A TIDY SWITCH
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {   
        m_Player->jump(dt);
    }
    else {

    }
    while(renderWindow.pollEvent(m_Event))
    {
        if(m_Event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
        {
            renderWindow.close();
        }
        if (m_Event.type == Event::KeyReleased && m_Event.key.code == Keyboard::Up )
        {   
                m_Player->setCanJump(true);
        }
        else {
            m_Player->setCanJump(false);
        }
    }
}


void GameBarrel::draw(RenderWindow& rWindow)
{
    rWindow.clear(Color::Blue);
    rWindow.draw(m_Player->getSprite());
    rWindow.draw(m_Enviroment.getVertexArray());
   // Draw the enemy

//    m_Enemy->draw(m_RenderWindow);       ///         WORKS !!!
    rWindow.draw(m_Enemy->getSprite());     // WORKS!!!!!

    rWindow.display();
}

void GameBarrel::update()
{
    m_Player->update(m_Dt, GameBarrel::GRAVITY);
    m_Enemy->update(m_Dt);
}

void GameBarrel::run()
{
    Clock clock;
    while(m_RenderWindow.isOpen())
    {
        m_Dt = m_Clock.restart().asSeconds();
        handleInput(m_RenderWindow, m_Dt);
        update();
        draw(m_RenderWindow);
    }
}
#include "GameBarrel.h"


GameBarrel::GameBarrel() : m_NumEnemies(2000)
{
    init();
}

//  THE INIT OF THE ENGINE  //
void GameBarrel::init()
{
    m_Player = make_shared<Player>(m_RenderWindow);
    m_RenderWindow.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Barrel!"); 
    m_GroundPos = Vector2f(0.f, VideoMode::getDesktopMode().width - 200);
    
    // for (int i = 0; i < m_NumEnemies; i++)
    // {
    //     m_Enemies[i] = make_shared<Enemy>(m_RenderWindow);
    // }

    // m_RenderWindow.setKeyRepeatEnabled(false);

    // Enviroment 
    m_Enviroment.init(m_RenderWindow);

}

//  THE INPUT SECTION OF THE ENGINE  //
bool GameBarrel::handleInput(RenderWindow& renderWindow, float dt)
{
    // TO DO: CHANGE ALL OF THIS NESTED IF FOR A TIDY SWITCH
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {   
        m_Player->jump(m_Dt);
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
    return false;
}


void GameBarrel::draw(RenderWindow& rWindow)
{
    rWindow.clear(Color::Blue);
    rWindow.draw(m_Player->getSprite());
    rWindow.draw(m_Enviroment.getVertexArray());
   // Draw the enemy
    // for (int i = 0; i < m_NumEnemies; i++)
    // {
    //     m_Enemies[i]->draw(m_RenderWindow);
    // }
    rWindow.display();
}

void GameBarrel::update()
{
    m_Player->update(m_Dt, GameBarrel::GRAVITY);
    // for(auto enemy : m_enemies)
    // {
    //     enemy->update(m_Dt);

    // }
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
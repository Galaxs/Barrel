#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "memory"
#include "Enviroment.h"
#include "iostream"
// #include

using namespace std;
using namespace sf;

class GameBarrel        // TODO DONT FORGET THE WINDOW.DISPLAY(); IT WOULD CAUSE A MEMORY ERROR IF DONT;
{
private:
    Clock m_Clock;
    Event m_Event;

    float m_Dt;
    float const GRAVITY = 19.5f;
    RenderWindow m_RenderWindow;
    std::shared_ptr<Player> m_Player;
    // const int m_NumEnemies;

    std::shared_ptr<Enemy> m_Enemy;
    // std::shared_ptr<Enemy> m_Enemies[2000];

    Enviroment m_Enviroment;

    Vector2f m_GroundPos;



    

public:

    GameBarrel();
    void init();
    void run();
    void update();
    void draw(RenderWindow& rWindow);
    void handleInput(RenderWindow& renderWindow, float dt);

};
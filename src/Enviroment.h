#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
class Enviroment
{
    private:
    sf::Vector2f m_Position;
    sf::VertexArray* m_VertexArray;
    public:
    Enviroment();
    ~Enviroment();
    Enviroment(sf::RenderWindow& rWindow);
    void init(sf::RenderWindow&);
    sf::VertexArray& getVertexArray();
};
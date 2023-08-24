#include "Enviroment.h"

Enviroment::Enviroment()
{
    
}
Enviroment::Enviroment(sf::RenderWindow& rWindow)
{
    init(rWindow);
}

void Enviroment::init(sf::RenderWindow& rWindow)
{
    float lineHeight = 0.8 * rWindow.getSize().y;
    m_Position = sf::Vector2f(0.f, lineHeight);

    // Create and draw the line
    m_VertexArray = new sf::VertexArray(sf::Lines, 2);

        // Create and draw the line
        // sf::VertexArray line(sf::Lines, 2);
        (*m_VertexArray)[0].position = sf::Vector2f(0.0f, lineHeight);
        (*m_VertexArray)[1].position = sf::Vector2f(rWindow.getSize().x, lineHeight);
        (*m_VertexArray)[0].color = sf::Color::Blue; // Change the color if desired
        (*m_VertexArray)[1].color = sf::Color::Red;

    
}

sf::VertexArray& Enviroment::getVertexArray()
{
    return *m_VertexArray;
}
Enviroment::~Enviroment()
{
    delete m_VertexArray;
}
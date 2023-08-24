#include "TextureHandler.h"

TextureHandler* TextureHandler::m_s_Instance =nullptr;

TextureHandler::TextureHandler()
{
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

void TextureHandler::addTexture(std::string const& filename)
{
    // Get a reference to the map of textures
    std::map<std::string, sf::Texture>::iterator keyValuePair = m_s_Instance->m_Textures.find(filename);

    if(keyValuePair == m_s_Instance->m_Textures.end())
    {
        // No texture found | Create Texture in the map
        sf::Texture texture = m_s_Instance->m_Textures[filename];
        m_s_Instance->m_StingStream << "../graphics/" << filename;
        texture.loadFromFile(m_s_Instance->m_StingStream.str());
    }
}

sf::Texture& TextureHandler::getTexture(std::string const& filename)
{
    std::map<std::string, sf::Texture>::iterator keyValuePair = m_s_Instance->m_Textures.find(filename);

    {
        if(keyValuePair != m_s_Instance->m_Textures.end())
        {
            return keyValuePair->second;           
        }
        else
        {
            #ifdef debuggingOnConsole
            std::cout << "Texture not found" << std::endl;
            #endif
            return keyValuePair->second;
        }
    }
}
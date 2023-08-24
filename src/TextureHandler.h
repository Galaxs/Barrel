#pragma once
#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

// #include "iostream"
#include "string"
#include "assert.h"
#include <map>
#include <SFML/Graphics.hpp>
#include "sstream"

class TextureHandler
{
    private:
    std::map<std::string, sf::Texture> m_Textures;
    std::map<std::string, sf::Texture>::iterator m_iter;
    static TextureHandler* m_s_Instance;
    std::stringstream m_StingStream;


    public:
    TextureHandler();
    static sf::Texture& getTexture(std::string const& filename);
    static void addTexture(std::string const& filename);

};

#endif
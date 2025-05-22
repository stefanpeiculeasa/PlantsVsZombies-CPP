#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "grid.h"
#include <unordered_map>
#include <string>

class TextureManager {
    std::unordered_map<std::string, sf::Texture> sunTextures;
    std::unordered_map<std::string, float> scaleFactors;

public:
    TextureManager();

    bool load(const std::string& id, const std::string& filepath);
    sf::Texture& get(const std::string& id);
    float getScaleFactor(const std::string& id) const;
    bool has(const std::string& id) const;
};

class Renderer {
    TextureManager sunTextureManager;
    sf::Sprite mapSprite;
    int scale = 2;
    sf::Font font;
    sf::Text sunText, hpText, selectedPlantText, remainingZombies;

public:
    explicit Renderer(sf::RenderWindow& window);

    void renderFrame(sf::RenderWindow& window, Grid& grid, int sun, int playerHp,
                     const std::string& selectedPlant, int remZombies);
};

#endif // RENDERER_H

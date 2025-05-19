#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "grid.h"
#include <unordered_map>
#include "zombie.h"

class TextureManager {

    std::unordered_map<std::string, sf::Texture> sunTextures;
    std::unordered_map<std::string, float> scaleFactors = {
        {"peashooter",0.1f},
        {"basiczombie",.3f},
        {"projectile",.05f},
        {"wallnut",0.1f},
        {"sunflower",.1f},
        {"sun",.5f}
    };

public:
    TextureManager() {
        load("peashooter","assets/peashooter.png");
        load("basiczombie","assets/viktor.png");
        load("map","assets/map.png");
        load("projectile","assets/projectile.png");
        load("wallnut","assets/wallnut.png");
        load("sunflower","assets/sunflower.png");
        load("sun","assets/sun.png");
    };

    bool load(const std::string& id, const std::string& filepath) {
        sf::Texture sunTexture;
        if (!sunTexture.loadFromFile(filepath))
            return false;
        sunTextures[id] = sunTexture;
        return true;
    }

    sf::Texture& get(const std::string& id) {
        return sunTextures.at(id);
    }

    float getScaleFactor(const std::string& id) const {
        return scaleFactors.at(id);
    }

    bool has(const std::string& id) const {
        return sunTextures.contains(id);
    }
};

class Renderer {

    TextureManager sunTextureManager;
    sf::Sprite mapSprite;
    int scale = 2;
    sf::Font font;
    sf::Text sunText,hpText,selectedPlantText,remainingZombies;

public:

    explicit Renderer(sf::RenderWindow& window) {
        // calculates and loads the map
        const unsigned int mapWidth = sunTextureManager.get("map").getSize().x;
        const unsigned int mapHeight= sunTextureManager.get("map").getSize().y;
        const unsigned int windowWidth = mapWidth * scale;
        const unsigned int windowHeight = mapHeight * scale;
        window.create(sf::VideoMode(windowWidth,windowHeight),  "Plants vs Victor",sf::Style::Close);
        mapSprite.setTexture(sunTextureManager.get("map"));
        mapSprite.setScale(static_cast<float>(scale),static_cast<float>(scale));
        // vsync
        window.setVerticalSyncEnabled(true);
        // font/sunText handling
        font.loadFromFile("assets/main_font.ttf");

        sunText.setFont(font);
        sunText.setCharacterSize(100);
        sunText.setFillColor(sf::Color::Yellow);
        sunText.setStyle(sf::Text::Bold);
        sunText.setPosition(20,20);

        hpText.setFont(font);
        hpText.setCharacterSize(100);
        hpText.setFillColor(sf::Color::Red);
        hpText.setStyle(sf::Text::Bold);
        hpText.setPosition(20,120);

        selectedPlantText.setFont(font);
        selectedPlantText.setCharacterSize(70);
        selectedPlantText.setFillColor(sf::Color(30,30,30));
        selectedPlantText.setStyle(sf::Text::Bold);
        selectedPlantText.setPosition(20,500);

        remainingZombies.setString("Remaining: \n 217");

        remainingZombies.setFont(font);
        remainingZombies.setCharacterSize(70);
        remainingZombies.setFillColor(sf::Color(78, 57, 212));
        remainingZombies.setStyle(sf::Text::Bold);
        remainingZombies.setPosition(20,250);
    }

    void renderFrame(sf::RenderWindow& window, Grid& grid, const int sun, const int playerHp, const std::string& selectedPlant) {
        window.clear();

        window.draw(mapSprite);

        std::vector<Entity*> sortedEntities;
        for (const auto& entity : grid.getEntities()) {
            sortedEntities.push_back(entity.get());
        }

        std::ranges::sort(sortedEntities, [](Entity* a, Entity* b) {
            auto getType = [](Entity* e) {
                const std::string& name = e->getName();
                if (name == "peashooter" || name == "sunflower" || name == "wallnut") return 0;
                if (name.find("zombie") != std::string::npos) return 1;
                return 2;
            };
            return getType(a) < getType(b);
        });

        for (auto* entity : sortedEntities) {
            sf::Sprite sprite;
            sprite.setTexture(sunTextureManager.get(entity->getName()));
            float scaleFactor = sunTextureManager.getScaleFactor(entity->getName());
            sprite.setScale(scaleFactor, scaleFactor);

            const sf::Vector2u texSize = sprite.getTexture()->getSize();
            const float scaledWidth = static_cast<float>(texSize.x) * scaleFactor;
            const float scaledHeight = static_cast<float>(texSize.y) * scaleFactor;

            const int x = entity->getPosition().first;
            const int y = entity->getPosition().second;
            sprite.setPosition(static_cast<float>(x) - scaledWidth / 2.f, static_cast<float>(y) - scaledHeight / 2.f);

            window.draw(sprite);
        }

        // Draw UI
        sunText.setString(std::to_string(sun));
        hpText.setString(std::to_string(playerHp));
        selectedPlantText.setString("Selected: \n" + selectedPlant);

        window.draw(hpText);
        window.draw(sunText);
        window.draw(selectedPlantText);
        window.draw(remainingZombies);

        window.display();
    }


};


#endif
#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "basiczombie.h"
#include "wallnut.h"
#include "peashooter.h"
#include "sunflower.h"
#include "utils.h"
#include "renderer.h"
#include "sun.h"

class Game {
    Grid grid;
    bool running;
    sf::RenderWindow window;
    sf::Clock clock;
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = GameUtils::keyCoords;
    std::string selectedPlant = "peashooter";

public:
    Game() : running(true) {}

    void run() {
        Renderer renderer(window);
        GameUtils::updateCoords(keyCoords,renderer.getScale());
        grid.updateCoords(keyCoords);
        while(running && window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                // main event switch
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::MouseButtonPressed: {
                        const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        sf::Vector2f mouseF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        const float clickBoxSize = static_cast<float>(keyCoords["hitboxSize"][0].first.x);

                        for (auto& entity : grid.getEntities()) {
                            if (dynamic_cast<Sun*>(entity.get()) && entity->getHitbox().getGlobalBounds().contains(mouseF)) {
                                entity->setDeletionMark(true);
                                grid.addSun(5);
                                break;
                            }
                        }

                        for (auto& center : keyCoords["tileCenters"]) {
                            sf::Vector2f scaledCenter(static_cast<float>(center.first.x), static_cast<float>(center.first.y));

                            sf::FloatRect clickBox(scaledCenter.x - clickBoxSize / 2,scaledCenter.y - clickBoxSize / 2,clickBoxSize,clickBoxSize);

                            // if (center.second) break; else center.second = false;

                            if (clickBox.contains(mouseF)) {
                                if (event.mouseButton.button == sf::Mouse::Left) {
                                    if (selectedPlant == "peashooter") {
                                        auto plant = std::make_unique<Peashooter>(center.first.x,center.first.y,renderer.getScale());
                                        grid.addEntity(std::move(plant));
                                    } else if (selectedPlant == "wallnut") {
                                        auto plant = std::make_unique<Wallnut>(center.first.x,center.first.y,renderer.getScale());
                                        grid.addEntity(std::move(plant));
                                    } else if (selectedPlant == "sunflower") {
                                        grid.addEntity(std::move(std::make_unique<Sunflower>(center.first.x,center.first.y,renderer.getScale())));
                                    }
                                }
                                else
                                    if (event.mouseButton.button == sf::Mouse::Right) {
                                        grid.addEntity(std::make_unique<BasicZombie>(center.first.x, center.first.y,renderer.getScale()));
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Num1:
                                selectedPlant = "peashooter";
                                break;
                            case sf::Keyboard::Num2:
                                selectedPlant = "wallnut";
                                break;
                            case sf::Keyboard::Num3:
                                selectedPlant = "sunflower";
                                break;
                            default: break;
                        }
                    default:
                        break;
                }

                if (const sf::Time sleep = GameUtils::frameTime - clock.getElapsedTime(); sleep > sf::Time::Zero) {
                    sf::sleep(sleep);
                }

            }
            grid.update(keyCoords);
            renderer.renderFrame(window,grid,grid.getSun(),grid.getPlayerHp(),selectedPlant);
        }
    }

    void stop() {
        running = false;
    }
};


#endif //GAME_H

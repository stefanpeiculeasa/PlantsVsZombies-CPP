#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "utils.h"
#include "renderer.h"

class Game {
    Game() = default;

    Grid grid;
    bool running = true;
    sf::RenderWindow window;
    sf::Clock clock;
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = GameUtils::keyCoords;

public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game() = default;

    static Game& getInstance() {
        static Game instance;
        return instance;
    }

    void run() {
        Renderer renderer(window);
        grid.updateCoords(keyCoords);
        while (running && window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::MouseButtonPressed: {
                        const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        const sf::Vector2f mouseF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                        if (event.mouseButton.button == sf::Mouse::Left) {
                            grid.handleClick(mouseF);
                        }
                        break;
                    }
                    case sf::Event::KeyPressed:
                        grid.handleKeyPress(event.key.code);
                        break;
                    default:
                        break;
                }

                if (const sf::Time sleep = GameUtils::frameTime - clock.getElapsedTime(); sleep > sf::Time::Zero) {
                    sf::sleep(sleep);
                }
            }
            grid.update();
            renderer.renderFrame(window, grid, grid.getSun(), grid.getPlayerHp(), grid.getSelectedPlant());
            clock.restart();
        }
    }

    void stop() {
        running = false;
    }
};

#endif
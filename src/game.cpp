#include "game.h"
#include "renderer.h"


Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::run() {
    Renderer renderer(window);
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

            if (const sf::Time sleep = Settings::frameTime - clock.getElapsedTime(); sleep > sf::Time::Zero) {
                sf::sleep(sleep);
            }
        }

        if (grid.getPlayerHp() <= 0)
            stop();
            window.close();

        grid.update();
        renderer.renderFrame(window, grid, grid.getSun(), grid.getPlayerHp(), grid.getSelectedPlant(), grid.getZombiesAmount());
        clock.restart();
    }
}

void Game::stop() {
    running = false;
}

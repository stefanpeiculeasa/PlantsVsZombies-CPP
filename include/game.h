#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "utils.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game {
    Game() = default;
    ~Game() = default;

    Grid grid;
    bool running = true;
    sf::RenderWindow window;
    sf::Clock clock;

public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& getInstance();

    void run();
    void stop();
};

#endif

#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>
#include <random>

namespace Settings {
    inline constexpr float fps = 60.0f;

    inline const sf::Time frameTime = sf::seconds(1.0f / fps);
    inline constexpr int playerHealth = 100;
    inline constexpr int startingSun = 20;
    inline constexpr int sunValue = 5;
    inline constexpr int sunRange = 150;
    inline constexpr std::pair<int,int> spawnAmount = std::make_pair(15, 30);
    inline constexpr std::pair<int,int> spawnInterval = std::make_pair(5,10);
    inline constexpr std::string defaultPlant = "peashooter";
    inline std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = {
        {"tileCenters", {
            {{416, 184}, false}, {{530, 184}, false}, {{646, 184}, false}, {{762, 184}, false}, {{878, 184}, false},
            {{994, 184}, false}, {{1110, 184}, false}, {{1218, 184}, false}, {{1336, 184}, false},
            {{416, 322}, false}, {{530, 322}, false}, {{646, 322}, false}, {{762, 322}, false}, {{878, 322}, false},
            {{994, 322}, false}, {{1110, 322}, false}, {{1218, 322}, false}, {{1336, 322}, false},
            {{416, 462}, false}, {{530, 462}, false}, {{646, 462}, false}, {{762, 462}, false}, {{878, 462}, false},
            {{994, 462}, false}, {{1110, 462}, false}, {{1218, 462}, false}, {{1336, 462}, false},
            {{416, 604}, false}, {{530, 604}, false}, {{646, 604}, false}, {{762, 604}, false}, {{878, 604}, false},
            {{994, 604}, false}, {{1110, 604}, false}, {{1218, 604}, false}, {{1336, 604}, false},
            {{416, 740}, false}, {{530, 740}, false}, {{646, 740}, false}, {{762, 740}, false}, {{878, 740}, false},
            {{994, 740}, false}, {{1110, 740}, false}, {{1218, 740}, false}, {{1336, 740}, false}
        }},
        {"zombieHit", {
            {{360, 184}, false}, {{360, 322}, false}, {{360, 462}, false}, {{360, 604}, false}, {{360, 740}, false}
        }},
        {"hitboxSize", {
            {{60, 60}, false}
        }},
        {"zombieSpawnPoints", {
            {{1480, 184}, false}, {{1480, 322}, false}, {{1480, 462}, false}, {{1480, 604}, false}, {{1480, 740}, false}
        }},
    };
    inline std::vector rows = {184,322,462,604,740};
    inline int random(const int a,const int b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(a, b);
        return dist(gen);
    }
}

#endif //UTILS_H

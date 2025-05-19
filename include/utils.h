#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>

namespace GameUtils {
    inline const sf::Time frameTime = sf::seconds(1.0f / 60.0f);
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
        }}
    };
}

#endif //UTILS_H

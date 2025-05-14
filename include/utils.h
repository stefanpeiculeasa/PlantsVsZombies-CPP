#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>

namespace GameUtils {
    inline const sf::Time frameTime = sf::seconds(1.0f / 60.0f);
    inline std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = {
        {"tileCenters", {
            {{208, 92}, true}, { {265, 92}, false}, { {323, 92}, true}, { {381, 92}, false}, { {439, 92}, true},
            { {497, 92}, false}, { {555, 92}, true}, { {609, 92}, false}, { {668, 92}, true},
            {{208, 161}, true}, { {265, 161}, false}, { {323, 161}, true}, { {381, 161}, false}, { {439, 161}, true},
            { {497, 161}, false}, { {555, 161}, true}, { {609, 161}, false}, { {668, 161}, true},
            {{208, 231}, true}, { {265, 231}, false}, { {323, 231}, true}, { {381, 231}, false}, { {439, 231}, true},
            { {497, 231}, false}, { {555, 231}, true}, { {609, 231}, false}, { {668, 231}, true},
            {{208, 302}, true}, { {265, 302}, false}, { {323, 302}, true}, { {381, 302}, false}, { {439, 302}, true},
            { {497, 302}, false}, { {555, 302}, true}, { {609, 302}, false}, { {668, 302}, true},
            {{208, 370}, true}, { {265, 370}, false}, { {323, 370}, true}, { {381, 370}, false}, { {439, 370}, true},
            { {497, 370}, false}, { {555, 370}, true}, { {609, 370}, false}, { {668, 370}, true}
        }},
        {"zombieHit", {
            {{180, 92}, true}, {{180, 161}, false}, {{180, 231}, true}, {{180, 302}, false}, {{180, 370}, true}
        }},
        {"hitboxSize", {
            {{44, 44}, true}
        }},
        {"zombieSpawnPoints", {
            {{740, 92}, true}, {{740, 161}, false}, {{740, 231}, true}, {{740, 302}, false}, {{740, 370}, true}
        }}
    };

    inline void updateCoords(std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& keyCoords,const int scale) {
        for (auto& key : keyCoords) {
            for (auto& coord : key.second) {
                coord.first.x *= scale;
                coord.first.y *= scale;
            }
        }
    }


}

#endif //UTILS_H

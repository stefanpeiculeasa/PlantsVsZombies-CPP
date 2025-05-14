#include "sun.h"

Sun::Sun(const int x, const int y, const int scale, const int damage, const int speed, sf::Vector2i finalPos)  : Entity(x,y,1,"sun",1,damage,scale), speed(speed), finalPos(finalPos) {}

void Sun::move() {
    float dx = static_cast<float>(finalPos.x - x);
    float dy = static_cast<float>(finalPos.y - y);
    float length = sqrt(dx*dx + dy*dy);

    if (length > 1.0f) {
        dx /= length;
        dy /= length;

        float new_x = x + dx*speed;
        float new_y = y + dy*speed;

        x = static_cast<int>(new_x);
        y = static_cast<int>(new_y);
    }

    hitbox.setPosition(x,y);
}

void Sun::update(Grid &grid) {
    move();
}


#include "sun.h"
#include <cmath>
#include "grid.h"

Sun::Sun(const int x, const int y, const int damage, const int speed, const sf::Vector2i finalPos)  : Entity(x,y,1,"sun",1,damage), speed(speed), finalPos(finalPos) {}

void Sun::move() {
    auto dx = static_cast<float>(finalPos.x - x.get());
    auto dy = static_cast<float>(finalPos.y - y.get());

    if (const auto length = static_cast<float>(sqrt(dx*dx + dy*dy)); length > 1.0f) {
        dx /= length;
        dy /= length;

        const float new_x = static_cast<float>(x.get()) + dx*static_cast<float>(speed);
        const float new_y = static_cast<float>(y.get()) + dy*static_cast<float>(speed);

        x = static_cast<int>(new_x);
        y = static_cast<int>(new_y);
    }

    hitbox.setPosition(static_cast<float>(x.get()),static_cast<float>(y.get()));
}

void Sun::update(Grid&) {
    move();
}


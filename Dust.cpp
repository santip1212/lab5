#include "Dust.hpp"
#include "Painter.h"

Dust::Dust(const Point& center, const Point& velocity, double lifetime, double radius, const Color& color)
    : d_center(center), d_velocity(velocity), d_lifetime(lifetime), d_radius(radius), d_color(color) {}

void Dust::update(double time) {
    d_center = d_center + d_velocity * time;
    d_lifetime -= time;
}

bool Dust::isAlive() const {
    return d_lifetime > 0.0;
}

void Dust::draw(Painter& painter) const {
    // Рисуем искру (кружочек)
    painter.draw(d_center, d_radius, d_color);
}
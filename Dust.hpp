#pragma once
#include "Point.h"
#include "Color.h"

class Painter;

class Dust {
public:
    Dust(const Point& center, const Point& velocity, double lifetime, double radius, const Color& color);
    
    void update(double time); // Двигает частицу и уменьшает время жизни
    bool isAlive() const;     // Проверяет, не пора ли удалить частицу
    void draw(Painter& painter) const;

private:
    Point d_center;
    Point d_velocity;
    double d_lifetime;
    double d_radius;
    Color d_color;
};
#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"
#include"Color.h"

class Ball {
private:
    Point b_center;
    double b_radius;
    Color b_color;
    double b_mass;
    bool b_isCollidable = true;
    Velocity b_velocity;

public:
    Ball(const Point& center, double radius, const Color& color);
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool isCollidable() const;
    void setCollidable(bool Collidable);
};

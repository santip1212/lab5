#pragma once
#include "Ball.hpp"
#include <vector>

class Physics {
  public:
  // для хранения координат места столкновения
      struct CollisionEvent {
        Point point;
    };
    Physics(double timePerTick = 0.001);
    void setWorldBox(const Point& topLeft, const Point& bottomRight);
    void update(std::vector<Ball>& balls, size_t ticks) const;
    // методы для получения и очистки 
    const std::vector<CollisionEvent>& getCollisionEvents() const { return events; }
    void clearCollisionEvents() { events.clear(); }

  private:
    void collideBalls(std::vector<Ball>& balls) const;
    void collideWithBox(std::vector<Ball>& balls) const;
    void move(std::vector<Ball>& balls) const;
    void processCollision(Ball& a, Ball& b,
                          double distanceBetweenCenters2) const;

  private:
    Point topLeft;
    Point bottomRight;
    double timePerTick;
    mutable std::vector<CollisionEvent> events;
};

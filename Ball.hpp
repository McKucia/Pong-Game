#pragma once

#include <SFML/Graphics.hpp>

//Ball
constexpr float ballSpeed = 0.2;
constexpr int ballRadius = 7;

enum class Direction{
    STOP = 0,
    LEFT = 1,
    LEFT_UP = 2,
    LEFT_DOWN = 3,
    RIGHT = 4,
    RIGHT_UP = 5,
    RIGHT_DOWN = 6,
};

class Ball : public sf::CircleShape{
public:
    Ball(int r = ballRadius);
    void reset();
    void randomDirection();
    bool mv(sf::RectangleShape& R1, sf::RectangleShape& R2, Direction dir);
    bool checkHit(sf::RectangleShape& R1, sf::RectangleShape& R2);
    Direction getCurrentDirection() const { return direction_; }

private:
    float speed_;
    int startPosX_;
    int startPosY_;
    Direction direction_;
};
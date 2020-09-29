#pragma once

#include <SFML/Graphics.hpp>

//Paddle
constexpr float paddleSpeed = 400;
constexpr int paddleWidth = 10;
constexpr int paddleHeight = 60;

enum class UpOrDown{
    UP = 0,
    DOWN = 1,
    STOP = 2,
};

class Paddle : public sf::RectangleShape{
public:
    Paddle(sf::Vector2f size = {paddleWidth, paddleHeight});
    void reset();
    float getSpeed()                const { return speed_; }
    int getPoints()                 const { return points_; }
    void setPoints(int newAmount)         { points_ = newAmount; }

private:
    int points_;
    static int paddleIndex_;
    float speed_;
    int startPosX_;
    int startPosY_;
    sf::Vector2f moveDirection_;
};
#pragma once

#include <SFML/Graphics.hpp>

//Paddle
constexpr float paddleSpeed = 0.2;
constexpr int paddleWidth = 10;
constexpr int paddleHeight = 100;

enum class UpOrDown{
    UP = 0,
    DOWN = 1,
    STOP = 2,
};

class Paddle : public sf::RectangleShape{
public:
    Paddle(sf::Vector2f size = {paddleWidth, paddleHeight});
    void reset();
    void mv();
    void setDirection(const sf::Vector2f& newDirection);
    float getSpeed()        const { return speed_; }

private:
    static int paddleIndex_;
    float speed_;
    int startPosX_;
    int startPosY_;
    sf::Vector2f moveDirection_;
};
#include "Paddle.hpp"
#include "GameManager.hpp"

int Paddle::paddleIndex_ = 0;

Paddle::Paddle(sf::Vector2f size) : sf::RectangleShape(size){
    paddleIndex_++;
    moveDirection_ = {0, 0};
    speed_ = paddleSpeed;
    this->setFillColor(sf::Color(110, 13, 37));

    startPosX_ = (paddleIndex_ == 2) ? windowWidth - paddleWidth * 2 : paddleWidth * 2;
    startPosY_ = windowHeight / 2;
    this->setOrigin(paddleWidth / 2, paddleHeight / 2);
    this->setPosition(startPosX_, startPosY_);
}

void Paddle::reset(){
    setPosition(startPosX_, startPosY_);
    moveDirection_ = {0, 0};
}




#include "Ball.hpp"
#include "GameManager.hpp"

Ball::Ball(int r) : sf::CircleShape(r){
    this->setFillColor(sf::Color(161, 48, 52));
    speed_ = ballSpeed;
    direction_ = Direction::STOP;

    startPosX_ = windowWidth / 2;
    startPosY_ = windowHeight / 2;
    this->setOrigin(ballRadius, ballRadius);
    this->setPosition(startPosX_, startPosY_);
}

void Ball::reset(){
    direction_ = Direction::STOP;
    setPosition(startPosX_, startPosY_);
}

void Ball::randomDirection(){
    direction_ = static_cast<Direction>(rand() % 6 + 1);
}

bool Ball::mv(sf::RectangleShape &R1, sf::RectangleShape &R2, Direction dir){
    switch (dir) {
        case Direction::LEFT:
            this->move(-speed_, 0);
            break;
        case Direction::RIGHT:
            this->move(speed_, 0);
            break;
        case Direction::LEFT_UP:
            this->move(-speed_ / 2, -speed_ / 2);
            break;
        case Direction::LEFT_DOWN:
            this->move(-speed_ / 2, speed_ / 2);
            break;
        case Direction::RIGHT_UP:
            this->move(speed_, -speed_ / 2);
            break;
        case Direction::RIGHT_DOWN:
            this->move(speed_, speed_ / 2);
            break;
        case Direction::STOP:
            this->move(0, 0);
            break;
    }

    return checkHit(R1, R2);
}

bool Ball::checkHit(sf::RectangleShape &R1, sf::RectangleShape &R2){
    //Hit Floor or Celling
    if(getPosition().y - getRadius() <= 0){
        if(direction_ == Direction::LEFT_UP)
            direction_ = Direction::LEFT_DOWN;
        if(direction_ == Direction::RIGHT_UP)
            direction_ = Direction::RIGHT_DOWN;
    }
    if(getPosition().y + getRadius() >= windowHeight){
        if(direction_ == Direction::LEFT_DOWN)
            direction_ = Direction::LEFT_UP;
        if(direction_ == Direction::RIGHT_DOWN)
            direction_ = Direction::RIGHT_UP;
    }

    //Hit Wall
    if(getPosition().x + getRadius() <= 0){
        return true;
    }
    if(getPosition().x - getRadius() >= windowWidth){
        return true;
    }

    //Hit paddles
    if (R1.getGlobalBounds().intersects(this->getGlobalBounds())) {
        float upperPart = R1.getPosition().y - R1.getSize().y / 4;
        float lowerPart = R1.getPosition().y + R1.getSize().y / 4;

        if(getPosition().y < upperPart)
            direction_ = Direction::RIGHT_UP;
        if(getPosition().y > lowerPart)
            direction_ = Direction::RIGHT_DOWN;
        if(getPosition().y < lowerPart && getPosition().y > upperPart )
            direction_ = Direction::RIGHT;
    }
    if (R2.getGlobalBounds().intersects(this->getGlobalBounds())) {
        float upperPart = R2.getPosition().y - R1.getSize().y / 4;
        float lowerPart = R2.getPosition().y + R1.getSize().y / 4;

        if(getPosition().y < upperPart)
            direction_ = Direction::LEFT_UP;
        if(getPosition().y > lowerPart)
            direction_ = Direction::LEFT_DOWN;
        if(getPosition().y < lowerPart && getPosition().y > upperPart )
            direction_ = Direction::LEFT;
    }
    return false;
}



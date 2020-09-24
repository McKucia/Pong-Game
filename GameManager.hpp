#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"

//Window
constexpr int windowHeight = 400;
constexpr int windowWidth = 600;

const std::string windowName = "Pong";

class GameManager{
public:
    GameManager(std::string n1 = "no_name", std::string n2 = "no_name");
    void newGame();
    void createWindow();
    void Update();
    void draw();
    void restartGame();

private:
    sf::RenderWindow Window;
    Paddle paddle1_;
    Paddle paddle2_;
    Ball ball_;
    sf::Font font_;
    std::string name1_;
    std::string name2_;
    sf::Text name1Text_;
    sf::Text name2Text_;
};
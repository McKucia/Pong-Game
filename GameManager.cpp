#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager(std::string n1, std::string n2) : name1_(n1), name2_(n2){
    font_.loadFromFile("../orange_juice.ttf");

    player1Points_.setFont(font_);
    player1Points_.setString("0");
    player1Points_.setCharacterSize(24);
    player1Points_.setFillColor(sf::Color(167, 152, 139));
    player1Points_.setPosition(20, windowHeight - 40);

    player2Points_.setFont(font_);
    player2Points_.setString("0");
    player2Points_.setCharacterSize(24);
    player2Points_.setFillColor(sf::Color(167, 152, 139));
    player2Points_.setPosition(windowWidth - 30, windowHeight - 40);

    name1Text_.setFont(font_);
    name1Text_.setString(name1_);
    name1Text_.setCharacterSize(30);
    name1Text_.setFillColor(sf::Color(167, 152, 139));
    name1Text_.setPosition(20, 20);

    name2Text_.setFont(font_);
    name2Text_.setString(name2_);
    name2Text_.setCharacterSize(30);
    name2Text_.setFillColor(sf::Color(167, 152, 139));
    name2Text_.setPosition(windowWidth - 120, 20);
}

void GameManager::newGame(){
    createWindow();
    Update();
}

void GameManager::createWindow(){
    Window.create(sf::VideoMode(windowWidth, windowHeight, 32), windowName);
    Window.setActive(true);
    Window.setKeyRepeatEnabled(false);
    Window.setKeyRepeatEnabled(false);
}

void GameManager::Update(){
    sf::Clock clock;
    while(Window.isOpen()){
        sf::Event event;
        while(Window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                Window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ball_.getCurrentDirection() == Direction::STOP)
                ball_.randomDirection();
        }

        float deltaTime = clock.restart().asSeconds();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1_.getPosition().y - paddle1_.getSize().y / 2 > 3){
            paddle1_.move(0, -paddle1_.getSpeed() * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddle1_.getPosition().y + paddle1_.getSize().y / 2 < windowHeight - 3){
            paddle1_.move(0, paddle1_.getSpeed() * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2_.getPosition().y - paddle2_.getSize().y / 2 > 3){
            paddle2_.move(0, -paddle2_.getSpeed() * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle2_.getPosition().y + paddle2_.getSize().y / 2 < windowHeight - 3){
            paddle2_.move(0, paddle2_.getSpeed() * deltaTime);
        }

        Window.clear(sf::Color(241, 235, 228));

        bool restart = ball_.mv(paddle1_, paddle2_, ball_.getCurrentDirection());
        if(restart) {
            restartGame();
        }

        draw();
    }
}

void GameManager::draw(){
    Window.draw(player1Points_);
    Window.draw(player2Points_);
    Window.draw(ball_);
    Window.draw(paddle1_);
    Window.draw(paddle2_);
    Window.draw(name1Text_);
    Window.draw(name2Text_);

    Window.display();
}

void GameManager::restartGame(){
    if(ball_.getWinner() == 1) {
        paddle1_.setPoints(paddle1_.getPoints() + 1);
        player1Points_.setString(std::to_string(paddle1_.getPoints()));
    }
    else if(ball_.getWinner() == 0) {
        paddle2_.setPoints(paddle2_.getPoints() + 1);
        player2Points_.setString(std::to_string(paddle2_.getPoints()));
    }
    ball_.reset();
    paddle1_.reset();
    paddle2_.reset();
}
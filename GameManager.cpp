#include "GameManager.hpp"

GameManager::GameManager(std::string n1, std::string n2) : name1_(n1), name2_(n2){
    font_.loadFromFile("../orange_juice.ttf");

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
    while(Window.isOpen()){
        while(Window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                Window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ball_.getCurrentDirection() == Direction::STOP)
                ball_.randomDirection();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                paddle1_.setDirection({0, -paddle1_.getSpeed()});
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                paddle1_.setDirection({0, paddle1_.getSpeed()});
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                paddle2_.setDirection({0, -paddle2_.getSpeed()});
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                paddle2_.setDirection({0, paddle2_.getSpeed()});

            if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S ))
                paddle1_.setDirection({0, 0});
            if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down))
                paddle2_.setDirection({0, 0});
        }
        Window.clear(sf::Color(241, 235, 228));
        paddle1_.mv();
        paddle2_.mv();
        bool restart = ball_.mv(paddle1_, paddle2_, ball_.getCurrentDirection());
        if(restart) {
            restartGame();
        }

        draw();
    }
}

void GameManager::draw(){
    Window.draw(ball_);
    Window.draw(paddle1_);
    Window.draw(paddle2_);
    Window.draw(name1Text_);
    Window.draw(name2Text_);

    Window.display();
}

void GameManager::restartGame(){
    ball_.reset();
    paddle1_.reset();
    paddle2_.reset();
}
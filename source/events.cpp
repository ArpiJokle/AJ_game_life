#include "events.h"

EventRet event_checker(sf::Event &event, sf::RenderWindow &window){
    EventRet Return;
    if (event.type == sf::Event::Closed)
        window.close();
        Return.first = 0;
    if (event.type == sf::Event::Resized)
        window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
        Return.first = 0;
    if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        Return.first = 1;
        Return.second.first = sf::Mouse::getPosition(window).x;
        Return.second.second = sf::Mouse::getPosition(window).y;
    }
    if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
        Return.first = 2;
    if(event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::C)))
        Return.first = 3;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)){
        Return.first = 4;
        Return.second.first = sf::Mouse::getPosition(window).x;
        Return.second.second = sf::Mouse::getPosition(window).y;
    }
    if(event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
        Return.first = 5;
        Return.second.first = 0;
    }
    if(event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))){
        Return.first = 5;
        Return.second.first = 1;
    }
    if(event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
        Return.first = 5;
        Return.second.first = 2;
    }if(event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
        Return.first = 6;
    return Return;
}
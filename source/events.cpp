#include "events.h"

std::pair< int, std::pair < int, int > > event_checker(sf::Event &event, sf::RenderWindow &window){
    std::pair< int, std::pair < int, int > > Return;
    if (event.type == sf::Event::Closed)
        window.close();
        Return.first = 0;
    if (event.type == sf::Event::Resized)
        window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
        Return.first = 0;
    if(event.type == sf::Event::MouseButtonPressed){
        Return.first = 1;
        Return.second.first = sf::Mouse::getPosition(window).x;
        Return.second.second = sf::Mouse::getPosition(window).y;
    }
    return Return;
}
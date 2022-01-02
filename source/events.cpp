#include "events.h"

void event_checker(sf::Event &event, sf::RenderWindow &window){
    if (event.type == sf::Event::Closed)
                window.close();
}
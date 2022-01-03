#include "events.h"
#include "cell.h"

void event_checker(sf::Event &event, sf::RenderWindow &window){
    if (event.type == sf::Event::Closed)
                window.close();
    if (event.type == sf::Event::Resized)
            window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
}
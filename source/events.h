#pragma onec
#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

std::pair < int, std::pair < int, int > > event_checker(sf::Event &event, sf::RenderWindow &window);

#endif
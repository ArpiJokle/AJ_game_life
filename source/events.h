#pragma onec
#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

typedef std::pair < int, std::pair < int, int > > EventRet;

EventRet event_checker(sf::Event &event, sf::RenderWindow &window);

#endif
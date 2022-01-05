#pragma onec
#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>

#include "events.h"
#include "cell.h"
#include "drawing.h"
#include "functions.h"

const int W_HEIGHT = 1200;
const int W_WIDTH = 1000;

bool MiddleMouseState = true;

bool AutoMode = false;
sf::Clock AutoModeTimer;
sf::Time AutoModeDelay = sf::milliseconds(300);

sf::RenderWindow window(sf::VideoMode(W_HEIGHT, W_WIDTH), "GameLife");

std::vector < std::vector < Cell > > Cells (W_HEIGHT / Cell::GetSize(), std::vector < Cell > (W_WIDTH / Cell::GetSize()));

std::vector < std::pair < int, int > > AliveCells;

std::vector < int > Survive = {2, 3};
std::vector < int > BecomeAlive = {3};

#endif
#pragma onec
#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "events.h"
#include "cell.h"
#include "drawing.h"


const int W_HEIGHT = 800;
const int W_WIDTH = 600;

sf::RenderWindow window(sf::VideoMode(W_HEIGHT, W_WIDTH), "Something");

std::vector < std::vector < Cell > > Cells (W_HEIGHT/40, std::vector < Cell > (W_WIDTH/40));

#endif
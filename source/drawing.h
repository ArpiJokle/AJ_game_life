#pragma onec
#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "cell.h"

void Draw_cells(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, const int &W_HEIGHT, const int &W_WIDTH);

void Drawing(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, const int &W_HEIGHT, const int &W_WIDTH);

#endif
#pragma onec
#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "cell.h"

void Draw_cells(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells);

void Drawing(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells);

#endif
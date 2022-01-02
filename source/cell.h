#pragma onec
#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell{
private:
    const double _size = 40;
    int x, y;
    bool Alive = false;
    sf::RectangleShape Back;
    sf::RectangleShape Body;
public:
    Cell();
    Cell(int x1, int y1);
    Cell& operator= (const Cell &Cell2);    
    void Draw(sf::RenderWindow &window);
};

#endif
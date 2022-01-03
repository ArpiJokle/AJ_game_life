#include "cell.h"

Cell::Cell(){
    x = 0;
    y = 0;
    Back.setFillColor(sf::Color(128, 128, 128));
    Back.setSize(sf::Vector2f(_size, _size));
    Back.setPosition(x * _size, y * _size);
    Body.setFillColor(sf::Color(255, 255, 255));
    Body.setSize(sf::Vector2f(_size - 4, _size - 4));
    Body.setPosition(x * _size, y * _size);
    Body.move(2, 2);
}

Cell::Cell(int x1 = 0, int y1 = 0){
    x = x1;
    y = y1;
    Back.setFillColor(sf::Color(128, 128, 128));
    Back.setSize(sf::Vector2f(_size, _size));
    Back.setPosition(x * _size, y * _size);
    Body.setFillColor(sf::Color(255, 255, 255));
    Body.setSize(sf::Vector2f(_size - 2, _size - 2));
    Body.setPosition(x * _size, y * _size);
    Body.move(1, 1);
}

Cell& Cell::operator= (const Cell &Cell2){
    x = Cell2.x;
    y = Cell2.y;
    Back = Cell2.Back;
    Body = Cell2.Body;
    return *this;
}

void Cell::Draw(sf::RenderWindow &window){
    window.draw(Back);
    window.draw(Body);
}

int Cell::GetSize(){
    return _size;
}
#include "drawing.h"

void Draw_cells(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells){
    for(int i=0; i<CountOfCells; i++)
        for(int j=0; j<CountOfCells; j++)
            Cells[i][j].Draw(window);
}

void Drawing(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells){
    window.clear();
    Draw_cells(window, Cells);
    window.display();
}
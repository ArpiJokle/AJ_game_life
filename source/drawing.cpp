#include "drawing.h"

void Draw_cells(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, const int &W_HEIGHT, const int &W_WIDTH){
    for(int i=0; i<W_HEIGHT / Cell::GetSize(); i++)
        for(int j=0; j<W_WIDTH / Cell::GetSize(); j++)
            Cells[i][j].Draw(window);
}

void Drawing(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, const int &W_HEIGHT, const int &W_WIDTH){
    window.clear();
    Draw_cells(window, Cells, W_HEIGHT, W_WIDTH);
    window.display();
}
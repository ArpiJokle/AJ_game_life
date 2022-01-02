#include "drawing.h"

void Draw_cells(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, int W_HEIGHT, int W_WIDTH){
    for(int i=0; i<W_HEIGHT/40; i++)
        for(int j=0; j<W_WIDTH/40; j++)
            Cells[i][j].Draw(window);
}

void Drawing(sf::RenderWindow &window, std::vector < std::vector < Cell > > &Cells, int W_HEIGHT, int W_WIDTH){
    window.clear();
    Draw_cells(window, Cells, W_HEIGHT, W_WIDTH);
    window.display();
}
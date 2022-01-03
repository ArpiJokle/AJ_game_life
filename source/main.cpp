#include "main.h"

void Cells_initialize(std::vector < std::vector < Cell > > &Cells){
    for(int i=0; i<CountOfCells; i++)
        for(int j=0; j<CountOfCells; j++)
            Cells[i][j] = Cell(i, j);
}

int main(){
    Cells_initialize(Cells);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
            event_checker(event, window);
        Drawing(window, Cells);
    }
    return 0;
}
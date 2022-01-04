#include "main.h"

void Cells_initialize(std::vector < std::vector < Cell > > &Cells){
    for(int i=0; i<W_HEIGHT / Cell::GetSize(); i++)
        for(int j=0; j<W_WIDTH / Cell::GetSize(); j++)
            Cells[i][j] = Cell(i, j);
}

int main(){
    Cells_initialize(Cells);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            std::pair< int, std::pair < int, int > > EventReturn = event_checker(event, window);
            if(EventReturn.first == 1)
                Cells[std::ceil(EventReturn.second.first / Cell::GetSize())][std::ceil(EventReturn.second.second / Cell::GetSize())].ChangeStatus();
        }
        Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    }
    return 0;
}
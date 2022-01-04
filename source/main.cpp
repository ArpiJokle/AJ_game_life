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
            EventRet EventReturn = event_checker(event, window);
            if(EventReturn.first == 1){
                int X = std::ceil(EventReturn.second.first / Cell::GetSize());
                int Y = std::ceil(EventReturn.second.second / Cell::GetSize());
                Cells[X][Y].ChangeStatus();
                std::pair < int, int > _cell{X, Y};
                (Cells[X][Y].IsAlive()) ? (AliveCells.push_back(_cell)) : (void(AliveCells.erase(find(AliveCells.begin(), AliveCells.end(), _cell))));
            }
        }
        Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    }
    return 0;
}
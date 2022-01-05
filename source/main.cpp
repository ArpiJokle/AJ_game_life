#include "main.h"

int main(){
    CellsInitialize(Cells, W_HEIGHT, W_WIDTH);
    Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    while(window.isOpen()){
        bool Changes = false;
        sf::Event event;
        while (window.pollEvent(event)){
            EventRet EventReturn = event_checker(event, window);
            if(EventReturn.first == 1)
                Changes = ChangeOnClick(EventReturn.second, AliveCells, Cells);
            if(EventReturn.first == 2)
                Changes = CellsChecker(Survive, BecomeAlive, AliveCells, Cells);
        }
        if(Changes)
            Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    }
    return 0;
}
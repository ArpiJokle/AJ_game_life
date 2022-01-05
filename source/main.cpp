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
            if(EventReturn.first == 3)
                Changes = CellsClear(AliveCells, Cells);
            if(EventReturn.first == 4 && MiddleMouseTimer.getElapsedTime() > MiddleMouseDelay){
                Changes = ChangeOnClick(EventReturn.second, AliveCells, Cells);
                MiddleMouseTimer.restart();
            }
            if(EventReturn.first == 5 && EventReturn.second.first == 0)
                AutoMod = !AutoMod;
            if(EventReturn.first == 5 && EventReturn.second.first == 1 && AutoModDelay > sf::milliseconds(50))
                AutoModDelay -= sf::milliseconds(50);
            if(EventReturn.first == 5 && EventReturn.second.first == 2 && AutoModDelay < sf::milliseconds(5000))
                AutoModDelay += sf::milliseconds(50);
        }
        if(AutoMod && AutoModTimer.getElapsedTime() > AutoModDelay){
            Changes = CellsChecker(Survive, BecomeAlive, AliveCells, Cells);
            AutoModTimer.restart();
            Changes = true;
        }
        if(Changes)
            Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    }
    return 0;
}
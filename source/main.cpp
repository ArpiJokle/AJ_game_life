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
            if(EventReturn.first == 4)
                (MiddleMouseState) ? (Changes = SetAlive(EventReturn.second, AliveCells, Cells)) : (Changes = SetDead(EventReturn.second, AliveCells, Cells));
            if(EventReturn.first == 5 && EventReturn.second.first == 0)
                AutoMode = !AutoMode;
            if(EventReturn.first == 5 && EventReturn.second.first == 1 && AutoModeDelay > sf::milliseconds(25))
                AutoModeDelay -= sf::milliseconds(25);
            if(EventReturn.first == 5 && EventReturn.second.first == 2 && AutoModeDelay < sf::milliseconds(2000))
                AutoModeDelay += sf::milliseconds(25);
            if(EventReturn.first == 6)
                MiddleMouseState = !MiddleMouseState;
        }
        if(AutoMode && AutoModeTimer.getElapsedTime() > AutoModeDelay){
            Changes = CellsChecker(Survive, BecomeAlive, AliveCells, Cells);
            AutoModeTimer.restart();
            Changes = true;
        }
        if(Changes)
            Drawing(window, Cells, W_HEIGHT, W_WIDTH);
    }
    return 0;
}
#include "functions.h"

void CellsInitialize(std::vector < std::vector < Cell > > &Cells, int W_HEIGHT, int W_WIDTH){
    for(int i=0; i<W_HEIGHT / Cell::GetSize(); i++)
        for(int j=0; j<W_WIDTH / Cell::GetSize(); j++)
            Cells[i][j] = Cell(i, j);
}

int NumberOfNeighbors(std::pair < int, int > _cell, const std::vector < std::pair < int, int > > &AliveCells){
    int Number = 0;
    _cell.first -= 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.second -= 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.second += 2;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.first += 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.second -= 2;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.first += 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.second += 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    _cell.second += 1;
    if(find(AliveCells.begin(), AliveCells.end(), _cell) != AliveCells.end())
        Number++;
    return Number;
}

bool ChangeOnClick(std::pair < int, int > Coords, std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells){
    int X = std::ceil(Coords.first / Cell::GetSize());
    int Y = std::ceil(Coords.second / Cell::GetSize());
    if(X < 0) X = 0;
    if(X > Cells.size() - 1) X = Cells.size() - 1;
    if(Y < 0) Y = 0;
    if(Y > Cells[0].size() - 1) Y = Cells[0].size() - 1;
    Cells[X][Y].ChangeStatus();
    std::pair < int, int > _cell{X, Y};
    (Cells[X][Y].IsAlive()) ? (AliveCells.push_back(_cell)) : (void(AliveCells.erase(find(AliveCells.begin(), AliveCells.end(), _cell))));
    return true;
}

void IsChange(std::vector < int > &Survive, std::vector < int > &BecomeAlive,
                std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells,
                std::pair < int, int > Coords,
                std::vector < std::pair < int, int > > &CellsToChange){
    if(Coords.first < 0 || Coords.second < 0 || Coords.first > Cells.size() - 1 || Coords.second > Cells[0].size() - 1)
        return;
    if(Cells[Coords.first][Coords.second].IsAlive() && (std::find(Survive.begin(), Survive.end(),NumberOfNeighbors(Coords, AliveCells)) == Survive.end()))
        if(find(CellsToChange.begin(), CellsToChange.end(), Coords) == CellsToChange.end())
            CellsToChange.push_back(Coords);
    if(!Cells[Coords.first][Coords.second].IsAlive() && (std::find(BecomeAlive.begin(), BecomeAlive.end(), NumberOfNeighbors(Coords, AliveCells)) != BecomeAlive.end()))
        if(find(CellsToChange.begin(), CellsToChange.end(), Coords) == CellsToChange.end())
            CellsToChange.push_back(Coords);
}

bool CellsChecker(std::vector < int > &Survive, std::vector < int > &BecomeAlive,
                std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells){
    std::vector < std::pair < int, int > > CellsToChange;
    for(auto i : AliveCells){
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.first -= 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.second -= 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.second += 2;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.first += 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.second -= 2;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.first += 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.second += 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
        i.second += 1;
        IsChange(Survive, BecomeAlive, AliveCells, Cells, i, CellsToChange);
    }
    for(auto i : CellsToChange){
        Cells[i.first][i.second].ChangeStatus();
        if(!Cells[i.first][i.second].IsAlive())
            AliveCells.erase(find(AliveCells.begin(), AliveCells.end(), i));
        else
            AliveCells.push_back(i);
    }
    return true;
}

bool CellsClear(std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells){
    while(AliveCells.size() != 0){
        Cells[AliveCells[0].first][AliveCells[0].second].ChangeStatus();
        AliveCells.erase(AliveCells.begin());
    }
    return true;
}

bool SetCurrentMode(std::pair < int, int > Coords, std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells, bool Mode){
    int X = std::ceil(Coords.first / Cell::GetSize());
    int Y = std::ceil(Coords.second / Cell::GetSize());
    if(X < 0) X = 0;
    if(X > Cells.size() - 1) X = Cells.size() - 1;
    if(Y < 0) Y = 0;
    if(Y > Cells[0].size() - 1) Y = Cells[0].size() - 1;
    if(Cells[X][Y].IsAlive() == Mode){
        Cells[X][Y].ChangeStatus();
        std::pair < int, int > _cell{X, Y};
        AliveCells.push_back(_cell);
        return true;
    }
    return false;
}

bool SetRandom(std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells){
    srand(time(0));
    int MaxCellsNumber = Cells.size() * Cells[0].size();
    int Iretations = (MaxCellsNumber*0.25) + std::rand() % int(MaxCellsNumber*0.75);
    for(int i=0; i<Iretations; i++){
        int X = rand() % Cells.size();
        int Y = rand() % Cells[0].size();
        if(!Cells[X][Y].IsAlive()){
            Cells[X][Y].ChangeStatus();
            AliveCells.push_back({X, Y});
        }
    }
    return true;
}
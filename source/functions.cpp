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
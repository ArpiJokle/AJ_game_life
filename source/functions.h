#pragma onec
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <ctime>

#include "cell.h"

void CellsInitialize(std::vector < std::vector < Cell > > &Cells, int W_HEIGHT, int W_WIDTH);

int NumberOfNeighbors(std::pair < int, int > _cell, const std::vector < std::pair < int, int > > &AliveCells);

bool ChangeOnClick(std::pair < int, int > Coords, std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells);

void IsChange(std::vector < int > &Survive, std::vector < int > &BecomeAlive,
                std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells,
                std::pair < int, int > Coords,
                std::vector < std::pair < int, int > > &CellsToChange);

bool CellsChecker(std::vector < int > &Survive, std::vector < int > &BecomeAlive,
                std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells);

bool CellsClear(std::vector < std::pair < int, int > > &AliveCells,
                std::vector < std::vector < Cell > > &Cells);

bool SetCurrentMode(std::pair < int, int > Coords, std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells, bool Mode);

bool SetDead(std::pair < int, int > Coords, std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells);

bool SetRandom(std::vector < std::pair < int, int > > &AliveCells, std::vector < std::vector < Cell > > &Cells);

#endif
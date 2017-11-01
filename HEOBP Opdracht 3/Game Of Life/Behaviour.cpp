
#include "Behaviour.h"
#include <vector>
#include <iostream>

using namespace std;

void StandardBehaviour::updateCells(Cell *cell, vector<vector<Cell> > cellGrid)
{
	CellCalculator calc = CellCalculator();
	calc.calculateCells(cell, cellGrid);

	if (cell->getLivingNeigbours() > 3)
	{
		cell->setAliveNextFrame(false);
	}
	else if (cell->getLivingNeigbours() <= 0)
	{
		cell->setAliveNextFrame(false);
	}
	else
	{
		cell->setAliveNextFrame(true);
	}
}

void MobBehaviour::updateCells(Cell *cell, vector<vector<Cell> > cellGrid)
{
	CellCalculator calc = CellCalculator();
	calc.calculateCells(cell, cellGrid);

	
	if (cell->getLivingNeigbours() > 5)
	{
		cell->setAliveNextFrame(false);
	}
	else if (cell->getLivingNeigbours() > 1)
	{
		cell->setAliveNextFrame(true);
		
	}
	else
	{
		cell->setAliveNextFrame(false);
	}
}

void LonerBehaviour::updateCells(Cell *cell, vector<vector<Cell> > cellGrid)
{
	CellCalculator calc = CellCalculator();
	calc.calculateCells(cell, cellGrid);


	if (cell->getLivingNeigbours() > 2)
	{
		cell->setAliveNextFrame(false);
	}
	else if (cell->getLivingNeigbours() >=1)
	{
		cell->setAliveNextFrame(true);
	}

}

CellCalculator::CellCalculator() {};

void CellCalculator::calculateCells(Cell *cell, vector<vector<Cell> > cellGrid)
{
	cell->resetLivingNeigbours();
	for (int y = cell->getY() - 1; y <= cell->getY() +1 ; y++)
	{
		if (y >= 0 && y <= cellGrid.size() - 1)
		{
			for (int x = cell->getX() - 1; x <= cell->getX() + 1; x++)
			{
				if (x >= 0 && x <= cellGrid[y].size() - 1)
				{
					if (cellGrid[y][x].isAlive() && !(y == cell->getY() && x == cell->getX()))
					{
						cell->addLivingNeigbour();
					}
				}
			}
		}
	}
}

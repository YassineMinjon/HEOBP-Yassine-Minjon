#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Grid::Grid(int x, int y, Behaviour* b)
{
	this->x = x;
	this->y = y;
	this->updateBehaviour = b;

	for (int i = 0; i < y; i++)
	{
		vector<Cell> vec;

		for (int f = 0; f < x; f++)
		{
			 Cell cell = Cell(f, i, false);
			 vec.push_back(cell);
		}

		cellGrid.push_back(vec);
	}


	cellGrid[y / 2][x / 2].setAlive(true);
	cellGrid[(y / 2)-1][x / 2].setAlive(true);
	cellGrid[y / 2][(x / 2)-1].setAlive(true);
	cellGrid[(y / 2)-1][(x / 2)-1].setAlive(true);

}

void Grid::setUpdateBehaviour(Behaviour* b)
{
	this->updateBehaviour = b;
}

void Grid::updateGrid()
{
	for (int i = 0; i < cellGrid.size(); i++)
	{
		for (int j = 0; j < cellGrid[i].size(); j++)
		{
			updateBehaviour->updateCells(&cellGrid[i][j], cellGrid);
		}
	}

	for (int y = 0; y < cellGrid.size(); y++)
	{
		for (int x = 0; x < cellGrid[y].size(); x++)
		{
			cellGrid[y][x].setAlive(cellGrid[y][x].getAliveNextFrame());
		}
	}

}


void Grid::displayGrid()
{
	system("cls");
	for (int i = 0; i < cellGrid.size(); i++)
	{
		for (int j = 0; j < cellGrid[i].size(); j++)
		{
			if (cellGrid[i][j].isAlive())
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << "X";
			}
			else if(cellGrid[i][j].getAliveNextFrame())
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				cout << "O";
			}
			else
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << "O";
			}
		}
		cout << "\n";
	}
	cout << endl;
}
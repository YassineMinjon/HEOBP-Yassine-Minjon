// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Behaviour.h"
#include "Cell.h"
#include "Grid.h"
#include <Windows.h>


int main()
{
	Grid grid = Grid(30, 30, new StandardBehaviour);

	while (true)
	{
		grid.updateGrid();
		grid.displayGrid();
		Sleep(250);
	}
    return 0;
}



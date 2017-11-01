#pragma once
#include <vector>
#include "Cell.h"
#include "Behaviour.h"

using namespace std;

class Grid
{
	public:
		Grid(int x, int y, Behaviour* b);	
		void setUpdateBehaviour(Behaviour* b);
		void updateGrid();
		void displayGrid();

	private:
		int x;
		int y;
		vector<vector<Cell> > cellGrid;
		Behaviour* updateBehaviour;

};

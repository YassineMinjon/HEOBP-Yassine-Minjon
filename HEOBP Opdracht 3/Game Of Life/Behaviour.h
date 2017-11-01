#pragma once
#include <vector>
#include "Cell.h"
using namespace std;

class Behaviour 
{
	public:
		virtual void updateCells(Cell *cell, vector<vector<Cell> > cellGrid) = 0;
};

class StandardBehaviour : public Behaviour
{
	public:
		virtual void updateCells(Cell *cell, vector<vector<Cell> > cellGrid);
};

class MobBehaviour : public Behaviour
{
	public:
		virtual void updateCells(Cell *cell, vector<vector<Cell> > cellGrid);
};

class LonerBehaviour : public Behaviour
{
	public:
		virtual void updateCells(Cell *cell, vector<vector<Cell> > cellGrid);
};

class CellCalculator
{
	public:
		CellCalculator();
		void calculateCells(Cell *cell, vector<vector<Cell> > cellGrid);
};
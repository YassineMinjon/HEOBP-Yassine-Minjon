#pragma once
#include <vector>

class Cell 
{
	public:
		Cell(int x, int y, bool isAlive);
		void setAlive(bool alive);
		void setAliveNextFrame(bool canLive);
		bool getAliveNextFrame();
		bool isAlive();
		void addLivingNeigbour();
		int getLivingNeigbours();
		void resetLivingNeigbours();
		int getX();
		int getY();

	private:
		bool alive = false;
		bool aliveNextFrame = false;
		int livingNeigbours;
		int x;
		int y;
};
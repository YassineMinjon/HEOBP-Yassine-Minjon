#include "Cell.h"

#include <iostream>


Cell::Cell(int x, int y, bool isAlive)
{
	this->x = x;
	this->y = y;
	this->alive = isAlive;
	this->aliveNextFrame = false;
	this->livingNeigbours = 0;
}

void Cell::setAlive(bool alive)
{
	this->alive = alive;
}

void Cell::setAliveNextFrame(bool canLive)
{
	this->aliveNextFrame = canLive;
}

bool Cell::getAliveNextFrame()
{
	return aliveNextFrame;
}

bool Cell::isAlive()
{
	return alive;
}

void Cell::addLivingNeigbour()
{
	this->livingNeigbours++;
}

int Cell::getLivingNeigbours()
{
	return livingNeigbours;
}

void Cell::resetLivingNeigbours()
{
	this->livingNeigbours = 0;
}

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}
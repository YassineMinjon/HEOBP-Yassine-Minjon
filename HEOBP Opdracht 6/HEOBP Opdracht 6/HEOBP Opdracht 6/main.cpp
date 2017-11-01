#include <iostream>
#include <thread>
#include "concurrent_vector.h"
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
int c = 0;
bool done = false;
queue<int> goods;
condition_variable flag;


void consumer() 
{
	unique_lock<mutex> lock(mtx);
	while (!done) flag.wait(lock);
	{
		while (!goods.empty())
		{
			goods.pop();
			c--;
		}
	}
	lock.unlock();
}

void producer()
{
	unique_lock<mutex> lock(mtx);
	for (int i = 0; i < 500; ++i)
	{
		goods.push(i);
		c++;
	}

	done = true;
	lock.unlock();
	flag.notify_one();
}


template<class T>
void AddToVector(int i, T& vec)
{
	vec.push_back(i);
}


int main()
{
	concurrent_vector<int> thisvector;
	thisvector.mass_push_back();


	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();
	std::cout << "Net: " << c << std::endl;
	return 0;
}





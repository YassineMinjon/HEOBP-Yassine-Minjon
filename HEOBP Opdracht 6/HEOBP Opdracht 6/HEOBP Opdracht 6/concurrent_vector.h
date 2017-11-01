#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

template <typename Q>
class concurrent_vector
{

	public:
		concurrent_vector() {};

		void push_back(Q value)
		{
			mtx.lock();
			vector.push_back(value);
			cout << value << endl;
			mtx.unlock();
		};

		void mass_push_back()
		{
			for (int i = 0; i < 100; i++)
			{
				thread first(&concurrent_vector::push_back,this, i);
				thread second(&concurrent_vector::push_back,this, i*100);

				first.join();
				second.join();
			}
		};

	private:
		mutex mtx;
		vector<Q> vector;
};



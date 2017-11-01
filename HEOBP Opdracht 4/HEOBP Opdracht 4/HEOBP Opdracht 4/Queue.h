#pragma once
#include <vector>

template <class Q>
class Queue
{

	private:
		std::vector<Q> queue;

	public:
		Queue(){};

		void put(Q val)
		{
			queue.push_back(val);
		};

		Q get()
		{
			Q temp = queue[0];
			queue.erase(queue.begin());
			std::cout << "get returned: " << temp << " and erased it from the queue"<< std::endl;
			return temp;
		};

		int size()
		{
			std::cout << "get returned: " << queue.size()<< std::endl;
			return queue.size();
		};
};
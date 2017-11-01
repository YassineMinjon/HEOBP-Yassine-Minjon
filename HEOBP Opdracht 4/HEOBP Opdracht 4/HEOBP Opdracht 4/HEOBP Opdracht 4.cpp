// HEOBP Opdracht 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include <string>

using namespace std;
enum npcTypes
{
	_Farmer = 0,
	_Soldier = 1,
	_Shaman = 2
};

#pragma region

class AbstractNPC
{
	public:
		virtual void render() = 0;
};

class NPC : public AbstractNPC
{
	private:
		string name;
	public:
		NPC(string basename)
		{ 
			name.assign(basename);
		}

		void render()
		{
			cout << name; 
		}
};

class NPCDecorator : public AbstractNPC
{
	private:
		AbstractNPC * npc;
	public:
		NPCDecorator(AbstractNPC *n)
		{
			npc = n;
		}
		void render() 
		{ 
			npc->render(); 
		}
};

class Farmer : public NPCDecorator
{
	public:
		Farmer(AbstractNPC * n):NPCDecorator(n){}
		void render()
		{
			NPCDecorator::render();
			cout << " Farmer   Rol: useless";
		}
};

class Soldier : public NPCDecorator
{
public:
	Soldier(AbstractNPC * n) :NPCDecorator(n) {}
	void render()
	{
		NPCDecorator::render();
		cout << " Soldier   Rol: tank";
	}
};

class Shaman : public NPCDecorator
{
public:
	Shaman(AbstractNPC * n) :NPCDecorator(n) {}
	void render()
	{
		NPCDecorator::render();
		cout << " Shaman   Rol: healer";
	}
};
#pragma endregion

#pragma region
class NPCFactory
{
	public:
		static AbstractNPC* CreateNPC(string Race, int Type)
		{
			AbstractNPC *npc;
			switch (Type)
			{
			case(_Farmer):
				npc = new Farmer(new NPC(Race));
				break;

			case(_Soldier):
				npc = new Soldier(new NPC(Race));
				break;

			case(_Shaman):
				npc = new Shaman(new NPC(Race));
				break;
			}
			return npc;
		}
};
#pragma endregion

template <class T>
void sortContainer(T &t)
{
	bool swaped = true;
	int length = (sizeof(t) / sizeof(t[0]));

	while (swaped)
	{
		swaped = false;
		for (int i = 0; i < length; i++)
		{
			if (i < length - 1 && t[i]>t[i+1])
			{
				auto S = t[i + 1];
				t[i + 1] = t[i];
				t[i] = S;
				swaped = true;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		cout << t[i] << endl;
	}
}


int main()
{
	int a[7] = {2,4,1,3,5,7,6};
	sortContainer(a);
	cout << endl;
	float o[7] = {1.2,1.4,1.1,1.3,1.5,1.7,1.6};
	sortContainer(o);
	cout << endl;
	string u[6] = { "abc", "ab", "abcde", "abcd", "a", "abcdef"};
	sortContainer(u);
	cout << endl;


	Queue<int> queue = Queue<int>(); 
    queue.put(8);
	queue.put(4);
	queue.put(6);
	queue.put(0);
	queue.get();
	queue.size();
	cout << endl;

	//Orginele opdracht
	/*
	AbstractNPC *orc1 = new Farmer(new NPC("Orc"));
	AbstractNPC *orc2 = new Soldier(new NPC("Orc"));
	AbstractNPC *orc3 = new Shaman(new NPC("Orc"));

	AbstractNPC *elve1 = new Farmer(new NPC("Elve"));
	AbstractNPC *elve2 = new Soldier(new NPC("Elve"));
	AbstractNPC *elve3 = new Shaman(new NPC("Elve"));
	*/

	//opdracht 7
	AbstractNPC *orc1 = NPCFactory::CreateNPC("Orc", _Farmer);
	AbstractNPC *orc2 = NPCFactory::CreateNPC("Orc", _Soldier);
	AbstractNPC *orc3 = NPCFactory::CreateNPC("Orc", _Shaman);

	AbstractNPC *elve1 = NPCFactory::CreateNPC("Elve", _Farmer);
	AbstractNPC *elve2 = NPCFactory::CreateNPC("Elve", _Soldier);
	AbstractNPC *elve3 = NPCFactory::CreateNPC("Elve", _Shaman);
	


	orc1->render(); cout << endl;
	orc2->render(); cout << endl;
	orc3->render(); cout << endl;

	elve1->render(); cout << endl;
	elve2->render(); cout << endl;
	elve3->render(); cout << endl;


    return 0;
}


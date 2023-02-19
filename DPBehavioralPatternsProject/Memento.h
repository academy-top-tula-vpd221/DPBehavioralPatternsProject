#pragma once
#include <iostream>
#include <stack>

using namespace std;

//Memento
class PlayerMemento
{
	int points;
	int level;
public:
	int& Points() { return points; }
	int& Level() { return level; }

	PlayerMemento(int points, int level)
		: points{ points }, level{ level } {}
};

// Originator
class Player
{
	int points;
	int level;
public:
	Player() : points{}, level{ 1 } {}

	void Play()
	{
		srand(time(nullptr));
		int p = -3 + rand() % 7;
		if (points + p > 0)
			points += p;

		int l = rand() % 2;
		level += l;

		cout << "current player state: points[" << points << "], level [" << level << "]\n";
	}

	PlayerMemento* Save()
	{
		cout << "save player state: points[" << points << "], level [" << level << "]\n";
		return new PlayerMemento(points, level);
	}

	void Load(PlayerMemento* memento)
	{
		points = memento->Points();
		level = memento->Level();
		cout << "load player state: points[" << points << "], level [" << level << "]\n";
	}
};

// Caretaker
class GameHistory
{
	stack<PlayerMemento*> history;
public:
	stack<PlayerMemento*>& History() { return history; }
	void Save(PlayerMemento* memento)
	{
		history.push(memento);
	}
	PlayerMemento* Load()
	{
		PlayerMemento* memento = history.top();
		history.pop();
		return memento;
	}
};


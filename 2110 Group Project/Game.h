#pragma once
#include<iostream>
#include "Hero.h"
#include "Room.h"

using namespace std;

class Game
{
private:
	Room* currentRoom;
	Hero HeroName = Hero(10, 10, 10, 1); // hp, ap, dp, retreats available
	void creatMap();             // map must have at least 7 rooms, 2 monsters, 3 items

public:
	void run();
	Game();

	void displayMap();

	void startItemPromt();


};
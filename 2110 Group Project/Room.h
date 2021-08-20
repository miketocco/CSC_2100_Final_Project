#pragma once
#include <string>
#include "Monster.h"
#include "Item.h"
using namespace std;

class Room
{
private:
	string name;
	Room* east,* west,* north,* south;
	Monster* roomMonster;
	Item* roomItem;
	bool exit = false;
public:
	void setName(string name);
	string getName() const;
	void setEastRoom(Room* room);
	void setWestRoom(Room* room);
	void setNorthRoom(Room* room);
	void setSouthRoom(Room* room);
	Room* getEastRoom() const;
	Room* getWestRoom() const;
	Room* getNorthRoom() const;
	Room* getSouthRoom() const;
	void setRoomMonster(Monster* monster);
	Monster* getRoomMonster() const;
	void setRoomItem(Item* item);
	Item* getRoomItem() const;
	bool isExit();
	Room(string name, Room* east, Room* west, Room* north, Room* south, Monster* monster, Item* item);
	Room(string name, Room* east, Room* west, Room* north, Room* south, Monster* monster);
	Room(string name, Room* east, Room* west, Room* north, Room* south, Item* item);
	Room(string name, Room* east, Room* west, Room* north, Room* south, bool isExitRoom);
};
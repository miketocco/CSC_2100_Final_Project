#include "Room.h"
#include <iostream>

void Room::setName(string name)
{
	this->name = name;
}

string Room::getName() const
{
	return name;
}

void Room::setEastRoom(Room* room)
{
	if (east == nullptr)
	{
		east = room;
		room->west = this;
	}
	else
	{
		//Give an error
		cout << "Room has already been set" << endl;
	}
}

void Room::setWestRoom(Room* room)
{
	if (west == nullptr)
	{
		west = room;
		room->east = this;
	}
	else
	{
		//Give an error
		cout << "Room has already been set" << endl;
	}
}

void Room::setNorthRoom(Room* room)
{
	if (north == nullptr)
	{
		north = room;
		room->south = this;
	}
	else
	{
		//Give an error
		cout << "Room has already been set" << endl;
	}
}

void Room::setSouthRoom(Room* room)
{
	if (south == nullptr)
	{
		south = room;
		room->north = this;
	}
	else
	{
		//Give an error
		cout << "Room has already been set" << endl;
	}
}

Room* Room::getEastRoom() const
{
	return east;
}

Room* Room::getWestRoom() const
{
	return west;
}

Room* Room::getNorthRoom() const
{
	return north;
}

Room* Room::getSouthRoom() const
{
	return south;
}

void Room::setRoomMonster(Monster* monster)
{
	roomMonster = monster;
}

Monster* Room::getRoomMonster() const
{
	return roomMonster;
}

void Room::setRoomItem(Item* item)
{
	roomItem = item;
}

Item* Room::getRoomItem() const
{
	return roomItem;
}

bool Room::isExit()
{
	return exit;
}

Room::Room(string name, Room* east, Room* west, Room* north, Room* south, Monster* monster, Item* item)
{
	this->name = name;
	this->east = east;
	this->west = west;
	this->north = north;
	this->south = south;
	roomMonster = monster;
	roomItem = item;
}

Room::Room(string name, Room* east, Room* west, Room* north, Room* south, Monster* monster)
{
	this->name = name;
	this->east = east;
	this->west = west;
	this->north = north;
	this->south = south;
	roomMonster = monster;
}

Room::Room(string name, Room* east, Room* west, Room* north, Room* south, Item* item)
{
	this->name = name;
	this->east = east;
	this->west = west;
	this->north = north;
	this->south = south;
	roomItem = item;
	roomMonster = nullptr;
}

Room::Room(string name, Room* east, Room* west, Room* north, Room* south, bool isExitRoom)
{
	this->name = name;
	this->east = east;
	this->west = west;
	this->north = north;
	this->south = south;
	exit = isExitRoom;
}

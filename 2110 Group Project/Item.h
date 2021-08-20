#pragma once
using namespace std;

class Item
{
private:
	int type; //0-hp, 1-defense
	int value;
public:
	bool isHP() const;
	bool isDefense() const;
	int getValue() const;
	Item(int typeParam, int valueParam);
};
#pragma once
#include "Character.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

class Hero : public Character
{
private:
	int defensePower; //can't be < 1
	int retreatCount; // can't be < 0
public:
	Item* bag[3];

	int getDefensePower() const;
	void decreaseDefensePower();
	void setDefensePower(int DP);
	int getRetreatCount() const;
	void decreaseRetreatCount();
	bool anyItems() const;
	bool isAlive() const;

	int operator*(Monster& m);

	Hero(int HP, int AP, int DP, int RetreatCount); // parameterized constructor

	// function overrides
	void setHP(int HP);
	int getHP() const;
	void setAttackPower(int AP);
	int getAttackPower() const;
};
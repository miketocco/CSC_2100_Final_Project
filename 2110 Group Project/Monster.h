#pragma once
#include "Character.h"
using namespace std;

class Monster : public Character
{
public:
	void decreaseAttackPower();

	Monster(int HP, int AP); // parameterized constructor


	// method overrides
	void setHP(int HP); 
	int getHP() const;
	void setAttackPower(int AP);
	int getAttackPower() const;


};
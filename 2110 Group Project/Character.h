#pragma once
using namespace std;


class Character
{
protected:
	int hp;           // hp cannot be less than zero (for your character only)
	int attackPower;

public:
	void virtual setHP(int HP) = 0;
	int virtual getHP() const = 0;
	void virtual setAttackPower(int AP) = 0;
	int virtual getAttackPower() const = 0;
};
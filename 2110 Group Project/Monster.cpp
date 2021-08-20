	#include "Monster.h"

void Monster::setHP(int HP)
{
	if (HP < 0)
		hp = 0;
	else
		hp = HP;
}

int Monster::getHP() const
{
	return hp;
}

void Monster::setAttackPower(int AP)
{
	attackPower = AP;
}

int Monster::getAttackPower() const
{
	return attackPower;
}

void Monster::decreaseAttackPower()
{
	if (attackPower != 0)
		attackPower--;
}

Monster::Monster(int HP, int AP)
{
	if (HP > 1)
		hp = HP;
	else
		hp = 1;

	if (AP > 1)
		attackPower = AP;           // cannot be < 1
	else
		attackPower = 1;
}

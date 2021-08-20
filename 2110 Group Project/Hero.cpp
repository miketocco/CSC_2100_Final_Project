#include "Hero.h"

void Hero::setHP(int HP)
{
    if (HP < 0)
        hp = 0;
    else
        hp = HP;
}

int Hero::getHP() const
{
    return hp;
}

void Hero::setAttackPower(int AP)
{
    attackPower = AP;
}

int Hero::getAttackPower() const
{
    return attackPower;
}

int Hero::getDefensePower() const
{
    return defensePower;
}

void Hero::decreaseDefensePower()
{
    if (defensePower > 1)
    defensePower--;
}

void Hero::setDefensePower(int DP)
{
    if (defensePower >= 1)
        defensePower = DP;
}

int Hero::getRetreatCount() const
{
    return retreatCount;
}

void Hero::decreaseRetreatCount()
{
    if (retreatCount != 0)
        retreatCount--;
    else
        return;
    
}

bool Hero::anyItems() const
{
    if (bag[0] == nullptr || bag[1] == nullptr || bag[2] == nullptr)
        return false;
    else
        return true;
}

bool Hero::isAlive() const
{
    if (hp > 0)
        return true;
    else
        return false;
}

int Hero::operator*(Monster& monster)
{
    monster.setHP(monster.getHP() - attackPower);

    setHP(hp - (monster.getAttackPower() / defensePower));

    monster.decreaseAttackPower();

    decreaseDefensePower();

    if (hp == 0) // hero is dead
        return -1;
    else if (monster.getHP() == 0) // monster is dead
        return 1;
    else // no character died
        return 0;
}

Hero::Hero(int HP, int AP, int DP, int RetreatCount) 
{
    for (int i = 0; i < 3; i++)
    {
        bag[i] = nullptr;
    }

    if (HP > 0)
        hp = HP;
    else
        hp = 1;

    if (AP > 0)
        attackPower = AP;
    else
        attackPower = 1;

    if (DP > 0)
        defensePower = DP;
    else
        defensePower = 1;

    if (RetreatCount >= 0)
        retreatCount = RetreatCount;
    else
        retreatCount = 0;
}

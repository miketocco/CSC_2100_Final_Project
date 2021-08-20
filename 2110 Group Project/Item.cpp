#include "Item.h"

bool Item::isHP() const
{
    return type == 0;
}

bool Item::isDefense() const
{
    return type == 1;
}

int Item::getValue() const
{
    return value;
}

Item::Item(int typeParam, int  valueParam)
{
    type = typeParam;                  // When a 0-type item is used, the hero’s hp is increased by the item’s value.
    value = valueParam;                   // When a 1-type item is used, the hero’s defense is increased by the item’s value.
}


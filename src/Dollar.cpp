#include "Dollar.h"

Dollar::Dollar(const int amount) : Money()
{
    this->amount = amount;
}

Dollar Dollar::Times(const int multiplier) const
{
    return Dollar(amount * multiplier);
}

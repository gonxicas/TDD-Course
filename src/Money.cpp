#include "Money.h"

bool Money::operator==(const Money& money) const
{
    return amount == money.amount;
}

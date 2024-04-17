#include "Money.h"
#include <typeinfo>
bool Money::operator==(const Money& money) const
{
    return amount == money.amount && typeid(*this).name() == typeid(money).name();
}

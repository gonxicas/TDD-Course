#include "Euro.h"

Euro::Euro(const int amount) : Money()
{
    this->amount = amount;
}

Euro Euro::Times(const int multiplier) const
{
    return Euro(amount * multiplier);
}
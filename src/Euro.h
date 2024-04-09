#ifndef EURO_H
#define EURO_H
#include "Money.h"


class Euro : public Money
{
public:
    explicit Euro(int amount);


    [[nodiscard]] Euro Times(int multiplier) const;
};



#endif

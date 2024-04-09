#ifndef DOLLAR_H
#define DOLLAR_H
#include "Money.h"


class Dollar : public Money
{
public:
    explicit Dollar(int amount);
    
    [[nodiscard]] Dollar Times(int multiplier) const;
};



#endif

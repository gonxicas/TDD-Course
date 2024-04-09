#ifndef MONEY_H
#define MONEY_H


class Money
{
public:
    bool operator==(const Money& money) const;
protected:
    int amount;
};


#endif

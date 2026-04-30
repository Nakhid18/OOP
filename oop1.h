#ifndef MONEY_H
#define MONEY_H

struct Money
{
    int grn;
    short int cop;
};

void addMoney(Money& money, Money& addMoney),
multiplyMoney(Money& money, int count),
roundMoney(Money& money),
printMoney(Money& money),
calcGeneralPrice(const char* path);

#endif

#ifndef LAB1_H
#define LAB1_H

struct money {
    int grn;
    short int kop;
};

void normalize(money *m);
void sum(money *a, money b);
void multi(money *m, int n);
void roundMoney(money *m);
void parseLines(const char *file_name);

#endif
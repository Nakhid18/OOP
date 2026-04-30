#pragma once

struct money {
  int grn;
  short int kop;
};

void sum(money *a, money b);
void multi(money *m, int n);

void round(money *m);
void parseLines(char *file_name);

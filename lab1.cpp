#include "lab1.h"
#include <cstdio>
#include <iostream>

using namespace std;

void sum(money *a, money b) {
  int total_kop = (a->grn + b.grn) * 100 + a->kop + b.kop;
  a->grn = total_kop / 100;
  a->kop = total_kop % 100;
}

void multi(money *m, int n) {

  if (n < 0) {
    return;
  }

  int total_kop = (m->grn * 100 + m->kop) * n;
  m->grn = total_kop / 100;
  m->kop = total_kop % 100;
}

void round(money *m) {

  int mod = m->kop % 10;

  if (mod >= 5) {

    m->kop += (10 - mod);

    if (m->kop >= 100) {

      m->grn += 1;
      m->kop -= 100;
    }

  } else {
    m->kop -= mod;
  }
}

void parseLines(char *file_name) {
  FILE *f = fopen(file_name, "r");
  if (!f) {
    cout << "Error: Could not open file" << endl;
    return;
  }

  char itemName[256];
  int g, k, q;
  money totalAmount = {0, 0};

  while (fscanf(f, "%255s %d %d %d", itemName, &g, &k, &q) == 4) {
    if (g < 0 || k < 0 || q < 0)
      continue;

    money itemPrice = {g, (short int)k};
    multi(&itemPrice, q);
    sum(&totalAmount, itemPrice);
  }

  fclose(f);

  round(&totalAmount);
  cout << "Full receipt amount: { grn: " << totalAmount.grn
       << ", kop: " << totalAmount.kop << " }" << endl;
}

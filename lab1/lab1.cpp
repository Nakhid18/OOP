#include "lab1.h"
#include <cstdio>
#include <iostream>

using namespace std;

void normalize(money *m) {
    m->grn += m->kop / 100;
    m->kop = m->kop % 100;
}

void sum(money *a, money b) {
    int total_kop = (a->grn * 100 + a->kop) + (b.grn * 100 + b.kop);
    a->grn = total_kop / 100;
    a->kop = total_kop % 100;
}

void multi(money *m, int n) {
    int total_kop = (m->grn * 100 + m->kop) * n;
    m->grn = total_kop / 100;
    m->kop = total_kop % 100;
}

void roundMoney(money *m) {
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

void parseLines(const char *file_name) {
    FILE *f = fopen(file_name, "r");

    if (f == NULL) {
        cout << "Could not open file" << endl;
        return;
    }

    char buffer[256];
    int grn;
    short int kop;
    int quantity;
    char item[256];

    money total_money = {0, 0};

    while (fgets(buffer, sizeof(buffer), f)) {
        quantity = 1;

        int parseItemsCount =
            sscanf(buffer, "%255s %d %hd %d", item, &grn, &kop, &quantity);

        if (parseItemsCount >= 3) {

            if (quantity < 0 || grn < 0 || kop < 0) {
                cout << "Incorrect format of input" << endl;
                fclose(f);
                return;
            }

            money m = {grn, kop};

            // нормалізація після створення
            normalize(&m);

            if (quantity > 1) {
                multi(&m, quantity);
            }

            cout << item << " "
                 << m.grn << " grn, "
                 << m.kop << " kop, "
                 << quantity << "x" << endl;

            sum(&total_money, m);
        }
    }

    fclose(f);

    cout << endl
         << "Sum without rounding: { grn: "
         << total_money.grn
         << ", kop: "
         << total_money.kop
         << " }" << endl;

    roundMoney(&total_money);

    cout << endl
         << "Full receipt amount: { grn: "
         << total_money.grn
         << ", kop: "
         << total_money.kop
         << " }" << endl;
}
#include "lab1.h"
#include <cstdio>
#include <iostream>

using namespace std;

void normalize(money *m) {
    if (m->kop >= 100) {
        m->grn += m->kop / 100;
        m->kop %= 100;
    }
}

void sum(money *a, money b) {
    a->grn += b.grn;
    a->kop += b.kop;
    normalize(a);
}

void multi(money *m, int n) {
    m->grn *= n;
    m->kop *= n;
    normalize(m);
}

void roundMoney(money *m) {
    int mod = m->kop % 10;

    if (mod >= 5) {
        m->kop += (10 - mod);
    } else {
        m->kop -= mod;
    }

    normalize(m);
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

        int parsed =
            sscanf(buffer, "%255s %d %hd %d", item, &grn, &kop, &quantity);

        if (parsed >= 3) {

            if (quantity < 0 || grn < 0 || kop < 0) {
                cout << "Incorrect format of input" << endl;
                fclose(f);
                return;
            }

            money m = {grn, kop};
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

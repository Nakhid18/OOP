#include "lab1.h"
#include <cstdio>
#include <iostream>

using namespace std;

void normalize(money *m) {
    if (m->kop >= 100) {
        m->grn += m->kop / 100;
        m->kop %= 100;
    }

    if (m->kop < 0) {
        int borrow = (-m->kop + 99) / 100;
        m->grn -= borrow;
        m->kop += borrow * 100;
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

    money total_money = {0, 0};

    while (fgets(buffer, sizeof(buffer), f)) {

        int parsed = sscanf(buffer, "%d %hd %d", &grn, &kop, &quantity);

        if (parsed == 3) {

            if (quantity <= 0 || grn < 0 || kop < 0) {
                cout << "Incorrect format of input" << endl;
                continue;
            }

            money m = {grn, kop};
            normalize(&m);

            multi(&m, quantity);

            cout << grn << " грн "
                 << kop << " коп × "
                 << quantity << endl;

            sum(&total_money, m);
        }
    }

    fclose(f);

    cout << endl
         << "Сума без округлення: "
         << total_money.grn << " грн "
         << total_money.kop << " коп" << endl;

    roundMoney(&total_money);

    cout << "До оплати (після округлення): "
         << total_money.grn << " грн "
         << total_money.kop << " коп" << endl;
}
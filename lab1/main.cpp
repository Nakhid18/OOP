#include "lab1.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    const char *receiptName = "receipt.txt";

    FILE *my_file = fopen(receiptName, "w");

    if (!my_file) {
        cout << "Could not create receipt.txt" << endl;
        return 1;
    }

    fprintf(my_file, "Apple 2 55 5\n");
    fprintf(my_file, "Milk 3 6 1\n");

    fclose(my_file);

    cout << "\n-- Receipt got --\n" << endl;

    parseLines(receiptName);

    cout << "\n-----------------\n" << endl;

    return 0;
}

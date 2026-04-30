#include "lab1.h"
#include <iostream>

using namespace std;

int main() {
    const char *fileName = "receipt.txt";

    cout << "\n--- Читання файлу ---\n" << endl;

    parseLines(fileName);

    cout << "\n---------------------\n" << endl;

    return 0;
}
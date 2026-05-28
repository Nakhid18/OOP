#include <iostream>
#include "lab2.h"
#include <cmath>
using namespace std;

int main(){ 
    triangle t;
    int n;

    cout << "Enter the point A: " << endl;
    cin >> t.A.x >> t.A.y;

    cout << "Enter the point B: " << endl;
    cin >> t.B.x >> t.B.y;

    cout << "Enter the point C: " << endl;
    cin >> t.C.x >> t.C.y;

    if(fabs(t.area()) < 1e-9 && fabs(cross(t.A, t.B, t.C)) < 1e-9){
        cout << "Triangle is degenerate" << endl;
    } 
    else cout << "Triangle is not degenerate" << endl;

    cout << "Enter the number of points: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        Points p;
        cout << "Enter point " << i + 1 << ": " << endl;
        cin >> p.x >> p.y; 

         int r1 = t.contains1(p);

        switch (r1)
        {
            case 1:
                cout << "Method 1: inside" << endl;
                break;
            case 0:
                cout << "Method 1: on border" << endl;
                break;
            case -1:
                cout << "Method 1: outside" << endl;
                break;
        }

        int r = t.contains2(p);

        switch (r)
        {
            case 1: 
                cout << "Method 2: inside" << endl;
                break;
            case 0: 
                cout << "Method 2: on border" << endl;
                break;
            case -1: 
                cout << "Method 2: outside" << endl; 
                break;
        } 
    }

    return 0;
}
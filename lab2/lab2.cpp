#include "lab2.h"
#include <cmath>
#include <iostream>
using namespace std;

double distance(const Points &p1, const Points &p2){
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

double heronArea(const triangle &t){
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.A, t.C);

    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangle::area() const{
    return fabs(cross(A, B, C)) / 2.0;
}

double cross(const Points &A, const Points &B, const Points &P){
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

bool onSegment(const Points &A, const Points &B, const Points &P) {
    return P.x >= min(A.x, B.x) - EPS && P.x <= max(A.x, B.x) + EPS &&
           P.y >= min(A.y, B.y) - EPS && P.y <= max(A.y, B.y) + EPS;
}

int triangle::contains1(const Points &P) const {
    double d1 = cross(A, B, P);
    double d2 = cross(B, C, P);
    double d3 = cross(C, A, P);

    if (fabs(d1) < EPS && onSegment(A, B, P)) return 0;
    if (fabs(d2) < EPS && onSegment(B, C, P)) return 0;
    if (fabs(d3) < EPS && onSegment(C, A, P)) return 0;

    triangle T1 = {A, B, P};
    triangle T2 = {B, C, P};
    triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    if (fabs(S_main - S_sum) < EPS * S_main)
        return 1;

    return -1;
}

int triangle::contains2(const Points &P) const {

    if (area() < EPS) {
        if (fabs(cross(A, B, P)) < EPS && onSegment(A, C, P))
            return 0; 
        return -1; 
    }

    double d1 = cross(A, B, P);
    double d2 = cross(B, C, P);
    double d3 = cross(C, A, P);

    if (fabs(d1) < EPS && onSegment(A, B, P)) return 0;
    if (fabs(d2) < EPS && onSegment(B, C, P)) return 0;
    if (fabs(d3) < EPS && onSegment(C, A, P)) return 0;

    bool has_pos = (d1 > EPS) || (d2 > EPS) || (d3 > EPS);
    bool has_neg = (d1 < -EPS) || (d2 < -EPS) || (d3 < -EPS);

    if (!(has_pos && has_neg)) return 1;

    return -1;
}
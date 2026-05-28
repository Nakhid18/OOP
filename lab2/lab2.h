#pragma once
#include <cmath>
const double EPS = 1e-9;
 struct Points{
    double x, y;
 };
 struct triangle{
    Points A, B, C;
    double area() const;

    int contains1(const Points &P) const;
    int contains2(const Points &P) const;
 };
 double distance(const Points &p1, const Points &p2);
 double heronArea(const triangle &t);
 double cross(const Points &A, const Points &B, const Points &P);
 bool onSegment(const Points &A, const Points &B, const Points &P);
 
 
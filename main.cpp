#include "Dyhotomia_class.h"
#include <iostream>

int main()
{
    Dyhotomia_class *dyh = new Dyhotomia_class();
    double x_dyhotomia;
    double x_newton;

    dyh->setVolumes(0.4, 1.0);
    dyh->setTolerance(0.0001);

    if (dyh->countDyhotomia(x_dyhotomia) == 0)
    {
        std::cout << "Method Dyhotomia: x = " << x_dyhotomia << std::endl;
    }
    else
    {
        std::cout << "Method Dyhotomia: no root on this interval" << std::endl;
    }

    if (dyh->countNewton(x_newton) == 0)
    {
        std::cout << "Method Newton:    x = " << x_newton << std::endl;
    }
    else
    {
        std::cout << "Method Newton: derivative problem" << std::endl;
    }

    delete dyh;
    return 0;
}

#pragma once
#include <cmath>
#include <iostream>

enum roots {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = 3
};

class quadraticExpression
{
public:

    double evaluate(double x) const;

    int getNumberOfRoots() const;
    double getFirstRoot() const;
    double getSecondRoot() const;
    double getFirstRootLocation() const;
    double getSecondRootLocation() const;
    double getACoefficient() const;
    double getBCoefficient() const;
    double getCCoefficient() const;
    quadraticExpression();
    quadraticExpression(double a, double b, double c);
private:
    double a;
    double b;
    double c;

};


quadraticExpression::quadraticExpression(double a, double b, double c) : a(a), b(b), c(c)
{}

quadraticExpression::quadraticExpression() : a(0), b(0), c(0)
{}

double quadraticExpression::evaluate(double x) const
{
    double y;
    y = (a * (x * x)) + (b * x) + c;
    return y;
}


int quadraticExpression::getNumberOfRoots() const
{

    
    double firstRoot;
    double secondRoot;
    double firstLocation;
    double secondLocation;
    firstRoot = getFirstRoot();
    secondRoot = getSecondRoot();
    firstLocation = getFirstRootLocation();
    secondLocation = getSecondRootLocation();

    if (secondLocation == firstLocation)
        return ONE_ROOT;

    if (firstRoot == 0 && secondRoot == 0)
    {
        return TWO_ROOTS;
    }
    else if (firstRoot == 0 || secondRoot == 0)
    {
        return ONE_ROOT;
    }
    else if (firstRoot != 0 && secondRoot != 0)
    {
        return NO_ROOTS;
    }

}
double quadraticExpression::getFirstRoot() const
{
    
    double groot = (b * b);
    double groot2 = (4 * a * c);
    double solnOne;
    double ans;
    ans = ((b * (-1)) + sqrt(groot - groot2)) / (2 * a);

    solnOne = (a * (ans * ans)) + (b * ans) + c;
    if (solnOne < 0.5) {
        solnOne = 0;
    }
    return solnOne;

}
double quadraticExpression::getSecondRoot() const
{
    
    double groot = (b * b);
    double groot2 = (4 * a * c);
    double solnTwo;
    double ans;
    ans = ((b * (-1)) - sqrt(groot - groot2)) / (2 * a);
    solnTwo = (a * (ans * ans)) + (b * ans) + c;
    if (solnTwo < 0.5) {
        solnTwo = 0;
    }
    return solnTwo;

}

double quadraticExpression::getFirstRootLocation() const
{
    
    double groot = (b * b);
    double groot2 = (4 * a * c);
    double sol;
    double ans;
    ans = ((b * (-1)) + sqrt(groot - groot2)) / (2 * a);
    return ans;

}

double quadraticExpression::getSecondRootLocation() const
{
    
    double groot = (b * b);
    double groot2 = (4 * a * c);
    double sol;
    double ans;
    ans = ((b * (-1)) - sqrt(groot - groot2)) / (2 * a);
    return ans;

}

double quadraticExpression::getACoefficient() const
{
    return a;
}

double quadraticExpression::getBCoefficient() const
{
    return b;
}

double quadraticExpression::getCCoefficient() const
{
    return c;
}


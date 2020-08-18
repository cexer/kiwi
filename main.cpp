#include "kiwi/kiwi.h"
#include <vector>
#include <iostream>
using namespace kiwi;


int main(int argc, char** argv)
{

    Variable x1("x1");
    Variable x2("x2");
    Variable xm("xm");

    Constraint constraints[4] = { 
        Constraint(x1 >= 0),
        Constraint(x2 <= 100),
        Constraint(x2 >= x1 + 20),
        Constraint(xm == (x1 + x2) / 2)
    };


    Solver solver;

    for(size_t i = 0; i < 4; ++i)
    {
        solver.addConstraint(constraints[i]);
    }

    solver.addConstraint(Constraint(x1 == 40, strength::weak));
    solver.suggestValue(xm, 90);
    solver.updateVariables();
    std::cout << xm.value() << ", " << x1.value() << ", " << x2.value();
}
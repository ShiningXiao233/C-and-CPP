#include "myfunc.hpp"
#include <iostream>

#ifdef USE_MYFUNC
#include "pow.hpp"
#else
#include <cmath>
#endif

int myfunc::pow(int x, int p)
{
#ifdef USE_MYFUNC
    std::cout << "use myfunc" << std::endl;
    return math::num::pow(x, p);
#else
    std::cout << "no-use myfunc" << std::endl;
    return static_cast<int>(std::pow(x, p));
#endif
}
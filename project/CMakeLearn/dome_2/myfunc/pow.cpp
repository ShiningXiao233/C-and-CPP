#include "pow.hpp"

int math::num::pow(int x, int p)
{
    if (p < 0) return 0; 
    int res = 1;
    while (p --) {
        res *= x;
    }
    return res;
}
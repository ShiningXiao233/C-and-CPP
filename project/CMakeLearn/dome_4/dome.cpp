#include <iostream>
#include "myfunc.hpp"

using namespace std;

int main() {
    cout << myfunc::pow(2, 6) << endl;
    cout << __cplusplus << endl;
    return 0;
}
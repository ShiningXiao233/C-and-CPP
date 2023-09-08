#include <iostream>

using namespace std;

int fun(int x) {
    return x * x;
}

int main() {
    int (*fun_pr)(int) = fun;
    cout << fun_pr(3) << endl;
    cout << (*fun_pr)(3) << endl;
    
    return 0;
}
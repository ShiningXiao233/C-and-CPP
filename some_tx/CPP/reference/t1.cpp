#include <iostream>

using namespace std;

int test1(const int &a) {
    return a * a;
}

int main() {
    int a = 2;
    cout << test1(a) << '\n';
    cout << test1(2 + a) << '\n';
    cout << test1(a++) << '\n';
     
    return 0;
}
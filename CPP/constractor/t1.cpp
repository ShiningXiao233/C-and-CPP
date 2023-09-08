#include <iostream>

using namespace std;

class lib {
public:

    explicit lib(int a, int b = 4) : _a(a), _b(b) {
        cout << "oh ! == " << a << ' ' << b << endl;
    }

    // lib(int a) : _a(a) {
    //     cout << "oh ! == " << a << endl;
    // }

    lib() {
        cout << "0 oh ! == " << endl;
    }

    operator double() {
        return _a * _b * 1.0;
    }

private:
    int _a;
    int _b;

};

int main() {

    lib b(1,4);
    lib a(b);
    // b = 5.3 + 4;
    // b = {4, 5};
    b = lib(2.3, 3);
    cout << double(b) << endl;
    cout << double(a) << endl;
    return 0;
}
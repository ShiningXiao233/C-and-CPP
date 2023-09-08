#include <iostream>

using namespace std;

class t1 {
public:
    t1(int a) : _a(a) {
        cout << "t1 !" << endl;
    }
private:
    int _a;
};

class t2 : public t1 {
public:
    t2(int a) : t1(a) {
        cout << "t2 !" << endl;
        // cout << _a << endl;
    }
};


class f1 {
public:
    void g() {
        cout << "f1" << endl;
    }
};

class f2 {
public:
    void g() {
        cout << "f2" << endl;
    }
};

class f3 : public f1, public f2 {
public:
};


int main() {
    // t2 tt(3);
    return 0;
}
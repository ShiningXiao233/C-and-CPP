#include <iostream>

using namespace std;

class lib {

friend ostream& operator<<(ostream&, const lib&);
friend lib operator * (const int&, const lib&);

public:
    lib(int _a, int _b) : a(_a), b(_b) {}
private:
    int a, b;

};

ostream& operator << (ostream& out, const lib& rhv) {
    out << '(' << rhv.a << ',' << rhv.b << ')';
    return out;
}

lib operator * (const int& a, const lib& b) {
    return lib(a * b.a, a * b.b);
}

int main() {
    lib g(4, 5);
    cout << g << 3 << endl;
    cout << 3 * g << endl;
    return 0;
}
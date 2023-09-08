#include <iostream>

using namespace std;

class t1 {
public:

    void ff(int x) {
        cout << x << endl;
    }

    t1(int a) : ax(a) {
        ff(3);
    }
    t1(const t1& rhs): ax(rhs.ax) {
        cout << "copy constractor" << endl;
    }
    int getax() {
        return ax;
    }
private:
    const int ax;
};

int main() {
    t1 a(2);
    t1 b = a;
    cout << a.getax() << endl;
    return 0;
}
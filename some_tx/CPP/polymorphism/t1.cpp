#include <iostream>
#include <typeinfo>

using namespace std;

class A {
public: 
    virtual void getname() {
        cout << typeid(*this).name() << endl;
    }
};

class B : public A {

};

void get(B& a) {
    a.getname();
}

int main() {
    B b;
    b.getname();
    A a = b;
    a.getname();
    return 0;
}
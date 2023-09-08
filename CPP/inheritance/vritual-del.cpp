#include <iostream>

using namespace std;

class baset {
public:
    virtual ~baset() {
        cout << "base" << endl;
    }

    virtual void print() {
        cout << "base" << endl;
    }
};

class derived : public baset {
public:
    ~derived() {
        cout << "derived" << endl;
    }
    void print() {
        cout << "derived" << endl;
    }
};

class exderived : public derived {
public:
    ~exderived() {
        cout << "exderived" << endl;
    }
    void print() {
        cout << "exderived" << endl;
    }
};

class exexderived : public exderived {
public:
    ~exexderived() {
        cout << "exexderived" << endl;
    }
    void print() {
        cout << "exexderived" << endl;
    }
};

int main() {
    derived *p = new exexderived();
    p->print();
    delete p;  
    return 0;
}
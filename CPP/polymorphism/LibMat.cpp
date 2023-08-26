#include <iostream>
#include <typeinfo>

using namespace std;


class LibMat {
private:
    /* data */
public:
    LibMat(/* args */) {

    }
    virtual void getinfo() {
        cout << "LibMat" << endl;
    }
    virtual LibMat* aaa() {
        cout << "LibMat" << endl;
        return this;
    }
};

class Book : public LibMat {

public:
    void getinfo() {
        cout << "Book" << endl;
    }

    Book* aaa() {
        cout << "aaa" << endl;
        return this;
    }
private:
    

};

int main() {

    Book a;
    LibMat p = a;
    p.aaa();
    cout << typeid(p).name() << endl;
    cout << typeid(a).name() << endl;  
    return 0;
}
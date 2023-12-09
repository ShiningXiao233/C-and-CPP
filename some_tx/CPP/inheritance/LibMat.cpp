#include <iostream>

using namespace std;

class LibMat
{
private:
    string _name;
public:
    LibMat();
    LibMat(string name);
    ~LibMat();
    string getname() const {
        return _name;
    }
    void print(int a) {
        cout << a << endl;
    }
    virtual string gettype() const;
};


string LibMat::gettype() const {
    return "LibMat";
}

LibMat::LibMat(string name) {
    this->_name = name;
    cout << "Create This is LibMat" << endl;
    cout << "name: " << this->_name << endl;
}

LibMat::LibMat(/* args */)
{
    cout << "Create This is LibMat" << endl;
}

LibMat::~LibMat()
{
    cout << "del LibMat" << endl;
}

class Book : public LibMat {
public: 

    Book(string name = "book1") : LibMat(name) {
        cout << "Create Book" << endl;
    }

    virtual string gettype() const {
        return "Book";
    }
    ~Book() {
        cout << "del Book!" << endl;
    }

    void print(int a, int b) {
        cout << a << ' ' << b << endl;
    }
private:

};


#define printline cout << "=============" << endl

void printg(const LibMat &x) {
    cout << "Name: " << x.getname() << endl;
    cout << "Type: " << x.gettype() << endl;
}

int main() {

    LibMat *a = new LibMat("fhjdsk");
    cout << a->gettype() << endl;
    delete a;
    
    printline;

    Book b;
    cout << b.getname() << endl;
    cout << b.gettype() << endl;

    printline;
    // cout << "==============" << endl;
    a = new Book("book2");
    cout << a->gettype() << endl;

    printline;

    LibMat aa("LibMat_1");
    Book bb("Book_1");

    printline;

    printg(aa);
    printline;

    printg(bb);
    printline;
    bb.LibMat::print(1);
    bb.print(1, 3);

    exit(0);
}

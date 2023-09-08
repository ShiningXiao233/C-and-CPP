#include <iostream>
#include <vector>
using namespace std;

class dell
{
private:
    /* data */
public:
    virtual ~dell() = 0;
};

dell::~dell()
{
    cout << "dell" << endl;
}

class exdell : public dell {
public:
    ~exdell() {
        cout << "exdell" << endl;
    }
};

int main() {
    vector<int> s(0);
    s.push_back(2);
    s.clear();
    return 0;
}
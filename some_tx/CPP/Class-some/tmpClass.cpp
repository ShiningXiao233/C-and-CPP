#include <iostream>
#include <vector>

using namespace std;

class myStack {
private:
    vector<int> _stack;

public:
    myStack() {
        cout << "create a myStack!" << endl;
        _stack.clear();
    }
    ~myStack();
    bool push(const int);
    int pop();
};


myStack::~myStack() {
    cout << "delate a my myStack!" << endl;
}

bool myStack::push(const int x) {
    _stack.push_back(x);
    return true;
}

int myStack::pop() {
    int res = _stack[_stack.size() - 1];
    _stack.erase(_stack.end() - 1, _stack.end());
    return res;
}


int main() {

    myStack a;
    a.push(1);
    a.push(2);

    cout << a.pop() << endl;
    cout << a.pop() << endl;

    // exit(0);
    return 0;
}
#include <iostream>

class A {
public:
void PrintContent() { 
std::cout << "A" << std::endl;
}
};

class B : public A {
public:
void PrintContent() {
std::cout << "B" << std::endl;
}
};


class C : public A {
public:
void PrintContent() {
std::cout << "C" << std::endl;
}
};

int main() {
    A *a_pointer = new B();
    a_pointer->PrintContent();	//输出
    delete a_pointer;

    a_pointer = new C();
    a_pointer->PrintContent();	//输出
    delete a_pointer;

    B b;
    A a_none_pointer = b;             	
    a_none_pointer.PrintContent(); //输出

    return 0;
}

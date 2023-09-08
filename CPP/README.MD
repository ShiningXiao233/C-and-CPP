# C++学习

学习来参考《Essential C++中文版》 Stanley B.Lippman 著，侯捷译


### 0. IO

IO是程序的灵魂，C++的IO类似于C，但是提供了更好的封装，均以Stream(流)的概念出现。

```cpp
#include <fstream>


using namespace std;

int main() {
    ofstream outfile("./1.txt"); // 以写mode打开文件
    ifstream infile("./1.txt"); // 以读mode打开文件
    // fstream iofile("", mode....) // 打开文件，自定义模式 ios_base::app....之类的
    outfile << 1 << endl;
    exit(0);
}

```


基本上还是模仿了C的一套，新知识不多

### 1. virtual 关键字

`virtual` 关键字是 C++ 实现多态的关键。\
拥有 `virtual` 的类会维护一个虚函数表。虚函数表负责在父类指针或者父类引用指向派生子类时可以调用子类的函数定义。

特性：
1. 在经过父类一次声明虚函数后，派生子类不需要再显式声明 `virtaul`，默认全是虚函数。
```cpp
#include <iostream>

using namespace std;

class baset {
public:
    virtual ~baset() {
        cout << "del base" << endl;
    }

    virtual void print() {
        cout << "base" << endl;
    }
};

class derived : public baset {
public:
    ~derived() {
        cout << "del derived" << endl;
    }
    void print() {
        cout << "derived" << endl;
    }
};

class exderived : public derived {
public:
    ~exderived() {
        cout << "del exderived" << endl;
    }
    void print() {
        cout << "exderived" << endl;
    }
};

class exexderived : public exderived {
public:
    ~exexderived() {
        cout << "del exexderived" << endl;
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

/* 
==========================
输出：

exexderived
del exexderived
del exderived
del del derived
del base

*/
```



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


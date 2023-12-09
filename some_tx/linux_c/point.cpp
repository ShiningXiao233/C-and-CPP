#include <iostream>

int main() {
    int (*p)[4];
    std::cout << p << std::endl;
    printf("%d\n", p);
    p += 1;

    std::cout << p << std::endl;
    printf("%d\n", p);
     
    return 0;
}
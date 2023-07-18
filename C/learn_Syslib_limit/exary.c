#include <stdio.h>

int a[10];

int main() {
    for (int i = -10; i <= 10; ++i) {
        a[i] = 1;
    }
    int i = 100000000;
    printf("%d\n", a[i]);
    return 0;
}
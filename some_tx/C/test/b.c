#include <stdio.h>

int main() {
    int a;
    for (int i = 1; i <= 10; ++i) {
        scanf("%d", &a);
        printf("%d\n", a + 10);
    }
    return 0;
}
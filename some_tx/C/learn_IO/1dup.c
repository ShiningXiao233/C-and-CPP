#include <stdio.h>

int main() {
    FILE* fp = fopen("./1.txt", "r");
    stdin = fp;
    int a;
    scanf("%d", &a);
    printf("%d\n", a);
}
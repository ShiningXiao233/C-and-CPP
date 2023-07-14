#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = system("sudo mkdir aaa");
    // printf("%d\n", a);
    printf("%d %d %d\n",a, a >> 8, a & 0xff);
    return 0;
}
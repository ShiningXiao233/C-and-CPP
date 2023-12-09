#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void t1() {
    char *p;
    for (int i = 1; i <= 20; ++i) {
        p = (char*) malloc(1024 * 1024);
        for (int i = 0; i < 1024 * 1024; ++i) {
            *(p + i) = '6';
        }
        printf("%d\n", i);
        sleep(1);
    }
}

int main() {
    
    return 0;
}
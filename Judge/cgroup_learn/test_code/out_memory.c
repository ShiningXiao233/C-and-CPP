#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define OneMB 1024

int main() {
    void *p;
    for (int i = 1; i <= 20; ++i) {
        p = malloc(OneMB);
        printf ("%d\n", i);
    }

    return 0;
}
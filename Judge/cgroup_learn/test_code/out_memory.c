#include <stdio.h>
#include <unistd.h>

#define OneMB 1024

int main() {
    void *p;
    for (int i = 1; i <= 20; ++i) {
        usleep(3000000);
        printf("%d\n", i);
        sleep(1);
        printf("-%d\n", i);
    }
    return 0;
}
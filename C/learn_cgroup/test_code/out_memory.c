#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define OneMB 1024 * 1024


int main() {
    char *p;
    for (int i = 1; i <= 20; ++i) {
        p = (char*)malloc(OneMB);
        printf("%d MB\n", i);
        sleep(1);
        for (int j = 0; j < OneMB; ++j) {
            *(p + j) = j & (0xFF);
        }
    }
    return 0;
}
#include <stdio.h>
#include <unistd.h>

int main() {
    int n;
    for (int i = 1; i <= 10; ++i) {
        sleep(1);
        printf("%d\n", i);
        fflush(stdout);
    }
    fclose(stdout);
    return 0;
}
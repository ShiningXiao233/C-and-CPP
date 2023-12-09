#include <stdio.h>
#include <unistd.h>



int main() {
    // sleep(2);
    int p = 1e8;
    int g = 4;
    for (int i = 1; i <= p; ++i) {
        g ^= i;
        g &= i;
        g |= i;
        g *= i;
        g %= i;
    }
    printf("%d\n", g);
    return 0;
}
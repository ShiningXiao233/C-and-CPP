#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("%ld\n", sizeof(pid_t));
    return 0;
}
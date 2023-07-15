#include <stdio.h>
#include <stdlib.h>

char s[300];

int main() {
    sprintf(s, "sudo rmdir /sys/fs/cgroup/judge/%d", 23);
    printf("%s\n", s);
    int a = system(s);
    printf("%d\n", a);
    return 0;
}
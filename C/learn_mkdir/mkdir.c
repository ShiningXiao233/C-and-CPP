#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int a = mkdir("/sys/fs/cgroup/myjudge", 0777);
    printf("%d\n", a);
    return 0;
}
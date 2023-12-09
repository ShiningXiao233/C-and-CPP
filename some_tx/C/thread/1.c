#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
// #include <bits/sigaction.h>

void signal_handler(int signum) {
    printf("Received signal: %d\n", signum);
    printf("=== %ld\n", pthread_self());
    exit(0);
}


void *pthread_func(void *arg) {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    printf("+++ %ld\n", pthread_self());
    // 注册信号处理程序
    alarm(1);
    sigaction(SIGALRM, &sa, NULL);
    while (1);
}

int main() {
    printf("%ld\n", pthread_self());
    pthread_t pid;

    pthread_create(&pid, NULL, pthread_func, NULL);
    pthread_join(pid, NULL);
    printf(" ok !!!");
    return 0;
}

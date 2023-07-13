#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void sig_handler(int signo, siginfo_t *info, void *context) {
    pthread_t thread_id = pthread_self();
    printf("Signal received in thread: %lu\n", (unsigned long)thread_id);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sig_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    // 创建两个线程
    // pthread_t thread1, thread2;
    // pthread_create(&thread1, NULL, NULL, NULL);
    // pthread_create(&thread2, NULL, NULL, NULL);

    // 使主线程休眠一段时间，以模拟程序运行
    sleep(5);

    return EXIT_SUCCESS;
}

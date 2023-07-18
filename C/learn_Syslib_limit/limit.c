#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct rlimit rlmt;

unsigned long get_now_memory(int pid) {
    char path[50] = {0};
    sprintf(path, "/proc/%d/statm", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("error\n");
        return 1;
    }
    unsigned long res = 0;
    fscanf(fp, "%lu", &res);
    fclose(fp);
    printf("%ld\n", sysconf(_SC_PAGESIZE));
    return res * sysconf(_SC_PAGESIZE);

}

void test_cpu() {
    rlmt cpu_limt;
    cpu_limt.rlim_cur = 5;
    cpu_limt.rlim_max = 5;
    setrlimit(RLIMIT_CPU, &cpu_limt);

    char *const arg[] = {"./extime.out", NULL};
    execvp("./extime.out", arg);
}

void test_memory() {
    rlmt memory_limt;
    memory_limt.rlim_cur = 1024 * 1024 * 10;
    memory_limt.rlim_max = 1024 * 1024 * 50;
    setrlimit(RLIMIT_AS, &memory_limt);

    char *const arg[] = {"./exmemory.out", NULL};
    execvp("./exmemory.out", arg);
}

void test_dec_0() {
    // rlmt memory_limt;
    // memory_limt.rlim_cur = 1024 * 1024 * 10;
    // memory_limt.rlim_max = 1024 * 1024 * 50;
    // setrlimit(RLIMIT_AS, &memory_limt);

    char *const arg[] = {"./exreturn.out", NULL};
    execvp("./exreturn.out", arg);
}

void test_ex_ary() {
    // rlmt memory_limt;
    // memory_limt.rlim_cur = 1024 * 1024 * 10;
    // memory_limt.rlim_max = 1024 * 1024 * 50;
    // setrlimit(RLIMIT_AS, &memory_limt);

    char *const arg[] = {"./exary.out", NULL};
    execvp("./exary.out", arg);
}

void test_() {
    char *const arg[] = {"./test.out", NULL};
    execvp("./test.out", arg);
}

int main() {
    
    
    pid_t p = fork();
    if (p == -1) {
        printf("create son process error!");
    } else if (p == 0) {
        // printf("%d\n", getpid());
        printf("%lu\n", get_now_memory(getpid()));

        // test_();
        test_cpu();
        // test_memory();
        // test_dec_0();
        // test_ex_ary();
        printf("%d\n", p);
        return 2;
    } else {
        int a = getpid();
        // if (p == -1)
        // sleep(1);
        printf("%d==%d\n", a, p);
        int statu = -1;
        // sleep(1);
        // kill(p, SIGKILL);
        // printf("1111\n");
        waitpid(p, &statu, 0);
        
        if (WIFEXITED(statu)) {
            printf("return by %d\n", WEXITSTATUS(statu));
        }
        if (WIFSIGNALED(statu)) {
            printf("sig by %d\n", WTERMSIG(statu));
            
        }

    }

    return 0;
}

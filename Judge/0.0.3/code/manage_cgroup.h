#ifndef __MANAGR_CGROUP__

#define __MANAGR_CGROUP__ " manage_cgroup of OpenJudgeCore written by ZhilinXiao"

#include "read_config.h"
#include <stdlib.h>
#include <stdio.h>

const char* __manage_cgroup_agv__[] = {"CGROUP_ROOT_PATH", "JUDGE_NAME", "CGROUP_MEMORY_PEAK",
                                     "CGROUP_MEMORY_MAX", "JUDGE_PATH", "CGROUP_SUB_CONTROLLER"};
char __manage_cgroup_val__[6][ARGMAXLEN] = {
    "/sys/fs/cgroup",
    "judge",
    "memory.peak",
    "memory.max",
    "",
    "cgroup.subtree_control"
};

#define CGROUP_ROOT_PATH __manage_cgroup_val__[0]
#define JUDGE_NAME __manage_cgroup_val__[1]
#define CGROUP_MEMORY_PEAK __manage_cgroup_val__[2]
#define CGROUP_MEMORY_MAX __manage_cgroup_val__[3]
#define JUDGE_PATH __manage_cgroup_val__[4]
#define CGROUP_SUB_CONTROLLER __manage_cgroup_val__[5]


typedef unsigned long long ull;

char __manage_cgroup_command[ARGMAXLEN * 10];

const ull MEMORY_KB = 1024ull;
const ull MEMORY_MB = MEMORY_KB * 1024ull;
const ull MEMORY_GB = MEMORY_MB * 1024ull;

int cgroup_clear();
int cgroup_init();
int cgroup_del(const char* uuid);
ull cgroup_read_max_memory(const char* uuid, ull unit);
int cgroup_create(const char* uuid, ull memory_limit, ull unit);


/**
 * 删除cgroup的judge根目录
 * 返回0说明删除成功，返回-1说明失败
*/
int cgroup_clear() {
    sprintf(__manage_cgroup_command, "rmdir %s", JUDGE_PATH);
    printf("%s\n", JUDGE_PATH);
    int state = system(__manage_cgroup_command);
    if (state != 0) {
        printf("\033[31m error\033[0m: not del judge root cgroup, meybe have procs\n");
        return -1;
    }
    printf("\033[032m del judge_root success\033[0m: clear root judge cgroup\n");
    return 0;
}


/**
 * 初始化cgroup
 * 在cgroup根目录下建立一个唯一的judge的cgroup，用来限制资源
 * 返回0说明创建成功，返回-1说明失败
*/
int cgroup_init() {
    read_config_char("./cgroup.config", __manage_cgroup_agv__, __manage_cgroup_val__, 1);
    
    sprintf(__manage_cgroup_command, "%s/%s", CGROUP_ROOT_PATH, JUDGE_NAME);
    strcpy(JUDGE_PATH, __manage_cgroup_command);
    printf("%s\n", JUDGE_PATH);
    sprintf(__manage_cgroup_command, "mkdir %s", JUDGE_PATH);
    int state = system(__manage_cgroup_command);
    if (state != 0) {
        printf("\033[31m error\033[0m: not create judge root cgroup\n");
        return -1;
    }
    sprintf(__manage_cgroup_command, "%s/%s", JUDGE_PATH, CGROUP_SUB_CONTROLLER);
    FILE *fp = fopen(__manage_cgroup_command, "w");

    if (fp == NULL) {
        printf("\033[31m open cgroup controller error\033[0m: %s\n", __manage_cgroup_command);
        state = cgroup_clear();
        if (state == -1) {
            printf("\033[31m system error \033[0m\n");
            // exit(-1);
        }
        return -1;
    }

    fprintf(fp, "+memory +cpu +io\n");
    fclose(fp);

    printf("\033[32m create success \033[0m: judge root cgroup create in %s\n", JUDGE_PATH);

    return 0;
}




/**
 * 删除一个cgroup组
 * uuid 为删除的组名称
 * 返回0成功，-1失败
*/
int cgroup_del(const char* uuid) {
    sprintf(__manage_cgroup_command, "rmdir %s/%s", JUDGE_PATH, uuid);
    int state = system(__manage_cgroup_command);
    if (state != 0) {
        sprintf(__manage_cgroup_command, "\033[31m error\033[0m: not make cgroup %s\n", uuid);
        perror(__manage_cgroup_command);
        return -1;
    }
    printf("del cgroup %s: \033[032m success!\033[0m \n", uuid);
    return 0;
}

/**
 * 创建一个cgroup组
 * uuid 为创建的组名称[千万千万不要重名]
 * memory_limit 指定内存限制，默认32
 * unit 指定内存单位，默认MB
 * 返回0成功，-1失败
*/
int cgroup_create(const char* uuid, ull memory_limit, ull unit) {

    sprintf(__manage_cgroup_command, "mkdir %s/%s", JUDGE_PATH, uuid);
    int state = system(__manage_cgroup_command);
    if (state != 0) {
        sprintf(__manage_cgroup_command, "\033[31m error\033[0m: not make cgroup %s", uuid);
        perror(__manage_cgroup_command);
        return -1;
    }

    sprintf(__manage_cgroup_command, "%s/%s/%s", JUDGE_PATH, uuid, CGROUP_MEMORY_MAX);

    FILE *fp = fopen(__manage_cgroup_command, "w");

    if (fp == NULL) {
        sprintf(__manage_cgroup_command, "\033[31m set memory error\033[0m: %s/%s", JUDGE_PATH, uuid);
        perror(__manage_cgroup_command);
        state = cgroup_del(uuid);
        if (state == -1) {
            printf("\033[31m system error \033[0m\n");
            // exit(-1);
        }
        return -1;
    }

    fprintf(fp, "%llu\n", memory_limit * unit);

    fclose(fp);

    printf("\033[32m create cgroup success\033[0m: %s\n", uuid);

    return 0;
}

/**
 * 读出一个cgroup组的最大使用内存（一般用来读取程序使用的内存信息）
 * uuid 组名称
 * unit 读出单位，默认KB
*/
ull cgroup_read_max_memory(const char* uuid, ull unit) {
    sprintf(__manage_cgroup_command, "%s/%s/%s", JUDGE_PATH, uuid, CGROUP_MEMORY_PEAK);
    FILE *fp = fopen(__manage_cgroup_command, "r");
    if (fp == NULL) {
        sprintf(__manage_cgroup_command, "\033[31m read memory.peak error\033[0m: open %s fail\n", uuid);
        perror(__manage_cgroup_command);
        return -1;
    }
    ull res = 0;
    fscanf(fp, "%lld", &res);
    res /= unit;
    fclose(fp);
    return res;
}

#endif
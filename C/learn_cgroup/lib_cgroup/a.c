#include <stdio.h>
#include <stdlib.h>
#include <libcgroup.h>
#include <unistd.h>


int main() {
    struct cgroup_controller *controller = NULL;
    struct cgroup *cg = NULL;
    const char *cgroup_name = "/my_cgroup";

    // 初始化 libcgroup
    if (cgroup_init()) {
        fprintf(stderr, "Failed to initialize libcgroup\n");
        exit(1);
    }

    // 获取 cgroup 控制器
    controller = cgroup_get_controller("cgroup2");
    if (!controller) {
        fprintf(stderr, "Failed to get cgroup controller\n");
        exit(1);
    }

    // 创建 cgroup
    cg = cgroup_new_cgroup(cgroup_name);
    if (!cg) {
        fprintf(stderr, "Failed to create cgroup\n");
        exit(1);
    }

    // 添加 cgroup 控制器
    cgroup_add_controller(cg, controller);

    // 创建 cgroup
    if (cgroup_create_cgroup(cg, 0)) {
        fprintf(stderr, "Failed to create cgroup\n");
        exit(1);
    }

    printf("Cgroup created successfully: %s\n", cgroup_name);

    sleep(60);

    // 释放资源
    cgroup_delete_cgroup_ext(cg, CGFLAG_DELETE_RECURSIVE | CGFLAG_DELETE_IGNORE_MIGRATION);

    return 0;
}

# cgroup v2

[cgroup v2 官方文档](https://www.kernel.org/doc/html/v5.10/admin-guide/cgroup-v2.html)

## 简介


cgroup 是一种以 hierarchical（树形层级）方式组织进程的机制（a mechanism to organize processes hierarchically），以及在层级中以受控和 可配置的方式（controlled and configurable manner）分发系统资源 （distribute system resources）。

cgroup是一个linux资源管理工具，由于没有学过V1，直接学的V2，现在在ubuntu22.04中已经集成了 cgroup V2。


### cgroup 组成部分
cgroup 主要由两部分组成：

核心（core）：主要负责层级化地组织进程；

控制器（controllers）：大部分控制器负责 cgroup 层级中 特定类型的系统资源的分配，少部分 utility 控制器用于其他目的。

### 进程/线程与 cgroup 关系

所有 cgroup 组成一个树形结构（tree structure），

系统中的每个进程都属于且只属于某一个 cgroup；

一个进程的所有线程属于同一个 cgroup；

创建子进程时，继承其父进程的 cgroup；

一个进程可以被迁移到其他 cgroup；

迁移一个进程时，子进程（后代进程）不会自动跟着一起迁移；

### 控制器
遵循特定的结构规范（structural constraints），可以选择性地 针对一个 cgroup 启用或禁用某些控制器；
控制器的所有行为都是 hierarchical 的。

如果一个 cgroup 启用了某个控制器，那这个 cgroup 的 sub-hierarchy 中所有进程都会受控制。
如果在更接近 root 的节点上设置了资源限制（restrictions set closer to the root），那在下面的 sub-hierarchy 是无法覆盖的。





## 使用

cgroup2是一个树形结构，根节点是 group，挂载点一般是 `/sys/fs/group`。

每个节点可以看成一个容器，每个节点管理着当前节点以及以下所有子节点的资源配置。

下面有很多文件，用来限制相关资源的使用。

比如内存：memory.* 的相关文件 \
还有系统文件 cgroup.*。

### 删除/新增节点

V2似乎不需要在进行挂载，直接在某个节点下面执行 `mkdir` 命令就会字段生成一个节点。

`rmdir` 会删除节点以及子节点，当然删除时，需要保证节点为空，也就是没有进程在当前节点下运行。

### 运行进程在指定组中

1. 使用填写 pid 的方式，在节点的 cgroup.procs 中写入即可。

> `sudo echo <pid> | sudo tee cgroup.procs`
>
> 小知识：在Linux中，sudo命令仅会应用于echo这个命令，而不会对重定向操作符（>）也应用sudo权限。因此，执行`sudo echo <pid> > cgroup.procs`实际上等同于以下两个步骤：
> 1. 使用超级用户权限执行echo命令：`sudo echo <pid>`
> 2. 尝试将该命令的输出重定向到文件 cgroup.procs
> 
> 所以使用`sudo echo <pid> | sudo tee cgroup.procs`时，`sudo`权限将应用于`tee`命令及其重定向操作符，重定向操作将成功执行。


2. 使用工具 cgroup-tools

> 需要先安装 `sudo apt install cgroup-tools`
> 
> 使用 `cgexec` 的命令进行。
> 
> `cgexec [-h] [-g <controllers>:<path>] [--sticky] command [arguments]`
> 
> 只有两个参数:
>   -h help 没啥用
>   -g 指定你需要放入的cgroup，注意了，这个比较坑 `<controllers>:<path>` 
>       `<controllers>`: 一般指控制资源的子系统，实际上 cgroupV2 中，已经没有 V1 的那种显式的子系统了，就是 `cpu,memory,io` 之类的，在V1中，这些子系统是专门的，但是在V2中，每个节点都可以进行限制，所以这个参数你写啥都行，建议写`*`, 或者你为了看起来好看，你写你需要控制的，比如我就是要控制内存，我就写个`memory`，值得一提的是在V1中，这个参数是支持组合的，也就是`cpu,memory,io`写法。
>       `<path>`: 就是路径了，写的是关于根节点的路径，比如根节点挂载的路径是 `/sys/fs/cgroup`，你要放入的路径是 `/sys/fs/cgroup/xxx`，那么你写 `/xxx` 就行了。
>  组合起来大概是 `cgexec -g *:/xxx command` ;
>  返回值，如果超过限制，会返回 `137`，否则返回你的命令的返回值。

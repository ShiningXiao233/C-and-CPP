
## 1 重定向的最好方式

```c
// 系统级的定向，后续java，C/C++都能用

// 重定向输入

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int fp = open("./1.txt", O_RDONLY);
dup2(fp, STDIN_FILENO);


// 重定向输出

int fp = open("./1.txt", O_WRONLY);
dup2(fp, STDOUT_FILENO);

```
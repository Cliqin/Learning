# 各个函数的用法

---

## wait()

```c
#include <sys/wait.h>
pid_t wait(int *status);
```

`wait()`函数是一个进程等待函数，用于等待其子进程结束并返回状态信息。

参数:

- `status`参数是一个整型指针，用于存储子进程的退出状态，也可以传递`NULL`表示不关心子进程的退出状态。

作用:

- `wait()`函数的作用是挂起当前进程，等待子进程结束。

- 如果当前进程没有子进程，`wait()`函数会立即返回-1并设置errno为`ECHILD`；


- 如果当前进程有多个子进程，则`wait()`函数会等待任意一个子进程结束，并返回结束的子进程ID，


- 如果多个子进程同时结束，则随机返回一个结束的子进程ID。


在使用`wait()`函数时，可以根据返回值和子进程的退出状态来判断子进程的运行状态，进而进行相应的处理。例如，如果返回的状态值为0，则表示子进程正常结束；如果返回的状态值小于0，则表示子进程异常结束；如果返回的状态值大于0，则表示子进程被信号终止。

---

## waitpid()

```c
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *status, int options);
```

`waitpid()`函数是`wait()`函数的一种变种，用于等待指定进程结束并返回状态信息。

参数:

- `pid`参数是要等待的进程ID，可以指定为-1表示等待任意子进程结束

- `status`参数用于存储进程的退出状态信息，如果不需要获取状态信息，可以传递`NULL`

- `options`参数指定一些选项，如WNOHANG表示非阻塞等待

作用:

- `waitpid()`函数的作用是挂起当前进程，等待指定进程结束。

- 如果指定的进程已经结束，则`waitpid()`函数会立即返回进程ID，否则会挂起当前进程，直到指定的进程结束或者发生错误。

- 与wait()函数不同的是，`waitpid()`函数可以指定要等待的进程，避免了`wait()`函数随机返回进程ID的问题。

在使用`waitpid()`函数时，可以根据返回值和进程的退出状态来判断进程的运行状态，进而进行相应的处理。例如，如果返回的状态值为0，则表示指定进程正在运行；如果返回的状态值小于0，则表示出现了错误；如果返回的状态值为正整数，则表示指定进程已经结束。

----

## lockf( )

```c
int lockf(int fd, int cmd, off_t len);
```

参数:

- `fd`是文件描述符；`cmd`表示加锁方式，它可以是以下三个值之一：

  *   `F_LOCK`：请求加锁

  *   `F_TLOCK`：非阻塞地请求加锁

  *   `F_ULOCK`：请求解锁

  - `len`表示加锁/解锁的区域长度。

---

## lseek( )

```c
off_t lseek(int fd, off_t offset, int whence);
```

参数:

- `fd`是文件描述符；`offset`表示移动的偏移量；`whence`表示移动方式，它可以是以下三个值之一：

  - `SEEK_SET`：从文件开头开始偏移

  *   `SEEK_CUR`：从当前位置开始偏移

  *   `SEEK_END`：从文件末尾开始偏移

---

## read( )

```c
ssize_t read(int fd, void *buf, size_t count);
```

参数:

- `fd`是文件描述符
- `buf`是存放读取数据的缓冲区
- `count`表示读取数据的长度

---

## write( )

```c
ssize_t write(int fd, const void *buf, size_t count);
```

参数:

- `fd`是文件描述符
- `buf`是存放写入数据的缓冲区
- `count`表示写入数据的长度

---

## open()

```c
#include <fcntl.h>
int open(const char *path, int flags, mode_t mode);
```

参数:

- `path`是文件的路径名，`flags`是文件打开方式的标志，`mode`是文件的权限。
- 常用的`flags`参数有以下几种：
  - `O_RDONLY`：以只读方式打开文件。
  - `O_WRONLY`：以只写方式打开文件。
  - `O_RDWR`：以读写方式打开文件。
  - `O_CREAT`：如果文件不存在则创建该文件。
  - `O_TRUNC`：将文件长度截短为0。
  - `O_APPEND`：在文件末尾追加数据。
  - `O_EXCL`：与`O_CREAT`一同使用，如果文件已经存在则返回错误。
- `mode`参数是在创建文件时指定文件的访问权限，取值范围为0到0777，其中0表示没有权限，777表示所有权限。权限的计算方法为将3个数字分别转化成二进制后按位组合。

作用:

- `open()`函数返回的是文件的文件描述符，该文件描述符可以用于后续的文件操作，如读写文件等。

例如，下面的代码用于以只读方式打开一个名为"test.txt"的文件：

```c
int fd = open("test.txt", O_RDONLY);
if(fd < 0) {
    perror("open");
    exit(EXIT_FAILURE);
}
```

如果文件不存在，则会返回错误。如果需要创建该文件，可以使用O\_CREAT标志，例如：

```c
int fd = open("test.txt", O_CREAT|O_RDWR, 0644);
if(fd < 0) {
    perror("open");
    exit(EXIT_FAILURE);
}
```

该代码会创建一个名为"test.txt"的文件，如果文件已经存在，则会打开该文件，并以读写方式打开。如果文件不存在，则会创建该文件，并以读写方式打开，同时设置文件的权限为0644。

* * *

## sprintf()：

```c
int sprintf(char *str, const char *format, ...);
```

`sprintf()`函数是C语言标准库中的一个函数，用于将格式化的数据写入一个字符串中，返回写入的字符数量

参数:

- `str`是一个指向目标字符串的指针，`format`是一个格式字符串，用于指定输出的格式，`...`是一系列要写入字符串中的变量参数

作用:

- 该函数的作用与`printf()`类似，但不是向标准输出流写入字符串，而是将其写入到一个字符数组中

需要注意的是，由于`sprintf()`函数没有进行输出范围的检查，因此可能会导致缓冲区溢出等问题，因此使用该函数时应特别小心

---

## signal()

```c
void (*signal(int signum, void (*handler)(int)))(int);
```

参数:

- `signum`表示信号编号，`handler`表示信号处理函数。`signal()`函数将指定信号的处理函数设置为`handler`，并返回以前的信号处理函数
- 当信号`signum`产生时，将调用handler函数进行处理

在使用`signal`函数时，需要注意以下几点：

1. 信号处理函数需要使用`void`类型作为参数，表示信号编号
2. 信号处理函数需要使用`volatile`关键字来修饰其声明，表示其可能被异步调用
3. signal函数返回的是以前的信号处理函数指针，可以通过调用该指针来恢复以前的信号处理函数
4. 信号处理函数可以使用系统提供的一些函数来进行操作，如`sigprocmask`、`sigaction`、`kill`等

下面是一个使用signal函数处理SIGINT信号的例子：

```c
#include <stdio.h>
#include <signal.h>

void sigint_handler(int signum)
{
    printf("Received SIGINT signal\n");
}

int main()
{
    signal(SIGINT, sigint_handler); //将SIGINT信号处理函数设置为sigint_handler
    while(1);
    return 0;
}
```

在该例子中，使用signal函数将SIGINT信号的处理函数设置为sigint\_handler，当程序接收到SIGINT信号时，将调用该函数进行处理。

---

## close()

```c
int close(int fd);
```

参数：

*   `int fd`：需要关闭的文件描述符

返回值：

*   `0`：成功关闭文件描述符
*   `-1`：关闭文件描述符失败

执行过程：

1.  首先，`close()`函数检查文件描述符是否有效，如果无效则返回`-1`，并设置全局变量`errno`为`EBADF`表示无效的文件描述符。
2.  如果文件描述符有效，`close()`函数则释放内核所维护的该文件描述符结构体的内存空间，以及内核为该文件描述符分配的所有资源，如磁盘空间、缓冲区等。
3.  如果文件描述符所指向的文件是共享的，即在多个进程间共享访问，那么`close()`函数仅会减少该文件的引用计数器。当该文件的引用计数器降为`0`时，才会真正释放该文件的资源

作用：

*   关闭不再使用的文件描述符，以释放系统资源；
*   减少文件的引用计数器，释放文件资源。

---

## msgget()

```c
int msgget(key_t key, int msgflg);
```

参数:

- `key`是消息队列的键值，它是一个整数值，不同的键值代表不同的消息队列；
- `msgflg`是消息队列的权限和选项，可以使用`IPC_CREAT`标志创建新的消息队列，或者使用`IPC_EXCL`标志检查是否已经存在同样的消息队列

作用:

- 创建或获取消息队列

---

## msgsnd()

```c
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
```

参数:

- `msqid`是消息队列的标识符；
- `msgp`是指向消息数据的指针，消息数据需要定义为一个结构体，包含一个消息类型`msgtype`和消息内容`msgtext`；
- `msgsz`是消息内容的大小，单位是字节；`msgflg`是发送消息的选项，可以指定消息的优先级等信息

作用:

- 发送消息到消息队列中

---

## msgrcv()

接收消息从消息队列中，使用系统调用`msgrcv()`，它的原型为：

```c
int msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
```

参数:

- `msqid`是消息队列的标识符；
- `msgp`是指向消息数据的指针，需要定义为一个结构体，同样包含消息类型`msgtype`和消息内容`msgtext`；
- `msgsz`是消息内容的大小，单位是字节；`msgtyp`是要接收的消息类型，如果设置为0，则接收队列中第一个消息；`msgflg`是接收消息的选项，可以指定是否等待消息到达、是否删除已接收的消息等

作用:

- 接收消息从消息队列中

---

## msgctl()

```c
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
```

参数:

- `msqid`是消息队列的标识符；
- `cmd`是要执行的命令，可以是`IPC_RMID`删除消息队列，或者是其他命令修改消息队列的属性；
- `buf`是一个指向`struct msqid_ds`结构体的指针，用于传递和接收消息队列的属性

作用:

- 控制消息队列

---

## ftok()

```c
#include <sys/types.h>
#include <sys/ipc.h>
key_t ftok(const char *pathname, int proj_id);
```

参数:

- `pathname` 是指向一个存在的文件的指针
- `proj_id` 是任意正整数

作用:

- `ftok()` 函数将 `pathname` 所指文件的 i 节点号（inode number）和 `proj_id` 整合起来生成一个唯一的 IPC 键值。
- 这个函数返回的是一个 `key_t` 类型的键值，如果发生错误则返回 -1。
- 使用 `ftok()` 函数可以避免多个进程使用相同的标识符，因为每个文件都有不同的 i 节点号，而且由于 `proj_id` 是用户定义的，所以多个进程也可以使用同一个文件和不同的 `proj_id` 来创建 IPC 标识符。

---

## strcpy()

```c
char* strcpy(char* dest, const char* src);
```

参数:

- `dest`是目标字符串的指针
- `src`是源字符串的指针

作用:

- 函数的作用是将源字符串`src`复制到目标字符串`dest`中，并返回目标字符串`dest`的指针。

需要注意的是，`dest`指向的字符串必须有足够的空间来存放`src`指向的字符串，否则会导致内存越界或内存泄漏等问题。

工作过程:

1. 检查`src`和`dest`是否为`NULL`指针，如果是则返回`NULL`。
2. 从`src`指向的地址开始，逐个将每个字符复制到`dest`指向的地址中，直到遇到字符串结束符`\0`。
3. 返回`dest`指向的地址。

下面是一个简单的使用示例：

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    strcpy(dest, src);

    printf("Source string: %s\n", src);
    printf("Destination string: %s\n", dest);

    return 0;
}
```

该示例中，将`src`指向的字符串复制到`dest`指向的字符串中，最终输出两个相同的字符串。

* * *

## shmget()

```c
int shmget(key_t key, size_t size, int shmflg);
```

参数:

- `key`是共享内存的标识符
- `size`是共享内存的大小
- `shmflg`是共享内存的访问权限和创建标志

---

## shmat()

```c
void *shmat(int shmid, const void *shmaddr, int shmflg);
```

参数:

- `shmid`是共享内存段的标识符
- `shmaddr`是指定的共享内存地址，如果为`NULL`则让系统自动分配
- `shmflg`是共享内存的访问权限和附加标志

---

## shmdt()

```c
int shmdt(const void *shmaddr);
```



---

## shmctl()

```c
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```

参数:

- `shmid`是共享内存段的标识符
- `cmd`是指定的操作命令
- `buf`是指向共享内存状态信息的结构体指针

---

## semget()

```c

```



---

## semop()

```c

```



---



















































































































​       

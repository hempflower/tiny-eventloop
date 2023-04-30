# Tiny-eventloop —— 轻量级的 Eventloop 库

这是一个轻量级的 Eventloop 库，用于嵌入式 C 项目。它的设计目标是简单易用。

## 特性

- 简单易用
- 无动态内存分配
- 无依赖
- 无操作系统依赖
- 易于移植到任何平台，无汇编代码
- 低内存占用
- 纯 C 实现

## 用法

### 1. 定义任务函数

```c
void async_task(void *arg) {
    // do something
}
```

### 2. 添加任务到事件循环

```c
// 1000ms 后调用 async_task
el_setTimeout(async_task,NULL,1000);

// 每隔 1000ms 调用 async_task
el_setInterval(async_task,NULL,1000);
```

### 3. 运行事件循环

```c
el_enterLoop();
```

你可以在 [examples](examples) 目录中看到更多的例子。

## 移植

### 1. 定义 el_tick_t

打开 el_port.h 并定义 el_tick_t 为你的系统 tick 类型。例如，如果你的系统 tick 是 32 位的，你可以定义 el_tick_t 为 uint32_t。

```c
typedef uint32_t el_tick_t;
```

### 2. 实现 el_portTickGet

定义 el_portTickGet 为获取系统 tick 的函数。系统 tick 是系统启动以来的毫秒数。例如，在 linux 中，我们可以使用 gettimeofday 来获取系统 tick。

```c
el_tick_t el_portTickGet() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
```

幸运的是，许多平台，如 STM32，都有一个系统 tick 计数器。你可以通过读取计数器来获取系统 tick。

## API

### el_setTimeout

在超时后运行任务。

```c
void el_setTimeout(el_task_t task, void *arg, uint32_t timeout);
```

### el_setInterval

每隔一段时间运行任务。

```c
void el_setInterval(el_task_t task, void *arg, uint32_t interval);
```

### el_clearTimeout

取消一个Timeout任务。

```c
void el_clearTimeout(el_task_t task);
```

### el_clearInterval

取消一个Interval任务。

```c
void el_clearInterval(el_task_t task);
```

### el_enterLoop

运行事件循环。

```c
void el_enterLoop();
```

## License

MIT License   
作者: Evan Xiao



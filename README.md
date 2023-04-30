# Tiny-eventloop —— Simple Eventloop library

This is a simple eventloop library for embedded c projects. It is designed to be simple and easy to use. 

## Features

- Simple and easy to use
- No dynamic memory allocation
- No dependencies
- No operating system required
- Port easily to any platform. Without asm code.
- Low memory usage
- Implement by pure C


## Usage

### 1. Define task functions

```c
void async_task(void *arg) {
    // do something
}
```

### 2. Add task to eventloop

```c
// async_task will be called after 1000ms
el_setTimeout(async_task,NULL,1000);

// async_task will be called every 1000ms
el_setInterval(async_task,NULL,1000);
```

### 3. Run eventloop

```c
el_enterLoop();
```

You can see more examples in [examples](examples) directory.

## Porting

### 1. Define el_tick_t

Open el_port.h and define el_tick_t to the type of your system tick. For example, if your system tick is 32bit, you can define el_tick_t as uint32_t.

```c
typedef uint32_t el_tick_t;
```

### 2. Implement el_portTickGet

Define el_portTickGet to get system tick. System tick is the millisecond since system startup. For example, in linux, we can use gettimeofday to get system tick.

```c
el_tick_t el_portTickGet() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
```

Luckly, many platforms such as STM32 has a system tick counter. You can get system tick by reading the counter.


## API

### el_setTimeout
Run task after timeout.

```c
void el_setTimeout(el_task_t task, void *arg, uint32_t timeout);
```

### el_setInterval

Run task every interval.
```c
void el_setInterval(el_task_t task, void *arg, uint32_t interval);
```

### el_clearTimeout

Cancel timeout task.
```c
void el_clearTimeout(el_task_t task);
```

### el_clearInterval

Cancel interval task.
```c
void el_clearInterval(el_task_t task);
```

### el_enterLoop

Run eventloop.
```c
void el_enterLoop();
```

## License

MIT License   
Author: Evan Xiao

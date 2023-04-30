/**
 * @file eventloop.h
 * @author Yifan Xiao (1993996310@qq.com)
 * @brief Eventloop library header file
 * @version 0.1
 * @date 2023-04-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "el_port.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

struct el_task {
    void (*handler)(void *arg);
    void *arg;
    el_tick_t interval;
    el_tick_t run_at;
};

typedef struct el_task el_task_t;
typedef struct el_task *el_task_id_t;

void el_enter_loop(void);

el_task_id_t el_push_task(void (*handler)(void *arg), void *arg, el_tick_t interval, el_tick_t run_at);

void el_cancel_task(el_task_id_t task_id);


#define el_setTimeout(handler, arg, timeout) el_push_task(handler, arg, 0, el_get_tick() + timeout)
#define el_setInterval(handler, arg, interval) el_push_task(handler, arg, interval, el_get_tick() + interval)

#define el_clearTimeout(task_id) el_cancel_task(task_id)
#define el_clearInterval(task_id) el_cancel_task(task_id)

#endif
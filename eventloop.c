#include "eventloop.h"

/* Task list */
static el_task_t task_list[EL_MAX_TASKS] = {0};

void el_enter_loop()
{
    while (1)
    {
        for (int i = 0; i < EL_MAX_TASKS; i++)
        {
            if (task_list[i].handler != NULL)
            {
                if (el_get_tick() >= task_list[i].run_at)
                {
                    task_list[i].handler(task_list[i].arg);
                    if (task_list[i].interval)
                    {
                        task_list[i].run_at = el_get_tick() + task_list[i].interval;
                    }
                    else
                    {
                        task_list[i].handler = NULL;
                    }
                } 

            }
        }
    }
}

el_task_id_t el_push_task(void (*handler)(void *arg), void *arg, el_tick_t interval, el_tick_t run_at)
{
    for (int i = 0; i < EL_MAX_TASKS; i++)
    {
        if (task_list[i].handler == NULL)
        {
            task_list[i].handler = handler;
            task_list[i].arg = arg;
            task_list[i].interval = interval;
            task_list[i].run_at = run_at;
            return &task_list[i];
        }
    }
    return NULL;
}

void el_cancel_task(el_task_id_t task_id)
{
    task_id->handler = NULL;
}

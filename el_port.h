/**
 * @file el_port.h
 * @author Yifan Xiao (1993996310@qq.com)
 * @brief Porting file for eventloop library
 * @version 0.1
 * @date 2023-04-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EL_PORT_H
#define EL_PORT_H

typedef unsigned long el_tick_t;
el_tick_t el_portTickGet(void);

#define EL_MAX_TASKS 24


#endif
/*************************************************************************
	> File Name: stack.h
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Sun 12 Jun 2016 11:53:01 AM CST
 ************************************************************************/
#ifndef __BT_STACK_HEADER
#define __BT_STACK_HEADER

#include "binary_tree.h"
#include <stdio.h>

#define BT_STACK_SIZE 100
#define BT_STACK_INCREMENT 50

typedef struct bt_stack_s{
	bt_tree * base;
	bt_tree * top;
	int   len;
}bt_stack_t;

void init_bt_stack(bt_stack_t * bt_stack);
void push(bt_stack_t * bt_stack,bt_tree  bt);
void pop(bt_stack_t  * bt_stack,bt_tree *bt);

int get_top(bt_stack_t bt_stack,bt_tree * bt);
int Empty_Stack(bt_stack_t bt_stack);
#endif

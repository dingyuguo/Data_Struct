/*************************************************************************
	> File Name: stack.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Sun 12 Jun 2016 10:49:04 AM CST
 ************************************************************************/

#include <stdio.h>
#include <memory.h>
#include "stack.h"

void init_bt_stack(bt_stack_t * bt_stack)
{
#if 0
	bt_stack = (bt_stack_t *)malloc(sizeof(bt_stack_t));
	MALLOC_CHECK(bt_stack);	
	memset(bt_stack,0,sizeof(bt_stack_t));
#endif

	//memset(bt_stack,0,sizeof(bt_stack_t));
	bt_stack->base = (bt_tree)malloc(sizeof(bt_node) * BT_STACK_SIZE);
	MALLOC_CHECK(bt_stack->base);
	memset(bt_stack->base,0,sizeof(bt_node) * BT_STACK_SIZE);
	
	bt_stack->top = bt_stack->base;
	bt_stack->len = BT_STACK_SIZE;

	printf("bt_stack Success!\n");
}

void push(bt_stack_t *bt_stack,bt_tree  bt)
{
	
	if(bt_stack->top - bt_stack->base >= bt_stack->len)
	{
		bt_stack->base = (bt_stack_t *)realloc(bt_stack->base,bt_stack->len + BT_STACK_INCREMENT);
		MALLOC_CHECK(bt_stack->base);

		bt_stack->top = bt_stack->base + bt_stack->len;
		bt_stack->len += BT_STACK_INCREMENT;
	}

	*(bt_stack->top) = bt;
	(bt_stack->top)++;

}

void pop(bt_stack_t * bt_stack,bt_tree * bt)
{
	if(bt_stack->top == bt_stack->base)
	{
		printf("Empty Stack!\n");
		exit(0);
	}

	bt_stack->top--;	
	*bt = *(bt_stack->top);

}

int  Empty_Stack(bt_stack_t bt_stack)
{
	return (bt_stack.top == bt_stack.base?1:0);
}

int  get_top(bt_stack_t bt_stack,bt_tree * bt)
{
	if(bt_stack.top == bt_stack.base)
		return 0;
	*bt = *(bt_stack.top - 1);
	
	return 1;
}




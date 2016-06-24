/*************************************************************************
	> File Name: binary_tree.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Mon 30 May 2016 12:04:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include "binary_tree.h"
#include "stack.h"

void  init_binary_tree(bt_tree * bt)
{
	bt_tree bt_tmp;

	bt_tmp = (bt_tree)malloc(sizeof(bt_node));
	MALLOC_CHECK(bt_tmp);
	memset(bt_tmp,0,sizeof(bt_node));
	
	*bt = bt_tmp;
	printf("init binary tree Success!\n");
}

int create_binary_tree(bt_tree * bt)
{
	char ch = 0;

	scanf("%c",&ch);
	getchar();
	if(ch == ' ')
	{
		*bt = NULL;
	}else
	{
		*bt = (bt_tree)malloc(sizeof(bt_node));
		MALLOC_CHECK(*bt);
		memset(*bt,0,sizeof(bt_node));

		(*bt)->data = (int)ch;
		
		create_binary_tree(&((*bt)->left_child));
		create_binary_tree(&((*bt)->right_child));


	}
	

	return 0;
}


//DLR
void pre_order_traverse(bt_tree * bt,traverse_func visit)
{
	static int i = 0;
	bt_tree bt_tmp = *bt;
	if(bt_tmp == NULL)
		return;

	i++;
//	visit("[ %d ]--->data = %c\n",i,bt_tmp->data);

	visit("%c",(*bt)->data);
	pre_order_traverse(&(bt_tmp->left_child),visit);
	pre_order_traverse(&(bt_tmp->right_child),visit);
}
//LDR
void in_order_traverse(bt_tree *bt,traverse_func visit)
{
	static int i = 0;

	if(*bt == NULL)
		return 0;
	
	in_order_traverse(&((*bt)->left_child),visit);
	
	i++;
	//visit("[ %d ]--->data = %c\n",i,(*bt)->data);

	visit("%c",(*bt)->data);
	in_order_traverse(&((*bt)->right_child),visit);
}
//LRD
void post_order_traverse(bt_tree *bt,traverse_func visit)
{
	static int i = 0;
	if(*bt == NULL)
		return 0;
	post_order_traverse(&((*bt)->left_child),visit);
	post_order_traverse(&((*bt)->right_child),visit);
	i++;
	//visit("[ %d ]--->data = %c\n",i,(*bt)->data);
	visit("%c",(*bt)->data);
}

//非递归遍历-1
void in_order_stack_traverse(bt_tree *bt,traverse_func visit)
{
	bt_stack_t bt_stack;
	bt_tree bt_tmp = *bt;
	
	
	init_bt_stack(&bt_stack);
	
	while(bt_tmp ||!Empty_Stack(bt_stack))
	{
		if(bt_tmp)
		{

			push(&bt_stack,bt_tmp);
			bt_tmp = bt_tmp->left_child;
		}else
		{

			pop(&bt_stack,&bt_tmp);
			visit("%c",bt_tmp->data);
			bt_tmp = bt_tmp->right_child;
		}
	}	
}
//DLR
void pre_order_stack_traverse(bt_tree *bt,traverse_func visit)
{
	bt_tree bt_tmp = *bt;
	bt_stack_t bt_stack;
	
	init_bt_stack(&bt_stack);

	while(bt_tmp || !Empty_Stack(bt_stack))
	{
		if(bt_tmp)
		{
			visit("%c",bt_tmp->data);
			push(&bt_stack,bt_tmp);
			bt_tmp = bt_tmp->left_child;
		}else
		{
			pop(&bt_stack,&bt_tmp);
			bt_tmp = bt_tmp->right_child;
		}
	}
}

/*LDR */
void in_order_stack_traverse_2(bt_tree *bt,traverse_func visit)
{
	bt_tree bt_tmp = *bt;
	bt_stack_t bt_stack;
	init_bt_stack(&bt_stack);
	push(&bt_stack,bt_tmp);

	while(!Empty_Stack(bt_stack))
	{
		while(get_top(bt_stack,&bt_tmp) && bt_tmp)
		{
			push(&bt_stack,bt_tmp->left_child);
		}
		pop(&bt_stack,&bt_tmp); //pop NULL
		
		if(!Empty_Stack(bt_stack))
		{
			pop(&bt_stack,&bt_tmp);
			visit("%c",bt_tmp->data);
			push(&bt_stack,bt_tmp->right_child);
		}
	}
}


bt_ops_t bt_ops = {
	.base_ops.init_tree		= init_binary_tree,
	.base_ops.create_tree	= create_binary_tree,
	.pre_order_traverse		= pre_order_traverse,
	.in_order_traverse		= in_order_traverse,
	.post_order_traverse	= post_order_traverse,
};




void traverse_bt(bt_tree bt,void * (*push)(bt_stack_t *  ,bt_tree ),bt_stack_t * bt_stack)
{
	if(bt == NULL)
		return ;
	push(bt_stack,bt);
	traverse_bt(bt->left_child,push,bt_stack);
	traverse_bt(bt->right_child,push,bt_stack);
}

int  main()
{
	bt_tree bt = NULL;
	bt_tree bt_tmp = NULL;
	bt_stack_t bt_stack;
	bt_ops.base_ops.init_tree(&bt);
	
	printf("Input Data: ");
	bt_ops.base_ops.create_tree(&bt);
	printf("Success!\n");

#if 0
		
	init_bt_stack(&bt_stack);
	traverse_bt(bt,push,&bt_stack);

	bt_tmp = (bt_tree)malloc(sizeof(bt_node));
	MALLOC_CHECK(bt_tmp);
	memset(bt_tmp, 0 ,sizeof(bt_node));
	
	while(bt_stack.top - bt_stack.base)
	{
		pop(&bt_stack,&bt_tmp);
		if(bt_tmp)
			printf("%c\n",bt_tmp->data);
	}

#else
	printf("先序遍历\n");
	bt_ops.pre_order_traverse(&bt,printf);
	printf("\n\n");
	printf("中序遍历\n");
	bt_ops.in_order_traverse(&bt,printf);
	printf("\n\n");
	printf("后序遍历\n");
	bt_ops.post_order_traverse(&bt,printf);
	printf("\n\n");
	printf("非递归中序遍历-1\n");
	in_order_stack_traverse(&bt,printf);
	printf("\n\n");
	printf("非递归前序遍历-1\n");
	pre_order_stack_traverse(&bt,printf);
	printf("\n\n");
	printf("非递归中序遍历-2\n");
	in_order_stack_traverse_2(&bt,printf);

#endif
	printf("\n\n");
	return 0;
}
















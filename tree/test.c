/*************************************************************************
	> File Name: test.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Wed 29 Jun 2016 10:38:57 AM CST
 ************************************************************************/

#include<stdio.h>
#include"binary_tree.h"
#include "queue.h"
#include "stack.h"
#include "thread_binary_tree.h"
char * pre	= "GDAFEMHZ";
char * in	= "ADEFGHMZ";
char * post = "AEFDHZMG";

int test_creat_bt()
{
	bt_tree bt  = NULL;
	bt_tree bt_2 = NULL;
	
	bt = pre_in(pre,in,strlen(pre));
	bt_ops.pre_order_traverse(&bt,printf);

	printf("\n");
	bt_2 = post_in(post,in,strlen(post));

	bt_ops.pre_order_traverse(&bt,printf);
	
	printf("\n");	
	return 0;
}

int  test_binary_tree()
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
	printf("\n\n层次遍历：\n");
	bt_ops.level_order_traverse(&bt,printf);
#endif
	printf("\n\n");
	return 0;
}

int test_thread_tree()
{
	thr_bt_t thr_bt = NULL;
	thr_bt_t thr_bt_head = NULL;

	create_thr_bt(&thr_bt);

	in_order_threading(&thr_bt_head,thr_bt);
	
	printf("遍历线索二叉树:\n");
	traverse_list(thr_bt_head);
	printf("\n");	
	return 0;
}



int main()
{
	test_creat_bt();
	test_binary_tree();
	test_thread_tree();
	return 0;
}

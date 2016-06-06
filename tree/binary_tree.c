/*************************************************************************
	> File Name: binary_tree.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Mon 30 May 2016 12:04:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include "tree.h"

typedef struct binary_tree_ops_s{
	tree_common_ops_t base_ops;

	void (*pre_order_traverse)(void **tree,void (*visit)(void *, ...));
	void (*in_order_traverse)(void **tree,void(*visit)(void *,...));
	void (*post_order_traverse)(void **tree,void(*visit)(void *,...));
	void (*level_order_traverse)(void **tree,void(*visit)(void *,...));
}bt_ops_t;
/*binary tree data type declation*/
typedef struct binary_tree_s{
	int data;
	struct binary_tree_s *parent;
	struct binary_tree_s *left_child;
	struct binary_tree_s *right_child;
}bt_node;

typedef bt_node * bt_tree;


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




#if 0
void in_order_stack(bt_tree ** bt,traverse_func visit)
{
	bt_tree bt_tmp = *bt;
	
	while(bt_tmp)
	{
		push(bt_stack,bt_tmp->left_child);
		bt_tmp = bt_tmp->left_child;
	}

}
#endif

bt_ops_t bt_ops = {
	.base_ops.init_tree		= init_binary_tree,
	.base_ops.create_tree	= create_binary_tree,
	.pre_order_traverse		= pre_order_traverse,
	.in_order_traverse		= in_order_traverse,
	.post_order_traverse	= post_order_traverse,
};

int  main()
{
	bt_tree bt;
	bt_ops.base_ops.init_tree(&bt);
	
	bt_ops.base_ops.create_tree(&bt);
	printf("先序遍历\n");
	bt_ops.pre_order_traverse(&bt,printf);
	printf("\n\n");
	printf("中序遍历\n");
	bt_ops.in_order_traverse(&bt,printf);
	printf("\n\n");
	printf("后序遍历\n");
	bt_ops.post_order_traverse(&bt,printf);

	printf("\n\n");
	return 0;
}
















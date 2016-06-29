/*************************************************************************
	> File Name: thread_binary_tree.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Tue 14 Jun 2016 04:33:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "stack.h"
#include "thread_binary_tree.h"

void print_bt_data(thr_bt_t tree)
{
	printf("%c",tree->data);
}
void init_thr_bt(thr_bt_t *thr_bt_head)
{
	thr_bt_t head = *thr_bt_head;

	head = (thr_bt_t)malloc(sizeof(thr_bt_node_t));
	MALLOC_CHECK(head);
	memset(head,0,sizeof(thr_bt_node_t));
	/*just for test*/
	head->data = 'd';
	*thr_bt_head = head;
}
//DLR
void create_thr_bt(thr_bt_t * thr_bt)
{
	char data;

	scanf("%c",&data);
	getchar();

	if(data == ' ')
	{
		*thr_bt = NULL;
	}else
	{
		*thr_bt = (thr_bt_t)malloc(sizeof(thr_bt_node_t));
		MALLOC_CHECK(*thr_bt);
		memset(*thr_bt,0,sizeof(thr_bt_node_t));
		
		(*thr_bt)->data = data;
		
		create_thr_bt(&((*thr_bt)->left));
		create_thr_bt(&((*thr_bt)->right));
	}
}


void in_threading(thr_bt_t * p,thr_bt_t *pre)
{
	if(*p)
	{
		in_threading(&((*p)->left),pre);
		
		if(!((*p)->left))
		{
			(*p)->left		= *pre;
			(*p)->left_tag	= THREAD;
		}

		if(!((*pre)->right))
		{
			(*pre)->right		= *p;
			(*pre)->right_tag	= THREAD;
		}

		*pre = *p;

		in_threading(&((*p)->right),pre);
		
	}

}





/*按中序线索化*/
void in_order_threading(thr_bt_t *thr_bt_head,thr_bt_t thr_bt)
{
	thr_bt_t pre = thr_bt;
	(*thr_bt_head) = (thr_bt_t )malloc(sizeof(thr_bt_node_t));
	MALLOC_CHECK(*thr_bt_head);

	(*thr_bt_head)->left_tag	= LINK;
	(*thr_bt_head)->right_tag	= THREAD;
	(*thr_bt_head)->left		= thr_bt;
	
	if(!thr_bt)
	{
		(*thr_bt_head)->right	= *thr_bt_head;
	}else
	{
		pre = *thr_bt_head;
		in_threading(&((*thr_bt_head)->left),&pre);
		pre->right_tag = THREAD;
		pre->right = *thr_bt_head;
		(*thr_bt_head)->right = pre;
	}


}


void traverse_list(thr_bt_t thr_bt_head)
{
	thr_bt_t p = thr_bt_head->left;
	while(p != thr_bt_head)
	{
		while(p->left_tag == LINK)
			p = p->left;
		printf("%c",p->data);
		while(p->right_tag == THREAD && p->right != thr_bt_head)
		{
			p = p->right;
			printf("%c",p->data);
		}
		p = p->right;
	}
//	return 0;
}




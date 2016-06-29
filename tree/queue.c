/*************************************************************************
	> File Name: queue.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Tue 28 Jun 2016 01:40:14 PM CST
 ************************************************************************/

#include <stdio.h>
#include "queue.h"

//#define bt_tree int	//just for test

void init_queue(queue_t *q)
{
	q->front = (queue_node_t *) malloc(sizeof(queue_node_t));
	MALLOC_CHECK(q->front);
	memset(q->front,0,sizeof(queue_node_t));
	q->rear = q->front;
	q->len = 0;
}

void en_queue(queue_t *q,bt_tree  bt)
{
	queue_node_t * new_q = NULL;

	new_q = (queue_node_t *)malloc(sizeof(queue_node_t));
	MALLOC_CHECK(new_q);
	memset(new_q,0,sizeof(queue_node_t));

	new_q->bt = bt;
	new_q->next = NULL;
	q->rear->next = new_q;
	q->rear = new_q;
	q->len += 1;
}

int is_empty_queue(queue_t * q)
{
	return (q->front == q->rear)?1:0;
}

void de_queue(queue_t * q,bt_tree * bt)
{
	queue_node_t * p = q->front->next;

	if(is_empty_queue(q))
		return ;

	*bt = p->bt;
	q->front->next = p->next;

	if(q->rear == p)
		q->rear = q->front;
	free(p);
	q->len -= 1;
}






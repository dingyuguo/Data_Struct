/*************************************************************************
	> File Name: queue.h
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Tue 28 Jun 2016 02:47:17 PM CST
 ************************************************************************/
#ifndef __QUEUE_HEADER__
#define __QUEUE-HEADER__
#include"binary_tree.h"


typedef struct queue_node_s{

	bt_tree bt;
	struct queue_node_s *next;
}queue_node_t;

typedef struct queue_s{
	queue_node_t  * front;
	queue_node_t  * rear;
	int		len;
}queue_t;


/*function declaration*/
void init_queue(queue_t *q);
void en_queue(queue_t *q,bt_tree  bt);
int is_empty_queue(queue_t  * q);

void de_queue(queue_t * q,bt_tree * bt);

























#endif

/*************************************************************************
	> File Name: thread_binary_tree.h
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Tue 14 Jun 2016 04:23:04 PM CST
 ************************************************************************/
#ifndef __THREAD_BINARY_TREE_HEADER__
#define __THREAD_BINARY_TREE_HEADER__

typedef enum {
	LINK,
	THREAD,
}Pointer_tag;

typedef struct thread_bt_s{
	char data;
	Pointer_tag	left_tag,right_tag;
	struct thread_bt_s *left,*right;
}thr_bt_node_t;
typedef thr_bt_node_t * thr_bt_t;
#define MALLOC_CHECK(p)  if(!p)	\
						 {		\
							 printf("%s--%d:\tmalloc faild!",__func__,__LINE__); \
							 exit(0);	\
						 }	



















































#endif

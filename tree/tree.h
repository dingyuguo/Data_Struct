/*************************************************************************
	> File Name: tree.h
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Mon 30 May 2016 11:35:35 AM CST
 ************************************************************************/
#ifndef _TREE_HEADER
#define _TREE_HEADER
#include <stdio.h>
#include <memory.h>

#define MALLOC_CHECK(p)  if(!p)	\
						 {		\
							 printf("%s--%d:\tmalloc faild!",__func__,__LINE__); \
							 exit(0);	\
						 }	
typedef void (*traverse_func)(void * para,...);
typedef struct tree_common_ops_s{
	/*base ops*/
	void 	(*init_tree)(void ** tree);
	void	(*destory_tree)(void *tree);
	void	(*create_tree)(void **tree);
	void	(*clear_tree)(void *tree);
	int 	(*tree_empty)(void tree);//empty = TRUE;else = FALSE
	int		(*tree_depth)(void tree);
	void *	(*root)(void tree);
	void	(*value)(void tree,void cur_e);//return the value of "cur_e" node
	void	(*assign)(void *tree,void cur_e,void value);
	void *	(*parent)(void tree,void cur_e);
	void *	(*left_child)(void tree,void cur_e);
	void *	(*right_child)(void tree,void cur_e);
	void *	(*insert_child)(void *tree,void *p,void i,void c);//tree exist,p is the node of tree,c is unempty tree;
	void	(*delete_child)(void *tree,void *p,void i);
	void	(*traverse_tree)(void tree,traverse_func visit);
}tree_common_ops_t;












































#endif


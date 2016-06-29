/*************************************************************************
	> File Name: creat_bt.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Tue 28 Jun 2016 05:30:08 PM CST
 ************************************************************************/
/*Base DLR,LDR,LRD queue ,create  a binary_tree*/
/*Note :									*/
/*		DLR && LDR							*/
/*		LDR && LRD							*/
/*	DLR && LRD can not create a binary_tree	*/

#include <stdio.h>
#include <string.h>
#include "binary_tree.h"



bt_tree pre_in(char * pre,char *in,int len)
{
	bt_tree bt		= NULL;
	int root_pos	= 0;
	
	if(len > 0)
	{
		bt = (bt_tree )malloc(sizeof(bt_node));
		MALLOC_CHECK(bt);
		memset(bt,0,sizeof(bt_node));
		bt->data = pre[0];
#if 1
		for(root_pos = 0;root_pos < len;root_pos++)
		{
			if(pre[0] == in[root_pos])
				break;
		}
#else
		while(pre[0] != in[root_pos++]);
		root_pos--;
#endif
		bt->left_child  = pre_in(&pre[1],in,root_pos);
		bt->right_child = pre_in(&pre[root_pos+1],&in[root_pos + 1],len - root_pos - 1);
	}
	return bt;
}

bt_tree post_in(char * post, char * in,int len )
{
	int root_pos	= 0;
	bt_tree bt		= NULL;
	
	if(len > 0)
	{
		bt = (bt_tree )malloc(sizeof(bt_node));
		MALLOC_CHECK(bt);
		memset(bt,0,sizeof(bt_node));

		bt->data = post[len - 1];
	
		while(post[len - 1] != in[root_pos++]);
		root_pos--;

		bt->left_child	= post_in(post,in,root_pos);
		bt->right_child = post_in(&post[root_pos],&in[root_pos + 1],len - root_pos - 1);
	}
	return bt;
}


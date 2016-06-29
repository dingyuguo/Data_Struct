/*************************************************************************
	> File Name: ploynomial.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Wed 29 Jun 2016 05:23:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include"ploynomial.h"
#include<memory.h>

#define MALLOC_CHECK(p)  if(!p)	\
						 {		\
							 printf("%s--%d:\tmalloc faild!",__func__,__LINE__); \
							 exit(0);	\
						 }	

void init_ploy(ploy_t * p)
{
	memset(p,0,sizeof(ploy_t));
}

void create_ploy(ploy_t *p)
{
	int len  = 0;
	ploy_t *q = p;
	printf("Enter the num: ");
	scanf("%d",&len);
	getchar();
	
	while(len--)
	{
		q->next = (ploy_t *) malloc(sizeof(ploy_t));
		MALLOC_CHECK(q);
		memset(q->next,0,sizeof(ploy_t));
		
		q = q->next;
		
		scanf("%d%d",&(q->coef),&(q->exp));
		getchar();

	}
	printf("Input Done!\n");
}

void print_ploy(ploy_t p)
{
	ploy_t *q = p.next;

	printf("y = ");
	while(q)
	{
		if(q->coef)
		{
			if(q->coef != 1)
				printf("%d",q->coef);
			
			if(q->exp == 1)
				printf("x");
			else
				printf("x^%d",q->exp);
		}
		q = q->next;
		if(q)
			printf(" + ");
	}
	printf("\n");

}



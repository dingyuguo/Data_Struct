/*************************************************************************
	> File Name: test.c
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Wed 29 Jun 2016 05:51:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include"ploynomial.h"

int main()
{
	ploy_t A;
	ploy_t B;
	ploy_t *p = NULL;
	init_ploy(&A);
	init_ploy(&B);
	create_ploy(&A);

	print_ploy(A);
#if 0
	p = A.next;

	while(p)
	{
		printf("%d\n",p->coef);	
		p = p->next;
	}
#endif
	return 0;
}



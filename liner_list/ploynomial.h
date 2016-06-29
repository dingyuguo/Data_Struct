/*************************************************************************
	> File Name: ploynomial.h
	> Author: laoding
	> Mail: dyg1993@foxmail.com 
	> Created Time: Wed 29 Jun 2016 05:23:27 PM CST
 ************************************************************************/
#ifndef __PLOYNOMIAL_HEADER__
#define __PLOYNOMIAL_HEADER__
#include <stdio.h>


typedef struct ploy_s{

	int coef;
	int exp;
	struct ploy_s *next;
}ploy_t;













#endif

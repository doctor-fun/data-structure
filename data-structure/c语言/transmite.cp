//
//  main.cpp
//  1
//
//  Created by 晨 方 on 2017/11/22.
//  Copyright © 2017年 晨 方. All rights reserved.
//


#include<iostream>
#include <stdio.h>
using namespace std;

int i=0;
int main(void)
{
    char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int c[64],d,i=0,base;
    long n;
    printf("enter a number:\n"); scanf("%ld",&n);
    printf("enter new base:\n"); scanf("%d",&base);
    do{
        c[i]=n % base;
        i++;n=n / base;
    }   while(n!=0);
        printf("transmite new base: \n");
    for(--i;i>=0;--i)
    {
        d=c[i];
        printf("%c",b[d]);
        (i!=0)?printf(" "):printf("\n");
        
    }
    return 0;
}


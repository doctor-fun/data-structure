//
//  main.cpp
//  debug.cc
//
//  Created by 晨 方 on 2018/1/8.
//  Copyright © 2018年 晨 方. All rights reserved.
//
#include <stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,sum,temp;
    int i=0;
    scanf("%d %d",&a,&b);
    sum=a+b;
    temp=sum;
    while(temp!=0)
    {
        temp=temp/10;
        ++i;
    }
    if(i<=3)
    {
        printf("%d",sum);
    }
    else if(i>3&&i<=6)
    {
        int kilo_plus,temp_2=sum;
         int kilo_down=0;
        kilo_plus=temp_2/1000;
        cout<<kilo_plus<<',';
        temp_2=fabs(temp_2);
        for(int k=0;k<3;k++)
        {
            int c;
            c=temp_2%10;
            temp_2=temp_2/10;
            kilo_down=kilo_down+c*pow((double)10,(double)k);
        }
        cout<<kilo_down;
    }
    else if(i>6)
    {
        int temp_2=sum;
        char str[7]={0};
        if(temp_2<0)
        {
            cout<<'-';
            temp_2=fabs(temp_2);
        }
        sprintf(str,"%d",temp_2);
        for(int k=0;k<7;k++)
        {
            (k==1||k==4)?(printf(",%c",str[k])):(printf("%c",str[k]));
        }
     
    }
 
    
    
    return 0;
}

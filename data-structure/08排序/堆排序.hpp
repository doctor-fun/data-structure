//
//  堆排序.hpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/9.
//  Copyright © 2017年 晨 方. All rights reserved.
//



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100;
vector<int> heap(maxn);//容器

int n=10;//元素值
//插入一个结点所涉及的操作
//将元素放在末尾，然后进行向上调整
void upadjust(int low,int high){
    int i=high,j=i/2;//此时high就是欲向上调整的结点，j为它的父亲；
    while(j>low)
    {
     if(heap[j]<heap[i])
     {
         swap(heap[j],heap[i]);
         i=j;
         j=i/2;
     }
     else{
         break;
     }
        
    }
    
    
    
}
void heap_insert(int x)
{
    heap[++n]=x;
    upadjust(1,n);
    
    
}
void downadjust(int low,int high)
{
    int i=low,j=i*2;
    while(j<=high)
    {
        if(j+1<=high && heap[j+1]>heap[j])//j+1为右孩子，j为左孩子,j+1<=high说明右孩子存在(因为是完全二叉树)
        {
            j=j+1;//游标指向右孩子;
        }
        //孩子结点权值大于父结点权值，则需要交换，将较大的值传到上面来
        if(heap[j]>heap[i])
        {
            swap(heap[j],heap[i]);
            i=j;//(继续准备向下层进行比较)
            j=i*2;
        }
        else{
            break;
        }
    }
}
void delete_top()
{
        heap[1]=heap
    
    
    
}
void create_heap(int n)
{
    for(int i=n/2;i>=1;i--)
    downadjust(i,n);
}

void heapSort()
{
    create_heap(10);
    for(int i=10;i>1;i--)
    {
        swap(heap[1],heap[i]);
        downadjust(1,i-1);
        
    }
    
    
}




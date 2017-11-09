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
//插入一个元素所涉及的操作：
//将插入元素放在末尾，然后进行向上调整
//插入一个结点，不知道它是大是小，但被放在最底层，则需要和它的父亲进行比较
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
    heap[++n]=x;//先将size——n+1，后将欲插入的结点放到最后
    upadjust(1,n);//向上调整
}


//删除最大值后会将最底层的结点拿上来，所以需要向下调整算法
void downadjust(int low,int high)//取左右儿子里面较大的儿子与
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
void delete_top()//删除堆顶元素，把heap[n]拿上来，需要将heap[n]向下走一条路径，这条路径是和自己的子孙中较大值不断进行替换形成的
{
    heap[1]=heap[n--];//将完全二叉树最后一个元素替换堆顶元素，然后将堆顶元素向下调整
    downadjust(1,n);
    
    
}
void create_heap(int n)
{
    for(int i=n/2;i>=1;i--)
    downadjust(i,n);
}

void heapSort()
{
    create_heap(n);
    for(int i=n;i>1;i--)
    {
        swap(heap[1],heap[i]);
        downadjust(1,i-1);
    }
}




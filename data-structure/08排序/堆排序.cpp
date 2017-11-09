//
//  堆排序.hpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/9.
//  Copyright © 2017年 晨 方. All rights reserved.
//


//堆排序的前提是已经有一个数组，一旦有了一个数组，那么完全二叉树的所有结点的基础位序就确定了，后面直接进行多轮调整就可以了

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxn=100;

vector<int> heap(maxn);//容器

int n=10;//元素个数
//插入一个元素所涉及的操作：
//将插入元素放在末尾，然后进行向上调整
//插入一个结点，不知道它是大是小，当被放在最底层，则需要和它的父亲进行比较
void upadjust(int low,int high){
    int i=high,j=i/2;//此时high就是欲向上调整的结点，j为它的父亲；
    while(j>=low)
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
void heap_insert(int x)//加入了一个元素后，还得保证是堆
{
    heap[++n]=x;//先将size——n+1，后将欲插入的结点放到最后
    upadjust(1,n);//向上调整
}


//删除最大值后会将最底层的结点拿上来，所以需要向下调整算法
void downadjust(int low,int high)//取左右儿子里面较大的儿子与自己做swap
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
void create_heap(int n)//由于刚开始完全二叉树每一颗子树都不是堆，
//所以采用分治的方法，将最小规模的子树先调成堆，最合适的最小规模子树即为n/2,n这颗由两个结点组成的子树，小规模向大规模聚集，最终将整颗树调整成堆
{
    for(int i=n/2;i>=1;i--)
    downadjust(i,n);
}

void heapSort()
{
    create_heap(n);//建立好堆后，则每个子树都是最大堆，在此基础上开始排序
    for(int i=n;i>1;i--)
    {
        swap(heap[1],heap[i]);//将根结点heap[1]（此时根结点最大）放到数组最右边
        downadjust(1,i-1);//将堆的规模缩小一个
    }
}
int main()
{
//这里是获得初始数据
    int random_elem;
    srand((int)time(NULL));
    for(int i=1;i<=n;i++)
    {
        random_elem=rand()%100;
      // heap.push_back(random_elem);
        heap[i]=random_elem;
    }
    for(int j=1;j<=n;j++)
    {
        cout<<heap[j]<<" ";
        
    }
    cout<<"原始数据读入成功"<<endl;
//这里是建堆等到操作
    
    create_heap(n);
    for(int j=1;j<=n;j++)
    {
        cout<<heap[j]<<" ";
        
    }
    cout<<"建堆成功"<<endl;
//这里是删除操作
    delete_top();
   
    for(int j=1;j<=n;j++)
    {
        cout<<heap[j]<<" ";
        
    }
    cout<<"删除了根结点"<<endl;
//这里是排序操作
    heapSort();
    for(int j=1;j<=n;j++)
    {
        cout<<heap[j]<<" ";
        
    }
    cout<<"堆排序操作"<<endl;
    
    
    return 0;
    
    
}




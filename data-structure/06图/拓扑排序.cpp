//
//  拓扑排序.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/13.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include "拓扑排序.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn=100;
//拓扑排序：
//所有入度为0点结点入队，
//开始处理第一个入度为0的结点：从队中取出，并在队中删除这个结点，
//接着将它的邻接点的入度全部先减一，减1后，某个领结点的入度从1变成0，则将这个邻接点也入队。
//处理完第一个入度为0的结点后，开始处理第二个邻接点，以此类推
//常用于判断有向无环图
//拓扑是研究几何图形或空间在连续改变形状后还能保持不变的一些性质的一个学科。它只考虑物体间的位置关系而不考虑它们的形状和大小。
vector<int> G[maxn];//领接表统计入度
int n,indegree[maxn];//所有的结点的入度在算法开始前都应该已经计算好了的
//n 表示图的实际结点数
bool topologiscalSort()
{
    int num=0;
    queue<int> q;
    
    //刚开始，所有结点都未入过队，所以第一轮先将所有入度为0的结点入队
    for (int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)//队首结点的领接结点的处理过程；
        {
            int v=G[u][i];
            indegree[v]--;//因为所有的0入度结点都已经在此步之前入队，所以这里不会出现它的领接结点入度为0的情况
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
        G[u].clear();//将处理完的结点在领结表中删除
        num++;//要注意这个在while里面，每处理完一个结点做好删除和记录工作
    }
    if(num==n) return true;
    else return false;
}

//
//  最小生成树.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/14.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include<iostream>
#include <queue>
using namespace std;

//与dijkstra算法除了dist[]的定义不同外，其他一致，dijkstra算法的dist定义的是start到当前点的当下最短距离，而最小生成树定义的dist是当前集合到集合外未访问结点的最短距离
//图必须是联通的，连通图肯定有最小生成树
//正好用掉v-1条边
//不能有回路
//用图里有的边
//(1)任选根结点
//(2)边权最小的边连起来（树外）
//（3）以这颗树所有顶点为根集合，找到距离最近的邻接点
//（4）已经在最小生成树集合内的顶点不能再相互连接
//需要三个临时变量,ans,u,和min
const int maxn=1000;
const int INF=1000000000;
int n;
int G[maxn][maxn];
int dist_set[maxn];
bool had_visited[maxn]={false};
int prim()
{
    fill(dist_set,dist_set+maxn,INF);
    dist_set[0]=0;//根结点设定为编号为0的结点
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)
        {
                if(had_visited[j]==false && dist_set[j]<MIN)
                {
                    u=j;
                    MIN=dist_set[j];
                }
        }
        if(u==-1) return -1;
        had_visited[u]=true;
        ans+=dist_set[u];//将这条边加进最小生成树的边权之和当中；
        for(int v=0;v<n;v++)
        {
            //v未被访问，u到v的距离不为inf,表示u到v有路径可达，
            if(had_visited[v]==false && G[u][v]!=INF && G[u][v]<dist_set[v])
                dist_set[v]=G[u][v];
        }
            
        
    }
    return ans;
    
    
}

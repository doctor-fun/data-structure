//
//  最小生成树.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/14.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include<iostream>
#include <queue>
//prim的教材书上算法：核心，每轮从当前轮中找到，dist中最小的的destination_point的下标i，放进_has_found_least[]标记数组中（_has_found_least[i]=1），
//表示源点到此点的最短路径已经找到.(原理：如果在下一轮时，源点到这个min点的距离还可以进行更新，即仍然有比当前轮更短的（源点到min点）的距离，
//那么它一定是通过当前轮的兄弟结点作为中介抵达这个min点的，而源点到兄弟结点（min点的）的最短距离已经大于源点到min点的距离，
//如果再加上兄弟结点到min点的距离更加大于前一轮中源点到min点的距离了)

//prim适用于稠密图
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


//稀疏图
kruskal(int n,int m)
//先找权重最小的边都收进来，将这些边对应的顶点合成森林，刚开始权值最小的边为0，一个顶点即为一颗树
//如果权重最小的边加进来与森林构成回路，则舍弃它，取次小值
//直到边的数目=顶点数目-1；


//用最小堆来存储各种边
//用并查集来判断新进来的边是否与森林属于同一个集合（构成回路）


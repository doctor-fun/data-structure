//
//  图.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/11.
//  Copyright © 2017年 晨 方. All rights reserved.
//
//dfs每次都是沿着路径到不能再前进时才退回到最近的岔路口（前进过程中选择哪个结点进行前进？顺时针第一个，或者领接表第一个）
#include "图.hpp"
#include <vector>
using namespace std;
struct node{
    
    int v;//边的终点编号
    int w;//边权
    node(int _v,int _w):
    v(_v),w(_w)
    {
        
    }
};
const int maxv=1000;
const int inf=1000000000;
//领接表版本

int n,G[maxv][maxv];//顶点数和邻接表
//一般设置一个领接表和访问标记数组
//给定一个行标u，表示想要访问这个u结点的领接结点，进行此结点这一行整行扫描（出度）
//入度的话扫描的是某一整列

bool is_visited[maxv]={false};//所有结点的被访问标记刚开始都为false，如果被访问，则会被标记为ture
void Dfs(int u,int depth)//u为当前所想要访问的结点
{
    is_visited[u]=true;
    for(int v=0;v<n;v++)
    {
     if(is_visited[v]==false && G[u][v]!=inf)//从这里可以看出行标是不变的
     {
         Dfs(v,depth+1);
     }
    }
}
void Dfstrave(){
    for(int u=0;u<n;u++)
    {
        if(is_visited[u]==false){
            Dfs(u,1);
        }
    }
}
/*
// 领接表版本
vector<int> adj[maxv];
int n;
bool Is_Visited[maxv]={false};
void Dfs(int u,int depth)
{
     Is_Visited[u]=true;
     for(int i=0;i<adj[u].size();i++)
     {
         int v=adj[u][i];
         if(Is_visted[v]==false)
         {
             Dfs(v,depth+1);
         }
     }
}
 void Dfstrave()
 {
     for(int u=0;u<n;u++)
     {
         if(Is_visited[u]==false)
         {
             Dfs(u,1);
         }
     }
}

*/


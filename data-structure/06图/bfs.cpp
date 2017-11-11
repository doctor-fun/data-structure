//
//  bfs.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/11.
//  Copyright © 2017年 晨 方. All rights reserved.
//


#include <queue>
#include <vector>
using namespace std;
const int maxn=100;
const int inf=10000000;

//bfs规则：（因为没办法确定整个图是个联通图，所以光遍历根结点是不够的，需要DFS整个图所有结点）（每次dfs都会遍历完一个联通块）
//入队的结点有两个要求：
//1）是当前访问结点的出度
//2）从未入过队
//队列为空时，访问结束

/*
//同样需要一个标记数组，标记所有结点是否进入过队
int n, G[maxn][maxn];
bool have_in_queue[maxn]={false};//建立标记数组
void BFS(int u)//u一般是根结点
{
    queue<int> q;//建队
    q.push(u);//根结点进队
    have_in_queue[u]=true;//根结点进队
    while(!q.empty())
    {
        int front=q.front();//取队首结点
        q.pop();//弹出队首结点
        for(int v=0;v<n;v++)//将队首结点所在行的所有出度（且未曾过队）的结点进队，并将这些结点进队标记置为true
        {
            if(have_in_queue[v]==false && G[front][v]!=inf)
            {
                q.push(v);
                have_in_queue[v]=true;
            }
        }
    }
}
void bfstrave()
{
    for(int u =0;u<n;u++)
    {
        if (have_in_queue[u]==false)
        {
            BFS(u);//遍历u所在的连通快
        }
    }
}
 */
/*
//这个是领接表版本
vector<int> adj[maxn];//建图
int n;
bool had_in_queue[maxn];
void BFS(int u){
    queue<int> q;
    q.push(u);
    had_in_queue[u]=true;
    for(int v=0;v<adj[u].size();v++)
    {
        if(had_in_queue[v]==false)
        {
            q.push(v);
            had_in_queue[v]=true;
        }
    }
}
void BFStrave()
{
    for (int u=0;u<n;u++)
    {
            if(had_in_queue[u]==false)
            {
                BFS(u);
            }
    }
}
*/
struct node{
    int v;//顶点编号
    int layer;
};
const int n=100;//这里的n要加个const 不然编译器会报错
vector<node> adj[n];
bool had_in_queue[n]={false};
void BFS(int s)//s为起始顶点的变编号
{
    queue<node> q;
    
    node start;
    start.v=s;
    start.layer=0;
    
    q.push(start);
    had_in_queue[start.v]=true;
    while(!q.empty())
    {
        node topnode=q.front();
        q.pop();
        int u=topnode.v;
        for(int i=0;i<adj[u].size();i++)
        {
            node next=adj[u][i];
            next.layer=topnode.layer+1;
            if(had_in_queue[next.v]==false)
            {
                q.push(next);
                had_in_queue[next.v]=true;
            }
        }
    }
}
    
    
    
    
    
    



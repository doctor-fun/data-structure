//
//  最短路径.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/13.
//  Copyright © 2017年 晨 方. All rights reserved.
//

//单源最短路径问题
//dijkstra的教材书上算法：核心，每轮从当前轮中找到，dist[](&& _has_found_least[]==0)中最小的的destination_point的下标i，放进_has_found_least[]标记数组中（_has_found_least[i]=1），
//表示源点到此点的最短路径已经找到.(原理：如果在下一轮时，源点到这个min点的距离还可以进行更新，即仍然有比当前轮更短的（源点到min点）的距离，
//那么它一定是通过当前轮的兄弟结点作为中介抵达这个min点的，而源点到兄弟结点（min点的）的最短距离已经大于源点到min点的距离，
//如果再加上兄弟结点到min点的距离更加大于前一轮中源点到min点的距离了)
 //----------------------------------------------------------------------------------------
//最短路径最关键的就是a与b,c,d,e形成一个星型结构，但是b与c又有路径，a直接到c的距离未必比a->b->c的距离小，因此始终要实时更新a->...->c点的距离,与之前的距离做对比
//先将start自己到自己的路径长度设为0，再更新start到附近邻接点的距离（start到所有邻接点，而不是中介点到邻接点的距离），与之前的距离进行对比，较小的话进行替换，
//最后选择其中start到邻接点中距离最小的点继续往下访问，

//最短路径一般表示起始点到此点（编号）所经过的路径上的最小结点数、或者边权和，这里表示边权和，如果没有路，就为INF
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000;
const int INF=1000000000;

struct node{
    int v;
    int weight;
};

vector<node> adj[maxn];

int n;
int dist[maxn];//起点到达各点的路径长度，刚开始整个组都是一个极大值
bool had_visited[maxn]={false};
void dijkstra(int start)//dijkstra算法入口为起始点的序号
{
    fill(dist,dist+maxn,INF);//填充函数
    dist[start]=0;//起始点到自己的距离为0边权
    for (int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;//u表示最小结点的下标，刚开始为无:（-1）
        for(int j=0;j<n;j++)
        {
            //检查没被访问过的结点中到start点距离最小的点
            if(had_visited[j]==false && dist[j]<MIN)
            {
                u=j;
                MIN=dist[j];
            }
        }
        if(u==-1) return;//如果u=-1表示无，退出
        //刚开始第一轮循环肯定有一个<min的结点，那就是start结点
        had_visited[u]=true;
            
        for(int k=0;k<adj[u].size();k++)//将这个最小点的邻接点遍历
        {
            int v=adj[u][k].v;//获得邻接点的编号
            if(had_visited[v]==false && dist[v]>dist[u]+adj[u][k].weight)//如果start点到此邻居之前的路径距离比（dist[u]+此邻接点权值）要大，说明到经过u点到此邻接点的这条新路径比
                //原来的不经过u点到此领结点点距离要短
            {
                dist[v]=dist[u]+adj[u][k].weight;//将start点到此邻接点的距离更新
            }
        }
        
    }
 }
}

floyed//多源最短路径
//遍历所有结点，为每个结点生成到其他结点最短路径，
//生成一条最短路径的过程既是路过1，路过1，2，路过1，2，3，路过1,2,3,.....这些点抵达目标点的最短路径的递推（搜寻）过程
//从经过结点集合1，2，3...k-1到达目标结点的最短路径递推到1,2,3...k多一个k点的以后，
//如果源点经过1，2，3...k这个集合到达目标结点的最短路径中不包含k结点，则D^k=D^k-1
//如果k点是在最短路径，则该最短路径必为两个最短路径之和
Dk[i][j]=Dk-1[i][k]+Dk-1[k][j]


void floyd()
{
    for(int i =0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            D[i][j]=G[i][j];//最短路径的初始矩阵为图的邻接矩阵
            path[i][j]=-1;
        }
    for(k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(D[i][k]+D[k][j]<D[i][j])
            {
                D[i][j]=D[i][k]+D[k][j];
                path[i][j]=k;
                
            }
            
    
}







































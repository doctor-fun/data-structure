//
//  1050.cpp
//  debug.cc
//
//  Created by 晨 方 on 2018/1/10.
//  Copyright © 2018年 晨 方. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include <map>
#include<set>
#include<vector>
using namespace std;

const int maxn=500;
const int INF=10000000;
class Node{
    Node(int v,int w):_number(v),_weight(w)
    {}
private:
    int _number;
    int _weight;
};
//adj[1].push_back(Node(3,4)); 添加有向边=添加相对应地顶点
int n;


int dist[maxn];
bool had_visited[maxn]={false};
void Dijkstra(int source)
{
    fill(dist,dist+maxn,INF);
    dist[source]=0;
    for(int i=0;i<n;i++)//n个顶点,需要循环n次，确定源点到每个顶点的最短距离，
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)//每次都得遍历所有顶点， 确定最小这些顶点是否是未访问过的，进而在未访问过的顶点中寻找dist最小的点。
        {
            if(had_visited[j]==false && dist[j]<MIN)
            {
                u=j;
                MIN=dist[j];
            }
        }
        if(u==-1) return;
        had_visited[u]=true;
    }
    
}
int main()
{
    vector<Node> v1[maxn];
    
    
    
}



















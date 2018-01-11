//
//  1050.cpp
//  debug.cc
//
//  Created by 晨 方 on 2018/1/10.
//  Copyright © 2018年 晨 方. All rights reserved.
//

#include <iostream>
#include<string>
#include <map>
#include<set>
using namespace std;
int main()
{
    //非零
    map<int,float,greater<int> > mp;//重要
    
int n1,n2;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        int mici;
        float xishu;
        scanf("%d%f",&mici,&xishu);
        mp[mici]=xishu;
       
    }
    scanf("%d",&n2);
    for(int j=0;j<n2;j++)
    {
        int mici;
        float xishu;
        scanf("%d%f",&mici,&xishu);
        if(mp.find(mici)!=mp.end())
        {
            map<int,float>::iterator position;
            position=mp.find(mici);
            mp[mici]=mp[mici]+xishu;//重要，将幂次不是0的就加一次
            if(mp[mici]==0)
            {
                mp.erase(position);
            }
        }
        else
            mp[mici]=xishu;
    }
    printf("%d ",(int)mp.size());
    int k=0;
    for(map<int,float>::iterator it=mp.begin();it!=mp.end();it++)
    {
        
        printf("%d %.1f",it->first,it->second);
        ++k;
        if(k<(int)mp.size()) printf(" ");
       
        
    }
    return 0;
}




















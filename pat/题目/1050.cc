//
//  1050.cpp
//  debug.cc
//
//  Created by 晨 方 on 2018/1/10.
//  Copyright © 2018年 晨 方. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
/*int main()
{
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    
    string::size_type position;
    size_t len_a=a.length();
    
    for(int k=0;k<len_a;k++)
    {
        position=a.find(b[k]);
        while(position!=string::npos)
        {
           a.erase(position);
        }
    }
    printf("%s",a.c_str());
    return 0;
}*/
int main()
{
    string a;
    getline(cin,a);
    map<char,int> mp;
    
    while(1)
    {
        char c;
        c=getchar();
        if(c=='\n') break;
        mp[c]=1;
    }
    for(int i=0;i<a.length();i++)
    {
        char d=a[i];
        if(map.find(d)!=mp.end()) continue;
        printf("%c",d);
    }

    
    return 0;
}



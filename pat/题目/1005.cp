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
int main()
{
    string n;
    int sum=0;
    vector<string> hash_map(10);//注意vector要写个数字
    hash_map[1]="one";
    hash_map[2]="two";
    hash_map[3]="three";
    hash_map[4]="four";
    hash_map[5]="five";
    hash_map[6]="six";
    hash_map[7]="seven";
    hash_map[8]="eight";
    hash_map[9]="nine";
    hash_map[0]="zero";
    getline(cin,n);
    for(int i=0;i<n.size();i++)
    {
        sum+=n[i]-48;//
    }
    string sum_str;
    sum_str=to_string(sum);
    for(int k=0;k<sum_str.size();k++)
    {
        cout<<hash_map[sum_str[k]-48];//数字和'char'之间的关系
        if(k<sum_str.size()-1) printf(" ");
    }
    
    return 0;
}



















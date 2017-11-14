//
//  并查集.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/14.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include "并查集.hpp"
//用树根来代表集合，一棵树代表一个集合
//用一个指针数组来指向不同的树（集合）
//每个结点指向他们的父亲
//在数组s中查找值为x的元素所属的集合(根的下标)
//maxsize是全局变量，为数组s的最大长度
int maxsize=10;
int find(settype S[],elementype x)
{
    int i;
    for(i=0;i<maxsize && S[i].data!=x;i++);//在数组中找到x的下标
    
        if(i>=maxsize) return -1;
    
    for(；S[i].parent>=0;i=S[i].parent);
    
        return i;
        
    
}

//首先分别找到X1和X2两个元素所在集合树的根结点，如果它们不同根，则将其中一个根结点的父结点指针设置成另一个根结点的数组下标就行了。
void Union( SetType S[ ], ElementType X1, ElementType X2 )
{
    int Root1, Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);
    if（ Root1 != Root2 ）S[Root2].Parent = Root1;
}


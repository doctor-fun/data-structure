//
//  bst.cpp
//  data-structure
//
//  Created by 晨 方 on 2017/11/9.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include "bst.hpp"
//
//  main.cpp
//  bt
//
//  Created by 晨 方 on 2017/11/9.
//  Copyright © 2017年 晨 方. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* newnode(int v)
{
    node * Node=new node;
    Node->lchild=Node->rchild=NULL;
    Node->data=v;
    return Node;
}
node* findmax(node * & root)
{
    while(root->rchild!=NULL)
        root=root->rchild;
    return root;
    
}
node* findmin(node * & root)
{
    while(root->lchild!=NULL)
        root=root->lchild;
    return root;
}
void insert(node * & root, int x)
{
    if(root==NULL)
    {
        root=newnode(x);
        return;
    }
    else if (x==root->data)
    {
        printf("it has already had this node");
        return;
    }
    else if(x<root->data)
    {
        insert(root->lchild,x);
    }
    else if(x>root->data)
    {
        insert(root->rchild,x);
    }
}
void searchnode(node* root,int x)//有四种可能，分别为空树，根结点即为所要找的结点，小于根结点，大于根结点
{
    if(root==NULL)
    {
        printf("search %d failed",x);
        printf("\n");
        return;
    }
    else if (x==root->data)
    {
        cout<<"we have found this node"<<endl;
        printf("%d\n",root->data);
    }
    else if(x<root->data)
    {
        searchnode(root->lchild,x);
    }
    else
    {
        searchnode(root->rchild,x);
    }
}

node*  create(vector<int> data,int n)
{
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        insert(root,data[i]);
    }
    return root;
}
void deletenode(node * & root,size_t x)
{
    if(root==NULL) return ;
    if(x< root->data)
    {
        deletenode(root->lchild,x);
        
    }
    if (x>root->data)
    {
        deletenode(root->rchild,x);
    }
    else if(x==root->data)
    {
        if(root->lchild==NULL&& root->rchild==NULL)
        {
            root=NULL;
        }
        else if (root->lchild!=NULL)
        {
            node* pre=findmax(root->lchild);
            root->data=pre->data;
            deletenode(root->lchild,pre->data);
        }
        else if(root->rchild!=NULL)
        {
            node * next=findmin(root->rchild);
            root->data=next->data;
            deletenode(root->rchild,next->data);
            
        }
    }
}
void preorder(node * & root)
{
    if(root)
    {
        
        preorder(root->lchild);
        cout<<root->data<<" ";
        preorder(root->rchild);
    }
    
}
int main()
{
    vector<int> a={4,5,2,1,0,9,3,7,6,8};
    node* root=create(a,(int)a.size());
    preorder(root);
    cout<<endl;
    deletenode(root, 7);
    preorder(root);
    cout<<endl;
    searchnode(root, 7);
    insert(root, 7);
    preorder(root);
    
    return 0;
}

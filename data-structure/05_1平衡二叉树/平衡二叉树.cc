#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
//平衡二叉树的关键在于新插入结点影响了整颗树的平衡，而新插入结点的直接父亲的平衡因子是正确的（1），但是除直接父亲以外的祖先的平衡因子都>=2;此时只要调整子，父，爷这颗树的平衡，
//曾爷以及往上结点的平衡因子自动平衡
//平衡二叉树在新插入结点时始终只要调整局部位置就可以将整颗树平衡
//LL旋转的意思是指某结点的左子树的左子树上插入了个新结点（有可能是左曾孙或者右曾孙），需要向右旋转
//平衡二叉树的共同点就是我下去子上来

using namespace std;
struct node{
    int data,height;
    //v，权值，height高度
    node * lchild;
    node* rchild;
};
node * newNode(int v)
{
  node * Node=new node;
  Node->data=v;
  Node->height=1;
  Node->lchild=Node->rchild=NULL;
  return Node;
}

//计算结点所在树的的高度，由叶结点往上递归加整个的高度，其实就是由下往上递归，遇到null指针，向上返回树高为0
int getHeight(node * root)
{
  if (root==NULL) return 0;
  return root->height;
}

//确定根结点所在的高度
//等于左子树高度和右子树高度中较大值加一
void updateheight(node * root)
{
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
    //这里max是c++标准库的函数
}

int getBalanceFactor(node* root)
{
  //左子树高度减去右子树的高度;
  return getHeight(root->lchild)-getHeight(root->rchild);
}
void left_rotor(node* &root)
{
    node * temp =root->rchild;//新的temp根指向右子
    root->rchild=temp->lchild;//
    temp->lchild=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
    
    
    
    
}



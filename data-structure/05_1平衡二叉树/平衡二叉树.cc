struct node{
    int v,height;
    //v，权值，height高度
    node * lchild;
    node* rchild;
};
node * newNode(int v)
{
  node * Node=new node;
  Node->v=v;
  Node->height=1;
  Node->lchild=Node->rchild=NULL;
  return Node;
}
int getHeight(node * root)
{
  if (root==NULL) return 0;
  return root->height;
}
int getBalanceFactor(node* root)
{
  //左子树高度减去右子树的高度;
  return getHeight(node->lchild)-getHeight(node->rchild);
}
void updateheight(node * root)
{
    root->height=max(getHeight(root->lchild)),getHeight(root->rchild))+1;
    //这里max是c++标准库的函数
}

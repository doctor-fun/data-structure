struct node{
  typename data;
  node * lchild;
  node * rchild;
};

node* newnode(int v){
  node * Node= new node;
  node->data=v;
  Node->lchild=Node->rchild=NULL;
  return Node;
}
void search(node* root,int x)//有四种可能，分别为空树，根结点即为所要找的结点，小于根结点，大于根结点
{
  if(root==NULL)
  {
    printf("search failed");
    return;
  }
  else if (x==root->data)
  {
    printf("%d\n",root->data);
  }
  else if(x<root->data)
  {
    search(root->lchild,x);
  }
  else
  {
      search(root->rchild,x);
  }
}

void insert(node* &root,int x)//插入的过程要先判断是否有这个插入到元素，如果有就什么都不做，没有就左右递归，然后建结点
{
  if(root==NULL)
  {
    root=newnode(x);
    return;
  }
    if(x==root->data)
    {
      return;
  }
  else if(x<root->data)
  {
    insert(root->lchild,x)
  }
  else
  {
    insert(root->rchild,x);
  }

}
node* create(int data[],int n)//将数组插入到二叉树当中
{
  node* root=NULL;//着重注意这一句
  for(int i=0;i<n;i++)
  {
    insert(root,data[i]);
  }
  return root;
}
void findmax(node * root)//非递归算法
{
  while(root->rchild!=NULL)
  {
    root=root->rchild;
  }
  return root;
}
void findmin(node * root)
{
  while(root->lchild!=NULL)
  {
    root=root->lchild;
  }
  return root;
}
void delete(node* &root,int x)//欲删除某个结点时，需要考虑删除这个结点所造成的后果，
//将此结点的左右儿子做好安排
//先通过键值的大小找到这个结点
//欲删除结点为叶结点时，则将指向这个结点的指针指为NULL,即root->lchild=root->rchild==NULL,则root=NULL
//
//左右两边有一个或者都儿子则：寻找被删除结点的代替者
//(1)左子树里找个最大值（此结点不可能有右儿子）
//(2)右子树里找个最小值（此结点不可能有左儿子）
void delete(node* &root,int x)
{
  if(root==NULL) return ;
  else(x<root->data)
  {
      delete(root->lchild,x);
  }
  else(x>root->data)
  {
     delete(root->rchild,x);
  }
  else (root->data==x)
  {
     if(root->lchild==NULL && root->rchild==NULL)
      root==NULL;
     else if(root->lchild!=NULL)//因为是if，所以此时表示只有单左子
      node* pre=findmax(root->lchild);//找到root的左子树的最大值，这个结点肯定没有右结点，只可能有比他小的左结点
      //赋给pre结点
      root->data=pre->data;//将root结点的值变更为最大值
      delete(root->lchild,pre->data);//再走一轮删除，删除对象改为pre,而pre只有左子，且此子是叶结点，。
      //在root->lchild子树中找到上一轮的max值（即pre,将它的值改为它左子的值）
      //再往下走一层递归，则pre的值将变成它左子的值，最终它左子被删除了
     else (root->rchild!=NULL)
      {
          node* next=findmin(root->rchild);
          root->data=next->data;
          delete(root->rchild,next->data);
      }
  }
}
----------------------------------------------------------------------------------------------------------------
        

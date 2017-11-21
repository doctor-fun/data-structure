void Bubble_Sort(ElemType A[],int n)
{

  int flag=0;
    for(p=n-1;p>=0;p--)//排N个数，每次循环将一个数冒到数组最右端，需要冒N-1次，
    {

      for(i=0;i<p;i++)//从数组第一个位置开始,一般每轮要比较p次
      {
          if(a[i]>a[i+1])
          {
                swap(a[i],a[i+1]);
                flag=1;
          }
      }//当走完这个循环，第一个最大值到了末尾
      if (flag==0)
      {
        break;
      }
    }

}

void Insertion_Sort (ElemType a[],int n)//(从桌上(所有牌都黑的排列好)抓一手牌的过程 )
{
  for( int p=1;p<n;p++)//从前往后摸牌，摸第p张牌的时候其实手上已经有1（0）+p-1=p张牌 了
  {
      int tmp=a[p];//摸下一张牌
      for(int i=p;i>0 && a[i-1]>tmp;i--)//新摸的这张tmp牌先放到手上，然后和手上最后一张牌逐次向手上的前面牌进行对比(i--),
      //比新摸牌要大的全部后移一个位置
      {
        a[i]=a[i-1];//如果手上的牌比新摸的牌大,就要将手上的牌往后移一个位置。刚开始i-1=p,则i=p+1
      }
      //此时走出循环i的最终结果为i=i-1;
      a[i]=tmp;//新牌落位
  }
}

void Select_Sort(Elemtype a[],int n)//从小到大开始排位，寻找每一趟里面最小的值的游标，刚开始时，选择 a[0]最小
{
  for(int i=0;i<n-1;i++)//要确定n-1个位置的，第n个位置自然会形成
  {
    int min=i;
    {
      for(int j=i+1;j<n;j++)
      if(a[j]<a[min]) min=j;
      if(min!=j) swap(a[i],a[min]);
    }
  }
}
void downadjust(int low,int high)
{
  int i=low,j=i*2;
  while(j<=high)
  {
    if(j+1<=high && heap[j+1]>heap[j])//j+1为右孩子，j为左孩子,j+1<=high说明右孩子存在
    {
        j=j+1;//游标指向右孩子;
    }
    //孩子结点权值大于父结点权值，则需要交换，将较大的值传到上面来
    if(heap[j]>heap[i])
    {
      swap(heap[j],heap[i]);
      i=j;//(继续准备向下层进行比较)
      j=i*2;
    }
    else{
      break;
    }
  }
}
void heapSort()
{
  createHeap();
  for(int i=n,i>1;i--)
  {
      swap(heap[1],heap[i]);
      downAdjust(1,i-1);

  }


}
//快速排序


//取主元 a[0]，或者random，或者3）取头、中、尾的中位数，一般主元通过3）来取
//子集划分：
//一般选取主元后，设定两个游标，先让游标1从左边往右边开始走，一直走到游标所指向的位置大于主元的时候停止
//当游标1停止时，游标2开始从右边往左走，如果发现游标2所指元素小于主元，则游标2停止
//交换游标1和游标2所指的元素内容。
//继续让游标1往右走，递归前面的过程
//接着当游标1遇到游标2，游标2往左多走一个距离，此时，游标2小于游标1，停止，a[0]与游标2位置上的元素互换。

--------------------------------------






















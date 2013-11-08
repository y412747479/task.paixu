#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
//快速排序
void quickSort(int a[],int left,int right)//快速排序
{
   int i,j,temp;
   i=left;
   j=right;
   temp=a[left];
   if(left>right)
      return 0;
   while(i!=j)/*找到最终位置*/
   {
      while(a[j]>=temp && j>i)
         j--;
      if(j>i)
         a[i++]=a[j];
       while(a[i]<=temp && j>i)
          i++;
       if(j>i)
          a[j--]=a[i];

   }
   a[i]=temp;
   quickSort(a,left,i-1);/*递归左if(left>right)return 0;边*/
   quickSort(a,i+1,right);/*递归右边*/
}
//插入排序
void InsertSort(int array[],int length)// 插入排序,array为所要排序的数组，length为数组长度。
{
    int i,j,key;
    for(i=1;i<length;i++)//是key依次等于a1，a2，a3，a4.。。。
    {
        key=array[i];// 把i之前大于array[i]的数据向后移动
        for(j=i-1;j>=0&&array[j]>key;j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=key;
    }
}
//希尔排序
void shellsort(int data[], int n)//希尔排序,n为数组长度
{
    int i, j;
    for(i = n / 2; i > 2; i /= 2)
        for(j = 0; j < i; j++)
            insertion_sort(data, n - j, i);//
    insertion_sort(data, n, 1);//最后一次用间隔为一的插入排序，保证排序成功
}
void insertion_sort(int data[], int n, int increment)//将间隔为increment的数组合在一起并排序
{
    int i, j;
    for(i = increment; i < n; i += increment)
        for(j = i; j >= increment && data[j] < data[j - increment]; j -= increment)//控制升序或降序
            swap(&data[j], &data[j - increment]);
}

void swap(int *a, int *b)
{
    int x;
    x = *a;
    *a = *b;
    *b = x;
}
//冒泡排序
void Bubble_Sort(int a[],int length)
{
    int i,j;
    for (i=0;i<length-1;i++)
    {
        for (j=0;j<length-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],a[j+1]);
            }
        }

    }
}
void print(int a[],int length)
{
    int i,j=0;
    printf("由小到大排序为\n");
    for (i=0;i<length;i++)
    {
        printf("%d ",a[i]);
        j++;
        if (j%10==0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
int main()
{
    int a[100];
    int i;
    FILE *fp;
    fp=fopen("srand.txt","r");
    if (fp==NULL)
    {
        printf("文件不存在");
        exit(0);
    }
    for (i=0;i<100;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    quickSort(a,0,100);
    print(a,100);
    InsertSort(a,100);
    print(a,100);
    shellsort(a,100);
    print(a,100);
    Bubble_Sort(a,100);
    print(a,100);
}

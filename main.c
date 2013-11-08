#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
//��������
void quickSort(int a[],int left,int right)//��������
{
   int i,j,temp;
   i=left;
   j=right;
   temp=a[left];
   if(left>right)
      return 0;
   while(i!=j)/*�ҵ�����λ��*/
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
   quickSort(a,left,i-1);/*�ݹ���if(left>right)return 0;��*/
   quickSort(a,i+1,right);/*�ݹ��ұ�*/
}
//��������
void InsertSort(int array[],int length)// ��������,arrayΪ��Ҫ��������飬lengthΪ���鳤�ȡ�
{
    int i,j,key;
    for(i=1;i<length;i++)//��key���ε���a1��a2��a3��a4.������
    {
        key=array[i];// ��i֮ǰ����array[i]����������ƶ�
        for(j=i-1;j>=0&&array[j]>key;j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=key;
    }
}
//ϣ������
void shellsort(int data[], int n)//ϣ������,nΪ���鳤��
{
    int i, j;
    for(i = n / 2; i > 2; i /= 2)
        for(j = 0; j < i; j++)
            insertion_sort(data, n - j, i);//
    insertion_sort(data, n, 1);//���һ���ü��Ϊһ�Ĳ������򣬱�֤����ɹ�
}
void insertion_sort(int data[], int n, int increment)//�����Ϊincrement���������һ������
{
    int i, j;
    for(i = increment; i < n; i += increment)
        for(j = i; j >= increment && data[j] < data[j - increment]; j -= increment)//�����������
            swap(&data[j], &data[j - increment]);
}

void swap(int *a, int *b)
{
    int x;
    x = *a;
    *a = *b;
    *b = x;
}
//ð������
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
    printf("��С��������Ϊ\n");
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
        printf("�ļ�������");
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

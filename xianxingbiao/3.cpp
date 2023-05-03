//
// Created by lu on 23-5-3.
//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
unsigned int a[31270],s[31270];//第i组的总数;前i组的总数;
void reset()
{
    int i;
    s[1]=a[1]=1;
    for(i=2;i<31270;i++)
    {
        a[i]=a[i-1]+(int)log10((double)i)+1;//第i组的总数;
        s[i]=s[i-1]+a[i];//前i组的总的数;
    }
}
int main()
{
    int t;
    int n;
    int i;
    scanf("%d",&t);
    reset();
    while(t--)
    {
        scanf("%d",&n);
        i=1;
        while(s[i]<n)//找到在那组;
            i++;
        int pos=n-s[i-1];//只在最后一组开始找;
        int sum=0;
        for(i=1;sum<pos;i++)
            sum+=(int)log10((double)i)+1;//递推最后一组的总的恶个数;
        int k=sum-pos;//最后一组多余的数;//例123要得到2则3是多余的元素;
        printf("%d\n",(i-1)/(int)pow(10.0,k)%10);
    }
    return 0;
}

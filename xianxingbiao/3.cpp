//
// Created by lu on 23-5-3.
//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
unsigned int a[31270],s[31270];//��i�������;ǰi�������;
void reset()
{
    int i;
    s[1]=a[1]=1;
    for(i=2;i<31270;i++)
    {
        a[i]=a[i-1]+(int)log10((double)i)+1;//��i�������;
        s[i]=s[i-1]+a[i];//ǰi����ܵ���;
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
        while(s[i]<n)//�ҵ�������;
            i++;
        int pos=n-s[i-1];//ֻ�����һ�鿪ʼ��;
        int sum=0;
        for(i=1;sum<pos;i++)
            sum+=(int)log10((double)i)+1;//�������һ����ܵĶ����;
        int k=sum-pos;//���һ��������;//��123Ҫ�õ�2��3�Ƕ����Ԫ��;
        printf("%d\n",(i-1)/(int)pow(10.0,k)%10);
    }
    return 0;
}

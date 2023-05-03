//
// Created by lu on 23-5-3.
//
#include<iostream>
using namespace std;
int a[1001][1001];
int now=1;
int tot=0;
int hang,lie;
int main()
{
    int n;
    cin>>n;
    int c=2*n-1;
    while(tot!=(c*c))
    {
        if(tot==0)
        {
            a[1][c/2+1]=now;
            now++;
            hang=1;
            lie=c/2+1;
            tot++;
        }
        else if(hang==1&&lie!=c)
        {
            a[c][lie+1]=now;
            now++;
            tot++;
            hang=c;
            lie=lie+1;
        }
        else if(lie==c&&hang!=1)
        {
            a[hang-1][1]=now;
            now++;
            tot++;
            hang=hang-1;
            lie=1;
        }
        else if((hang==1&&lie==c)||(a[hang-1][lie+1]!=0))
        {
            a[hang+1][lie]=now;
            now++;
            tot++;
            hang=hang+1;
        }
        else
        {
            a[hang-1][lie+1]=now;
            now++;
            tot++;
            hang=hang-1;
            lie=lie+1;
        }
    }
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
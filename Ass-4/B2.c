#include<stdio.h>
int main(){int n;scanf("%d",&n);
    int r[]={7,0,1,2,0,3,0,4,2,3,0,3,2},l=13;
    int f[n],p=0,c=0;for(int i=0;i<n;i++)f[i]=-1;
    for(int i=0;i<l;i++)
    {
        int d=0;
        for(int j=0;j<n;j++)d=f[j]==r[i]?1:d;
        if(!d){f[p]=r[i];p=(p+1)%n;c++;}for(int j=0;j<n;j++)printf("%d ",f[j]);
        printf("\n");
    }
    printf("Total page faults: %d\n",c);
    return 0;
}

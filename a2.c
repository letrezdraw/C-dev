#include<stdio.h>
int main(){
    int p,r;
    printf("Enter number of processes and resources: ");
    scanf("%d%d",&p,&r);
    int max[p][r], alloc[p][r];
    printf("Need Matrix:\n");
    for(int i=0;i<p;i++) for(int j=0;j<r;j++) scanf("%d",&max[i][j]);
    printf("Allocation Matrix:\n");
    for(int i=0;i<p;i++) for(int j=0;j<r;j++) scanf("%d",&alloc[i][j]);
    for(int i=0;i<p;i++,puts("")) for(int j=0;j<r;j++) printf("%d ",max[i][j]-alloc[i][j]);
}
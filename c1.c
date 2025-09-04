#include <stdio.h>
int main() {
    int p=5,r=4;
    int allocation[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
    int max[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
    int need[5][4],work[4]={1,5,2,0},finish[5]={0},safeSeq[5],count=0;

    printf("\nNeed Matrix:\n\n");
    printf("A\tB\tC\tD\t\n\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            need[i][j]=max[i][j]-allocation[i][j];
            printf("%d\t",need[i][j]);
        }printf("\n\n");
        }
    printf("\n Available:\n\n");
    printf("A\tB\tC\tD\t\n\n");
    for(int i=0;i<r;i++)
        printf("%d\t",work[i]);
        printf("\n\n");

    while(count<p){
        int found=0;
        for(int i=0;i<p;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<r;j++)
                    if(need[i][j]>work[j])
                        break;
                if(j==r){
                    for(int k=0;k<r;k++)
                        work[k]+=allocation[i][k];
                    for(int k=0;k<r;k++)
                        printf("%d\t",work[k]);
                    printf("\n\n");
                    safeSeq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found){
            printf("\n\nThe system is NOT in a SAFE state!\n");
            return 0;
        }
    }
    printf("\n\nThe system is in a SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < p; i++) {
    printf("P%d ->", safeSeq[i]);
    
}
    printf("\n");

}

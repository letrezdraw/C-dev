#include <stdio.h>
int main(){
    int ref[]={2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8},n,i,j,k,f=0,l=16,fm[20],c=0;
    printf("Enter number of memory frames: "); scanf("%d",&n);
    for(i=0;i<l;i++){
        printf("Page %d: ",ref[i]);
        for(j=0;j<c && fm[j]!=ref[i];j++);
        if(j<c){
            printf("Hit [");
            for(k=0;k<c;k++) printf("%d%s",fm[k],k<c-1?", ":"");
            printf("]\n");
            for(;j>0;j--) fm[j]=fm[j-1];
            fm[0]=ref[i];
        }else{
            f++;
            if(c<n){
                for(j=c++;j>0;j--) fm[j]=fm[j-1];
                fm[0]=ref[i];
            }else{
                for(j=n-1;j>0;j--) fm[j]=fm[j-1];
                fm[0]=ref[i];
            }
            printf("Miss [");
            for(k=0;k<c;k++) printf("%d%s",fm[k],k<c-1?", ":"");
            printf("]\n");
        }
    }
    printf("Total Page Faults: %d\n",f);
    return 0;
}

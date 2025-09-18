#include <stdio.h>
int main(){
    int ref[]={2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8},n,i,j,k,faults=0,len=16,frames[20],count=0;
    printf("Enter number of memory frames: "); scanf("%d",&n);
    for(i=0;i<len;i++){
        printf("Page %d: ",ref[i]);
        for(j=0;j<count && frames[j]!=ref[i];j++);
        if(j<count){
            printf("Hit [");
            for(k=0;k<count;k++) printf("%d%s",frames[k],k<count-1?", ":"");
            printf("]\n");
            for(;j>0;j--) frames[j]=frames[j-1];
            frames[0]=ref[i];
        } else {
            faults++;
            if(count<n) {
                for(j=count;j>0;j--) frames[j]=frames[j-1];
                frames[0]=ref[i];
                count++;
            } else {
                for(j=n-1;j>0;j--) frames[j]=frames[j-1];
                frames[0]=ref[i];
            }
            printf("Miss [");
            for(k=0;k<count;k++) printf("%d%s",frames[k],k<count-1?", ":"");
            printf("]\n");
        }
    }
    printf("Total Page Faults: %d\n",faults);
    return 0;
}

#include <stdio.h>
int main(){
    int ref[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8},n,i,j,k,faults=0,len=16,frames[20],count=0;
    printf("Enter number of memory frames: "); scanf("%d",&n);
    for(i=0;i<len;i++){
        printf("Page %d: ",ref[i]);
        for(j=0;j<count && frames[j]!=ref[i];j++);
        if(j<count){
            printf("Hit [");
            for(k=0;k<count;k++) printf("%d%s",frames[k],k<count-1?", ":"");
            printf("]\n");
            for(;j<count-1;j++) frames[j]=frames[j+1];
            frames[count-1]=ref[i];
        } else {
            faults++;
            if(count<n) frames[count++]=ref[i];
            else {
                for(j=0;j<n-1;j++) frames[j]=frames[j+1];
                frames[n-1]=ref[i];
            }
            printf("Miss [");
            for(k=0;k<count;k++) printf("%d%s",frames[k],k<count-1?", ":"");
            printf("]\n");
        }
    }
    printf("Total Page Faults: %d\n",faults);
    return 0;
}

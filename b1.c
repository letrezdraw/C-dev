#include<stdio.h>
int main(){
int p,r,choice=0;
scanf("%d%d",&p,&r); //p processes, r resources
int max[p][r],alloc[p][r],need[p][r],avail[r];
for(int i=0;i<p;i++)for(int j=0;j<r;j++)scanf("%d",&max[i][j]);
for(int i=0;i<p;i++)for(int j=0;j<r;j++)scanf("%d",&alloc[i][j]);
while(choice!=5){
scanf("%d",&choice);
if(choice==1){
printf("Accept Available:\n");
for(int i=0;i<r;i++)scanf("%d",&avail[i]);
}
else if(choice==2){
printf("Display Max:\n");
for(int i=0;i<p;i++,puts(""))for(int j=0;j<r;j++)printf("%d ",max[i][j]);
printf("Display Allocation:\n");
for(int i=0;i<p;i++,puts(""))for(int j=0;j<r;j++)printf("%d ",alloc[i][j]);
}
else if(choice==3){
printf("Display Need:\n");
for(int i=0;i<p;i++,puts(""))for(int j=0;j<r;j++)printf("%d ",(need[i][j]=max[i][j]-alloc[i][j]));
}
else if(choice==4){
printf("Display Available:\n");
for(int i=0;i<r;i++)printf("%d ",avail[i]);
printf("\n");
}
else if(choice==5)return 0;
else printf("Enter valid choice\n");
}
return 0;
}

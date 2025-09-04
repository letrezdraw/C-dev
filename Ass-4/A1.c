#include <stdio.h>
#define P 10
#define R 10
int main() {
    int a[P][R],m[P][R],n[P][R],v[R],w[R],s[P],N,M,i,j,x=0,f[P]={0};
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)for(j=0;j<M;j++)scanf("%d",&a[i][j]);
    for(i=0;i<N;i++)for(j=0;j<M;j++) {
        scanf("%d",&m[i][j]);
        n[i][j]=m[i][j]-a[i][j];
    }
    for(j=0;j<M;j++)scanf("%d",&v[j]);
    for(j=0;j<M;j++)w[j]=v[j];
    while(x<N){
        int d=0;
        for(i=0;i<N;i++)if(!f[i]){
            int ok=1;
            for(j=0;j<M;j++)if(n[i][j]>w[j]){ok=0;break;}
            if(ok){
                for(j=0;j<M;j++)w[j]+=a[i][j];
                s[x++]=i;f[i]=1;d=1;
            }
        }
        if(!d)break;
    }
    if(x==N){
        printf("System is in a safe state.\nSafe sequence: ");
        for(i=0;i<N;i++)printf("%d ",s[i]);
        printf("\n");
    } else printf("System is not in a safe state.\n");
    printf("Minimum number of resources needed to avoid deadlock:\n");
    for(j=0;j<M;j++){
        int max=0;
        for(i=0;i<N;i++)if(m[i][j]>max)max=m[i][j];
        printf("Resource %d: %d\n",j,max);
    }
}

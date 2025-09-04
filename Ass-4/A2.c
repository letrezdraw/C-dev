#include <stdio.h>
#define P 10
#define R 10
int main() {
    int N, M, a[P][R], m[P][R], n[P][R], i, j;
    scanf("%d%d", &N, &M);
    for(i=0;i<N;i++)for(j=0;j<M;j++)scanf("%d",&a[i][j]);
    for(i=0;i<N;i++)for(j=0;j<M;j++) {
        scanf("%d",&m[i][j]);
        n[i][j] = m[i][j] - a[i][j];
    }
    printf("Number of processes: %d\nNumber of resources: %d\n", N, M);
    printf("Need matrix:\n");
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) printf("%d ", n[i][j]);
        printf("\n");
    }
}

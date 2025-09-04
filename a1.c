#include<stdio.h>
int main(){
    int p, sum = 0;
    scanf("%d", &p);
    for(int i = 0, x; i < p; i++) scanf("%d", &x), sum += x;
    printf("%d\n", sum - (p - 1));
}

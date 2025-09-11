#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int f[MAX], faults = 0;
int main() {
    int n, i, j, in, r[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 12, 1, 19, 8};
    int total = sizeof(r)/sizeof(r[0]);
    printf("Enter number of memory frames: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) f[i] = -1;
    for (i = 0; i < total; i++) {
        for (j = 0, in = 0; j < n; j++)
            if (f[j] == r[i]) { in = 1; break; }
        (!in) ? (
            faults++,
            j = rand() % n,
            printf("Page fault occurred for page %d\n", r[i]),
            printf("Page %d replaced with %d\n", f[j], r[i]),
            f[j] = r[i]
        ) : 0;
    }
    printf("Total number of page faults: %d\n", faults);
    return 0;
}

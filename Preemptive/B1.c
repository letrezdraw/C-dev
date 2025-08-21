#include <stdio.h>

int main() {
int n, i, j, time = 0, smallest, count = 0;
int at[10], bt[10], rt[10], ct[10], wt[10], tat[10];
float avg_wt = 0, avg_tat = 0;

printf("Enter number of processes: ");
scanf("%d", &n);


for (i = 0; i < n; i++) {
printf("Enter arrival time of P%d: ", i + 1);
scanf("%d", &at[i]);
printf("Enter burst time of P%d: ", i + 1);
scanf("%d", &bt[i]);
rt[i] = bt[i]; 
}

printf("\nGantt Chart:\n");

while (count < n) {
smallest = -1;

for (i = 0; i < n; i++) {
if (at[i] <= time && rt[i] > 0) {
if (smallest == -1 || rt[i] < rt[smallest]) {
    smallest = i;
}
}
}

if (smallest == -1) {
printf("Idle ");
time++;
continue;
}

printf("P%d ", smallest + 1);

rt[smallest]--;
time++;

if (rt[smallest] == 0) {
count++;
ct[smallest] = time;
tat[smallest] = ct[smallest] - at[smallest];
wt[smallest] = tat[smallest] - bt[smallest];
}
}

printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

for (i = 0; i < n; i++) {
avg_wt += wt[i];
avg_tat += tat[i];
printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

printf("\nAverage Waiting Time: %.2f", avg_wt / n);
printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

return 0;
}




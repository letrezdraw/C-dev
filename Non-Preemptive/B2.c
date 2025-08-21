#include <stdio.h>

struct Process {
int pid;
int at;
int bt;
int pr;
int ct;
int tat;
int wt;
int done;
};

int main() {
int n, i, time = 0, completed = 0;
struct Process p[10];
float total_tat = 0, total_wt = 0;

printf("Enter number of processes: ");
scanf("%d", &n);


for (i = 0; i < n; i++) {
p[i].pid = i + 1;
printf("Enter Arrival Time, Burst Time, Priority for P%d: ", p[i].pid);
scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].pr);
p[i].done = 0;
}

printf("\nGantt Chart:\n| ");


while (completed < n) {
int highest = -1;
for (i = 0; i < n; i++) {
    if (!p[i].done && p[i].at <= time) {
        if (highest == -1 || p[i].pr < p[highest].pr)
            highest = i;
    }
}

if (highest == -1) {
    printf("IDLE | ");
    time++;
} else {
    printf("P%d | ", p[highest].pid);
    time += p[highest].bt;
    p[highest].ct = time;
    p[highest].tat = p[highest].ct - p[highest].at;
    p[highest].wt = p[highest].tat - p[highest].bt;
    total_tat += p[highest].tat;
    total_wt += p[highest].wt;
    p[highest].done = 1;
    completed++;
}
}
}


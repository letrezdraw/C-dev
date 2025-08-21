#include <stdio.h>

struct Process {
char pid[5];
int At;
int Bt;
int Rt;  
int priority;
int Ft;
int Tat;
int Wt;
int completed;
};

int main() {
int n, completed = 0, currentTime = 0;
printf("Enter number of processes: ");
scanf("%d", &n);

struct Process p[n];
for(int i = 0; i < n; i++) {
printf("Enter PID of process %d: ", i+1);
scanf("%s", p[i].pid);
printf("Enter Arrival Time of process %d: ", i+1);
scanf("%d", &p[i].At);
printf("Enter Burst Time of process %d: ", i+1);
scanf("%d", &p[i].Bt);
printf("Enter Priority of process %d (lower number = higher priority): ", i+1);
scanf("%d", &p[i].priority);
p[i].Rt = p[i].Bt;
p[i].completed = 0;
}

while(completed < n) {
int idx = -1;
int highestPriority = 1e9;

for(int i = 0; i < n; i++) {
if(p[i].At <= currentTime && !p[i].completed) {
    if(p[i].priority < highestPriority) {
        highestPriority = p[i].priority;
        idx = i;
    } else if(p[i].priority == highestPriority) {
        if(p[i].At < p[idx].At) {
            idx = i;
        }
    }
}
}

if(idx == -1) {
currentTime++;
continue;
}

p[idx].Rt--;
currentTime++;

if(p[idx].Rt == 0) {
p[idx].completed = 1;
p[idx].Ft = currentTime;
p[idx].Tat = p[idx].Ft - p[idx].At;
p[idx].Wt = p[idx].Tat - p[idx].Bt;
completed++;
}
}

printf("\nPID\tAT\tBT\tPri\tFT\tTAT\tWT\n");
for(int i = 0; i < n; i++) {
printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
p[i].pid, p[i].At, p[i].Bt, p[i].priority, p[i].Ft, p[i].Tat, p[i].Wt);
}

float totalTat = 0, totalWt = 0;
for(int i = 0; i < n; i++) {
totalTat += p[i].Tat;
totalWt += p[i].Wt;
}

printf("\nAverage Turnaround Time: %.2f\n", totalTat/n);
printf("Average Waiting Time: %.2f\n", totalWt/n);

return 0;
}

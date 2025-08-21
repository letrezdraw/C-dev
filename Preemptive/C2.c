#include <stdio.h>

struct Process {
char pid[5];
int At;
int Bt;
int Rt;  
int Ft;
int Tat;
int Wt;
};

int main() {
int n, timeQuantum;
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
p[i].Rt = p[i].Bt;
p[i].Ft = 0;
p[i].Tat = 0;
p[i].Wt = 0;
}

printf("Enter Time Quantum: ");
scanf("%d", &timeQuantum);

int completed = 0, currentTime = 0;
int done;
while(completed < n) {
done = 1;
for(int i = 0; i < n; i++) {
if(p[i].Rt > 0 && p[i].At <= currentTime) {
done = 0;
if(p[i].Rt > timeQuantum) {
currentTime += timeQuantum;
p[i].Rt -= timeQuantum;
} else {
currentTime += p[i].Rt;
p[i].Rt = 0;
p[i].Ft = currentTime;
p[i].Tat = p[i].Ft - p[i].At;
p[i].Wt = p[i].Tat - p[i].Bt;
completed++;
}
}
}
if(done) {
currentTime++;
}
}

printf("\nPID\tAT\tBT\tFT\tTAT\tWT\n");
for(int i = 0; i < n; i++) {
printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].At, p[i].Bt, p[i].Ft, p[i].Tat, p[i].Wt);
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



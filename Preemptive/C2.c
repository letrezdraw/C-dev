#include <stdio.h>

struct Process {
    char pid[5];
    int At, Bt, Rt, Ft, Tat, Wt;
};

int main() {
    int n, tq, completed = 0, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    for(int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time for process %d: ", i+1);
        scanf("%s %d %d", p[i].pid, &p[i].At, &p[i].Bt);
        p[i].Rt = p[i].Bt;
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(completed < n) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(p[i].Rt > 0 && p[i].At <= t) {
                done = 0;
                int exec = (p[i].Rt > tq) ? tq : p[i].Rt;
                t += exec;
                p[i].Rt -= exec;
                if(p[i].Rt == 0) {
                    p[i].Ft = t;
                    p[i].Tat = t - p[i].At;
                    p[i].Wt = p[i].Tat - p[i].Bt;
                    completed++;
                }
            }
        }
        if(done) t++;
    }

    float totalTat = 0, totalWt = 0;
    printf("\nPID\tAT\tBT\tFT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].At, p[i].Bt, p[i].Ft, p[i].Tat, p[i].Wt);
        totalTat += p[i].Tat;
        totalWt += p[i].Wt;
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTat/n);
    printf("Average Waiting Time: %.2f\n", totalWt/n);
    return 0;
}



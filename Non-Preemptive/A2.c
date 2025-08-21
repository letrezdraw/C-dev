#include <stdio.h>
#include <stdlib.h>

#define IO_WAIT 2

typedef struct {int pid, arrival, burst, rem, total, complete, wait, turn;} P;
typedef struct {int pid, start, finish;} G;

int main() {
    int n, t=0, done=0;
    scanf("%d",&n);
    P *p=malloc(n*sizeof(P));
    G *g=malloc(1000*sizeof(G));
    int gc=0, *tl=malloc(1000*sizeof(int));
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        scanf("%d%d",&p[i].arrival,&p[i].burst);
        p[i].rem=2; p[i].total=0; p[i].complete=0;
    }
    while(done<n){
        int idx=-1, min=1<<30;
        for(int i=0;i<n;i++)
            if(p[i].arrival<=t && !p[i].complete && p[i].rem>0 && p[i].burst<min)
                min=p[i].burst, idx=i;
        if(idx==-1) { tl[t++]=0; continue; }
        int st=t;
        for(int i=0;i<p[idx].burst;i++) tl[t++]=p[idx].pid;
        g[gc].pid=p[idx].pid; g[gc].start=st; g[gc].finish=t-1; gc++;
        p[idx].total+=p[idx].burst; p[idx].rem--;
        if(p[idx].rem==1){
            for(int i=0;i<IO_WAIT;i++) tl[t++]=0;
            p[idx].burst=rand()%10+1;
        } else p[idx].complete=1, done++;
    }
    for(int i=0;i<n;i++){
        p[i].turn=p[i].complete?(t - p[i].arrival):0;
        p[i].wait=p[i].turn - p[i].total - IO_WAIT;
        if(p[i].wait<0) p[i].wait=0;
    }
    printf("P\tArr\tCPU\tComp\tTurn\tWait\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].total,t,p[i].turn,p[i].wait);
    printf("Gantt Chart:\n|");
    for(int i=0;i<t;i++)
        printf(" %s |", tl[i]? (char[4]){'P','0'+tl[i],0}:"   ");
    printf("\nTime: 0");
    for(int i=0;i<gc;i++) printf("    %d", g[i].finish+1);
    printf("\n\nProcess Execution Intervals:\n");
    for(int i=0;i<gc;i++)
        printf("P%d: Start = %d, Finish = %d\n", g[i].pid, g[i].start, g[i].finish);
    free(p); free(tl); free(g);
}

#include <stdio.h>
#include <unistd.h>
int main() {
    int n, i, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], rt[n], wt[n], tat[n], t = 0;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d: WT = %d, TAT = %d\n", i+1, wt[i], tat[i]);
    }

    return 0;
}

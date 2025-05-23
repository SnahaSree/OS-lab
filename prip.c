#include <stdio.h>
#include <unistd.h>

struct Process {
    int id, at, bt, rt, prio, ct, tat, wt;
};

int main() {
    int n, time = 0, complete = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter AT, BT and Priority of P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prio);
        p[i].rt = p[i].bt;
    }

    while (complete < n) {
        int idx = -1;
        int highest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].prio > highest) {
                highest = p[i].prio;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].rt--;
            if (p[idx].rt == 0) {
                complete++;
                p[idx].ct = time + 1;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        }

        time++;
    }

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].prio, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}

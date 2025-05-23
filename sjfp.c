#include <stdio.h>
#include <unistd.h>
struct Process {
    int id, at, bt, rt, ct, wt, tat;
};

int main() {
    int n, complete = 0, time = 0, min_rt = 1e9, shortest = -1;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter AT and BT of P%d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (complete < n) {
        shortest = -1;
        min_rt = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt < min_rt && p[i].rt > 0) {
                min_rt = p[i].rt;
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        p[shortest].rt--;
        if (p[shortest].rt == 0) {
            complete++;
            p[shortest].ct = time + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }

        time++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}

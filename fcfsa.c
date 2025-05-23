#include <stdio.h>

struct Process {
    int pid;
    int bt;   // Burst Time
    int at;   // Arrival Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
};

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P[%d]: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sortByArrival(p, n);

    p[0].wt = 0;  // First process always 0 waiting time
    for (int i = 1; i < n; i++) {
        int service_time = p[i - 1].at + p[i - 1].bt + p[i - 1].wt;
        p[i].wt = service_time - p[i].at;

        if (p[i].wt < 0)  // if CPU is idle
            p[i].wt = 0;
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], p[n];

    for(i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i;
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                int tmp = bt[i]; bt[i] = bt[j]; bt[j] = tmp;
                tmp = p[i]; p[i] = p[j]; p[j] = tmp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("P%d: WT = %d, TAT = %d\n", p[i]+1, wt[i], tat[i]);
    }

    return 0;
}

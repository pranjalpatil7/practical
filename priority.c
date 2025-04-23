#include <stdio.h>

int main() 
{
    int n, i, time = 0, highest, count = 0;
    int a[10], b[10], remaining[10], p[10];
    double wt = 0, tat = 0, end;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &b[i]);
        remaining[i] = b[i];
    }

    printf("Enter priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &p[i]);
    }

    p[9] = 9999;

    printf("\nGantt Chart:\n");
    for (time = 0; count != n; time++) 
    {
        highest = 9;
        for (i = 0; i < n; i++) {
            if (a[i] <= time && p[i] < p[highest] && remaining[i] > 0) 
            {
                highest = i;
            }
        }

        remaining[highest]--;
        printf("| P%d ", highest + 1);

        if (remaining[highest] == 0) {
            count++;
            end = time + 1;
            wt += end - a[highest] - b[highest];
            tat += end - a[highest];
        }
    }
    printf("|\n");

    printf("\nAverage Waiting Time = %.2lf\n", wt / n);
    printf("Average Turnaround Time = %.2lf\n", tat / n);

    return 0;
}

//5 
// 0 1 2 3 4
//4 3 1 5 2 
//1 2 3 4 4

/*  Gantt Chart:
| P2 | P5 | P5 | P5 | P5 | P5 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P3 | P3 | P4 |

Average Waiting Time = 8.20
Average Turnaround Time = 12.00 */
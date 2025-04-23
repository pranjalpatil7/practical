#include <stdio.h>

int main() 
{
    int n, i, time = 0, count = 0, smallest;
    int a[10], b[10], x[10];
    double wt = 0, tat = 0, end;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &b[i]);
        x[i] = b[i];    /*copy arrival time*/
    }

    b[9] = 9999;

    printf("Gantt Chart:\n");
    for (time = 0; count != n; time++) 
    {
        smallest = 9;
        for (i = 0; i < n; i++) 
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0) 
            {
                smallest = i;
            }
        }

        b[smallest]--; 
        printf("| P%d ", smallest + 1); 

        if (b[smallest] == 0) 
        { 
            count++;
            end = time + 1;
            wt = wt +  end - a[smallest] - x[smallest]; 
            tat = tat + end - a[smallest]; 
        }
    }
    printf("|\n");

    printf("Average Waiting Time = %.2lf", wt / n);
    printf("\nAverage Turnaround Time = %.2lf", tat / n);

    return 0;
}

//6
//000000
//7 5 3 1 2 1

/* Gantt Chart:
| P4 | P6 | P5 | P5 | P3 | P3 | P3 | P2 | P2 | P2 | P2 | P2 | P1 | P1 | P1 | P1 | P1 | P1 | P1 |
Average Waiting Time = 4.33
Average Turnaround Time = 7.50 */
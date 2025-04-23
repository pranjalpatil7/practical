#include<stdio.h>
#include<stdlib.h>
int main()
{
    int max,n,i,queue[20],head,seek=0,diff;
    float avg;
    printf("Max range of disk: ");
    scanf("%d",&max);

    printf("Size of pending request: ");
    scanf("%d",&n);

    printf("Queue of pending request \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }

    printf("Initial head position: ");
    scanf("%d",&head);

    printf("Disk head movements:\n");
    for (i = 0; i < n; i++) 
    {
        int diff = abs(queue[i] - head);
        seek = seek + diff;
        printf("From %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];
    }

    printf("Total seek time is %d",seek);
    avg=(float)seek/n;
    printf("Average seek time is %f\n",avg);
    return 0;
}

//200
//55 58 39 18 90 160 150 38 184
//100
//498
//55.3333332
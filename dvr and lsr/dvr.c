#include<stdio.h>

struct Router
{
    int distance[20];
    int next[20];
};

int main()
{
    int cost[20][20];
    struct Router router[20];

    int n;
    printf("Enter the Number of Nodes: ");
    scanf("%d",&n);

    printf("Enter the Cost Matrix (999 for infinity): \n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Cost of [%d][%d]: ",i+1,j+1);
            scanf("%d",&cost[i][j]);

            router[i].distance[j]=cost[i][j];
            router[i].next[j]=j;
        }
        printf("\n");
    }

    int k,updated;
    do
    {
        updated=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(router[i].distance[j]>cost[i][k]+router[k].distance[j])
                    {
                        router[i].distance[j]=cost[i][k]+router[k].distance[j];
                        router[i].next[j]=k;
                        updated=1;
                    }
                }
            }
        }
    } while (updated);

    for(i=0;i<n;i++)
    {
        printf("Routing Table for %d\n",i+1);
        printf("Destination\tNext\tDistance\n");
        for(j=0;j<n;j++)
        {
            printf("%d\t%d\t%d\n",j+1,router[i].next[j]+1,router[i].distance[j]);
        }
    }
    

}
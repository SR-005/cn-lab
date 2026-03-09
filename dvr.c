#include <stdio.h>

#define MAX 20
#define INF 999

//struct for a node- with shortest distance to each node from current node
struct Router
{
    int distance[20];
    int next[20];
};

int main()
{
    int cost[20][20];           //cost matrix initialization
    struct Router router[20];   

    int n;
    printf("Enter the Number of Nodes: ");          //prompt user with number of nodes and store in n
    scanf("%d",&n);

    //prompt user with cost matrix of each node to every other: no connection is 999
    printf("Enter the Cost Matrix [999 for infinity]: \n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Cost of [%d][%d]: ",i+1,j+1);
            scanf("%d",&cost[i][j]);

            router[i].distance[j]=cost[i][j];       //here distance=cost, and it is stored in router.distance
            router[i].next[j]=j;                //the node in comparison is the jth node. hence next=j
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
                    if(router[i].distance[j]>cost[i][k]+router[k].distance[j])      //bellmarn ford fromula
                    {
                        router[i].distance[j]=cost[i][k]+router[k].distance[j];     //bellmarn ford fromula
                        router[i].next[j]=k;            //update node in comparison to k
                        updated=1;      
                    }
                }
            }
        }
    }while(updated);

    //print the distance vector table
    for(i=0;i<n;i++)
    {
        printf("\nRouting Table for Router %d\n",i+1);
        printf("Destination\tnext\tDistance\n");
        for(j=0;j<n;j++)
        {
            printf("%d\t%d\t%d\n",j+1,router[i].next[j]+1,router[i].distance[j]);

        }
    }

    return 0;
}
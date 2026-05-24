#include<stdio.h>

int dijkstra(int G[10][10], int n, int u)
{
    int cost[10][10],distance[10],pred[10],visited[10];
    int mindistance,count,nextnode,i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (G[i][j]==0)
                cost[i][j]=9999;
            else
                cost[i][j]=G[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        distance[i]=cost[u][i];
        pred[i]=u;
        visited[i]=0;
    }

    distance[u]=0;
    visited[u]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=9999;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && visited[i]==0)
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;

        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                if(mindistance+cost[nextnode][i] < distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;    
    }

    for(i=0;i<n;i++)
    {
        if(i!=u){
            printf("\nDistance of the Node %d: %d", i, distance[i]);
            printf("\nPath: %d", i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            } while (j!=u);
            printf("\n");
        }
    }
}


int main()
{
    int G[10][10],i,j,n,u;
    printf("Enter the Number of Vertices: ");
    scanf("%d",&n);

    printf("Enter the Adjancency Matix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the Value[%d][%d]",i+1,j+1);
            scanf("%d",&G[i][j]);
        }
    }

    printf("Enter the Starting Node: ");
    scanf("%d",&u);

    dijkstra(G,n,u);
}
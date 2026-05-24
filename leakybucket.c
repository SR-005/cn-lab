#include<stdio.h>

int main()
{
    int i,size,rate,inputs,incoming,dropped,current=0;
    printf("\nEnter the Bucket Size: ");
    scanf("%d",&size);
    printf("\nEnter the Outgoing Rate: ");
    scanf("%d",&rate);
    printf("\nEnter the Input Burst: ");
    scanf("%d",&inputs);

    for(i=0;i<inputs;i++)
    {
        printf("Enter Input for Burst %d: \n",i+1);
        scanf("%d",&incoming);

        if(incoming<=(size-current))
        {
            current=current+incoming;
            printf("Accepted! Buffer: %d/%d\n",current,size);
        }
        else
        {
            printf("Overflow!\n");
            dropped=incoming-(size-current);
            current=size;
            printf("Dropped %d Packets. Buffer: %d/%d\n",dropped,current,size);
        }

        if(current>=rate)
        {
            current=current-rate;
            printf("Transmitted %d packets. Buffer: %d/%d\n",rate,current,size);
        }
        else
        {
            printf("Transmitted %d packets. Remaining in Buffer: %d\n",current,size);
        }
        printf("\n");
    }
}
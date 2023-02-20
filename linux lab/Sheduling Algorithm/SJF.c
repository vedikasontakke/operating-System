/* SJF scheduling program in c
P   AT  BT
1   1   3
3   1   2  
2   2   4
4   4   4
 https://www.prepbytes.com/blog/c-programming/sjf-scheduling-program-in-c/
*/
#include<stdio.h>
int main()
{
    int n , totwt=0 , totta=0;
    double awt , ata;
 
    printf("Enter the number of process:");
    scanf("%d",&n);

    int pn[n], bt[n],at[n],i,j,temp,st[n],ft[n],wt[n],ta[n];

    for(i=0; i<n; i++)
    {
        printf("Enter process name, arrival time& burst time:");
        scanf("%d%d%d",&pn[i],&at[i],&bt[i]);
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(bt[i]<bt[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp = pn[i];
                pn[i] = pn[j];
                pn[j] = temp;
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0) st[i]=at[i];
        else st[i]=ft[i-1];

        wt[i]=st[i]-at[i];
        ft[i]=st[i]+bt[i];
        ta[i]=ft[i]-at[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(double)totwt/n;
    ata=(double)totta/n;
    printf("\nProcess_id \t arrivaltime \t bursttime \t waitingtime \t turnaroundtime");
    for(i=0; i<n; i++)
    {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d",pn[i],at[i],bt[i],wt[i],ta[i]);
    }
    printf("\nAverage waiting time: %f",awt);
    printf("\nAverage turnaroundtime: %f",ata);
    return 0;
}
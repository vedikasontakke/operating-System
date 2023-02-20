// Banker's Algorithm

/*
no po processes : 5
no of resources : 3

Allocation matrix 
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

MAX  matrix 
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

availabe 3 3 2

*/
#include <stdio.h>

int max[10][10] , allocation[10][10] , need[10][10] ;
int available[10];
int np , nr;

void readmatrix(int matrix[10][10])
{
    for(int i=0 ; i<np ; i++)
    {
        for(int j=0 ; j<nr ; j++)
            scanf("%d",&matrix[i][j]);
    }
}

void displaymatrix(int matrix[10][10])
{
    for(int i=0 ; i<np ; i++)
    {
        printf("\n P%d",i);
        for(int j=0 ; j<nr ; j++)
            printf(" %d",matrix[i][j]);
    }
}

void calulate_need()
{
    for(int i=0 ; i<np ; i++)
    {
        for(int j=0 ; j<nr ; j++)
           need[i][j] = max[i][j] - allocation[i][j];
    }       
}

void banker()
{
    int k=0,flag;
    int finish[10],safe_seq[10];

    for(int i=0 ; i<np ; i++)
        finish[i]=0;       // declare as all processes are incomplete
    
    for(int i=0 ; i<np ; i++)
    {
        flag = 0;
        if(finish[i] == 0)  // execute incomplete process
        {
            for(int j=0 ; j<nr ; j++)
            {
                if(need[i][j] > available[j])
                {
                    flag = 1;     // break the loop as need > availabe and go to the next process
                    break;
                }
            }

            if(flag==0)    //need is less than availabe so complete the process
            {
               finish[i] = 1;
               safe_seq[k++] = i;

               //add allocated resources of finished process in a availabe resources
               for(int j=0 ; j<nr ; j++)
                  available[j] += allocation[i][j];

                i=-1;   
            }
        }
    }

    flag = 0;               // check if all processes are completed 
    for(int i=0 ; i<np ; i++)
    {
        if(finish[i]==0)
        {
            printf("\ndeadlock occured \n");
            flag = 1;
            break;
        }
    }
    
    if(flag==0)
    {
        printf("\n\n the system is in safe state. \n Safe sequence is ===> ");
        
        for(int i=0 ; i<np ; i++)
          printf(" P%d ->",safe_seq[i]);
    }
}

int main()
{
    int j;

    // read inputs
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("\nEnter the number of resources: ");
    scanf("%d", &nr);
    printf("\nEnter the allocation matrix:\n");
    readmatrix(allocation);
    printf("\nEnter the max requried matrix:\n");
    readmatrix(max);

    printf("\nenter available resources : ");
    for(int i=0 ; i<nr ; i++)
        scanf("%d",&available[i]);
    
    // display entered data
    printf("\n---------- entered data --------------\n");
    printf("\n initial matrix \n");
    displaymatrix(allocation);
    printf("\n\n Maximum resources \n");
    displaymatrix(max);
    printf("\n\n avaialbe resources ");

    for(int i=0 ; i<nr ; i++)
       printf(" %d ",available[i]);

    // calculate and display need
    calulate_need();
    printf("\n\n need matrix is \n");
    displaymatrix(need);

    //execute
    banker();
    printf("\n\n");
    return 0;
}
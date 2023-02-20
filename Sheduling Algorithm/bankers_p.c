#include<stdio.h>
#include<conio.h>

int np , nr;
int max[10][10] , aloc[10][10] , need[10][10] ;

void readmatrix(int matrix[10][10])
{
    for(int i=0 ; i<np ; i++)
    {
        for(int j=0 ; j<nr ; j++)
        {
            scanf("%d",matrix[i][j]);
        }
    }
}

void calculate_need(int max[10][10] , int aloc[10][10] ,  int need[10][10])
{
    for(int i=0 ; i<np ; i++)
    {
        for(int j=0 ; j<nr ; j++)
        {
            need[i][j] = max[i][j] - aloc[i][j];
        }
    }
}

void bankers(int availabe[10])
{
    int finish[10] , safe_seq[10];
    int flag = 0 , k=0 ;

    for(int i=0 ; i<10 ; i++)
    {
        finish[i] = 0;
    }

    for(int i=0 ; i<np ; i++)
    {
        flag = 0;

        if(finish[i] == 0)
        {
              for(int j=0 ; j<nr ; j++)
            {
            if(need[i][j] > availabe[j])
            {
                flag = 1;
                break;
            }
           }
         

        if(flag == 0)
        {
            finish[i] = 1;
            safe_seq[k++] = i;
          
            for(int j=0 ; j<nr ; j++)
               {
                    availabe[j] += aloc[i][j];
               }
            
            i = i-1;
        }
    }

    }

    flag = 0;

    for(int i=0 ; i<np ; i++)
    {
        if(finish[i] == 0)
        {
            printf("deadlock");
            flag = 1;
            break;
        }
    }

    if(flag==0)
    {
        printf("system in safe state :");

        for(int i=0 ; i<np ; i++)
        {
                      printf(" P%d ->",safe_seq[i]);

        }
    }
}

int main()
{
    
    printf("enter no of processes : ");
    scanf("%d",&np);

    printf("\nenter no of resources : ");
    scanf("%d",&nr);

    int availabe[nr];

    printf("\nenter allocation matrix : ");
    readmatrix(aloc);

    printf("\nenter max matrix : ");
    readmatrix(max);

    printf("\nenter availabe matrix : ");
    for(int i=0 ; i<nr ; i++)
       scanf("%d",&availabe[i]);

    printf("\nneed matrix is : ");
    calculate_need(max , aloc , need);   

    for(int i=0 ; i<np ; i++)
    {
        printf("P%d  ",i);
        for(int j=0 ; j<nr ; j++)
        {
            scanf("%d", need[i][j]);
        }
    }

    bankers(availabe);
       
}
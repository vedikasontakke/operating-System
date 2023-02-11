#include<stdio.h>
int main()
{
int i,j,no_pages,a[50],frame[10],no_frames,k,avail,count=0;
            printf("\n ENTER THE NUMBER OF PAGES:\n");
            scanf("%d",&no_pages);
            printf("\n ENTER THE PAGE NUMBER :\n");
            for(i=1;i<=no_pages;i++)
            scanf("%d",&a[i]);
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no_frames);
            for(i=0;i<no_frames;i++)
            frame[i]= -1;   // initially frame is free
            
            j=0;
            printf("\tref string\t page frames\n");

            for(i=1;i<=no_pages;i++)
          {
             printf("%d\t\t",a[i]);
             avail=0;
             
             for(k=0;k<no_frames;k++)
                if(frame[k]==a[i]){
                    avail=1;    // page already exsits
                    break;
                }                   
                if (avail==0)
             {
                    frame[j]=a[i];
                    j=(j+1)%no_frames;   // increment j 
                    count++;      // page fault
                   
            }
             for(k=0;k<no_frames;k++)
                        printf("%d\t",frame[k]);
                   
                    printf("\n");
        }                       
                        printf("Page Fault Is %d",count);
                        return 0;
}

/*
Enter number of frames: 3
Enter number of pages: 10
Enter page reference string: 2 3 4 2 1 3 7 5 4 3
*/
#include<stdio.h>

int main()
{
      int no_pages , no_frames ;

    printf("enter number of pages : ");
    scanf("%d",&no_pages);

    printf("enter number of frames : ");
    scanf("%d",&no_frames);

    int pages[no_pages] , frames[no_frames] , temp[no_frames] , faults=0 , pos , flag3;
    printf("enter referance string : \n");

    for(int i=0 ; i<no_pages ; i++)
    {
        scanf("%d",&pages[i]);
    }

    // showing that frames are blank 
    for(int i=0 ; i<no_frames ; i++)
    {
        frames[i] = -1 ;
    }
 
        printf("page \t f1 \t\t f2 \t\t f3 \t\t \n");


        //outer loop

        for(int i=0 ; i<no_pages ; i++)
        {
            int flag1 = 0;
            int flag2 = 0;
            

            // if page found in frame
            for(int j=0 ; j<no_frames ; j++)
            {
                if(frames[j] == pages[i])
                {
                    flag1 = 1;
                    flag2 = 1;
                    break;
                }
            }

            // if frame is free
            
            if(flag1 == 0)
            {
                for(int j=0 ; j<no_frames ; j++)
               {
                   if(frames[j] == -1)
                   {
                       frames[j] = pages[i];
                       faults++;
                       flag2 = 1;
                       break;
                    }
                }
            }

            //temp how many times page found 
            if(flag2 == 0)
            {
                int flag3 = 0;
                for(int j=0 ; j<no_frames ; j++)
                {
                     temp[j] == -1;

                     for(int k= i+1 ; k<no_pages ; k++)
                     {
                        if(pages[k] == frames[j])
                        {
                            temp[j] = k;
                            break;
                        }
                     }
                }

                 for(int j=0 ; j<no_frames ; j++)
            {
                // if page not used in future 
                if(temp[j] == -1)
                {
                    pos = j;          // on which frame number page will be inserted
                    flag3= 1;
                    break;
                }
            }
               // if all pages are used in future 
               if(flag3 == 0)
               {
                   int max = temp[0];
                   pos = 0;          // if remove show error 
                  for(int j=1 ; j<no_frames ; j++)
                  {
                     if(temp[j] > max)
                     {
                        max = temp[j];
                        pos = j;
                     }
                  }
               }

            frames[pos] = pages[i];
            faults++;
            }

             printf("%d \t ",pages[i]);
        for(int j=0 ; j<no_frames ; j++)
        {
            printf("%d \t \t",frames[j]);
        }

        printf("\n");
           
        }
      
      printf("no of page faults are : %d \n",faults);

}
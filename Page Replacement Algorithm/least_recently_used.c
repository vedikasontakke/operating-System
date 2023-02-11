//C program for LRU replacement algorithm implementation
 
#include <stdio.h>
 
//user-defined function
// returns the posistion of the least counter that is minium value from the time array (frame which is recently used )
int findLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}
 
//main function
int main()
{
   int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
   printf("Enter number of frames: ");
   scanf("%d", &no_of_frames);
 
   printf("Enter number of pages: ");
   scanf("%d", &no_of_pages);
 
   printf("Enter reference string: ");
 
   for (i = 0; i < no_of_pages; ++i)
   {
      scanf("%d", &pages[i]);
   }
 
   for (i = 0; i < no_of_frames; ++i)
   {
      frames[i] = -1;
   }
    
    // outer loop
   for (i = 0; i < no_of_pages; ++i)
   {
      flag1 = flag2 = 0;
      
      // check if page already exits
      for (j = 0; j < no_of_frames; ++j)
      {
         if (frames[j] == pages[i])
         {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;              // to notify page is placed in framec
            break;
         }
      }
      
      // if any frame is empty 
      if (flag1 == 0)
      {
         for (j = 0; j < no_of_frames; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = pages[i];
               time[j] = counter;
               flag2 = 1;           // to notify page is placed in frame
               break;
            }
         }
      }
      
      // if frame is full and need to replace a page 
      if (flag2 == 0)
      {
         pos = findLRU(time, no_of_frames);
         counter++;
         faults++;
         frames[pos] = pages[i];
         time[pos] = counter;
      }
 
      printf("\n");
      
      // printf(every status of frames after page replacment 
      for (j = 0; j < no_of_frames; ++j)
      {
         printf("%d\t", frames[j]);
      }
   }
 
   printf("\nTotal Page Faults = %d", faults);
 
   return 0;
}
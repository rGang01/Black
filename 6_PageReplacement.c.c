// // 1) FIF0
// // Frame - 3
// //Page -[4,1,2,4,5]
// #include <stdio.h>

// void fifo(int numOfFrames, int numOfPages, int pages[])
// {
//     int frame[numOfFrames];
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         frame[i] = -1;
//     }

//     int hit = 0, miss = 0, index = -1;
    
//     // Print the header of the table
//     printf("Page ");
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         printf("Frame%d ", i + 1);
//     }
//     printf("\n");

//     for (int i = 0; i < numOfPages; i++)
//     {
//         int flag = 0;
//         for (int j = 0; j < numOfFrames; j++)
//         {
//             if (frame[j] == pages[i])
//             {
//                 flag = 1;
//                 break;
//             }
//         }

//         if (flag)
//         {
//             printf("%6d ", pages[i]);
//             for (int k = 0; k < numOfFrames; k++)
//             {
//                 if (frame[k] == -1)
//                     printf("%6s ", "-");
//                 else
//                     printf("%6d ", frame[k]);
//             }
//             hit++;
//         } 
//         else
//         {
//             index = (index + 1) % numOfFrames;
//             frame[index] = pages[i];
//             miss++;
//             printf("%6d ", pages[i]);
//             for (int k = 0; k < numOfFrames; k++)
//             {
//                 if (frame[k] == -1)
//                     printf("%6s ", "-");
//                 else
//                     printf("%6d ", frame[k]);
//             }
//         }
//         printf("\n");
//     }
//     printf("\nPage hits: %d", hit);
//     printf("\nPage misses: %d", miss);
// }

// int main()
// {
//     int p, f;
//     printf("Enter number of frames: \n");
//     scanf("%d", &f);
//     printf("Enter number of pages: ");
//     scanf("%d", &p);

//     int pages[p];
//     for (int i = 0; i < p; i++)
//     {
//         printf("Enter page: ");
//         scanf("%d", &pages[i]);
//     }
//     printf("\n");
//     fifo(f, p, pages);
// }



// //input : 3 5  &&  4 1 2 4 5  




// // 2) Optimal

// #include <stdio.h>

// void optimal(int numOfFrames, int numOfPages, int pages[])
// {
//     int position;
//     int frame[numOfFrames];
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         frame[i] = -1;
//     }

//     int hit = 0, miss = 0;

//     // Print the header of the table
//     printf("Page ");
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         printf("Frame%d ", i + 1);
//     }
//     printf("\n");

//     for (int i = 0; i < numOfPages; i++)
//     {
//         int flag1 = 0, flag2 = 0;
//         for (int j = 0; j < numOfFrames; j++)
//         {
//             if (frame[j] == pages[i])
//             {
//                 flag1 = flag2 = 1;
//                 hit++;
//                 break;
//             }
//         }
//         if (flag1 == 0)
//         {
//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 if (frame[j] == -1)
//                 {
//                     miss++;
//                     frame[j] = pages[i];
//                     flag2 = 1;
//                     break;
//                 }
//             }
//         }
//         if (flag2 == 0)
//         {
//             int flag3 = 0;
//             int temp[numOfFrames];
//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 temp[j] = -1;
//                 for (int k = i + 1; k < numOfPages; k++)
//                 {
//                     if (frame[j] == pages[k])
//                     {
//                         temp[j] = k;
//                         break;
//                     }
//                 }
//             }
//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 if (temp[j] == -1)
//                 {
//                     position = j;
//                     flag3 = 1;
//                     break;
//                 }
//             }

//             if (flag3 == 0)
//             {
//                 int max = temp[0];
//                 position = 0;
//                 for (int j = 1; j < numOfFrames; j++)
//                 {
//                     if (temp[j] > max)
//                     {
//                         max = temp[j];
//                         position = j;
//                     }
//                 }
//             }
//             frame[position] = pages[i];
//             miss++;
//         }
//         printf("%6d ", pages[i]);
//         for (int j = 0; j < numOfFrames; j++)
//         {
//             if (frame[j] == -1)
//                 printf("%6s ", "-");
//             else
//                 printf("%6d ", frame[j]);
//         }
//         printf("\n");
//     }
//     printf("\nPage hits: %d", hit);
//     printf("\nPage misses: %d", miss);
// }

// int main()
// {
//     int p, f;
//     printf("\nEnter number of frames: ");
//     scanf("%d", &f);
//     printf("Enter number of pages: ");
//     scanf("%d", &p);

//     int pages[p];
//     for (int i = 0; i < p; i++)
//     {
//         printf("Enter page: ");
//         scanf("%d", &pages[i]);
//     }
//     printf("\n");
//     optimal(f, p, pages);
//     return 0;
// }


// //input : 4 13  &&  7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2




// // 3) Least Recently Used (LRU) Page Replacement algorithm
// #include <stdio.h>

// void lur(int numOfFrames, int numOfPages, int pages[])
// {
//     int position;
//     int frame[numOfFrames];
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         frame[i] = -1;
//     }

//     int hit = 0, miss = 0;

//     // Print the header of the table
//     printf("Page ");
//     for (int i = 0; i < numOfFrames; i++)
//     {
//         printf("Frame%d ", i + 1);
//     }
//     printf("\n");

//     for (int i = 0; i < numOfPages; i++)
//     {
//         int flag1 = 0, flag2 = 0;

//         for (int j = 0; j < numOfFrames; j++)
//         {
//             if (frame[j] == pages[i])
//             {
//                 hit++;
//                 flag1 = flag2 = 1;
//                 break;
//             }
//         }
//         if (flag1 == 0)
//         {
//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 if (frame[j] == -1)
//                 {
//                     frame[j] = pages[i];
//                     miss++;
//                     flag2 = 1;
//                     break;
//                 }
//             }
//         }
//         if (flag2 == 0)
//         {
//             int flag3 = 0;
//             int temp[numOfFrames];
//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 temp[j] = -1;
//                 for (int k = i - 1; k >= 0; k--)
//                 {
//                     if (frame[j] == pages[k])
//                     {
//                         temp[j] = k;
//                         break;
//                     }
//                 }
//             }

//             for (int j = 0; j < numOfFrames; j++)
//             {
//                 if (temp[j] == -1)
//                 {
//                     position = j;
//                     flag3 = 1;
//                     break;
//                 }
//             }

//             if (flag3 == 0)
//             {
//                 int min = temp[0];
//                 position = 0;
//                 for (int j = 1; j < numOfFrames; j++)
//                 {
//                     if (temp[j] < min)
//                     {
//                         min = temp[j];
//                         position = j;
//                     }
//                 }
//             }
//             frame[position] = pages[i];
//             miss++;
//         }
//         printf("%6d ", pages[i]);
//         for (int j = 0; j < numOfFrames; j++)
//         {
//             if (frame[j] == -1)
//                 printf("%6s ", "-");
//             else
//                 printf("%6d ", frame[j]);
//         }
//         printf("\n");
//     }
//     printf("\nPage hits: %d", hit);
//     printf("\nPage misses: %d", miss);
// }

// int main()
// {
//     int p, f;
//     printf("\nEnter number of frames: ");
//     scanf("%d", &f);
//     printf("Enter number of pages: \n");
//     scanf("%d", &p);

//     int pages[p];
//     for (int i = 0; i < p; i++)
//     {
//         printf("Enter page: ");
//         scanf("%d", &pages[i]);
//     }
//     printf("\n");
//     lur(f, p, pages);
//     return 0;
// }


// //input : 3 15  &&  1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3





// second chance or clock

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int reference;
} Frame;

void printFrames(Frame frames[], int numFrames) {
    printf("Frames: ");
    for (int i = 0; i < numFrames; i++) {
        if (frames[i].page != -1) {
            printf("%d ", frames[i].page);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int findPage(Frame frames[], int numFrames, int page) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i].page == page) {
            return i;
        }
    }
    return -1;
}

void secondChance(int pages[], int numPages, int numFrames) {
    Frame frames[MAX_FRAMES];
    for (int i = 0; i < numFrames; i++) {
        frames[i].page = -1;
        frames[i].reference = 0;
    }

    int pointer = 0;
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int pageIndex = findPage(frames, numFrames, page);

        if (pageIndex != -1) {
            // Page is already in the frames, give it a second chance
            frames[pageIndex].reference = 1;
        } else {
            // Page fault occurs
            while (frames[pointer].reference == 1) {
                frames[pointer].reference = 0;
                pointer = (pointer + 1) % numFrames;
            }

            frames[pointer].page = page;
            frames[pointer].reference = 1;
            pointer = (pointer + 1) % numFrames;
            pageFaults++;
        }

        printFrames(frames, numFrames);
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {2,5,10,1,2,2,6,9,1,2,10,2,6,1,2,1,6,9,5,1};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int numFrames = 4;

    printf("Second Chance Page Replacement Algorithm\n");
    secondChance(pages, numPages, numFrames);

    return 0;
}

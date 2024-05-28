#define MAX 20
#include<stdio.h> 

// Process [212,417,112,426]
// Block [100,500,200,300,600]

void firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
    int i, j; 

    int allocation[n]; 

    for(i = 0; i < n; i++) 
    { 
        allocation[i] = -1; 
    } 
    
   
    for (i = 0; i < n; i++)        //here, n -> number of processes 
    { 
        for (j = 0; j < m; j++)        //here, m -> number of blocks 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
               
                allocation[i] = j; 
  
                // Reduce available memory in this block. 
                blockSize[j] -= processSize[i]; 
  
                break;    //go to the next process in the queue 
            }  
        } 
    } 
  
} 

void BestFit(int blockSize[], int m, int processSize[], int n) 
{
    int i, j; 
    int min = 100000;
    int index;

    int allocation[n]; 

    for(i = 0; i < n; i++) 
    { 
        allocation[i] = -1; 
    } 

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
          if(blockSize[j]>processSize[i] && blockSize[j]-processSize[i]<min)
          {
            min = blockSize[j]-processSize[i];
            index = j;
          } 
        }
        blockSize[index] = min;
        allocation[i] = index;
    }
}


void WorstFit(int blockSize[], int m, int processSize[], int n) 
{
    int i, j; 
    int max = -100000;
    int index;

    int allocation[n]; 

    for(i = 0; i < n; i++) 
    { 
        allocation[i] = -1; 
    } 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          if(blockSize[j]>processSize[i] && blockSize[j]-processSize[i]>max)
          {
            max = blockSize[j]-processSize[i];
            index = j;
          } 
        }
        blockSize[index] = max;
        allocation[i] = index;
    }
}

void NextFit(int blockSize[], int m, int processSize[], int n) 
{
    int i,j;
    int s = 0;

    for(i=0;i<n;i++)
    {
        for(j=s;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                blockSize[j] = blockSize[j]-processSize[i];
                break;
            }
        }
       s = j;

    }
    
}

int main() 
{ 
    int m,n;
    int blockSize[MAX];
    int processSize[MAX];

    printf("Enter block size:\n");
    scanf("%d",&m);
    printf("Enter blocks:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&blockSize[i]);
    }

    printf("Enter process size:\n");
    scanf("%d",&n);
    printf("Enter process array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processSize[i]);
    }
  
    // firstFit(blockSize, m, processSize, n); 
    // // BestFit(blockSize,m,processSize,n);
    // // WorstFit(blockSize,m,processSize,n);
    // NextFit(blockSize,m,processSize,n);

    printf("The final block sizze is:\n");
    for(int i=0;i<m;i++)
    {
        printf("%d\t",blockSize[i]);
    }

 return 0;
}

















// // BestFit - 01
// #include <stdio.h>

// void bestFit(int m, int n, int blockSize[], int processSize[])
// {
//     int allocated[n];
//     for (int i = 0; i < n; i++)
//     {
//         allocated[i] = -1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int bestIndex = -1;

//         for (int j = 0; j < m; j++)
//         {
//             if (blockSize[j] >= processSize[i])
//             {
//                 if (bestIndex == -1)
//                 {
//                     bestIndex = j;
//                 }
//                 else if (blockSize[bestIndex] > blockSize[j])
//                 {
//                     bestIndex = j;
//                 }
//             }
//         }

//         if (bestIndex != -1)
//         {
//             allocated[i] = bestIndex;
//             blockSize[bestIndex] -= processSize[i];
//         }
//     }

//     printf("\nProcess No.\tProcess Size\tBlock no.\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d\t\t", i + 1);
//         printf("%d\t\t", processSize[i]);
//         if (allocated[i] != -1)
//         {
//             printf("%d", allocated[i] + 1);
//         }
//         else
//         {
//             printf("Not Allocated");
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int m, n;
//     printf("Enter number of blocks : ");
//     scanf("%d", &m);
//     printf("Enter number of processes : ");
//     scanf("%d", &n);
//     int blockSize[m], processSize[n];

//     for (int i = 0; i < m; i++)
//     {
//         printf("Enter size of block %d : ", i + 1);
//         scanf("%d", &blockSize[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter size of process %d : ", i + 1);
//         scanf("%d", &processSize[i]);
//     }

//     bestFit(m, n, blockSize, processSize);
// }



// //Input :  5 4  &&  100 500 200 300 600  &&  212 417 112 426




// //FirstFit -(01)
// #include <stdio.h>
// void firstFit(int blockSize[], int m, int processSize[], int n)
// {
//     int allocated[n];

//     for (int i = 0; i < n; i++)
//     {
//         allocated[i] = -1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (blockSize[j] >= processSize[i])
//             {
//                 allocated[i] = j;
//                 blockSize[j] -= processSize[i];
//                 break;
//             }
//         }
//     }

//     printf("\nProcess No.\tProcess Size\tBlock no.\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d\t\t", i + 1);
//         printf("%d\t\t", processSize[i]);
//         if (allocated[i] != -1)
//         {
//             printf("%d", allocated[i] + 1);
//         }
//         else
//         {
//             printf("Not Allocated");
//         }
//         printf("\n");
//     }
// }


// int main()
// {
//     int m, n;
//     printf("\nEnter number of blocks : ");
//     scanf("%d", &m);
//     printf("Enter number of processes : \n");
//     scanf("%d", &n);
//     int blockSize[m], processSize[n];

//     for (int i = 0; i < m; i++)
//     {
//         printf("Enter size of block %d : ", i + 1);
//         scanf("%d", &blockSize[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter size of process %d : ", i + 1);
//         scanf("%d", &processSize[i]);
//     }

//     firstFit(blockSize, m, processSize, n);
    
// }


// //Input : 5 4  &&  100 500 200 300 600  &&  212 417 112 426




// Next Fit(01)
// #include <stdio.h>

// void nextFit(int m, int n, int blockSize[], int processSize[])
// {
//     int allocated[n];
//     for (int i = 0; i < n; i++)
//     {
//         allocated[i] = -1;
//     }
//     int j = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         while (count < m)
//         {
//             if (blockSize[j] >= processSize[i])
//             {
//                 allocated[i] = j;
//                 blockSize[j] -= processSize[i];
//                 break;
//             }
//             j = (j + 1) % m;
//             count++;
//         }
//     }

//     printf("\nProcess No.\tProcess Size\tBlock no.\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d\t\t", i + 1);
//         printf("%d\t\t", processSize[i]);
//         if (allocated[i] != -1)
//         {
//             printf("%d", allocated[i] + 1);
//         }
//         else
//         {
//             printf("Not Allocated");
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int m, n;
//     printf("Enter number of blocks : ");
//     scanf("%d", &m);
//     printf("Enter number of processes : ");
//     scanf("%d", &n);
//     int blockSize[m], processSize[n];

//     for (int i = 0; i < m; i++)
//     {
//         printf("Enter size of block %d : ", i + 1);
//         scanf("%d", &blockSize[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter size of process %d : ", i + 1);
//         scanf("%d", &processSize[i]);
//     }
//     nextFit(m, n, blockSize, processSize);
// }


// //Input : 3 3  &&  5 10 20  &&  10 20 30







// WorstFit(01)
#include <stdio.h>

void worstFit(int m, int n, int blockSize[], int processSize[])
{
    int allocated[n];
    for (int i = 0; i < n; i++)
    {
        allocated[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int worstIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIndex == -1)
                {
                    worstIndex = j;
                }
                else if (blockSize[worstIndex] < blockSize[j])
                {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1)
        {
            allocated[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    printf("\nProcess No. \tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", i + 1);
        printf("%d\t\t", processSize[i]);
        if (allocated[i] != -1)
        {
            printf("%d", allocated[i] + 1);
        }
        else
        {
            printf("Not Allocated");
        }
        printf("\n");
    }
}

int main()
{
    int m, n;
    printf("Enter number of blocks : ");
    scanf("%d", &m);
    printf("Enter number of processes : ");
    scanf("%d", &n);
    int blockSize[m], processSize[n];

    for (int i = 0; i < m; i++)
    {
        printf("Enter size of block %d : ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter size of process %d : ", i + 1);
        scanf("%d", &processSize[i]);
    }
    worstFit(m, n, blockSize, processSize);
}



//Input :  5 4  &&  100 500 200 300 600  &&  212 417 112 426

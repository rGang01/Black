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

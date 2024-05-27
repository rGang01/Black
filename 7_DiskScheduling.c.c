#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, done = 0, headPosition;
    float tso = 0;
    printf("Enter number of requests : ");
    scanf("%d", &n);
    printf("Enter head position : ");
    scanf("%d", &headPosition);
    int requests[n];
    printf("\nEnter request sequence \n");
    for (int i = 0; i < n; i++) {
        printf("Enter request %d : ", i);
        scanf("%d", &requests[i]);
    }
    
    printf("\nSeek sequence : ");
    int initialHeadPosition = headPosition;
    for (int i = 0; i < n; i++) {
        tso = tso + abs(headPosition - requests[i]);
        headPosition = requests[i];
        done++;

        if (done == n) {
            printf("%d\n", requests[i]);
        } else {
            printf("%d -> ", requests[i]);
        }
    }
    
    printf("\nTotal Seek operations/count : %.2f\n", tso);
    printf("Average Seek Length : %.2f\n", tso / n);

    // // Print the sequence of head movements
    // printf("Sequence of head movements:\n");
    // headPosition = initialHeadPosition; // reset the initial head position
    // for (int i = 0; i < n; i++) {
    //     printf("Move from %d to %d\n", headPosition, requests[i]);
    //     headPosition = requests[i];
    // }

    return 0;
}


// Input : 8  &&  50  &&  176, 79, 34, 60, 92, 11, 41, 114







// // 2) SSTF(Shortest Seek time First)
// // The basic idea is the tracks that are closer to the current disk head position
// // should be serviced first in order to minimize the seek operations is basically known as Shortest Seek Time First (SSTF).
// #include <stdio.h>
// #include <stdlib.h>

// void sstf(int n, int headPosition, int requests[])
// {
//     int visited[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = 0;
//     }
//     float tso = 0;
//     int done = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int min = 99999;
//         int index;
//         for (int j = 0; j < n; j++)
//         {
//             if (visited[j] == 0)
//             {
//                 if (abs(headPosition - requests[j]) < abs(headPosition - min))
//                 {
//                     min = requests[j];
//                     index = j;
//                 }
//             }
//         }
//         tso += abs(headPosition - min);
//         headPosition = min;
//         done++;
//         visited[index] = 1;
//         if (done == n)
//         {
//             printf("%d\n", min);
//         }
//         else
//         {
//             printf("%d -> ", min);
//         }
//     }
//     printf("\nTotal Seek operations/count : %.2f\n", tso);
//     printf("Average Seek Length : %.2f\n", tso / n);
// }

// int main()
// {
//     int n, headPosition;
//     printf("Enter number of requests : ");
//     scanf("%d", &n);
//     printf("Enter head position : ");
//     scanf("%d", &headPosition);
//     int requests[n];
//     printf("\nEnter request sequence \n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter request %d : ",i);
//         scanf("%d", &requests[i]);
//     }
//     printf("\nSeek sequence : ");
//     sstf(n, headPosition, requests);
// }

// //Input : 8  &&  50  &&  176, 79, 34, 60, 92, 11, 41, 114





// 3)Scan

// #include <stdio.h>
// #include <stdlib.h>

// // Comparison function for qsort
// int compare(const void *a, const void *b) {
//     return (*(int *)a - *(int *)b);
// }

// void SCAN(int requests[], int n, int head, int direction, int disk_size) {
//     int seek_count = 0;
//     int distance, cur_track;
//     int size = n + 2;
//     int sorted_requests[size];

//     // Copy the request array to the new array
//     for (int i = 0; i < n; i++) {
//         sorted_requests[i] = requests[i];
//     }

//     // Add the head and end values based on direction
//     sorted_requests[n] = head;
//     sorted_requests[n + 1] = (direction == 1) ? disk_size - 1 : 0;

//     // Sort the array
//     qsort(sorted_requests, size, sizeof(int), compare);

//     // Find the position of the head in the sorted array
//     int pos;
//     for (int i = 0; i < size; i++) {
//         if (sorted_requests[i] == head) {
//             pos = i;
//             break;
//         }
//     }

//     printf("Seek Sequence is:\n");

//     // Process the requests based on the direction
//     if (direction == 1) {
//         // Move towards the end of the disk
//         for (int i = pos; i < size; i++) {
//             cur_track = sorted_requests[i];
//             distance = abs(cur_track - head);
//             seek_count += distance;
//             head = cur_track;
//             printf("%d ", cur_track);
//         }
//         // Move towards the start of the disk
//         for (int i = pos - 1; i >= 0; i--) {
//             cur_track = sorted_requests[i];
//             distance = abs(cur_track - head);
//             seek_count += distance;
//             head = cur_track;
//             printf("%d ", cur_track);
//         }
//     } else {
//         // Move towards the start of the disk
//         for (int i = pos; i >= 0; i--) {
//             cur_track = sorted_requests[i];
//             distance = abs(cur_track - head);
//             seek_count += distance;
//             head = cur_track;
//             printf("%d ", cur_track);
//         }
//         // Move towards the end of the disk
//         for (int i = pos + 1; i < size; i++) {
//             cur_track = sorted_requests[i];
//             distance = abs(cur_track - head);
//             seek_count += distance;
//             head = cur_track;
//             printf("%d ", cur_track);
//         }
//     }

//     printf("\nTotal number of seek operations = %d\n", seek_count);
// }

// int main() {
//     int n, head, direction, disk_size;

//     // Get the number of requests
//     printf("Enter the number of requests: ");
//     scanf("%d", &n);

//     int requests[n];

//     // Get the requests
//     printf("Enter the requests:\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }

//     // Get the initial head position
//     printf("Enter the initial head position: ");
//     scanf("%d", &head);

//     // Get the direction
//     printf("Enter the direction (1 for high, 0 for low): ");
//     scanf("%d", &direction);

//     disk_size = 200;

//     // Call the SCAN function
//     SCAN(requests, n, head, direction, disk_size);

//     return 0;
// }
// //8
// // Request sequence = {176, 79, 34, 60, 92, 11, 41, 114}
// // Initial head position = 50
// // Direction = left (We are moving from right to left)





// 4) C scan

// #include <stdio.h>
// #include <stdlib.h>

// // Comparison function for qsort
// int compare(const void *a, const void *b) {
//     return (*(int *)a - *(int *)b);
// }

// void CSCAN(int requests[], int n, int head, int disk_size) {
//     int seek_count = 0;
//     int distance, cur_track;
//     int size = n + 3; // Including head, end of disk, and start of disk (0)
//     int sorted_requests[size];

//     // Copy the request array to the new array
//     for (int i = 0; i < n; i++) {
//         sorted_requests[i] = requests[i];
//     }

//     // Add the head, end, and start values based on CSCAN
//     sorted_requests[n] = head;
//     sorted_requests[n + 1] = disk_size - 1; // End of the disk
//     sorted_requests[n + 2] = 0; // Start of the disk

//     // Sort the array
//     qsort(sorted_requests, size, sizeof(int), compare);

//     // Find the position of the head in the sorted array
//     int pos;
//     for (int i = 0; i < size; i++) {
//         if (sorted_requests[i] == head) {
//             pos = i;
//             break;
//         }
//     }

//     printf("Seek Sequence is:\n");

//     // Process the requests from head to end of the disk
//     for (int i = pos; i < size; i++) {
//         cur_track = sorted_requests[i];
//         distance = abs(cur_track - head);
//         seek_count += distance;
//         head = cur_track;
//         printf("%d ", cur_track);
//     }

//     // Jump to the start of the disk and move to the position before the initial head
//     // Since it is circular, we simulate the jump
//     head = 0;
//     seek_count += disk_size - 1; // Moving from end to start of the disk

//     for (int i = 0; i < pos; i++) {
//         cur_track = sorted_requests[i];
//         distance = abs(cur_track - head);
//         seek_count += distance;
//         head = cur_track;
//         printf("%d ", cur_track);
//     }

//     printf("\nTotal number of seek operations = %d\n", seek_count);
// }

// int main() {
//     int n, disk_size, head;

//     printf("Enter the number of requests: ");
//     scanf("%d", &n);

//     printf("Enter the initial head position: ");
//     scanf("%d", &head);

//     int requests[n];
//     printf("Enter the request sequence:\n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &requests[i]);
//     }



//     disk_size = 200;

//     CSCAN(requests, n, head, disk_size);

//     return 0;
// }
// // Request sequence = {176, 79, 34, 60, 92, 11, 41, 114}
// // Initial head position = 50
// // Direction = right(We are moving from left to right)






// 5) Clock


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
    int pages[] = {1, 2, 3, 2, 1, 4, 5, 1, 2, 3, 4, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int numFrames = 3;

    printf("Second Chance Page Replacement Algorithm\n");
    secondChance(pages, numPages, numFrames);

    return 0;
}
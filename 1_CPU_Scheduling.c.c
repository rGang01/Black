// // 1) FCFS

// #include <stdio.h>

// int main() {
//     int n, i, at[20], bt[20], wt[20], tat[20], avwt = 0, avtat = 0;

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter arrival time and burst time for each process:\n");   // AT -- 0 10 15
//      // BT -- 10 5 8
//     for (i = 0; i < n; i++) {
//         printf("P[%d]: ", i + 1);
//         scanf("%d %d", &at[i], &bt[i]);
//     }

//     wt[0] = 0;
//     for (i = 1; i < n; i++) {
//         wt[i] = wt[i - 1] + bt[i - 1] - at[i] + at[i - 1];
//         avwt += wt[i];
//     }

//     for (i = 0; i < n; i++) {
//         tat[i] = wt[i] + bt[i];
//         avtat += tat[i];
//     }

//     printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (i = 0; i < n; i++) {
//         printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
//     }

//     avwt /= n;
//     avtat /= n;

//     printf("Average Waiting Time: %d\n", avwt);
//     printf("Average Turnaround Time: %d\n", avtat);

//     return 0;
// }




// // 2) Priority Non primitive 

// #include <stdio.h>
// #include <stdlib.h>

// // 

// // Structure to represent a process
// typedef struct {
//     int id;  // 1 2 3 4 5 6 7
//     int burst_time;  // 3 5 4 2 9 4 10
//     int priority;  // 2 6 3 5 7 4 10
//     int arrival_time;  // 0 2 1 4 6 5 7
//     int waiting_time; 
//     int turnaround_time;
//     int completion_time;
// } Process;

// // Function to compare processes based on their priorities
// int compare(const void *a, const void *b) {
//     Process *p1 = (Process *)a;
//     Process *p2 = (Process *)b;
//     return p1->priority - p2->priority;
// }

// // Function to implement non-preemptive priority scheduling
// void nonPreemptivePriorityScheduling(int n, Process processes[]) {
//     // Sort processes based on their priorities
//     qsort(processes, n, sizeof(Process), compare);

//     int current_time = 0;
//     int total_waiting_time = 0;
//     int total_turnaround_time = 0;

//     for (int i = 0; i < n; i++) {
//         // If the process has not arrived yet, wait
//         if (processes[i].arrival_time > current_time) {
//             current_time = processes[i].arrival_time;
//         }

//         // Calculate waiting time
//         processes[i].waiting_time = current_time - processes[i].arrival_time;

//         // Calculate turnaround time
//         processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

//         // Calculate completion time
//         processes[i].completion_time = processes[i].turnaround_time;

//         // Update total waiting and turnaround times
//         total_waiting_time += processes[i].waiting_time;
//         total_turnaround_time += processes[i].turnaround_time;

//         // Update current time
//         current_time += processes[i].burst_time;
//     }

//     // Calculate average waiting and turnaround times
//     float avg_waiting_time = (float)total_waiting_time / n;
//     float avg_turnaround_time = (float)total_turnaround_time / n;

//     printf("Process ID\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].burst_time, processes[i].priority, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
//     }

//     printf("Average Waiting Time: %.2f\n", avg_waiting_time);
//     printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     Process processes[n];

//     for (int i = 0; i < n; i++) {
//         printf("Enter Process ID: ");
//         scanf("%d", &processes[i].id);
//         printf("Enter Burst Time: ");
//         scanf("%d", &processes[i].burst_time);
//         printf("Enter Priority: ");
//         scanf("%d", &processes[i].priority);
//         printf("Enter Arrival Time: ");
//         scanf("%d", &processes[i].arrival_time);
//     }

//     nonPreemptivePriorityScheduling(n, processes);

//     return 0;
// }





// // 3) Priority primitive
// #include <stdio.h>

// typedef struct Process {
//     int pid;
//     int burst_time;  // 3 4 6 4 2
//     int arrival_time; // 0 1 2 3 5 
//     int priority;  // 3 2 4 6 10
//     int remaining_time;
//     int turnaround_time;
//     int waiting_time;
// } Process;

// void preemptive_priority(Process processes[], int n, float *avg_turnaround_time, float *avg_waiting_time) {
//     int time = 0;
//     int completed = 0;
//     float total_turnaround_time = 0, total_waiting_time = 0;

//     while (completed != n) {
//         int highest_priority = -1;
//         int next_process = -1;

//         for (int i = 0; i < n; i++) {
//             if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
//                 if (highest_priority == -1 || processes[i].priority < highest_priority) {
//                     highest_priority = processes[i].priority;
//                     next_process = i;
//                 }
//             }
//         }

//         if (next_process == -1) {
//             time++;
//             continue;
//         }

//         processes[next_process].remaining_time--;

//         if (processes[next_process].remaining_time == 0) {
//             completed++;
//             processes[next_process].turnaround_time = time + 1 - processes[next_process].arrival_time;
//             processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;
//             total_turnaround_time += processes[next_process].turnaround_time;
//             total_waiting_time += processes[next_process].waiting_time;
//         }

//         time++;
//     }

//     *avg_turnaround_time = total_turnaround_time / n;
//     *avg_waiting_time = total_waiting_time / n;
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     Process processes[n];

//     for (int i = 0; i < n; i++) {
//         printf("\nEnter details for process P%d:\n", i + 1);
//         printf("Arrival Time: ");
//         scanf("%d", &processes[i].arrival_time);
//         printf("Burst Time: ");
//         scanf("%d", &processes[i].burst_time);
//         printf("Priority: ");
//         scanf("%d", &processes[i].priority);
//         processes[i].pid = i + 1;
//         processes[i].remaining_time = processes[i].burst_time;
//         processes[i].turnaround_time = 0;
//         processes[i].waiting_time = 0;
//     }

//     float avg_turnaround_time, avg_waiting_time;
//     preemptive_priority(processes, n, &avg_turnaround_time, &avg_waiting_time);

//     printf("\nPreemptive Priority Algorithm - \n\n");
//     printf("PID\tAT\tBT\tPriority\tTAT\tWT\n");

//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].turnaround_time, processes[i].waiting_time);
//     }

//     printf("Average Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n", avg_turnaround_time, avg_waiting_time);

//     return 0;
// }



// // 4) RoundRobin

// #include <stdio.h>
// #include <stdlib.h>

// struct process {
//     // TQ = 3
//     int arrivalTime;  // 0 5 1 6 8
//     int burstTime;  // 8 2 7 3 5
//     int finishTime;  
//     int turnTime;
//     int waitingTime;
//     int startTime;
// };

// int main() {
//     int n, tq, total_TAT = 0, BT[50], total_WT = 0, index;
//     struct process p[50];
//     float avgTAT, avgWT;

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter time quantum of CPU: ");
//     scanf("%d", &tq);

//     // Separate input for arrival times
//     for (int i = 0; i < n; i++) {
//         printf("Enter arrival time of process %d: ", i + 1);
//         scanf("%d", &p[i].arrivalTime);
//     }

//     // Separate input for burst times
//     for (int i = 0; i < n; i++) {
//         printf("Enter burst time of process %d: ", i + 1);
//         scanf("%d", &p[i].burstTime);
//         BT[i] = p[i].burstTime;
//     }

//     int q[100], front = -1, rear = -1;
//     q[++rear] = 0;

//     int current_time = 0;
//     int completed = 0;
//     int mark[100] = {0};
//     while (completed != n) {
//         index = q[++front];

//         // to find start time of process
//         if (BT[index] == p[index].burstTime) {
//             p[index].startTime = current_time > p[index].arrivalTime ? current_time
//                                                                      : p[index].arrivalTime;
//             current_time = p[index].startTime;
//         }

//         // check if process if finished nor not
//         if (BT[index] > tq) {
//             BT[index] -= tq;
//             current_time += tq;
//         } else {
//             current_time += BT[index];

//             p[index].finishTime = current_time;
//             p[index].turnTime = p[index].finishTime - p[index].arrivalTime;
//             p[index].waitingTime = p[index].turnTime - p[index].burstTime;
//             total_WT += p[index].waitingTime;
//             total_TAT += p[index].turnTime;
//             completed++;

//             BT[index] = 0;
//         }

//         // add new processes to queue of at <= CT
//         for (int i = 1; i < n; i++) {
//             if (BT[i] > 0 && p[i].arrivalTime <= current_time && !mark[i]) {
//                 mark[i] = 1;
//                 q[++rear] = i;
//             }
//         }

//         // enter current process again in queue if it not finished
//         if (BT[index] > 0) {
//             q[++rear] = index;
//         }
//     }

//     avgWT = (float)total_WT / n;
//     avgTAT = (float)total_TAT / n;
//     printf("\n");
//     printf("Process\tAT\tBT\tFT\tTAT\tWT\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t%d\t%d\n",
//                i + 1,
//                p[i].arrivalTime,
//                p[i].burstTime,
//                p[i].finishTime,
//                p[i].turnTime,
//                p[i].waitingTime);
//     }
//     printf("\n");
//     printf("Average Waiting Time = %.2f\n", avgWT);
//     printf("Average Turnaround Time = %.2f\n", avgTAT);
//     return 0;
// }
//  //input 4 && arrival : 0 1 2 4 && brust : 5 4 2 1 && TQ = 2





// // 5)  SJF(Premative)

// #include <stdio.h>
  
// // BT   6 2 8 3 4
// // AT 2 5 1 0 4

// int main() {
//     int total_BT = 0, smallest, n;
//     int tat = 0, wt = 0;

//     printf("\nEnter the number of processes: \n");
//     scanf("%d", &n);

//     int burst_time[n], remaining_bt[n], at[n], completion_time[n], turnaround_time[n], waiting_time[n];

//     // Input burst times
//     printf("\nBurst time\n");
//     for (int i = 0; i < n; i++) {
//         printf("Enter burst time for process P%d: ", i);
//         scanf("%d", &burst_time[i]);
//         remaining_bt[i] = burst_time[i]; // Initialize remaining burst times
//         total_BT += burst_time[i];
//     }

//     // Input arrival times
//     printf("\nArrival time\n");
//     for (int i = 0; i < n; i++) {
//         printf("Enter arrival time for process P%d: ", i);
//         scanf("%d", &at[i]);
//     }

//     remaining_bt[n] = 9999; // Sentinel value for comparison

//     int time = 0, completed = 0;
//     while (completed < n) {
//         smallest = n;
//         for (int i = 0; i < n; i++) {
//             if (at[i] <= time && remaining_bt[i] > 0 && remaining_bt[i] < remaining_bt[smallest])
//                 smallest = i;
//         }

//         if (smallest == n) {
//             time++;
//             continue;
//         }

//         time += remaining_bt[smallest];
//         completion_time[smallest] = time;
//         turnaround_time[smallest] = completion_time[smallest] - at[smallest];
//         waiting_time[smallest] = turnaround_time[smallest] - burst_time[smallest];

//         tat += turnaround_time[smallest];
//         wt += waiting_time[smallest];
//         remaining_bt[smallest] = 0;
//         completed++;
//     }

//     // Display results
//     printf("\nProcess\t\tBT\t\tAT\t\tCT\t\tTAT\t\tWT\n");
//     for (int i = 0; i < n; i++) {
//         printf("P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", i, burst_time[i], at[i], completion_time[i], turnaround_time[i], waiting_time[i]);
//     }

//     // Display average times
//     printf("\n\nAverage waiting time = %.2f", wt * 1.0 / n);
//     printf("\nAverage turnaround time = %.2f", tat * 1.0 / n);

//     return 0;
// }

// //Input : 5  &&  6 2 8 3 4   &&   2 5 1 0 4






//SJF(Primitive)  SRTF
// //AT - 2 5 1 0 4
// // BT - 6 2 8 3 4

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20

// int main()
// {
//     int a[MAX][7], i, CPU_Total_Time = 0, CPU_Current_Time, small, n, temp[MAX];
//     float awt, atat;
//     printf("Enter number of processes : ");
//     scanf("%d", &n);

//     printf("\nBurst time\n");
//     for (i = 0; i < n; i++)
//     {

//         a[i][0] = i;
//         printf("Enter burst time of process P%d : ", i);
//         scanf("%d",&a[i][2]);
//         CPU_Total_Time += a[i][2];
//         a[i][6] = -1;
//     }

//     printf("\nArrival time\n");
//     for (i = 0; i < n; i++)
//     {

//         a[i][0] = i;
//         printf("Enter arrival time of process P%d : ", i);
//         scanf("%d", &a[i][1]);
//         //CPU_Total_Time += a[i][2];
//         a[i][6] = -1;
//     }

//     small = a[0][1];
//     for (i = 0; i < n; i++)
//     {
//         if (small > a[i][1])
//             small = a[i][1];

//         temp[i] = a[i][2];
//     }

//     // printf("Starting CPU_Current_Time at %d",small);
//     CPU_Current_Time = small;
//     CPU_Total_Time = CPU_Total_Time + small;

//     while (CPU_Current_Time < CPU_Total_Time)
//     {
//         // checking AT
//         for (i = 0; i < n; i++)
//         {
//             if (a[i][6] == -1 && a[i][1] <= CPU_Current_Time)
//             {
//                 small = i;
//                 break;
//             }
//         }

//         // checking smallest BT for AT
//         for (i = 0; i < n; i++)
//         {

//             if (a[i][6] == -1 && a[i][1] <= CPU_Current_Time)
//             {
//                 if (a[small][2] > a[i][2])
//                     small = i;
//             }
//         }

//         CPU_Current_Time++;
//         a[small][2]--;
//         if (a[small][2] == 0) // processed
//         {
//             a[small][6] = 0;                // status
//             a[small][3] = CPU_Current_Time; // completion time
//         }
//     }

//     atat = 0.0;
//     awt = 0.0;
//     printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\t");
//     for (i = 0; i < n; i++)
//     {
//         printf("\n %d", a[i][0]);
//         printf("\t %d", a[i][1]);
//         printf("\t %d", temp[i]);
//         printf("\t %d", a[i][3]);
//         a[i][4] = a[i][3] - a[i][1];
//         printf("\t %d", a[i][4]);
//         a[i][5] = a[i][4] - temp[i];
//         printf("\t %d", a[i][5]);
//         awt = awt + a[i][5];
//         atat = atat + a[i][4];
//     }
//     atat = atat / n;
//     awt = awt / n;
//     printf("\n\nAverage TAT : %.2f", atat);
//     printf("\nAverage WT : %.2f", awt);

//     return 0;
// }


// //Input : 5  &&  6 2 8 3 4   &&   2 5 1 0 4
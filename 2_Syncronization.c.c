// // 1) Producer Consumer
// #include <pthread.h>
// #include <semaphore.h>
// #include <stdlib.h>
// #include <stdio.h>

// /*
// This program provides a possible solution for producer-consumer problem using mutex and semaphore.
// I have used 5 producers and 5 consumers to demonstrate the solution. You can always play with these values.
// */

// #define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
// #define BufferSize 5 // Size of the buffer

// sem_t empty;
// sem_t full;
// int in = 0;
// int out = 0;
// int buffer[BufferSize];
// pthread_mutex_t mutex;

// void *producer(void *pno)
// {   
//     int item;
//     for(int i = 0; i < MaxItems; i++) {
//         item = rand(); // Produce an random item
//         sem_wait(&empty);
//         pthread_mutex_lock(&mutex);
//         buffer[in] = item;
//         printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
//         in = (in+1)%BufferSize;
//         pthread_mutex_unlock(&mutex);
//         sem_post(&full);
//     }
// }
// void *consumer(void *cno)
// {   
//     for(int i = 0; i < MaxItems; i++) {
//         sem_wait(&full);
//         pthread_mutex_lock(&mutex);
//         int item = buffer[out];
//         printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
//         out = (out+1)%BufferSize;
//         pthread_mutex_unlock(&mutex);
//         sem_post(&empty);
//     }
// }

// int main()
// {   

//     pthread_t pro[5],con[5];
//     pthread_mutex_init(&mutex, NULL);
//     sem_init(&empty,0,BufferSize);
//     sem_init(&full,0,0);

//     int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

//     for(int i = 0; i < 5; i++) {
//         pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
//     }
//     for(int i = 0; i < 5; i++) {
//         pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
//     }

//     for(int i = 0; i < 5; i++) {
//         pthread_join(pro[i], NULL);
//     }
//     for(int i = 0; i < 5; i++) {
//         pthread_join(con[i], NULL);
//     }

//     pthread_mutex_destroy(&mutex);
//     sem_destroy(&empty);
//     sem_destroy(&full);

//     return 0;

// }







// // 2) Reader Writer
// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>

// pthread_mutex_t wr, mutex;
// int a = 0;
// int readcount = 0; // Initialize readcount

// void *reader(void *arg) {
//     long int num;
//     num = (long int)arg;

//     pthread_mutex_lock(&mutex);
//     readcount++;
//     if (readcount == 1) {
//         pthread_mutex_lock(&wr);
//     }
//     pthread_mutex_unlock(&mutex);

//     printf("The Reader %ld is in critical section\n", num);
//     printf("The Reader %ld is reading data %d\n", num, ++a);
//     sleep(1);

//     pthread_mutex_lock(&mutex);
//     readcount--;
//     if (readcount == 0) {
//         pthread_mutex_unlock(&wr);
//     }
//     pthread_mutex_unlock(&mutex);

//     printf("The Reader %ld left critical section\n", num);
// }

// void *writer(void *arg) {
//     long int num;
//     num = (long int)arg;

//     pthread_mutex_lock(&wr);
//     printf("Writer %ld have written data as %d\n", num, ++a);
//     sleep(1);
//     pthread_mutex_unlock(&wr);

//     printf("Writer %ld left critical section\n", num);
// }

// int main() {
//     pthread_t r[10], w[10];
//     long int i, j;

//     pthread_mutex_init(&wr, NULL); // Initialize mutex variable
//     pthread_mutex_init(&mutex, NULL);

//     printf("Enter readers and writers:\n");
//     // Create reader and writer threads

//     int nor, now;
//     scanf("%d %d", &nor, &now);

//     for (i = 0; i < nor; i++) {
//         pthread_create(&r[i], NULL, reader, (void *)i);
//     }

//     for (j = 0; j < now; j++) {
//         pthread_create(&w[j], NULL, writer, (void *)j);
//     }

//     for (i = 0; i < nor; i++) {
//         pthread_join(r[i], NULL);
//     }

//     for (j = 0; j < now; j++) {
//         pthread_join(w[j], NULL);
//     }

//     return 0;
// }




// 3) Dining Philosopher

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

void *Philosopher(void *arg);
void printstatus();

sem_t chop[5];
sem_t mutex;
char status[6] = {'-','-','-','-','-','-'};

int main()
{
    pthread_t phil[5];
    long int i,j;

    for(i=0;i<5;i++)
    {
        sem_init(&chop[i],0,1); // 0 means not shared with others process .... and last 1 means chopstick is free now..
    }
    sem_init(&mutex,0,1);
    
    printf("\n");

    //printing heading of table
    for(i=0;i<5;i++)
    {
        printf(" P[%ld]",i);
    }

    for(i=0;i<5;i++)
    {
        pthread_create(&phil[i],NULL,Philosopher,(void*)i);
    }

    for(j=0;j<5;j++)
    {
        pthread_join(phil[j],NULL);
    }
}

void *Philosopher(void *arg)
{
  long int num = (long int)arg;
   
   // philosopher is hungry

   status[num] = 'H';
   printstatus();

   //Acquire chopstick[left and right]
   // lock critical section mhanje jeecha philosophe j1 karel tevha to 2 chostick gheil ...but as hou shakt ki philospher 1 chostk gheil ani dusri uchalyla jail tevhdhat tych neighbour hungry houn tychi chostick to gheun takel that is problem known as deadlock.. here..
   sem_wait(&mutex);
   sem_wait(&chop[num]);
   sleep(1);
   sem_wait(&chop[(num+1)%5]);
   sem_post(&mutex);
   status[num] = 'E';
   printstatus();
   sleep(1);  // philosopher eating hence we give him 
   
   //release chostick

   sem_post(&chop[(num+1)%5]);
   sem_post(&chop[num]);

   //philosopher is thinking
   status[num] = 'T';
   printstatus();

   pthread_exit(NULL);
}

void printstatus()
{
    printf("\n");

    for(int i=0;i<5;i++)
    {
        printf("    %c",status[i]);
    }
}


// ashu 
// #include <pthread.h>
// #include <semaphore.h>
// #include <stdio.h>
// #include <unistd.h>

// #define N 5  // Number of philosophers
// #define THINKING 2
// #define HUNGRY 1
// #define EATING 0
// #define LEFT (ph_num + 4) % N
// #define RIGHT (ph_num + 1) % N
// #define MAX_EAT 3  // Each philosopher eats 3 times

// int state[N];
// int phil[N] = {0, 1, 2, 3, 4};
// int eat_count[N] = {0};  // Count of how many times each philosopher has eaten

// sem_t mutex;
// sem_t S[N];

// void *philosopher(void *num);
// void take_fork(int ph_num);
// void put_fork(int ph_num);
// void test(int ph_num);

// int main() {
//     int i;
//     pthread_t thread_id[N];

//     // Initialize the semaphores
//     sem_init(&mutex, 0, 1);

//     for (i = 0; i < N; i++) {
//         sem_init(&S[i], 0, 0);
//     }

//     for (i = 0; i < N; i++) {
//         pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
//         printf("Philosopher %d is thinking\n", i + 1);
//     }

//     for (i = 0; i < N; i++) {
//         pthread_join(thread_id[i], NULL);
//     }

//     sem_destroy(&mutex);
//     for (i = 0; i < N; i++) {
//         sem_destroy(&S[i]);
//     }

//     return 0;
// }

// void *philosopher(void *num) {
//     int *i = num;
//     while (eat_count[*i] < MAX_EAT) {
//         sleep(1);
//         take_fork(*i);
//         sleep(0); // Philosopher is eating
//         put_fork(*i);
//     }
//     return NULL;
// }

// void take_fork(int ph_num) {
//     sem_wait(&mutex);

//     state[ph_num] = HUNGRY;
//     printf("Philosopher %d is Hungry\n", ph_num + 1);

//     test(ph_num);

//     sem_post(&mutex);

//     sem_wait(&S[ph_num]);
//     sleep(1);
// }

// void put_fork(int ph_num) {
//     sem_wait(&mutex);

//     state[ph_num] = THINKING;
//     printf("Philosopher %d putting fork %d and %d down\n", ph_num + 1, LEFT + 1, ph_num + 1);
//     printf("Philosopher %d is thinking\n", ph_num + 1);

//     test(LEFT);
//     test(RIGHT);

//     sem_post(&mutex);
// }

// void test(int ph_num) {
//     if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
//         state[ph_num] = EATING;
//         eat_count[ph_num]++;
//         sleep(2);

//         printf("Philosopher %d takes fork %d and %d\n", ph_num + 1, LEFT + 1, ph_num + 1);
//         printf("Philosopher %d is Eating\n", ph_num + 1);

//         sem_post(&S[ph_num]);
//     }
// }

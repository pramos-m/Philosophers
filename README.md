# Philosophers 42 Guide— “The Dining Philosophers Problem”

The famous “Dining Philosophers Problem” explained/walkthrough — 42 cursus project  
Dean Ruina  

Dean Ruina

· Follow

11 min read · Aug 21, 2023  

Here is my philosophers repository for reference. I’ll explain here the general idea of my solution. If you’re interested in seeing my code you can check it here:

[GitHub - DeRuina/philosophers: Philosophers 42 Explained/Walkthrough. The Dining Philosophers Problem guide](https://github.com/DeRuina/philosophers)

## The Dining Philosophers Problem

The dining philosophers problem is a famous problem in computer science used to illustrate common issues in concurrent programming. The problem was originally formulated in 1965 by Edsger Dijkstra, and is stated as follows:

- X amount of philosophers sit at a round table with bowls of food.
- Forks are placed in front of each philosopher.
- There are as many forks as philosophers.
- All day the philosophers take turns eating, sleeping, and thinking.
- A philosopher must have two forks in order to eat, and each fork may only be used by one philosopher at a time.
- At any time a philosopher can pick up or set down a fork, but cannot start eating until picking up both forks.
- The philosophers alternatively eat, sleep, or think.
- While they are eating, they are not thinking nor sleeping, while thinking, they are not eating nor sleeping, and, of course, while sleeping, they are not eating nor thinking.

Let me start by explaining the general idea. First of all, we have to imagine a round table, X num of philosophers sitting around it and each of them brings a fork and places it in front of them. At this point we know that a philosopher can do three things: eat, sleep, or think, but in order to eat he has to pick two forks (the one in front of him and another one to his right or to his left, in my solution he picks the one to his right, both work — different implementation). Let’s use a picture to have a more concrete idea of what we are talking about:

The number of forks is equal to the number of philosophers

Let’s say there are 5 philosophers sitting at the table. Philosopher 1 wants to eat, so he picks the fork in front of him and the one to his right (the one in front of philosopher 5), at this point, we notice that philosopher 2 can’t eat nor does philosopher 5, since philosopher 1 picked the fork in front of him and in front of philosopher 5. This might seem a little obvious but keep in mind this situation because the main problem of this project is how to organize the eating action of the philosophers. Probably the first solution that came to your mind is to simply make the odd and even philosophers eat separately, well we are not going to do that, it’s too hard-coded and we would lose the meaning of the project, philosophers have to organize by themselves. We will be using threads and implement a multithreading solution. I’m attaching the project subject as well so you could understand completely what is needed.

In order to understand the solution, you’ll need to understand the concept of threads first, here are some good videos I recommend you watch:

- [General introduction to threads](https://www.youtube.com/watch?v=7Gfupf2VggY)
- [Introduction to threads with code examples](https://www.youtube.com/watch?v=9BFRi-nH1v8)
- [Short introduction to threads (pthreads)](https://www.youtube.com/watch?v=qrF7-a-1Bsk) 

**Code Vault covers all the knowledge you need for this project/problem in this playlist**

## Data Races (Race Conditions) — What Are They?

Data races are a common problem in multithreaded programming. Data races occur when multiple tasks or threads access a shared resource without sufficient protections, leading to undefined or unpredictable behavior.

- Two or more threads concurrently accessing a location of memory
- One of them is a write
- One of them is unsynchronized

In simpler words, a race condition can happen when 2 or more threads are trying to access and modify the same variable at the same time, it can lead to an error in the final value of the variable, it doesn’t mean it will for sure happen though. For an example let’s think of a function that deposits the amount you insert to your bank account. If we use multithreading and use 2 threads and want to deposit 300 using the first thread and 200 using the second you will think our bank account will have a total of 500, but that’s not particularly the case, let’s see it in code:

```c
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// the initial balance is 0
int balance = 0;

// write the new balance (after a simulated 1/4 second delay)
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}

// returns the balance (after a simulated 1/4 second delay)
int read_balance()
{
  usleep(250000);
  return balance;
}

// carry out a deposit
void* deposit(void *amount)
{
  // retrieve the bank balance
  int account_balance = read_balance();

  // make the update locally
  account_balance += *((int *) amount);

  // write the new bank balance
  write_balance(account_balance);

  return NULL;
}

int main()
{
  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);

  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;

  // the deposit amounts... the correct total afterwards should be 500
  int deposit1 = 300;
  int deposit2 = 200;

  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);

  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // output the balance after the deposits
  int after = read_balance();
  printf("After: %d\n", after);

  return 0;
}
```

You would think if you run this code that the balance will be 500 but the output we get is actually 200, now, why is that? Here is a visualization of the above program’s execution:
| Thread #1   | Thread #2   | Bank Balance |
|-------------|-------------|--------------|
| Read Balance  |             | <----------------------------------- 0   |
| balance = 0   |             |             |
| Read Balance  | <------------- 0	   |             |
| balance = 0|  |             |             |
| Deposit +300  |             |             |
| balance = 300 |             |             |
| Deposit +200  |             |             |
| Balance = 200 |             |             |
| Write Balance |             | ----------------------------------> 300         |
| balance = 300 |             |             |
| Write Balance | ------------> 200	|             |
| balance = 200 |             |             |

When the two deposit functions run at the same time, they both read the balance which is 0, they both deposit the amount inserted and change the balance variable locally, but when they write it to the variable itself, they overwrite each other. Thread #1 writes 300 first but thread #2 writes as well and changes the variable to 200. How can we solve this? Easily we just need to attach a lock, let me introduce you to mutex.

What are Race Conditions? — Great explanation down to the Assembly level
Race Conditions Explained With An Example

## Mutex
Now that we know what is a race condition let’s see what is the solution. Imagine a lock that protects a block of code and it can be only executed by the lock owner until he unlocks the lock. Taking the previous example we can avoid the overwrite by adding a lock in the deposit function. If thread #1 reaches the lock thread #2 will just have to wait until thread #1 is done executing the code and reaches the unlock, only then thread #2 will enter and execute itself.
```c
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// the initial balance is 0
int balance = 0;
pthread_mutex_t mutex;

// write the new balance (after a simulated 1/4 second delay)
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}

// returns the balance (after a simulated 1/4 second delay)
int read_balance()
{
  usleep(250000);
  return balance;
}

// carry out a deposit
void* deposit(void *amount)
{
  // lock the mutex
  pthread_mutex_lock(&mutex);

  // retrieve the bank balance
  int account_balance = read_balance();

  // make the update locally
  account_balance += *((int *) amount);

  // write the new bank balance
  write_balance(account_balance);

  // unlock to make the critical section available to other threads
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main()
{
  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);

  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;

  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // the deposit amounts... the correct total afterwards should be 500
  int
```

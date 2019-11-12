/* hello_signal.c */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n");
  alarm(1); 
}
void timer(int signum){
  double num_seconds = 0.0;
  clock_t start_time = clock();
  signal(SIGALRM,handler);
  clock_t finish_time = clock();
  num_seconds += (double)(finish_time - start_time)/ CLOCKS_PER_SEC;
  printf("Total number of seconds it was executed is %f seconds\n", num_seconds);
  exit(1);
}
int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, timer);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1); //busy wait for signal to be delivered
  return 0; //never reached
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(void) {
  char name[10];
  for(int i = 0; i <4; i++) {
    pid_t pid = fork();
    
 
    if(pid == 0) {
      printf("Child process >> PPID=%d, PID=%d\n", getppid(), getpid());
      printf("\nEnter Name : ");
      scanf("%s",&name);
      printf("\n Name :%s\n ",name);
      exit(0);
    }
    else  {
      printf("Parent process >> PID=%d\n", getpid());
      printf("Waiting for child processes to finish...\n");
      wait(NULL);
      printf("Job is done.\n");
    }
  }
 
  return EXIT_SUCCESS;
}

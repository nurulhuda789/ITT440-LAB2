#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
 char name[10];
 for(int i = 1; i < 5; i++) {
 printf("\nEnter Name : ");
 scanf("%s",&name);
 printf("\n Name : %s\n ",name);
 }
}

void parentTask() {
  
  printf("\nJob is done\n");
}

int main(void) {
  char name[10];
  
    pid_t pid = fork();
    
 
    if(pid == 0) {
    childTask();
    exit(EXIT_SUCCESS);

    }
      else if(pid > 0) {
    wait(NULL);
    parentTask();
   }
    
      else {
    printf("Unable to create child process.");
    }
   
  
  
 
    return EXIT_SUCCESS;

  }
 
  

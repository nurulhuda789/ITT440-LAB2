#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
 char name[10];
 
 printf("\nEnter Name : ");
 scanf("%s",&name);
 printf("\n Name : %s\n ",name);

}

void parentTask() {
  
  printf("Job is done");
}

int main(void) {
  char name[10];
  for(int i = 0; i <4; i++) {
    pid_t pid = fork();
    
 
    if(pid == 0) {
    childTask();
    exit(EXIT_SUCCESS);

    }
    
      else {
    printf("Unable to create child process.");
    }
   
  
  if(pid>0){
    parentTask();
   }
 }
    return EXIT_SUCCESS;

  }
 
  

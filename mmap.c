//simple code where two child process manipulate same variable using shared memory

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int *global_var;

int main(void)
{
	pid_t pid1,pid2;
	global_var = mmap(NULL, sizeof *global_var, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*global_var = 1;
	printf("initial global variable value is: %d\n",*global_var);

    	pid1=fork();
	if(pid1==0){
		pid2=fork();
		if (pid2==0){
			*global_var = *global_var+1;
			printf("value from child2:  %d\n", *global_var);
			exit(EXIT_SUCCESS);
		}
		else{
			*global_var = *global_var+1;
			printf("value from child1:  %d\n", *global_var);
			exit(EXIT_SUCCESS);
		}
	}
	else{
		wait(NULL);
		printf("final value of global variable is: %d\n",*global_var);
		munmap(global_var, sizeof *global_var);
	}

    return 0;
}

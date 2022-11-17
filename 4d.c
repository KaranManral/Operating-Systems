#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if(pid==0)
	{
		printf("Child Process\n");
	}
	else
	{
		printf("Parent Process\n");
		wait(NULL);
		printf("Child Complete\n");
	}
	return 0;
}
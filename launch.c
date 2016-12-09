#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include "helper.h"
#include "builtin.h"

extern int fg;
extern char fgname[1000];

int main_launch(char **args)
{
	pid_t proc_id;
	int status, flag = 0, i = 0;

	proc_id = fork();
	if (proc_id == 0) 
	{
		while(args[i] != NULL)
		{
			if(strcmp(args[i], "&") == 0)
			{
				flag = 1;
				args[i] = NULL;
				break;
			}
			i++;
		}

		if (execvp(args[0], args) == -1) 
		{
			perror("main");
		}
		exit(EXIT_FAILURE);
	} 
	else if (proc_id < 0) 
	{
		perror("main");
	} 
	else
	{
		fg = proc_id;
		while(args[i] != NULL)
		{
			if(strcmp(args[i], "&") == 0)
			{
				printf("%s [%d]\n", args[0], proc_id);
				main_insert(proc_id, args[0]);
				flag = 1;
				args[i] = NULL;
				break;
			}
			i++;
		}

		if(!flag)
		{
			fg = proc_id;
			strcpy(fgname, args[0]);
			waitpid(proc_id, &status, WCONTINUED);
		}
	}

	return 1;
}

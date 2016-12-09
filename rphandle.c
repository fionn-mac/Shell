#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include <pwd.h>
#include "builtin.h"
#include "helper.h"

int main_rphandle(char * commands)
{
	pid_t pid;
	int i, status, input, filedescriptors[2], n = 0;

	input = 0;
	char * temp = NULL, * pipeCommands[1000], ** args;

	while(commands)
	{
		temp = strsep(&commands, "|");
		if(temp != NULL) 
		{
			if(strlen(temp) > 0) 
			{
				pipeCommands[n++] = temp;
			}
		}
	}

	if(n > 0)
		n--;

	for (i = 0; i < n; i++)
	{
		pipe(filedescriptors);
		args = main_delim_split(pipeCommands[i]);
		args = main_redirect(args);
		main_rpexec(input, args, filedescriptors[1]);
		free(args);
		close(filedescriptors[1]);
		input = filedescriptors[0];
	}

	if(input != 0)
	{
		dup2(input, 0);
	}

	args = main_delim_split(pipeCommands[n]);
	args = main_redirect(args);

	status = main_execute(args);
	free(args);
	return status;
}

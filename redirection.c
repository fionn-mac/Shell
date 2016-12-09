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

char ** main_redirect(char **args)
{
	int i, in, out;
	i = 0;
	
	while(args[i] != NULL)
	{
		if(strcmp(args[i],">") == 0)
		{
			args[i] = NULL;
			i++;
			out = open(args[i], O_WRONLY| O_TRUNC | O_CREAT, 0777);
			dup2(out,STDOUT_FILENO);
			close(out);
			args[i] = NULL;
		}

		else if(strcmp(args[i],">>") == 0)
		{
			args[i] = NULL;
			i++;
			out = open(args[i], O_APPEND | O_RDWR | O_CREAT, 0777);
			dup2(out,STDOUT_FILENO);
			close(out);
			args[i] = NULL;
		}

		else if(strcmp(args[i],"<") == 0)
		{
			args[i] = NULL;
			i++;
			in = open(args[i],O_RDONLY);
			dup2(in,STDIN_FILENO);
			close(in);
			args[i] = NULL;
		}
		i++;
	}

	return args;
}

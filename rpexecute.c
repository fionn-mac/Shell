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

int main_rpexec(int in, char **args, int out)
{
	pid_t pid;
	int i, len;

	char *builtin_str[] = {"cd", "pwd", "echo", "quit", "jobs", "killallbg", "sendsig", "fg"};
	int (*builtin_func[]) (char **) = {&main_cd, &main_pwd, &main_echo, &main_exit, &main_listjobs, &main_killallbg, &main_sendsig, &main_fg};

	for (i = 0; i < 8; i++) 
	{
		if (strcmp(args[0], builtin_str[i]) == 0) 
		{
			len = 0;
			if (out != 1)
			{
				dup2(out, 1);
				close(out);
			}
	
			while(args[len] != NULL)
			{
				if (strcmp("&", args[len]) == 0)
				{
					args[len] = NULL;
					break;
				}
				len++;
			}
			return (*builtin_func[i])(args);
		}
	}

	pid = fork();

	if(pid == 0)
	{
		if(in != 0)
		{
			dup2(in,0);
			close(in);
		}

		if(out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		execvp(args[0],args);

	}

	return pid;
}

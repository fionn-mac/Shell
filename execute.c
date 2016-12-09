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

char *builtin_str[] = {"cd", "pwd", "echo", "quit", "jobs", "killallbg", "sendsig", "fg"};
int (*builtin_func[]) (char **) = {&main_cd, &main_pwd, &main_echo, &main_exit, &main_listjobs, &main_killallbg, &main_sendsig, &main_fg};

int main_execute(char **args)
{
	int i, len;

	if (args[0] == NULL) {
		return 1;
	}

	for (i = 0; i < 8; i++) 
	{
		if (strcmp(args[0], builtin_str[i]) == 0) 
		{
			len = 0;
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

	return main_launch(args);
}

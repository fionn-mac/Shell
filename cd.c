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

extern char code_dir[1000];
int temp;

int main_cd(char **args)
{
	if (args[1] == NULL) 
	{
		fprintf(stderr, "main: expected argument to \"cd\"\n");
	} 
	else 
	{
		if(strcmp(args[1],"~") == 0)
		{
			temp = chdir(code_dir);
			if(temp != 0)
			{
				perror("main");
			}
		}
		
		else if (chdir(args[1]) != 0) 
		{
			perror("main");
		}
	}
	return 1;
}

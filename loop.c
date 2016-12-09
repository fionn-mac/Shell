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

extern char curr_dir[1000];
extern char code_dir[1000];
int  status;

void main_loop(void)
{
	getcwd(code_dir, 1000);
	char * line, * temp;
	int status, i, j, flag = 0;
	while(1)
	{
		getcwd(curr_dir, 1000);
		name();
		line = main_read_line();
		while(line)
		{
			temp = strsep(&line, ";");
			status = main_rphandle(temp);
			if(status == 0)
				return;
		}
		j++;
		free(line);
	}
}

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

void tstp_handler(int signum)
{
	if(fg != 0)
	{
		kill(fg, SIGTSTP);
		main_insert(fg, fgname);
		fg = 0;
		strcpy(fgname, "\0");
		kill(fg, SIGCONT);
	}
	return;
}

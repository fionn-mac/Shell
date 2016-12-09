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

void chld_handler(int signum)
{
	int status;
	pid_t proc_id;
	(proc_id = waitpid(-1, &status, WNOHANG));
	if (proc_id>0)
	{
		main_delete(proc_id);   
	}
	return;
}

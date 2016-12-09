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

int name()
{
	register uid_t uid;
	register struct passwd *pw;
	struct hostent* h;
	char hostname[1024];
	int c;
	uid = geteuid ();
	pw = getpwuid (uid);
	hostname[1023] = '\0';
	gethostname(hostname, 1023);

	if (pw)
	{	
		printf("<%s@%s:%s$> ", pw->pw_name, hostname, replace_str(curr_dir));
		return 1;
	}
	else	
		return 0;
}


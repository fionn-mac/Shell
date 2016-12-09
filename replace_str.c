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

char * replace_str(char * str)
{
	static char buffer[4096];
	char rep[2];
	strcpy(rep, "~");
	char *p;

	p = strstr(str, code_dir);

	if(!p)
	{
		strcpy(buffer,str);
		return buffer;
	} 

	strncpy(buffer, str, p-str);
	buffer[p-str] = '\0';

	sprintf(buffer+(p-str), "%s%s", rep, p+strlen(code_dir));

	return buffer;
}

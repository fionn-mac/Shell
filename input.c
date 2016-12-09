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

extern int stdin_copy,stdout_copy;

char * main_read_line(void)
{

	int c, position = 0;
	char *buffer = malloc(sizeof(char) * 10000);

	dup2(stdin_copy, 0);
	dup2(stdout_copy, 1);

	while(1) {
		c = getchar();
		
		if(c==EOF)
		{	printf("\n");
			exit(0);
		}

		if ( c == '\n') 
		{
			buffer[position] = '\0';
			return buffer;
		} 
		else 
		{
			buffer[position] = c;
		}
		position++;


	}
}

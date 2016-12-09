#include <sys/wait.h>
#include <errno.h>
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

extern Node * head;

int main_killallbg(char ** args)
{
	int errsv, i; 
	pid_t value;
	Node * temp = head->next;
	while(temp != NULL)
	{
		value = temp->pid;
		i = kill(value, 9);
		errsv = errno;
		if(i == -1)
			fprintf(stderr, "%s", strerror(errsv));
		temp = head->next;
	}
	return 1;
}

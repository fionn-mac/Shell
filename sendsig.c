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

int main_sendsig(char ** args)
{
	int errsv, no, i = 0;
	pid_t id;
	id = atoi(args[1]);
	no = atoi(args[2]);
	Node * temp = head->next;

	while(temp != NULL)
	{
		i++;
		if(i == id)
			break;
		temp = temp->next;
	}
	
	if(temp != NULL)
	{
		i = kill(temp->pid, no);
		errsv = errno;
		if(i == -1)
		fprintf(stderr, "%s", strerror(errsv));
	}

	return 1;
}

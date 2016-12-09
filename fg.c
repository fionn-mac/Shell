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

extern Node * head;

int main_fg(char **args)
{
	Node * temp = head->next;
	int status, i = 0;
	pid_t id = atoi(args[1]);

	while(temp != NULL)
	{
		i++;
		if(i == id)
		{
			waitpid(temp->pid, &status, WCONTINUED);
			main_delete(temp->pid);
			break;
		}
		temp = temp->next;
	}

	return 1;
}

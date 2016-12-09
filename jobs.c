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

int main_listjobs(char ** args)
{
	int i = 1;
	Node * temp = head->next;
	while(temp != NULL)
	{
		printf("[%d] %s [%d]\n", i, temp->pname, temp->pid);
		i++;
		temp = temp->next;
	}
	return 1;
}

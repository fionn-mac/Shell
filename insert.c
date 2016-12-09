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
extern Node * end;

void main_insert(pid_t proc_id, char name[])
{
	Node * n = (Node *)malloc(sizeof(Node));
	n->pid = proc_id;
	strcpy(n->pname, name);
	n->next = NULL;
	end->next = n;
	end = n;
	return;
}

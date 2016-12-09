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

Node * head, * end, * lead, * follow;
extern int status;

void main_delete(pid_t proc_id)		
{
	if(head->next != NULL)
		follow = head->next;

	if(follow != NULL && follow->next != NULL && follow->pid != proc_id)
	{
		lead = follow->next;

		while(lead != NULL)
		{
			if(lead->pid == proc_id)
			{
				printf("%s [%d] %d\n", lead->pname, proc_id, WEXITSTATUS(status));
				if(lead->next == NULL)
					end = follow;
				follow->next = lead->next;
				free(lead);
				break;	
			}
			else
			{
				follow = lead;
				lead = follow->next;
			}
		}
		return;
	}

	else if(follow != NULL && follow->pid == proc_id)
	{
		printf("%s [%d] %d\n", follow->pname, proc_id,WEXITSTATUS(status));
		head->next = follow->next;
		if(head->next == NULL)
			end = head;
		free(follow);
		return;
	}

	return;
}

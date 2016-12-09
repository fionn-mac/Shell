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

char curr_dir[1000];
char code_dir[1000];
Node * head;
Node * end;
int stdin_copy, stdout_copy;
int fg;
char fgname[1000];

int main(int argc, char **argv)
{
  	stdin_copy = dup(0); 
	stdout_copy = dup(1);
	head = (Node *)malloc(sizeof(Node));
	head -> next = NULL;
	end = head;
	fg = 0;
	strcpy(fgname, "\0");
	signal(SIGINT, int_handler);
	signal(SIGCHLD, chld_handler);
	signal(SIGTSTP, tstp_handler);
	main_loop();
	return EXIT_SUCCESS;
}

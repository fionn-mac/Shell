#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/utsname.h>
#include "helper.h"
#include "builtin.h"

int main_echo(char **args)
{ 	
	int i=1;
	while(args[i]!=NULL)
  		printf("%s ",args[i++]);
	printf("\n");
  return 1;
}

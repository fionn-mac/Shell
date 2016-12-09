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

int main_pwd()
{
	char dir[1000];
	getcwd(dir, 1000);
	printf("%s\n", replace_str(dir));
	return 1;
}

int main_cd(char **args);
int main_exit(char **args);
int main_pwd(void);
int main_echo(char **args);
int main_listjobs(char ** args);
int main_killallbg(char ** args);
int main_sendsig(char ** args);
int main_fg(char ** args);
char ** main_delim_split(char * line);
char ** main_redirect(char ** args);
int main_rphandle(char * commands);
void tstp_handler(int signum);
void main_insert(pid_t proc_id, char name[]);

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define LSH_RL_BUFSIZE 1024

typedef struct node{
	pid_t pid;
	char pname[1000];
	struct node * next;
}Node;

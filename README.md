# Shell

The goal of the project was to create a user defined interactive shell program that could create and manage new processes. The shell is able to create a process out of a system program like emacs, vi or any user-defined executable. 

Features
1. The shell supports semi-colon separated list of commands. Commands can be executed with or without arguments.
2. The shell supports the '&' operator which lets a program run in background after printing the process id of the newly created process.
3. On execution of the shell, a prompt of the form "<username@system_name:curr_dir>" is displayed.
4. The shell supports input/output redirection and piping.
5. The shell also supports the following manually defined commands -
  a.) jobs - prints a list of all currently running background process along with their pids in order of their creation
  b.) kjob <jobId> <signalNumber> - takes the job id of a running job and sends mentioned signal value to that job
  c.) fg <jobId> - brings the background job with the given job number to foreground
  d.) killallbg - kills all background processes
  e.) quit or CTRL + D - exits the shell
  f.) CTRL + Z - changes the status of currently running foreground processes to stop, pushes it to background and resumes its execution
  g.) CTRL + C - kills all running processes

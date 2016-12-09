README
_______________________________________________________
_______________________________________________________

FEATURES SUPPORTED
-------------------------------------------------------
The shell supports cd,pwd,echo and other built in commands.
Errors are handled properly using perror.
Echo command is not the same as in the bash shell.


HOW TO COMPILE
-------------------------------------------------------

to compile run the command:-   make

HOW TO RUN
-------------------------------------------------------
run the command:- ./main
FILES
-------------------------------------------------------
cd.c:- cd command
echo.c:- echo command (simply prints input string)
execute.c:- calls respective function to call
exit.c:- exits from shell
input.c:- takes command(s) as input
launch.c:- launches command
loop.c:- calls input, execute and launch functions
main.c:- calls loop function
name.c:- gets username and hostname
pwd.c:- gets present working directory of user
replace_str.c:- searches for pattern and replaces it with predefined pattern
split.c:- splits string with given delimiter


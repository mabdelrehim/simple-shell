Mohamed Elsayed Abdelrehim
4055


Simple Shell application

The application first prompts the user to enter a command to be executed on linux. This command
is seperated into tokens based on the space character as a dilimiter. Then the application checks
for the "&" character at the end of the entered command to set a flag that will help the parent
process decide whether to wait or not. Then the application forks its main process and executes
the command on a child process then it terminates that file process. Whenever a child process
terminates and a SIGCHLD signal is sent to the parent a signal handler writes into a log file.
Only two commands are implemented that do not use the execvp() function: 'cd' and 'exit'.
exit terminates the main process and cd changes the working directory of the main process. 
As those commands affect the main process they need to be implemeted by the main process.



For a brief discription of what each function does, check the comments on the header files. there
are three main modules: execute, which handles each command, parser, which deals with the user
input and checks for "&", sig-handler, which contains the signal handler function, and the main 
module, which has the main loop.

=================================================================================================
An object file and a Makefile are included in the project in the folder cmake-build-debug


**Important Notice: The log file will not be created unless you change the code in the 
sig-handler module to open a file on your specific directory. I tried to make it generel but 
every time I use cd then ls or somthing else a new log file is created in the current directory
resulting in seperate log files so I solved this by hardcoding the path I want the log file to be in**

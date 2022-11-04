
The Thompson shell was the first Unix shell, introduced in the first version of Unix in 1971, and was written by Ken Thompson.It was a simple command interpreter, not designed for scripting, but nonetheless introduced several innovative features to the command-line interface and led to the development of the later Unix shells.
				*Unix shell*
A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.
Users typically interact with a Unix shell using a terminal emulator; however, direct operation via serial hardware connections or Secure Shell are common for server systems. All Unix shells provide filename wildcarding, piping, here documents, command substitution, variables and control structures for condition-testing and iteration.
				*Early shells*
The thompson shell was the first unix shell,  sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975.
Though old and rudimentary per current requirements, it introduced many of the basic features common to all later Unix shells.

Bourne shell
		The Bourne shell, sh, was a new Unix shell by Stephen Bourne at Bell Labs. Distributed as the shell for UNIX Version 7 in 1979, it introduced the rest of the basic features considered common to all the later Unix shells, including here documents, command substitution, more generic variables and more extensive builtin control structures. The language, including the use of a reversed keyword to mark the end of a block, was influenced by ALGOL 68. Traditionally, the Bourne shell program name is sh and its path in the Unix file system hierarchy is /bin/sh. But a number of compatible work-alikes are also available with various improvements and additional features.
				*List of allowed functions*
List of allowed functions and system calls:
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

					*Compilation*
This shell will be compiled with
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


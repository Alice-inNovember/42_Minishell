<img width="703" alt="image" src="https://github.com/user-attachments/assets/d7a034a1-f52f-4867-96f9-27849709df31">

## About
This is one of the 42 cursus core curriculum projects. Here, we implemented a shell program like `bash` in `C`. Our program handles command history, path-based executable searching and launching, redirections and pipes, environment variable expansion, handling of control characters, and several built-in commands like `cd, echo, env, exit, export, pwd, unset`.

## Prerequisites (This is only tested on OS X)
1. You need to install `readline` first to run.
`brew install readline`
3. Find installed `readline.h` in `homebrew` directory and add `#include <stdio.h>` inside the header file.
4. Specify the path of readline header file and archive in `Makefile`.
```
# Makefile

#NAME
NAME		=	minishell
...
RDLDIR		=	/opt/homebrew/Cellar/readline/8.2.13 # change this path
...
#FILES
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a -lreadline -L$(RDLDIR)/lib # link archive
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR) -I $(INCDIR) -I$(RDLDIR)/include # header
SRCS		=	$(SRCDIR)/main.c \
				$(ENVPDIR)/envp.c \
				$(ENVPDIR)/envp_util.c \
...
```
5. For OS X Sonoma users, the default path of `ar` would've been set to the one in `homebrew`. Please specify the path of `ar` to `/usr/bin/ar` in Makefiles of `libraries/dllist`, `libraries/libft`, `libraries/get_next_line`. Otherwise you'll encounter `mach -o` errors.
```
# libraries/dllist/Makefile

NAME = libdll.a
...
AR = /usr/bin/ar # here
ARFLAGS = -rcs
...
```

## How to run
```
git clone https://github.com/Alice-inNovember/42_Minishell.git
cd ./42_Minishell
make
./minishell
```

## BNF Grammar
We have implemented our parser from this BNF grammar below, which is `Recursive Descent Parser`.
```
program	    :	expression
		;
expression  :   simple_command
		| expression '|' simple_command
		;
simple_cmd  : 	cmd_prefix cmd_word cmd_suffix
		| cmd_prefix cmd_word
		| cmd_prefix
		| cmd_word cmd_suffix
		| cmd_word
		;
cmd_word    :	WORD
		;
cmd_prefix  :	io_redirect
		| cmd_prefix io_redirect
		;
cmd_suffix  :	io_redirect
		| cmd_suffix io_redirect
		| WORD
		| cmd_suffix WORD
		;
io_redirect :	io_file
		| io_here
		;
io_file  	: '<' filename
		| '>' filename
		| '>>' filename
		;
filename    :	WORD
		;
io_here     :	'<<' here_end
		;
here_end	: WORD
		;
```

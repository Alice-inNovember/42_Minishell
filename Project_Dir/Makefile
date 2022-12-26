#NAME
NAME		=	minishell
#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
#DIRS
LFTDIR		=	libft
DLLDIR		=	doubly_linked_list
GNLDIR		=	get_next_line
SRCDIR		=	
BONUSDIR	=	
#FILES
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR)
SRCS		=	main.c
OBJS		=	${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(DLLDIR)
	$(MAKE) -C $(GNLDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

bonus : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
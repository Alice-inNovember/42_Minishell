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
SRCDIR		=	
BONUSDIR	=	
#FILES
LIBS		=	$(LFTDIR)/libft.a
SRCS		=	main.c
OBJS		=	${SRCS:.c=.o}
BSRCS		=	
BOBJS		=	${BSRCS:.c=.o}

all : $(NAME)

ifeq ($(filter bonus, $(MAKECMDGOALS)), bonus)
$(NAME) : $(BOBJS)
	$(MAKE) -C $(LFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBS)
else
$(NAME) : $(OBJS)
	$(MAKE) -C $(LFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
endif

bonus : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LFTDIR)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
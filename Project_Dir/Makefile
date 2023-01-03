#NAME
NAME		=	minishell
#CMDS
CC			=	cc -fsanitize=address -g3
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	
#DIRS
LFTDIR		=	libraries/libft
DLLDIR		=	libraries/dllist
GNLDIR		=	libraries/get_next_line
SRCDIR		=	srcs
INCDIR		=	./includes
ENVPDIR		=	$(SRCDIR)/envp
LEXERDIR	=	$(SRCDIR)/lexer
PARSEDIR	=	$(SRCDIR)/parser
UTILDIR		=	$(SRCDIR)/util
BONUSDIR	=	
#FILES
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR) -I $(INCDIR)
SRCS		=	$(SRCDIR)/main.c \
				$(ENVPDIR)/envp.c \
				$(LEXERDIR)/make_token_list.c \
				$(LEXERDIR)/make_token_list_utils.c \
				$(LEXERDIR)/print_token_list.c \
				$(LEXERDIR)/state/branch.c \
				$(LEXERDIR)/state/clear.c \
				$(LEXERDIR)/state/dquote_branch.c \
				$(LEXERDIR)/state/dquote_close.c \
				$(LEXERDIR)/state/dquote_expand.c \
				$(LEXERDIR)/state/dquote_making_word.c \
				$(LEXERDIR)/state/expand.c \
				$(LEXERDIR)/state/init.c \
				$(LEXERDIR)/state/making_dgreat.c \
				$(LEXERDIR)/state/making_dless.c \
				$(LEXERDIR)/state/making_great.c \
				$(LEXERDIR)/state/making_less.c \
				$(LEXERDIR)/state/making_pipe.c \
				$(LEXERDIR)/state/making_word.c \
				$(LEXERDIR)/state/quote_branch.c \
				$(LEXERDIR)/state/quote_close.c \
				$(LEXERDIR)/state/quote_making_word.c \
				$(LEXERDIR)/expand/expand_logic.c \
				$(LEXERDIR)/expand/expand_utils.c \
				$(PARSEDIR)/parser.c \
				$(PARSEDIR)/parser_utils.c \
				$(UTILDIR)/syntax_err.c \
				$(UTILDIR)/del_lists.c
OBJS		=	${SRCS:.c=.o}


all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(DLLDIR)
	$(MAKE) -C $(GNLDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lreadline

bonus : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(DLLDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(DLLDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

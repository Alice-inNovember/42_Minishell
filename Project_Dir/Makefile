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
				$(LEXERDIR)/print_token_lst.c \
				$(LEXERDIR)/tokenize.c \
				$(LEXERDIR)/tokenize_utils.c \
				$(LEXERDIR)/status/dquote_close.c \
				$(LEXERDIR)/status/dquote_error.c \
				$(LEXERDIR)/status/dquote_expand.c \
				$(LEXERDIR)/status/dquote_open.c \
				$(LEXERDIR)/status/expand.c \
				$(LEXERDIR)/status/expand_utils.c \
				$(LEXERDIR)/status/making_dgreat.c \
				$(LEXERDIR)/status/making_dless.c \
				$(LEXERDIR)/status/making_great.c \
				$(LEXERDIR)/status/making_less.c \
				$(LEXERDIR)/status/making_pipe.c \
				$(LEXERDIR)/status/making_word.c \
				$(LEXERDIR)/status/quote_close.c \
				$(LEXERDIR)/status/quote_error.c \
				$(LEXERDIR)/status/quote_open.c \
				$(LEXERDIR)/status/start.c \
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

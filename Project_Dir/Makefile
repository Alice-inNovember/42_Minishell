#NAME
NAME		=	minishell
#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=
DFLAGS		=	-g3 -fsanitize=address
#DIRS
LFTDIR		=	libraries/libft
DLLDIR		=	libraries/dllist
GNLDIR		=	libraries/get_next_line
SRCDIR		=	srcs
INCDIR		=	./includes
ENVPDIR		=	$(SRCDIR)/envp
LEXERDIR	=	$(SRCDIR)/lexer
PARSEDIR	=	$(SRCDIR)/parser
EXECDIR		= 	$(SRCDIR)/executor
BUIDIR		=	$(SRCDIR)/builtin
UTILDIR		=	$(SRCDIR)/util
BONUSDIR	=	
#FILES
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR) -I $(INCDIR)
SRCS		=	$(SRCDIR)/main.c \
				$(ENVPDIR)/envp.c \
				$(ENVPDIR)/envp_util.c \
				$(LEXERDIR)/make_token_list.c \
				$(LEXERDIR)/state/branch.c \
				$(LEXERDIR)/state/skip_space.c \
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
				$(LEXERDIR)/state/clear.c \
				$(LEXERDIR)/expand/expand_logic.c \
				$(LEXERDIR)/expand/expand_utils.c \
				$(LEXERDIR)/utils/make_buf.c \
				$(LEXERDIR)/utils/make_token.c \
				$(LEXERDIR)/utils/print_token_list.c \
				$(PARSEDIR)/parser.c \
				$(PARSEDIR)/parse_suffix_prefix.c \
				$(PARSEDIR)/parse_word_redir.c \
				$(PARSEDIR)/parse_heredoc.c \
				$(PARSEDIR)/check_return_cases.c \
				$(PARSEDIR)/redir_check_set_err.c \
				$(PARSEDIR)/parser_utils.c \
				$(PARSEDIR)/heredoc/make_temp_file.c \
				$(PARSEDIR)/heredoc/make_file_using_mktemp.c \
				$(PARSEDIR)/heredoc/make_random_name_file.c \
				$(EXECDIR)/executor.c \
				$(EXECDIR)/executor_child.c \
				$(EXECDIR)/executor_util.c \
				$(BUIDIR)/built_in.c \
				$(BUIDIR)/built_in_util.c \
				$(BUIDIR)/bt_cd.c \
				$(BUIDIR)/bt_echo.c \
				$(BUIDIR)/bt_env.c \
				$(BUIDIR)/bt_exit.c \
				$(BUIDIR)/bt_export.c \
				$(BUIDIR)/bt_pwd.c \
				$(BUIDIR)/bt_unset.c \
				$(UTILDIR)/syntax_err.c \
				$(UTILDIR)/del_lists.c
OBJS		=	${SRCS:.c=.o}

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

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

debug	:
	$(MAKE) IF_DEBUG=1 all

.PHONY : all clean fclean re

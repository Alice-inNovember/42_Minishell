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
SIGDIR		=	$(SRCDIR)/signal
BONUSDIR	=	
#FILES
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a -lreadline -L/Users/jincpark/.brew/opt/readline/lib
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR) -I $(INCDIR) -I/Users/jincpark/.brew/opt/readline/include
SRCS		=	$(SRCDIR)/main.c \
				$(ENVPDIR)/envp.c \
				$(ENVPDIR)/envp_util.c \
				$(LEXERDIR)/tokenizer.c \
				$(LEXERDIR)/print_token_list.c \
				$(LEXERDIR)/utils/join_buf.c \
				$(LEXERDIR)/utils/make_buf.c \
				$(LEXERDIR)/utils/expand/get_env_length.c \
				$(LEXERDIR)/utils/expand/is_limiter.c \
				$(LEXERDIR)/utils/expand/make_expanded_line.c \
				$(LEXERDIR)/utils/expand/make_question_mark_expanded_line.c \
				$(LEXERDIR)/state/start.c \
				$(LEXERDIR)/state/branch.c \
				$(LEXERDIR)/state/skip_space.c \
				$(LEXERDIR)/state/clear.c \
				$(LEXERDIR)/state/pipe/add_buf_pipe.c \
				$(LEXERDIR)/state/pipe/make_pipe_token.c \
				$(LEXERDIR)/state/less/add_buf_less.c \
				$(LEXERDIR)/state/less/branch_less.c \
				$(LEXERDIR)/state/less/make_less_token.c \
				$(LEXERDIR)/state/less/add_buf_dless.c \
				$(LEXERDIR)/state/less/make_dless_token.c \
				$(LEXERDIR)/state/great/add_buf_great.c \
				$(LEXERDIR)/state/great/branch_great.c \
				$(LEXERDIR)/state/great/make_great_token.c \
				$(LEXERDIR)/state/great/add_buf_dgreat.c \
				$(LEXERDIR)/state/great/make_dgreat_token.c \
				$(LEXERDIR)/state/word/add_buf_word.c \
				$(LEXERDIR)/state/word/make_word_token.c \
				$(LEXERDIR)/state/expand/add_buf_in_expand.c \
				$(LEXERDIR)/state/expand/branch_expand.c \
				$(LEXERDIR)/state/expand/check_expand.c \
				$(LEXERDIR)/state/expand/expand.c \
				$(LEXERDIR)/state/expand/expand_end.c \
				$(LEXERDIR)/state/expand/make_word_token_expand.c \
				$(LEXERDIR)/state/expand/question_mark_expand.c \
				$(LEXERDIR)/state/expand/skip_space_in_expand.c \
				$(LEXERDIR)/state/quote/add_buf_in_quote.c \
				$(LEXERDIR)/state/quote/branch_quote.c \
				$(LEXERDIR)/state/quote/close_quote.c \
				$(LEXERDIR)/state/quote/make_word_token_quote.c \
				$(LEXERDIR)/state/quote/open_quote.c \
				$(LEXERDIR)/state/quote/open_quote_error.c \
				$(LEXERDIR)/state/dquote/add_buf_in_dquote.c \
				$(LEXERDIR)/state/dquote/branch_dquote.c \
				$(LEXERDIR)/state/dquote/close_dquote.c \
				$(LEXERDIR)/state/dquote/make_word_token_dquote.c \
				$(LEXERDIR)/state/dquote/open_dquote.c \
				$(LEXERDIR)/state/dquote/open_dquote_error.c \
				$(LEXERDIR)/state/dquote/skip_backslash_in_dquote.c \
				$(LEXERDIR)/state/dquote/expand_dquote/check_expand_dquote.c \
				$(LEXERDIR)/state/dquote/expand_dquote/expand_dquote.c \
				$(LEXERDIR)/state/dquote/expand_dquote/question_mark_expand_dquote.c \
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
				$(PARSEDIR)/heredoc/get_heredoc_input.c \
				$(PARSEDIR)/heredoc/get_limiter.c \
				$(EXECDIR)/executor.c \
				$(EXECDIR)/executor_child.c \
				$(EXECDIR)/executor_util1.c \
				$(EXECDIR)/executor_util2.c \
				$(BUIDIR)/built_in.c \
				$(BUIDIR)/built_in_util.c \
				$(BUIDIR)/bt_cd.c \
				$(BUIDIR)/bt_echo.c \
				$(BUIDIR)/bt_env.c \
				$(BUIDIR)/bt_exit.c \
				$(BUIDIR)/bt_export_1.c \
				$(BUIDIR)/bt_export_2.c \
				$(BUIDIR)/bt_pwd.c \
				$(BUIDIR)/bt_unset.c \
				$(SIGDIR)/signal_handler.c \
				$(UTILDIR)/syntax_err.c \
				$(UTILDIR)/del_lists.c \
				$(UTILDIR)/etc.c
OBJS		=	${SRCS:.c=.o}

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

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
	$(MAKE) -C $(DLLDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(DLLDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) -j6 all

rebug	: fclean
	$(MAKE) -j6 IF_DEBUG=1 all

.PHONY : all clean fclean re

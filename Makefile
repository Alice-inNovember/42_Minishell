# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyi <tyi@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 09:54:10 by tyi          #+#    #+#              #
#    Updated: 2023/01/13 09:54:12 by tyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME		=	minishell
#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs
#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
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
LIBS		=	$(LFTDIR)/libft.a $(DLLDIR)/libdll.a $(GNLDIR)/libgnl.a -lreadline -L${HOME}/.brew/opt/readline/lib
INCS		=	-I $(LFTDIR) -I $(DLLDIR) -I $(GNLDIR) -I $(INCDIR) -I${HOME}/.brew/opt/readline/include
SRCS		=	$(SRCDIR)/main.c \
				$(ENVPDIR)/envp.c \
				$(ENVPDIR)/envp_util.c \
				$(LEXERDIR)/tokenizer.c \
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
				$(LEXERDIR)/state/quote/open_quote.c \
				$(LEXERDIR)/state/quote/open_quote_error.c \
				$(LEXERDIR)/state/dquote/add_buf_in_dquote.c \
				$(LEXERDIR)/state/dquote/branch_dquote.c \
				$(LEXERDIR)/state/dquote/close_dquote.c \
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
				$(EXECDIR)/executor_util3.c \
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
				$(SIGDIR)/signal_utils.c \
				$(UTILDIR)/syntax_err.c \
				$(UTILDIR)/del_lists.c \
				$(UTILDIR)/error_msg.c \
				$(UTILDIR)/etc.c
OBJS		=	${SRCS:.c=.o}
#COLOR
Color_Off	=	"\033[0m"
LRed		=	"\033[1;31m"
LGreen		=	"\033[1;32m"
LBlue		=	"\033[1;34m"
LPurple		=	"\033[1;35m"
LCyan		=	"\033[1;36m"
INFO		=

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

all :
	@$(MAKE) -j6 $(NAME)

$(NAME) : $(OBJS)
	$(eval INFO = $(shell echo $(LBlue)Compiling$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LFTDIR) libft.a
	$(eval INFO = $(shell echo $(LCyan)libft.a "  "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(DLLDIR) libdll.a
	$(eval INFO = $(shell echo $(LCyan)libdll.a " "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(GNLDIR) libgnl.a
	$(eval INFO = $(shell echo $(LCyan)libgnl.a " "✅$(Color_Off)))
	$(info $(INFO))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	$(eval INFO = $(shell echo $(LPurple)minishell ""✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	$(eval INFO = $(shell echo $(LRed)Cleaning$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(LFTDIR) fclean
	$(eval INFO = $(shell echo $(LCyan)libft "    "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(DLLDIR) fclean
	$(eval INFO = $(shell echo $(LCyan)libdll "   "✅$(Color_Off)))
	$(info $(INFO))
	@$(MAKE) -C $(GNLDIR) fclean
	$(eval INFO = $(shell echo $(LCyan)libgnl "   "✅$(Color_Off)))
	$(info $(INFO))
	@$(RM) $(OBJS) $(BOBJS)
	$(eval INFO = $(shell echo $(LCyan)obj files ""✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

fclean : clean
	$(eval INFO = $(shell echo $(LRed)Removing$(Color_Off)))
	$(info $(INFO))
	@$(RM) $(NAME)
	$(eval INFO = $(shell echo $(LPurple)minishell ""✅$(Color_Off)))
	$(info $(INFO))
	$(eval INFO = $(shell echo $(LGreen)Done!$(Color_Off)))
	$(info $(INFO))
	$(info )

re :
	@$(MAKE) fclean
	@$(MAKE) all

rebug	:
	@$(MAKE) fclean
	@$(MAKE) IF_DEBUG=1 all

.PHONY : all clean fclean re

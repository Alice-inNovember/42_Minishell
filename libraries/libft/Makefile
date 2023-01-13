# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 11:00:34 by tyi               #+#    #+#              #
#    Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = src
SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isspace.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_str3join.c \
		ft_str4join.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_malloc.c \
		ft_calloc.c \
		ft_exit.c \
		ft_free_vector.c \
		ft_pipe.c \
		ft_fork.c \
		ft_dup.c \
		ft_dup2.c \
		ft_unlink.c \
		ft_waitpid.c \
		ft_execve.c \
		ft_stat.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

clean:
	@$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)

re:
	@make fclean
	@make all

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:51:52 by tyi               #+#    #+#              #
#    Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = src
SRCS = get_next_line.c \
	   get_next_line_utils.c

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

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY : all bonus clean fclean re

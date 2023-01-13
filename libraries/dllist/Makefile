# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 15:36:02 by tyi               #+#    #+#              #
#    Updated: 2023/01/13 12:37:00 by tyi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdll.a

CC = CC
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

HEADER_DIR = includes

SRCS_DIR = src
SRCS = list_add.c \
	   list_delete.c \
	   list_peek.c \
	   list_basic.c

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

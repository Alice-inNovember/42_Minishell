# NAME		=	minishell
# #CMDS
# CC			=	cc -g3 -fsanitize=address
# RM			=	rm -rf
# LIBC		=	ar rcs

# CFLAGS		=	
# #DIRS
# LFTDIR		=	../../libraries/libft
# DLLDIR		=	../../libraries/dllist
# ENVPDIR 	=	../envp
# SRCDIR		=	srcs

all :
	 cc -Wall -Wextra -Wall -g3 -fsanitize=address -lreadline bt_cd.c         bt_echo.c       bt_env.c        bt_exit.c       bt_export.c     bt_pwd.c        bt_unset.c      built_in.c          envp.a          libdll.a        libft.a

# $(NAME) : $(OBJS)
# 	$(MAKE) -C $(LFTDIR)
# 	$(MAKE) -C $(DLLDIR)
# 	$(MAKE) -C $(ENVPDIR)	
# 	$(CC) 	
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lreadline

# bonus : $(NAME)

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# clean :
# 	$(MAKE) -C $(LFTDIR) clean
# 	$(MAKE) -C $(DLLDIR) clean
# 	$(MAKE) -C $(GNLDIR) clean
# 	$(RM) $(OBJS) $(BOBJS)

# fclean : clean
# 	$(MAKE) -C $(LFTDIR) fclean
# 	$(MAKE) -C $(DLLDIR) fclean
# 	$(MAKE) -C $(GNLDIR) fclean
# 	$(RM) *.a
# 	$(RM) $(NAME)

# re : fclean all

# .PHONY : all clean fclean re
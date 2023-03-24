# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: datran <datran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 11:58:04 by datran            #+#    #+#              #
#    Updated: 2023/03/24 16:19:43 by datran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		pipex
CC				=		gcc
FLAGS			=		-Wall -Wextra -Werror
RM				=		rm -rf

HEAD_DIR		=		./includes/

SRCS_DIR		=		./mandatory/
SRCS_FILES		=		pipex.c free.c error.c redirects.c
SRCS			=		$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=		$(SRCS:.c=.o)

all:		$(NAME)

%o:			%.c
			$(CC) -I$(HEAD_DIR) $(FLAGS) -c $?
			
$(NAME):	$(OBJS) libft
			$(CC) $(FLAGS) $(OBJS) -Llibft -lft -I$(HEAD_DIR) -o $@

libft:
			make -C libft

clean:
			make -C libft clean
			$(RM) ./mandatory/*.o

fclean:		clean
			$(RM) $(NAME) $(OBJS) ./libft/libft.a

re:			fclean all

git:
			@git add -A
			@git commit -m "$m"
			@git push
			@echo "Commit sent to GitHub"
# Use make git m="msg" to commit

.PHONY:		all libft clean fclean re

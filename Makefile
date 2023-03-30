# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: datran <datran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 11:58:04 by datran            #+#    #+#              #
#    Updated: 2023/03/30 17:38:46 by datran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		pipex
CC				=		gcc
FLAGS			=		-Wall -Wextra -Werror
RM				=		rm -rf

HEAD_DIR		=		./includes/

SRCS_DIR		=		srcs/
SRCS_FILES		=		pipex.c free.c error.c redirects.c
SRCS			=		$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=		$(SRCS:.c=.o)

LIBFT			=		libft/libft.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@
			
$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) -Llibft -lft -o $@

$(LIBFT):
			make -C libft

clean:
			make -C libft clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

git:
			@git add -A
			@git commit -m "$m"
			@git push
			@echo "Commit sent to GitHub"
# Use make git m="msg" to commit

.PHONY:		all libft clean fclean re

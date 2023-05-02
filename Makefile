NAME		=	pipex
BONUS		=	pipex_bonus
LIBFT		=	libft/libft.a
CC			=	gcc

SRCS_DIR	=	srcs/
SRCS_FILES	=	main.c error.c childs.c close.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		=	$(SRCS:%.c=%.o)

BSRCS_DIR	=	srcs_bonus/
BSRCS_FILES	=	main_bonus.c error_bonus.c childs_bonus.c close_bonus.c
BSRCS		=	$(addprefix $(BSRCS_DIR), $(BSRCS_FILES))
BOBJS		=	$(BSRCS:%.c=%.o)

LIBFTFLAGS			=		-Llibft -lft


CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:		$(NAME)
bonus:		$(BONUS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(CFLAGS) $(LIBFTFLAGS) -o $(NAME)

$(BONUS):	$(BOBJS) $(LIBFT)
			$(CC) $(BOBJS) $(CFLAGS) $(LIBFTFLAGS) -o $(BONUS)

$(LIBFT):
			make -C libft

clean:
			make -C libft clean
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(LIBFT)
			$(RM) $(NAME) $(BONUS)

re:			fclean all

rebonus:	fclean bonus

git:
			@git add -A
			@git commit -m "$m"
			@git push
			@echo "Commit sent to GitHub"
# Use make git m="msg to commit"

.PHONY:		all clean fclean re bonus rebonus git

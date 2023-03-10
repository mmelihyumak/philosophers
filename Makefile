SRCS		=		main.c philo_error.c philo_struct.c ft_atoi.c philo_thread.c philo_wait.c

OBJS		=		$(SRCS:.c=.o)

NAME		=		philo

CC			=		gcc

RM			=		rm -rf

all:				$(NAME)

$(NAME):			$(OBJS)
						$(CC) $(OBJS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
						$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re

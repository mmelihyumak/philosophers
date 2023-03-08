SRCS		=		philo.c ft_atoi.c philo_struct.c philo_thread.c pthread_mutex.c philo_time.c philo_death_control.c philo_error.c \
					philo_eating.c

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

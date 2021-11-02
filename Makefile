NAME = philo
CFLAGS = -Werror -Wextra -g -pthread
SRCS = srcs/main.c \
		srcs/death.c \
		srcs/error.c \
		srcs/parser.c \
		srcs/utils.c \
		srcs/activity.c \
		srcs/processing.c \


OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				gcc $(CFLAGS) $(OBJS) -o $(NAME)

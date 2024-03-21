NAME = pipex

HEADERS = includes/pipex.h

LIBFT = libft/libft.a

CFILES = src/main.c \
			src/utils.c \
			src/get_struct.c

OFILES = $(CFILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) -C libft all

$(NAME) : $(OFILES)
	$(CC) $(OFILES) $(LIBFT) -o $(NAME)

clean :
	$(MAKE) -C libft clean
	rm -rf $(OFILES)

fclean : clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY :
	all clean fclean re
NAME=libftprintf.a
LIBFT=libft/libft.a

SRCS=ft_printf.c ft_printf_utils.c
OBJS=$(SRCS:.c=.o)


CC=gcc
CFLAGS=-Wall -Wextra -Werror

# $@ - target
# $^ - butun dependen
# $< - ilk dependen

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

help:
	@echo "------------------------ <<HELP COMMAND>> --------------------------"
	@echo "make:        compiles all *.c files and create an archive file called"
	@echo "             'libftprintf.a' which contains a clone of printf function"
	@echo "make clean:  cleans all *.o files"
	@echo "make fclean: cleans all *.o files and the archive file 'libftprintf.a'"
	@echo "make re:     cleans all files and compiles again"

re: fclean all

.PHONY: all clean fclean re bonus help
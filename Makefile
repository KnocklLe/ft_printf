
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
INCLUDES = -Iincludes
NAME     = libftprintf.a
EXEC     = programme
SOURCES  = srcs/ft_putstr.c \
           srcs/ft_putnbr.c \
           srcs/ft_putchar.c \
           srcs/ft_printf.c
OBJECTS  = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o: %.c includes/printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all

main: $(NAME) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf -o $(EXEC)

.PHONY: all clean fclean re main

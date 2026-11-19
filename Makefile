
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
INCLUDES = -Iincludes

NAME     = libftprintf.a
EXEC     = programme

GREEN    = \033[0;32m
RED      = \033[0;31m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
RESET    = \033[0m

SOURCES  = srcs/ft_printf.c \
           srcs/ft_putchar.c \
           srcs/ft_putstr.c \
           srcs/ft_putnbr.c \
           srcs/ft_putnbr_unsigned.c \
           srcs/ft_putnbr_base.c

OBJECTS  = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)Création de $(NAME)...$(RESET)\n"
	@ar rcs $@ $^
	@printf "$(GREEN)Bibliothèque compilée avec succès !$(RESET)\n"

%.o: %.c includes/ft_printf.h
	@printf "$(YELLOW)Compilation de $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

main: $(NAME) main.c
	@printf "$(BLUE)====== TEST FT_PRINTF ======$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf -o $(EXEC)
	@printf "$(GREEN)Exécution du programme...$(RESET)\n"
	@./$(EXEC)

clean:
	@printf "$(YELLOW)Suppression des fichiers objets...$(RESET)\n"
	@rm -f $(OBJECTS)

fclean: clean
	@printf "$(RED)Suppression de la bibliothèque et du programme...$(RESET)\n"
	@rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re main
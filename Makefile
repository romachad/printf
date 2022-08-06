NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
LIB_SRC := ft_strdup.c ft_strlen.c ft_putstr.c ft_strchr.c ft_printf.c ft_count_char.c ft_check_allowed.c ft_strchr_n.c ft_substr.c ft_strjoin2.c ft_calloc.c
OBJ := ${LIB_SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $@ $^

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re

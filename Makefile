NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_SRC = ft_strdup ft_strlen ft_putstr ft_strchr ft_printf ft_substr ft_strjoin2 ft_calloc ft_itoa ft_utoa hex_str ft_putchar
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(LIB_SRC)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(LIB_SRC)))
SRCS_DIR = srcs/
OBJ_DIR = objs/

all:
	mkdir -p $(OBJ_DIR)
	make $(NAME)

$(NAME): $(OBJ)
	ar -crs $@ $^

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) -c $^ $(CFLAGS) -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re

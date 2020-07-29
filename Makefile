NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = clang
AR = ar rcs
REMOVE = rm -Rf
SRC_DIR = src/
SRC = ft_printf.c \
	  ft_printf_utils.c \
	  ft_itoa_base.c \
	  conversion_char.c \
	  conversion_num.c \
	  parse.c \
	  libft_functions.c
SRC_PATH = $(patsubst %.c, $(SRC_DIR)%.c, $(SRC))
OBJ = $(SRC_PATH:.c=.o)
HEADER = includes/ft_printf.h
INCLUDES = includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
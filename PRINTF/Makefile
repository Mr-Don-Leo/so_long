# Compiler that will be used to compile
CC = cc
# Name of the library that will be created
NAME = libftprintf.a
# These are the compiler flags that will be used
COMP_FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c print_utils.c output_char.c output_str.c \
		output_int.c output_hexa.c output_pointer.c output_unsigned.c\

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	ar -rcs $@ $(OBJ)

%.o: %.c
	$(CC) -c $(COMP_FLAGS) $?

re: fclean all

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY:			all clean fclean re
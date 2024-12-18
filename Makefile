
NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c applys.c case_ab.c case_ba.c checker_arg.c \
enter_data.c func_lists.c get_string.c operators.c operatorstwo.c \
operatorsthree.c parseo.c sort_others.c sort.c utils.c \

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)
		make clean -C libft

fclean: clean
	$(RM) $(NAME)
		make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
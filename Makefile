NAME = minishell

SRC = ./sources/main.c ./sources/parameter_search.c

OBJ = main.o parameter_search.o

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/ libft.a
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

libft:
	make -C libft/ libft.a

clean:
	make -C libft/ clean
	rm -fr $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -fr $(NAME)

re: fclean all





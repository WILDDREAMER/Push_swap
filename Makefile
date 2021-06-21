NAME = push_swap

SRC = *.c
	
all : $(NAME)

$(NAME):$(SRC)
	make -C ./libft
	gcc $(SRC) ./libft/libft.a -g -o push_swap
clean:
	rm -rf push_swap push_swap.dSYM
fclean:
	rm -rf push_swap push_swap.dSYM ./libft/*.o a.out ./libft/libft.a
re: fclean all

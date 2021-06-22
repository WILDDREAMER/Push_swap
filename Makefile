CH_NAME = checker
PS_NAME = push_swap


CH_SRC = ./checker.c ./getnextline/get_next_line.c

PS_SRC = ./push_swap.c ./getnextline/get_next_line.c 

all : $(PS_NAME)

$(PS_NAME):$(PS_SRC)
	make -C ./libft
	gcc $(PS_SRC) ./libft/libft.a -o $(PS_NAME)

bonus: $(CH_SRC)
	make -C libft
	gcc $(CH_SRC) ./libft/libft.a  -o $(CH_NAME) 

clean:
	rm -rf checker.dSYM
	rm -rf push_swap.dSYM
	rm -rf libft/*.o

fclean: clean
	rm -f checker
	rm -f push_swap
	rm -f libft/libft.a
re: fclean all

.PHONY: all bonus clean fclean re
CH_NAME = checker
PS_NAME = push_swap


CH_SRC = checker.c handle_input.c ./utils.c \
 		./cercular_linked_list/cercular_linked_list_utils.c \
		 ./cercular_linked_list/cercular_linked_list_utils_2.c \
		 ./cercular_linked_list/cercular_linked_list_utils_3.c \
		 ./cercular_linked_list/cercular_linked_list_utils_1.c  \
		 checker_utils.c push_swap_utils.c instructions.c \
		 instructions_1.c getnextline/get_next_line.c

PS_SRC = push_swap.c handle_input.c ./utils.c \
		./sort/sort_five.c ./sort/sort_big_numbers.c \
		./sort/big_numbers_utils.c ./sort/sort_three.c \
		./sort/sort_two.c ./cercular_linked_list/cercular_linked_list_utils.c \
		./cercular_linked_list/cercular_linked_list_utils_2.c \
		./cercular_linked_list/cercular_linked_list_utils_3.c \
		./cercular_linked_list/cercular_linked_list_utils_1.c  \
		checker_utils.c push_swap_utils.c instructions.c \
		instructions_1.c getnextline/get_next_line.c

all : $(PS_NAME)

$(PS_NAME):$(PS_SRC)
	make -C libft
	gcc $(PS_SRC) libft/libft.a  -o push_swap

bonus: $(CH_SRC)
	make -C libft
	gcc $(CH_SRC) libft/libft.a  -o checker

clean:
	rm -rf checker.dSYM
	rm -rf push_swap.dSYM
	rm -rf libft/*.o

fclean: clean
	rm -f checker
	rm -f push_swap
	rm -f libft/libft.a
	rm -rf checker.dSYM
	rm -rf push_swap.dSYM
re: fclean all

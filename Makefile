CH_NAME = checker
PS_NAME = push_swap


CH_SRC = checker.c ./cercular_linked_list/cercular_linked_list_utils.c ./cercular_linked_list/cercular_linked_list_utils_2.c ./cercular_linked_list/cercular_linked_list_utils_3.c ./cercular_linked_list/cercular_linked_list_utils_1.c  checker_utils.c push_swap_utils.c visualizer.c instructions.c getnextline/get_next_line.c

PS_SRC = push_swap.c ./sort/sort_five.c ./sort/sort_big_numbers.c ./sort/big_numbers_utils.c ./sort/sort_three.c ./sort/sort_two.c ./cercular_linked_list/cercular_linked_list_utils.c ./cercular_linked_list/cercular_linked_list_utils_2.c ./cercular_linked_list/cercular_linked_list_utils_3.c ./cercular_linked_list/cercular_linked_list_utils_1.c  checker_utils.c push_swap_utils.c visualizer.c instructions.c getnextline/get_next_line.c 

all : $(PS_NAME) $(CH_NAME)

$(PS_NAME):$(PS_SRC) $(CH_SRC)
	make -C libft
	gcc $(PS_SRC) -g libft/libft.a -o push_swap
	gcc $(CH_SRC) -g libft/libft.a -o checker

# bonus: $(CH_SRC)
# 	make -C libft
# 	gcc $(CH_SRC) -g libft/libft.a -o checker

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
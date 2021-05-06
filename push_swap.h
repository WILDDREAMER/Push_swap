#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libft/libft.h"

typedef struct	s_stack
{
	int val;
    struct s_stack *prev;
    struct s_stack *next;
}				t_stack;


#endif
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
	int index;
}	t_node;
typedef struct s_stack
{
	t_node *element;
	int size;
	t_node *top;
}	t_stack;


long	ft_atoi(const char *str);
int is_num(char c);
int checking_num(char**argv);
int checking_dup(char **argv, int argc); 
int	isempty(t_stack *s);
int checking_max_min(char **argv);

#endif
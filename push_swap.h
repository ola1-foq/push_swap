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
	int size;
	t_node *top;
}	t_stack;


long	ft_atoi(const char *str);
int is_num(char c);
int checking_num(char**argv);
int checking_dup(char **argv, int argc); 
int	isempty(t_stack *s);
int checking_max_min(char **argv);
t_node *creating_node(int data);
void sa_op(t_stack *a);
void sb_op(t_stack *b);
void ss_op(t_stack *a, t_stack *b);
void pa_op(t_stack *a, t_stack *b);
void pb_op(t_stack *a, t_stack *b);
void ra_op(t_stack *a);
void rb_op(t_stack *b);
void rr_op(t_stack *a, t_stack *b);
void rra_op(t_stack *a);
void rrb_op(t_stack *b);
void rrr_op(t_stack *a, t_stack *b);
void radix_sort(t_stack **a, t_stack **b);
void mini_sort(t_stack **a, t_stack **b);
void sort_2(t_stack **a);
void sort_3(t_stack **a);
void sort_4(t_stack **a, t_stack **b);
void sort_5(t_stack **a, t_stack **b);
int ft_lstsize(t_stack *lst);
void push(t_stack *a, int data);
void pop(t_stack *a);
int checking_all(char**argv, int argc,int *arr);
int is_sorted(int *arr, int size);
void filling(t_stack *a,int argc,int *arr);
void assign_index(t_stack *a, int *arr, int size);


#endif
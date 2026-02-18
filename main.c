#include <unistd.h>
#include <string.h>
#include "push_swap.h"

int is_num(char y)
{
	if(!(y>='0' && y<='9'))
		return (0);
	return (1);
}

int checking_num(char**argv)
{

	int i;
	int j;
	i=1;
	while(argv[i])
	{
		j =0;
		while(argv[i][j])
		{
			if(!(is_num(argv[i][j])))
			{
				write(2,"Error\n",6);
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}

int checking_dup(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int is_sorted(int	*arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int checking_all(char**argv, int argc,int *arr)
{
	if(!checking_num(argv) || !checking_dup(argv,argc))
	{
		free(arr);
		return(0);
	}
	if(!checking_max_min(argv))
	{
		free(arr);
		return(0);
	}
	if(is_sorted(arr,argc-1))
	{
		free(arr);
		return(0);
	}
	return (1);
}

t_node *creating_node (int data)
{
	t_node *n1;
	n1=malloc(sizeof(t_node));
	if(!n1)
		return (NULL);
	n1->data = data;
	n1->index = 0;
	n1->next =NULL;
	return (n1);
}

void assign_index(t_stack *a, int *arr, int size)
{
	t_node *tmp;
	int i;
	int rank;

	tmp = a->top;
	while (tmp)
	{
		rank = 0;
		i = 0;
		while (i < size)
		{
			if (arr[i] < tmp->data)
				rank++;
			i++;
		}
		tmp->index = rank;
		tmp = tmp->next;
	}
}

void  filling(t_stack *a,int argc,int *arr)
{
	int i = argc - 2;
	t_node *node;
	while(i >= 0)
	{
		node=creating_node(arr[i]);
		if(!node)
			return ;
		node->next=a->top;
		a->top=node;
		a->size++;
		i--;
	}
}

void init_stack(t_stack *a)
{
	a->top=NULL;
	a->size=0;
}

int main(int argc,char**argv)
{
	t_stack *a;
	t_stack *b;


	if(argc <2)
		return(0);
	int *arr;
	arr=malloc(sizeof(int) * (argc - 1));
	if(!arr)
		return(0);
	int i=1;
	int j=0;
	while(i<argc)
	{
		arr[j]=ft_atoi(argv[i]);
		i++;
		j++;
	}	
	if(!checking_all(argv,argc,arr))
		return(0);
	a=malloc(sizeof(t_stack));
	b=malloc(sizeof(t_stack));
	if(!a || !b)
		return(0);
	init_stack(a);
	init_stack(b);
	filling(a,argc,arr);
	assign_index(a, arr, argc - 1);

	if (a->size > 6)
		radix_sort(&a, &b);
	else if (a->size > 1)
		mini_sort(&a, &b);

	free(arr);
}


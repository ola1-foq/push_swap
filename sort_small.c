#include "push_swap.h"
 
void sort_2(t_stack **a)
{
	if(!a)
		return ;
	if((*a)->size <2)
		return;
	int tmp =(*a)->top->data;
	int tmp_2=(*a)->top->next->data;
	if(tmp>tmp_2)
		sa_op(*a); 
}

void sort_3(t_stack **a)
{
	if(!(*a)->top || !(*a)->top->next ||(*a)->top->next->next )
		return ;
		
}


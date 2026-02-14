#include "push_swap.h"

void sa_op(t_stack *a)
{
	if(a->size < 2)
		return ;
	int temp;
	temp = a->element->data;
	a->element->data = a->element->next->data;
	a->element->next->data = temp;
	write(1,"sa\n",3);
}
void sb_op(t_stack *b)
{
	if(b->size < 2)
		return ;
	int temp;
	temp = b->element->data;
	b->element->data = b->element->next->data;
	b->element->next->data = temp;
	write(1,"sb\n",3);
}

void ss_op(t_stack *a,t_stack *b)
{
	sa_op(a);
	sb_op(b);
	write(1,"ss\n",3);
}
void push(t_stack *a,int data)
{
	t_node *new_node = creating_node(data);
	if(!a)
		return ;
	if(isempty(a))
		return ;
	a->size++;
	new_node->next = a->element;
	a->top=new_node;
}
void pop(t_stack *a)
{
	if(!a)
		return ;
	if(isempty(a))
		return ;
	a->size--;
	a->element = a->element->next;
}
void pa_op(t_stack *a,t_stack *b)
{
	if(!a || !b)
		return ;
	if(isempty(b))
		return ;
	int temp;
	temp = b->element->data;
	pop(b);
	push(a,temp);
	write(1,"pa\n",3);
}
void pb_op(t_stack *a,t_stack *b)
{
	if(!a || !b)
		return ;
	if(isempty(a))
		return ;
	int temp;
	temp = a->element->data;
	pop(a);
	push(b,temp);
	write(1,"pb\n",3);
}
void ra_op(t_stack *a)
{
	t_node	*tmp;
	t_node	*u;

	if (isempty(a))
		return ;
	tmp = a->top;
	u = a->top;
	while (u->next)
		u = u->next;
	a->top = tmp->next;
	u->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
void rb_op(t_stack *b)
{
	t_node	*tmp;
	t_node	*u;

	if (isempty(b))
		return ;
	tmp = b->top;
	u = b->top;
	while (u->next)
		u = u->next;
	b->top = tmp->next;
	u->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}
void rr_op(t_stack *a,t_stack *b)
{
	if (isempty(b) || isempty(a))
		return ;
	ra_op(a);
	rb_op(b);
	write(1, "rr\n", 3);
}
void rra_op(t_stack *a)
{
	t_node	*tmp;
	t_node	*u;
	if (isempty(a))
		return ;
	tmp = a->top;
	u = a->top;
	while (u->next)
		u = u->next;
	u->next = tmp;
	a->top = u;
	tmp->next = NULL;
	write(1, "rra\n", 3);
}
void rrb_op(t_stack *b)
{
	t_node	*tmp;
	t_node	*u;
	if (isempty(b))
		return ;
	tmp = b->top;
	u = b->top;
	while (u->next)
		u = u->next;
	u->next = tmp;
	b->top = u;
	tmp->next = NULL;
	write(1, "rrb\n", 3);
}
void rrr_op(t_stack *a,t_stack *b)
{	if (isempty(b) || isempty(a))
		return ;
	rra_op(a);
	rrb_op(b);
	write(1, "rrr\n", 3);
}

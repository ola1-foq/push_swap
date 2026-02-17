/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:38:02 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/17 20:43:58 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 static int find_min_position(t_stack *a)
{
    t_node  *tmp;
    int     min;
    int     pos;
    int     i;

    if (!a || !a->top)
        return (0);

    tmp = a->top;
    min = tmp->data;
    pos = 0;
    i = 0;

    while (tmp)
    {
        if (tmp->data < min)
        {
            min = tmp->data;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (pos);
}

void sort_2(t_stack **a)
{
	if (!a || !(*a) || (*a)->size < 2)
    	return;
	int tmp =(*a)->top->data;
	int tmp_2=(*a)->top->next->data;
	if(tmp>tmp_2)
		sa_op(*a); 
}

void sort_3(t_stack **a)
{
	int f;
    int s;
    int th;

	if (!(*a) || !(*a)->top || !(*a)->top->next || !(*a)->top->next->next)
        return;
 	f = (*a)->top->data;
    s = (*a)->top->next->data;
    th= (*a)->top->next->next->data;
 	if (f > s && s < th && f < th)
        sa_op(a);
    else if (f > s && s > th)
    {
        sa_op(a);
        rra(a);
    }
    else if (f > s && s < th && f > th)
        ra(a);
    else if (f < s && s > th && f < th)
    {
        sa_op(a);
        ra(a);
    }
    else if (f < s && s > th && f > th)
        rra(a);
}
void sort_4(t_stack **a ,t_stack **b)
{
	 int pos;

	if (!(*a) || (*a)->size < 4)
        return;

	pos = find_min_position(*a);

	if(pos == 1)
		ra(a);
	else if(pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if(pos == 3)
		rra(a);

	pb(a,b);
	sort_3(a);
	pa(a,b);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:38:02 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/18 19:52:38 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void mini_sort(t_stack **a, t_stack **b)
{
	int size;
	
	size = ft_lstsize(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}

 static int find_min_position(t_stack *a)
{
    t_node  *tmp;
    int     min_idx;
    int     pos;
    int     i;

    if (!a || !a->top)
        return (0);

    tmp = a->top;
    min_idx = tmp->index;
    pos = 0;
    i = 0;

    while (tmp)
    {
        if (tmp->index < min_idx)
        {
            min_idx = tmp->index;
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
	int idx1 = (*a)->top->index;
	int idx2 = (*a)->top->next->index;
	if(idx1 > idx2)
		sa_op(*a); 
}

void sort_3(t_stack **a)
{
	int f;
	int s;
	int th;

	if (!(*a) || !(*a)->top || !(*a)->top->next || !(*a)->top->next->next)
		return;
	f = (*a)->top->index;
	s = (*a)->top->next->index;
	th = (*a)->top->next->next->index;
	
	if (f < s && s < th)
		return;
	else if (f > s && s < th && f < th)
		sa_op(*a);
	else if (f > s && s > th)
	{
		sa_op(*a);
		rra_op(*a);
	}
	else if (f > s && s < th && f > th)
		ra_op(*a);
	else if (f < s && s > th && f < th)
	{
		sa_op(*a);
		ra_op(*a);
	}
	else if (f < s && s > th && f > th)
		rra_op(*a);
}
void sort_4(t_stack **a ,t_stack **b)
{
	 int pos;

	if (!(*a) || (*a)->size < 4)
        return;

	pos = find_min_position(*a);

	if(pos == 1)
		ra_op(*a);
	else if(pos == 2)
	{
		ra_op(*a);
		ra_op(*a);
	}
	else if(pos == 3)
		rra_op(*a);

	pb_op(*a,*b);
	sort_3(a);
	pa_op(*a,*b);
}

void sort_5(t_stack **a, t_stack **b)
{
	int pos;
	int i;

	if (!a || !(*a) || (*a)->size < 5)
		return;
	i = 0;
	while (i < 2)
	{
		pos = find_min_position(*a);
		while (pos != 0)
		{
			if (pos <= (*a)->size / 2)
				pos -= (ra_op(*a), 1);
			else
				pos += (rra_op(*a), 1);
		}
		pb_op(*a, *b);
		i++;
	}
	sort_3(a);
	pa_op(*a, *b);
	pa_op(*a, *b);
}

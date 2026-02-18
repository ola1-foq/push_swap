/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:28:09 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/18 19:42:35 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int max_bit(t_stack *list)
{
    t_node *tmp;
    int  max_len;
    int i;
    
    i = 0;
    tmp = list->top;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    i--;
    max_len = 0;
    while(i)
    {
        i = i / 2;
        max_len++;
    }
    return(max_len);
}
void radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int j;
    int max_bits;
    int size;
    
    if (!a || !*a || !b)
        return;
    max_bits = max_bit(*a);
    size = (*a)->size;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((*a)->top && (((*a)->top->index >> i) & 1) == 0)
                pb_op(*a, *b);
            else if ((*a)->top)
                ra_op(*a);
            j++;
        }
        while (*b && (*b)->size > 0)
            pa_op(*a, *b);
        i++;
    }
}
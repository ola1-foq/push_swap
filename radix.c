/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:28:09 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/15 21:12:36 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ind_stack(t_stack *a)
{
    t_node *cur;
    t_node *it;
    t_node *min_node;
    int count;
    int min_value;

    if (!a || is_empty(a))
        return;
    cur = a->top;
    while (cur)
    {
        cur->index = -1;
        cur = cur->next;
    }

    count = 0;
    while (count < a->size)
    {
        it = a->top;
        min_node = NULL;
        min_value = INT_MAX;

        while (it)
        {
            if (it->index == -1 && it->data < min_value)
            {
                min_value = it->data;
                min_node = it;
            }
            it = it->next;
        }

        if (min_node)
            min_node->index = count;

        count++;
    }
}

void radix_sort(t_stack *a, t_stack *b)
{
    int i = 0;
    int j;
    int max_index;
    int max_bits = 0;
    int size;

    if (!a || is_empty(a) || a->size <= 1)
        return;
    max_index = a->size - 1;
    while ((max_index >> max_bits) != 0)
        max_bits++;

    while (i < max_bits)
    {
        j = 0;
        size = a->size;

        while (j < size)
        {
            if (((a->top->index >> i) & 1) == 1)
                ra_op(a);
            else
                pb_op(a, b);

            j++;
        }
        while (!is_empty(b))
            pa_op(a, b);

        i++;
    }
}
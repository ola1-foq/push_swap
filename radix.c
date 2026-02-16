/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:28:09 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/16 19:26:11 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int max_bit(t_stack *list)
{
    t_stack *tmp ;
    int  max_len;
    int i;
    
    i = 0;
    tmp =list;
    while(tmp)
    {
        tmp = tmp ->next;
        i++;
    }
    i--;
    max_len = 0;
    while(i)
    {
        i = i / 2;
        max_bit++;
    }
    return(max_bit);
}

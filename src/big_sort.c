/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:19:57 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 23:19:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void    radix_sort(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int size;
    int max_num;
    int max_bits;
    int num;

    size = a->size;
    max_num = size;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    i = 0;
    while(i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = a->top->index;
            if(((num >> i)& 1) == 0)
                pb(b, a);
            else
                ra(a);
            j++;
        }
        while (b->size > 0)
            pa(a, b);
        i++;
    }

}
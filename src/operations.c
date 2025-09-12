/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:05:35 by marvin            #+#    #+#             */
/*   Updated: 2025/09/12 09:05:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//SWAP
static void swap_nodes(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (!stack || stack->size < 2)
        return;
    first = stack->top;
    second = first->next;
    first ->next = second ->next;
    second ->top = second;
}

void    sa(t_stack)
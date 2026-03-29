/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:34:11 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:51:37 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Pega o topo da stack b e empurra para o
topo da stack a
*/
void	pa(t_stack *a, t_stack *b)
{
	t_node	*top_removed;

	if (!a || !b || b->length == 0)
		return ;
	top_removed = pop(b);
	push(a, top_removed);
	ft_putstr_fd("pa\n", 1);
}

/*
Pega o topo da stack a e empura para o
topo da stack b
*/
void	pb(t_stack *a, t_stack *b)
{
	t_node	*top_removed;

	if (!a || !b || a->length == 0)
		return ;
	top_removed = pop(a);
	push(b, top_removed);
	ft_putstr_fd("pb\n", 1);
}

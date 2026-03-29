/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:16:04 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:51:52 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
O ultimo elemento de A vai para o topo de A
*/
void	rra(t_stack *a)
{
	if (!a || a->length <= 1)
		return ;
	rotate(a);
	ft_putstr_fd("rra\n", 1);
}

/*
O último elemento de B vai para o top de B
*/
void	rrb(t_stack *b)
{
	if (!b || b->length <= 1)
		return ;
	rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

/*
Rotaciona de forma reversa as duas stacks tanto a quanto b ao mesmo tempo
*/
void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b || a->length <= 1 || b->length <= 1)
		return ;
	rotate(a);
	rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

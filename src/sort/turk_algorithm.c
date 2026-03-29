/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:29:06 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:29:06 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Função principal e responsável por implementar o turk algorithm
resposável pela ordenação da stack
*/
void	turk(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		median;

	while (a->length > 3)
	{
		median = find_median(a);
		if (a->top->value <= median)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (b->length > 0)
	{
		node = best_move(a, b);
		do_move(a, b, node);
	}
	final_adjust(a);
}

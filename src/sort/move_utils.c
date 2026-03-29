/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:53:36 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 14:53:36 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Função auxiliar -> do_move 
rotaciona simultaneamente as duas stacks 
*/
void	rotate_both(t_stack *a, t_stack *b, int *pos_a, int *pos_b)
{
	while ((*pos_a > 0 && *pos_b > 0)
		&& *pos_a <= a->length / 2 && *pos_b <= b->length / 2)
	{
		rr(a, b);
		(*pos_a)--;
		(*pos_b)--;
	}
	while (*pos_a > a->length / 2 && *pos_b > b->length / 2)
	{
		rrr(a, b);
		(*pos_a)++;
		if (*pos_a == a->length)
			*pos_a = 0;
		(*pos_b)++;
		if (*pos_b == b->length)
			*pos_b = 0;
	}
}

/*
Função auxiliar -> do_move 
rotaciona apenas uma stack  b até que a posição chegue ao top
*/
void	rotate_b(t_stack *b, int *pos_b)
{
	while (*pos_b != 0)
	{
		if (*pos_b <= b->length / 2)
		{
			rb(b);
			(*pos_b)--;
		}
		else
		{
			rrb(b);
			(*pos_b)++;
			if (*pos_b == b->length)
				*pos_b = 0;
		}
	}
}

/*
Função auxiliar -> do_move
rotaciona apenas umma stack a até que a posição chegue ao top
*/
void	rotate_a(t_stack *a, int *pos_a)
{
	while (*pos_a != 0)
	{
		if (*pos_a <= a->length / 2)
		{
			ra(a);
			(*pos_a)--;
		}
		else
		{
			rra(a);
			(*pos_a)++;
			if (*pos_a == a->length)
				*pos_a = 0;
		}
	}
}

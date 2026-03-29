/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:01:19 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:01:19 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Verifica se a stack já está ordenada
*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || stack->length < 2)
		return (1);
	current = stack->top;
	while (current && current->prev)
	{
		if (current->value > current->prev->value)
			return (0);
		current = current->prev;
	}
	return (1);
}

/*
Função útilitaria -> tem como objetivo tratar casos
 onde o menor nó precisa ser rotacionado até o topo
*/
static	void	bring_to_top(t_stack *a, t_stack *b, t_node *node)
{
	int	pos;
	int	len;

	pos = calculate_pos(a, node);
	len = a->length;
	if (pos <= len / 2)
	{
		while (a->top != node)
			ra(a);
	}
	else
	{
		while (a->top != node)
			rra(a);
	}
	pb (a, b);
}

/*retorna 0 para erro e um para correto utilitaria para sort_three*/
static	int	validations(t_stack *a, int top, int mid, int head)
{
	if (top < mid && mid < head)
		return (0);
	if (top > mid && mid < head && top < head)
		sa(a);
	else if (top > mid && mid > head)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < head && top > head)
		ra(a);
	else if (top < mid && mid > head && top < head)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > head && top > head)
		rra(a);
	return (1);
}

/*
Ordena uma stack com apenas três elementos
*/
void	sort_three(t_stack *a)
{
	if (!a || a->length != 3)
		return ;
	if (!validations(a, a->top->value, a->top->prev->value, a->head->value))
		return ;
}

/*
Ordena uma stack com apenas 5 elementos 
*/
void	sort_five(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	bring_to_top(a, b, get_min_node(a));
	bring_to_top(a, b, get_min_node(a));
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

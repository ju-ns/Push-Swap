/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:43:14 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:56:36 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Função utilitária, calcula a mediana dos valores de uma stack
*/
int	find_median(t_stack *stack)
{
	int		*arr_stack;
	int		median;
	int		i;
	t_node	*current;

	arr_stack = malloc(sizeof(int) * stack->length);
	if (!arr_stack)
		return (0);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr_stack[i++] = current->value;
		current = current->prev;
	}
	median = quickselect(arr_stack,
			0,
			stack->length - 1,
			(stack->length - 1) / 2);
	free (arr_stack);
	return (median);
}

/*
Calcula a posição de um nó em uma stack (a distancia em que ele esta do seu topo)
*/
int	calculate_pos(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		pos;

	if (!stack || !node)
		return (-1);
	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current == node)
			break ;
		current = current->prev;
		pos++;
	}
	return (pos);
}

/*
Calcula o valor maximo entre dois inteiros
*/
int	ft_max(int value_a, int value_b)
{
	if (value_a > value_b)
		return (value_a);
	return (value_b);
}

/*
Calcula quantas operações são necessárias para trazer um elemento 
de B para o topo e seu target em A para o topo simultaneamente 
*/
int	calculate_cost(t_stack *a, t_stack *b, t_node *node)
{
	int		pos_a;
	int		pos_b;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	pos_b = calculate_pos(b, node);
	pos_a = calculate_pos(a, find_target(a, node->value));
	if (pos_a <= a->length / 2)
		cost_a = pos_a;
	else
		cost_a = a->length - pos_a;
	if (pos_b <= b->length / 2)
		cost_b = pos_b;
	else
		cost_b = b->length - pos_b;
	if (pos_a <= a->length / 2 && pos_b <= b->length / 2)
		total_cost = ft_max(cost_a, cost_b);
	else if (pos_a > a->length / 2 && pos_b > b->length / 2)
		total_cost = ft_max(cost_a, cost_b);
	else
		total_cost = cost_a + cost_b;
	return (total_cost);
}

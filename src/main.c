/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:04:04 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/25 14:52:56 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Inicializa a stack com length 0, top e head null
*/
static	void	init_stack(s_stack *stack)
{
	stack->length = 0;
	stack->head = NULL;
	stack->top = NULL;
}

static void	free_stack(s_stack *stack)
{
	s_node	*current;
	s_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->prev;
		free(temp);
	}
}

/*
Cleanup utilitario
*/
static	int	clean_up(s_stack *a, s_stack *b, int exit_code)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (exit_code);
}

static void	decision_sort(s_stack *a, s_stack *b)
{
	if (a->length == 2)
		sa(a);
	else if (a->length == 3)
		sort_three(a);
	else if (a->length == 5)
		sort_five(a, b);
	else
		turk(a, b);
}

int	main(int argc, char **argv)
{
	s_stack	*a;
	s_stack	*b;

	a = malloc(sizeof(s_stack));
	b = malloc(sizeof(s_stack));
	if (!a || !b)
		return (free(a), free(b), 1);
	init_stack(a);
	init_stack(b);
	if (!parse(argc, argv, a))
	{
		ft_putstr_fd("Error\n", 2);
		return (clean_up(a, b, 1));
	}
	if (a->length <= 1 || is_sorted(a))
		return (clean_up(a, b, 0));
	decision_sort(a, b);
	return (clean_up(a, b, 0));
}

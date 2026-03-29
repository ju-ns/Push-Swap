/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:18:32 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:52:09 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Função utilitária da stack para rotacionar o primeiro elemento para o ultimo
*/
static void	rotate_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->length < 2)
		return ;
	temp = stack->top;
	stack->top = temp->prev;
	stack->top->next = NULL;
	temp->prev = NULL;
	stack->head->prev = temp;
	temp->next = stack->head;
	stack->head = temp;
}

/*
Rotaciona o topo de A para a sua base
*/
void	ra(t_stack *a)
{
	if (!a || a->length < 2)
		return ;
	rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
}

/*
Rotaciona a base para o top de B
*/
void	rb(t_stack *b)
{
	if (!b || b->length < 2)
		return ;
	rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
}

/*
Rotaciona as duas stacks ao mesmo tempo
*/
void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}

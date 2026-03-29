/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:01:37 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 15:58:19 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Utilitaria: recebe um valor inteiro e cria o nó para adicionar a stack
retorna o novo nó -> ainda não está conectado a stack
*/
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/*
Utilitaria: função clássica da estrutura, remove o topo da stack
respeitando o LIFO -> retorna o nó que estava no topo
*/
t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack ->length == 0)
		return (NULL);
	temp = stack->top;
	if (stack->length == 1)
	{
		stack->head = NULL;
		stack->top = NULL;
	}
	else
	{
		stack->top = temp->prev;
		stack->top->next = NULL;
	}
	temp->prev = NULL;
	temp->next = NULL;
	stack->length--;
	return (temp);
}

/*
Utilitaria: função clássica da estrutura, recebe um novo nó e adiciona
depois do topo, atualiza a nova posição do topo
*/
void	push(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->length == 0)
	{
		stack->head = new_node;
		stack->top = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = stack->top;
		new_node->next = NULL;
		stack->top->next = new_node;
		stack->top = new_node;
	}
	stack->length++;
}

/*
Utilitaria: altera a referencia do top, a base da pilha vai para a posiçao do top
*/
void	rotate(t_stack *stack)
{
	t_node	*old_head;
	t_node	*old_top;

	if (!stack || stack->length <= 1)
		return ;
	old_head = stack->head;
	old_top = stack->top;
	stack->head = old_head->next;
	stack->head->prev = NULL;
	old_head->prev = old_top;
	old_top->next = old_head;
	old_head->next = NULL;
	stack->top = old_head;
}

/*
Utilitaria: retorna o nó com o menor valor da stack
*/

t_node	*get_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	current = stack->top;
	min_node = NULL;
	while (current)
	{
		if (!min_node || current->value < min_node->value)
			min_node = current;
		current = current->prev;
	}
	return (min_node);
}

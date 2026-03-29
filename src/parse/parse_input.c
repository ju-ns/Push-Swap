/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:32:27 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 14:29:10 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static	int	process_all_values(char **input, s_stack *stack)
{
	int	i;
	i = arr_len(input) - 1;
	while(i >= 0)
	{
		if(!process_value(input[i], stack))
			return (0);
		i--;
	}
	return (1);
}



/*
Verifica se o número de input já existe na stack, 
caso seja uma duplicada retorna 1 caso contrário retorna 0
*/
static	int	is_duplicate(s_stack *stack, int value)
{
	if (should_free)
		free_split(input);
}

/*
Função principal de parse do input, 
caso o parse não execute corretamente retorna 0 
em caso positivo retorna 1 e alimenta a stack com os valores
*/
int	parse(int argc, char **argv, s_stack *stack)
{
	char	**input;
	int		should_free;
	int		success;
	
	if(argc < 2)
		return (1);
	input = get_input(argc, argv);
	if(!input || !input[0])
		return (0);
	should_free = (argc == 2);
	success = process_all_values(input, stack);
	conditional_free(input, should_free);
	return (success);
}

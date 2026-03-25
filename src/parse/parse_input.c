/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:32:27 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/25 16:34:49 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Verifica se é um número válido (sem letras e símbolos)
retorna 0 para falso e 1 para verdadeiro
*/
static	int	is_valid_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
Converte uma string para long verificando o overflow
retorna 0 caso a conversão tenha falhado, caso contrário 
realiza a conversão e retorna 1 para verdadeiro
*/
static	int	ft_atoi_safe(char *str, long *result)
{
	long	num;
	int		sign;
	int		i;

	if (!str || !result)
		return (0);
	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	*result = num;
	return (1);
}

/*
Verifica se o número de input já existe na stack, 
caso seja uma duplicada retorna 1 caso contrário retorna 0
*/
static	int	is_duplicate(s_stack *stack, int value)
{
	s_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->prev;
	}
	return (0);
}

/*
Função auxiliar para liberar a memória utilizada no split
*/
static	void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/*
Função principal de parse do input, 
caso o parse não execute corretamente retorna 0 
em caso positivo retorna 1 e alimenta a stack com os valores
*/
int	parse(int argc, char **argv, s_stack *stack)
{
	int		i;
	char	**input;
	long	value;
	s_node	*new_node;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!argv[1] || !argv[1][0])
			return (0);
		input = ft_split(argv[1], ' ');
		if (!input)
			return (0);
	}
	else
		input = argv + 1;
	i = 0;
	while (input[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (!is_valid_number(input[i]))
		{
			if (input != argv + 1)
				free_split(input);
			return (0);
		}
		if (!ft_atoi_safe(input[i], &value))
			return (0);
		if (is_duplicate(stack, value))
			return (0);
		new_node = create_node((int)value);
		if (!new_node)
			return (0);
		push(stack, new_node);
		i--;
	}
	if (input != argv + 1)
		free_split(input);
	return (1);
}

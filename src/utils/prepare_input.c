#include "push_swap.h"

/*
Função auxiliar para liberar a memória utilizada pelo split
*/
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/*
Utilitária: processa o input
*/
char	**get_input(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!argv[1] || !argv[1][0])
			return (NULL);
		return(ft_split(argv[1], ' '));
	}
	return (argv + 1);
}

/*
Verifica se o número de input já existe na stack, 
caso seja uma duplicada retorna 1 caso contrário retorna 0
*/
int	is_duplicate(s_stack *stack, int value)
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
Verifica se é um número válido (sem letras e símbolos)
retorna 0 para falso e 1 para verdadeiro
*/
int	is_valid_number(char *str)
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

int	process_value(char *str, s_stack *stack)
{
	long	value;
	s_node	*node;

	if(!is_valid_number(str))
		return (0);
	if(!ft_atoi_safe(str, &value))
		return (0);
	if(is_duplicate(stack, (int)value))
		return (0);
	node = create_node((int)value);
	if(!node)
		return (0);
	push(stack, node);
	return (1);
}

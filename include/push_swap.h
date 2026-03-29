/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:33:44 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/29 16:01:06 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct node
{
	int			value;
	struct node	*prev;
	struct node	*next;
}	t_node;

typedef struct stack{
	t_node	*top;
	t_node	*head;
	int		length;
}	t_stack;

/*
Operações essenciais para ordenações
localizadas no diretório operations
*/
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
/*
funções da estrutura stack
localizadas no diretorio stack
*/
t_node	*create_node(int value);
t_node	*pop(t_stack *stack);
void	push(t_stack *stack, t_node *newNode);
void	rotate(t_stack *stack);
t_node	*get_min_node(t_stack *stack);
/*
Parsing do input 
loalizada no diretorio parse
*/
int		parse(int argc, char **argv, t_stack *stack);

/*
Utilitárias para o parsing do input
*/
char	**get_input(int argc, char **argv);
int		is_duplicate(t_stack *stack, int value);
int		is_valid_number(char *str);
int		process_value(char *str, t_stack *stack);
void	free_split(char **str);

/*
Funções utilitárias de calculo para o algoritmo de ordenação
localizadas no arquivo calculate_utils do diretorio sort
*/
int		ft_max(int value_a, int value_b);
int		calculate_pos(t_stack *stack, t_node *node);
int		calculate_cost(t_stack *a, t_stack *b, t_node *node);
int		find_median(t_stack *stack);
/*
Funções auxiliares de movimentações para o algoritmo de ordenação
localizadas no arquivo move_utils no diretório sort
*/
void	rotate_both(t_stack *a, t_stack *b, int *pos_a, int *pos_b);
void	rotate_b(t_stack *b, int *pos_b);
void	rotate_a(t_stack *a, int *pos_a);
/*
Funções auxiliares para o algoritmo de ordenação
localizadas no arquivo sort_utils no diretorio sort
*/
t_node	*find_target(t_stack *a, int value);
t_node	*best_move(t_stack *b, t_stack *a);
void	do_move(t_stack *a, t_stack *b, t_node *node);
void	final_adjust(t_stack *a);
/*
Função de ordenação
*/
void	turk(t_stack *a, t_stack *b);
/*
Pequenas ordenações para casos especificos
*/
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
/*
utilitária para find_median localizada no diretorio sort
arquivo quickselect
*/
int		quickselect(int *arr, int low, int higth, int k);
#endif

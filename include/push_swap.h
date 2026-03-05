#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <limits.h>

typedef struct node
{
	int value;
	struct node *prev;
	struct node *next;
} s_node;

typedef struct stack{
	s_node *top;
	s_node *head;
	int length;
} s_stack;

/*
Operações essenciais para ordenações
localizadas no diretório operations
*/
void	pa(s_stack *a, s_stack *b);
void	pb(s_stack *a, s_stack *b);
void	rra(s_stack *a);
void	rrb(s_stack *b);
void	rrr(s_stack *a, s_stack *b);
void	ra(s_stack *a);
void	rb(s_stack *b);
void	rr(s_stack *a, s_stack *b);
void	sa(s_stack *a);
void	sb(s_stack *b);
void	ss(s_stack *a, s_stack *b);
/*
funções da estrutura stack
localizadas no diretorio stack
*/
s_node	*create_node(int value);
s_node	*pop(s_stack *stack);
void	push(s_stack *stack, s_node *newNode);
void	rotate(s_stack *stack);
s_node	*get_min_node(s_stack *stack);
/*
Parsing do input 
loalizada no diretorio parse
*/
int	parse(int argc, char **argv, s_stack *stack);
/*
Funções utilitárias de calculo para o algoritmo de ordenação
localizadas no arquivo calculate_utils do diretorio sort
*/
int	ft_max(int value_a, int value_b);
int	calculate_pos(s_stack *stack, s_node *node);
int	calculate_cost(s_stack *a, s_stack *b, s_node *node);
int	find_median(s_stack *stack);
/*
Funções auxiliares de movimentações para o algoritmo de ordenação
localizadas no arquivo move_utils no diretório sort
*/
void	rotate_both(s_stack *a, s_stack *b, int *pos_a, int *pos_b);
void	rotate_b(s_stack *b, int *pos_b);
void	rotate_a(s_stack *a, int *pos_a);
/*
Funções auxiliares para o algoritmo de ordenação
localizadas no arquivo sort_utils no diretorio sort
*/
s_node	*find_target(s_stack *a, int value);
s_node	*best_move(s_stack *b, s_stack *a);
void	do_move(s_stack *a, s_stack *b, s_node *node);
void	final_adjust(s_stack *a);
/*
Função de ordenação
*/
void	turk(s_stack *a, s_stack *b);
/*
Pequenas ordenações para casos especificos
*/
void	sort_three(s_stack *a);
void	sort_five(s_stack *a, s_stack *b);
int		is_sorted(s_stack *stack);
/*
utilitária para find_median localizada no diretorio sort
arquivo quickselect
*/
int	quickselect(int *arr, int low, int higth, int k);
#endif

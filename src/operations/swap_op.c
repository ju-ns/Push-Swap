#include "push_swap.h"

/*
Realiza a troca entre os valores dos nós informados como parâmetros
não altera a estrutura interna da stack
*/
static void swap_nodes(s_node *a, s_node *b)
{
    int temp;

    temp = a->value;
    a->value = b->value;
    b->value = temp;
}

/*
Utilitária para troca dos nós
*/
static void swap_stacks(s_stack *stack)
{
    s_node *top;
    s_node *second;

    if(!stack || stack->length < 2)
        return;
    top = stack->top;
    second = stack->top->prev;

    swap_nodes(top, second);    
}

/*
Troca os dois primeiros valores do topo da stack a
*/
void sa(s_stack *a)
{
    swap_stacks(a);
    ft_putstr_fd("sa\n", 1);
}

/*
Troca os dois primeiros valores do topo da stack b
*/
void sb(s_stack *b)
{
    swap_stacks(b);
    ft_putstr_fd("sb\n", 1);
}

/*
Realiza ao mesmo tempo a troca entre os dois primeiros valores das respectivas stacks:
"a" e "b"
*/
void ss(s_stack *a, s_stack *b)
{
    swap_stacks(a);
    swap_stacks(b);
    ft_putstr_fd("ss\n", 1);
}
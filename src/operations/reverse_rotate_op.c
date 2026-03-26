#include "push_swap.h"

/*
O ultimo elemento de A vai para o topo de A
*/
void rra(s_stack *a)
{
    if(!a || a->length <= 1)
        return;
    rotate(a);
    ft_putstr_fd("rra\n", 1);
}

/*
O último elemento de B vai para o top de B
*/
void rrb(s_stack *b)
{
    if(!b || b->length <= 1)
        return;
    rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

/*
Rotaciona de forma reversa as duas stacks tanto a quanto b ao mesmo tempo
*/
void rrr(s_stack *a, s_stack *b)
{
    if(!a || !b || a->length <= 1 || b->length <= 1)
        return;
    rotate(a);
    rotate(b);
    ft_putstr_fd("rrr\n", 1);
}

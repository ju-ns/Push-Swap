#include "push_swap.h"

/*
Pega o topo da stack b e empurra para o
topo da stack a
*/
void pa(s_stack *a, s_stack *b)
{
    s_node *top_removed;
    if(!a || !b || b->length == 0)
        return;
    
    top_removed = pop(b);
    push(a,top_removed);
    ft_putstr_fd("pa\n", 1);
}

/*
Pega o topo da stack a e empura para o
topo da stack b
*/
void pb(s_stack *a, s_stack *b)
{
    s_node *top_removed;
    if(!a || !b || a->length == 0)
        return;
    
    top_removed = pop(a);
    push(b, top_removed);
    ft_putstr_fd("pb\n", 1);
}
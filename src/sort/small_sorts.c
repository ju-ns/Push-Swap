#include "push_swap.h"

/*
Verifica se a stack já está ordenada
*/

int is_sorted(s_stack *stack)
{
    s_node *current;

    if(!stack || !stack->top || stack->length < 2)
        return (1);
    current = stack->top;
    while(current && current->prev)
    {
        if(current->value > current->prev->value)
            return(0);
        current = current->prev;
    }
    return (1);
    
}

/*
Função útilitaria -> tem como objetivo tratar casos onde o menor nó precisa ser rotacionado até o topo
*/
static void bring_to_top(s_stack *a, s_stack *b, s_node *node)
{
    int pos;
    int len;
    
    pos = calculate_pos(a, node);
    len = a->length;

    if(pos <= len / 2)
    {
        while(a->top != node)
            ra(a);
    }
    else{
        while(a->top != node)
            rra(a);
    }
    pb(a, b);

}

/*
Ordena uma stack com apenas três elementos
*/
void sort_three(s_stack *a)
{
    //s_node *current;
    int top;
    int mid;
    int head;
    if(!a || a->length != 3)
        return;
    top = a->top->value;
    mid = a->top->prev->value;
    head = a->head->value;
        // já ordenado
    if (top < mid && mid < head)
        return;
    // 2 1 3
    if (top > mid && mid < head && top < head)
        sa(a);
    // 3 2 1
    else if (top > mid && mid > head)
    {
        sa(a);
        rra(a);
    }
    // 3 1 2
    else if (top > mid && mid < head && top > head)
        ra(a);

    // 1 3 2
    else if (top < mid && mid > head && top < head)
    {
        sa(a);
        ra(a);
    }
    // 2 3 1
    else if (top < mid && mid > head && top > head)
        rra(a);
}

/*
Ordena uma stack com apenas 5 elementos 
*/
void sort_five(s_stack *a, s_stack *b)
{    
    if(is_sorted(a))
        return;
    bring_to_top(a, b, get_min_node(a));
    bring_to_top(a, b, get_min_node(a));
    sort_three(a);
    pa(a, b);
    pa(a, b);
}


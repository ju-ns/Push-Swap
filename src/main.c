#include "push_swap.h"

/*
Inicializa a stack com length 0, top e head null
*/
static void init_stack(s_stack *stack)
{
    stack->length = 0;
    stack->head = NULL;
    stack->top = NULL;
}


void free_stack(s_stack *stack)
{
    s_node *current;
    s_node *temp;
    current = stack->top;
    while(current)
    {
        temp = current;
        current = current->prev;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    s_stack *a;
    s_stack *b;

    a = malloc(sizeof(s_stack));
    b = malloc(sizeof(s_stack));
    if(!a || !b)
    {
        free(a);
        free(b);
        return(1);
    }
        
    init_stack(a);
    init_stack(b);

    if(!parse(argc, argv, a))
    {
        ft_putstr_fd("Error\n", 2);
        free_stack(a);
        free_stack(b);
        free(a);
        free(b);
        return (1);
    }
    if(a->length <= 1 || is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        free(a);
        free(b);
        return (0);
    }
    if(a->length == 2)
        sa(a);
    else if(a->length == 3)
        sort_three(a);
    else if(a->length == 5)
        sort_five(a, b);
    else
        turk(a, b);
    
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    
    return(0);
}




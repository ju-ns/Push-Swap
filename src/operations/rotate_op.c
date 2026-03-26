#include "push_swap.h"

/*
Função utilitária da stack para rotacionar o primeiro elemento para o ultimo
*/
static void  rotate_stack(s_stack *stack)
{
    //vamos alterar a ref de top ele vai para a base
    // isso significa que stack 1 2 3 4 5 depois de ra vai ficar 2 3 4 5 1 -> novo head
    //so que como estamos usando uma linked list duplamente ligada fica   null - head - 5 - 4 - 3 - 2 - 1 -> top - null
    s_node *temp;
    if(!stack || stack->length < 2)
        return;
    temp = stack->top; //ref do topo
    stack->top = temp->prev; //no exe top agora é 2
    stack->top->next = NULL;
    //agora vamos retirar a ref do antigo top
    temp->prev = NULL;

    //agora vamos ligar ele ao head -> base 
    stack->head->prev = temp;
    temp->next = stack->head; //ligado ao head 
    stack->head = temp; //atualizando a ref da base;
}


/*
Rotaciona o topo de A para a sua base
*/
void ra(s_stack *a)
{
    if(!a || a->length < 2)
        return;
    rotate_stack(a);
    ft_putstr_fd("ra\n", 1);
}

/*
Rotaciona a base para o top de B
*/
void rb(s_stack *b)
{
    if(!b || b->length < 2)
        return;
    rotate_stack(b);
    ft_putstr_fd("rb\n", 1);
}

/*
Rotaciona as duas stacks ao mesmo tempo
*/
void rr(s_stack *a, s_stack *b)
{
    rotate_stack(a);
    rotate_stack(b);
    ft_putstr_fd("rr\n", 1);
}


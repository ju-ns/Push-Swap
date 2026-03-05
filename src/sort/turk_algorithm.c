#include "push_swap.h"

/*
Função principal e responsável por implementar o turk algorithm
resposável pela ordenação da stack
*/
void turk(s_stack *a, s_stack *b)
{
    s_node *node;
    int median;

    while(a->length > 3)
    {
        median = find_median(a);
        if(a->top->value <= median)
            pb(a, b);
        else
            ra(a);
    }
    sort_three(a);
    while(b->length > 0)
    {
        node = best_move(a, b);
        do_move(a, b, node);
    }
    
    final_adjust(a);
}


// void turk(s_stack *a, s_stack *b)
// {
//     s_node *node;
//     int median;

//     while(a->length > 3)
//         pb(a, b);
//     sort_three(a);
//     while(b->length > 0)
//     {
//         node = best_move(a, b);
//         do_move(a, b, node);
//     }
    
//     final_adjust(a);
// }

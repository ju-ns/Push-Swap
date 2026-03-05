#include "push_swap.h"

/*
Recebe um valor de B e precisa encontrar
onde ele se encaixa em A. 
Encontra o menor valor maior que o valor de B e retorna esse nó.
*/
s_node *find_target(s_stack *a, int value)
{
    s_node *current; 
    s_node *target; 
    if(!a || !a->length)
        return (NULL);
    current = a->top;
    target = NULL;
    while(current)
    {
        if(current->value > value)
            if(!target || current->value < target->value)
                target = current;
        current = current->prev;
    }
    if(!target)
    {
        current = a->top;
        while(current)
        {
            if(!target || current->value < target->value)
            	target = current;
            current = current->prev;
        }
    }
    return(target);
}

/*
Percorre toda a stack  e calcula o menor custo, guarda o nó com o menor custo
e retorna esse nó no final
*/
s_node *best_move(s_stack *a, s_stack *b)
{
	s_node *current;
	s_node *best_node;
	int cost;
	int best_cost;


	best_node = NULL;
	current = b->top;
	best_cost = INT_MAX;
	while(current)
	{
		cost = calculate_cost(a, b, current);
		if(cost < best_cost)
		{
			best_cost = cost;
			best_node = current;
		}
		current = current->prev;
	}
	return (best_node);
}

/*
Recebe o nó com o menor custo escolhido pela função
best_move e executa as operações necessárias para inseri-lo na posição correta em A
*/
void do_move(s_stack *a, s_stack *b, s_node *node)
{
	int pos_b;
	int pos_a;
	s_node *target_a;

	target_a = find_target(a, node->value);
	if(!target_a)
		return;
	pos_a = calculate_pos(a, target_a);
	pos_b = calculate_pos(b, node);

	rotate_both(a, b, &pos_a, &pos_b);
	rotate_a(a, &pos_a);
	rotate_b(b, &pos_b);
	pa(a,b);
}

/*
Encontra o menor elemento de A e o coloca no top
*/
void final_adjust(s_stack *a)
{
	int pos;
	
	pos = calculate_pos(a, get_min_node(a));
	while(pos != 0)
	{
		if(pos <= a->length / 2)
		{
			ra(a);
			pos--;
		}
		else
		{
			rra(a);
			pos++;
			if (pos == a->length)
				pos = 0;
		}
	}
}




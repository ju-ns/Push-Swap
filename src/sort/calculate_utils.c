#include "push_swap.h"


/*
Função utilitária, calcula a mediana dos valores de uma stack
*/
int find_median(s_stack *stack)
{
    int *arr_stack;
    int median;
    int i;
    s_node *current;

    arr_stack = malloc(sizeof(int) * stack->length); //alocamos memoria para copiar os dados da stack para o array
    if(!arr_stack)
        return (0);
    current = stack->top;
    i = 0;
    while(current)
    {
        arr_stack[i++] = current->value;
        current = current->prev;
    }
    //agora a arr_stack está populada com todos os valores da stack
    median = quickselect(arr_stack, 0, stack->length, stack->length / 2);
    free(arr_stack);
    return(median);

}

/*
Calcula a posição de um nó em uma stack (a distancia em que ele esta do seu topo)
*/
int calculate_pos(s_stack *stack, s_node *node)
{
    s_node *current;
    int pos;

    if(!stack || !node)
        return(-1);

    current = stack->top;
    pos = 0;
    while(current)
    {
        if(current == node)
            break;
        current = current->prev;
        pos++;
    }
    return (pos);
}

/*
Calcula o valor maximo entre dois inteiros
*/
int ft_max(int value_a, int value_b)
{
    if(value_a > value_b)
        return (value_a);
    return (value_b);
}

/*
Calcula quantas operações são necessárias para trazer um elemento 
de B para o topo e seu target em A para o topo simultaneamente 
*/
int calculate_cost(s_stack *a, s_stack *b, s_node *node)
{
    int pos_a;
    int pos_b;
    int cost_a;
    int cost_b;
    int total_cost;
    s_node *target_a;

    pos_b = calculate_pos(b, node);
    target_a = find_target(a, node->value);
    pos_a = calculate_pos(a, target_a);
    if(pos_a <= a->length /2)
        cost_a = pos_a;
	else
		cost_a = a->length - pos_a;
	if(pos_b <= b->length /2)
		cost_b = pos_b;
	else
		cost_b = b->length - pos_b;
	if(pos_a <= a->length / 2 && pos_b <= b->length / 2)
		total_cost = ft_max(cost_a, cost_b);
	else if(pos_a > a->length / 2 && pos_b > b->length / 2)
		total_cost = ft_max(cost_a, cost_b);
	else
		total_cost = cost_a + cost_b;
    return (total_cost);
}

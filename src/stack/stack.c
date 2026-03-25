
#include "push_swap.h"

/*
Recebe um valor inteiro e cria o nó para adicionar a stack
retorna o novo nó -> ainda não está conectado a stack
*/
s_node *create_node(int value)
{
    s_node *newNode;
    newNode = malloc(sizeof(s_node));
    if(!newNode)
        return NULL;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return(newNode);
}

/*
Pop -> função clássica da estrutura, remove o topo da stack
respeitando o LIFO -> retorna o nó que estava no topo
*/
s_node *pop(s_stack *stack)
{
    s_node *temp;
    if(!stack || stack->length == 0)
        return (NULL);
    temp = stack->top;

    if(stack->length == 1)
    {
        stack->head = NULL;
        stack->top = NULL;
    }
    else{
        stack->top = temp->prev;
        stack->top->next = NULL;
    }
    temp->prev = NULL;
    temp->next = NULL;
    stack->length--;

    return(temp);
}
/*
Push -> função clássica da estrutura, recebe um novo nó e adiciona
depois do topo, atualiza a nova posição do topo
*/
void push(s_stack *stack, s_node *newNode){

    if(!stack || !newNode)
        return;
    if(stack->length == 0)
    {
        stack->head = newNode;
        stack->top = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        newNode->prev = stack->top;
        newNode->next = NULL;
        stack->top->next = newNode;
        stack->top = newNode;

    }
    stack->length++;
}

/*
Utilitária: altera a referencia do head e top
head vira o novo top e top vai para o head
*/
void rotate(s_stack *stack)
{
    s_node *old_head;
    s_node *old_top;
    if(!stack || stack->length <= 1)
        return;
    old_head = stack->head;
    old_top = stack->top;

    //atualizando a base
    stack->head = old_head->next;
    stack->head->prev = NULL;

    //colocando a antiga base em cima do top
    old_head->prev = old_top;
    old_top->next = old_head;

    //agora desconecta o antigo top
    old_head->next = NULL;
    stack->top = old_head;

}

/*
Retorna o nó com o menor valor da stack
*/
s_node *get_min_node(s_stack *stack)
{
    s_node *current;
    s_node *min_node;

    if(!stack)
        return (NULL);
    
    current = stack->top;
    min_node = NULL;
    while(current)
    {
        if(!min_node || current->value < min_node->value)
            min_node = current;
        current = current->prev;
    }
    return(min_node);
}

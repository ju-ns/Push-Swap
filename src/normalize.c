/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:44:25 by marvin            #+#    #+#             */
/*   Updated: 2025/09/12 08:44:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int *copy_values(t_stack *stack)
{
    int *arr;
    int i;
    t_node *tmp;

    arr = malloc(sizeof(int) * stack->size);
    if (!arr)
        return (NULL)
    tmp = stack->top;
    i = 0;
    while(tmp){
        arr[i++] = tmp->value;
        tmp = tmp->next;
    }
    return (arr);
}

static void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if(arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void normalize(t_stack * stack)
{
    int *arr;
    int i;
    t_node *tmp;
    arr = copy_values(stack);
    if (!arr)
        error_exit("Erro: malloc\n");
    sort_array(arr, stack ->size);
    tmp = stack->top;
    while(tmp)
    {
        i = 0;
        while (i < stack->size)
        {
            if (arr[i] == tmp -> value)
            {
                if (arr[i] == tmp->value)
                {
                    tmp->index = i;
                    break;
                }
                i++;
            }
            tmp = tmp->next;
        }
        free(arr);
    }
}
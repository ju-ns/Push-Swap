#include "push_swap.h"


/*
Função utilitária -> Partition para Quickselect
*/
static int partition(int *arr, int low, int hight)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = arr[hight];
    i = low;
    j = low;

    while(j < hight)
    {
        if(arr[j] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
    temp = arr[i];
    arr[i] = arr[hight];
    arr[hight] = temp;
    return (i);
}

/*
Função utilitária -> Quickselect para encontrar o k-ésimo menor elemento
*/
int quickselect(int *arr, int low, int higth, int k)
{
    int pi;

    if(low == higth)
        return(arr[low]);
    pi = partition(arr, low, higth);

    if(k == pi)
        return arr[pi];
    else if( k < pi)
        return (quickselect(arr, low, pi - 1, k));
    else
        return (quickselect(arr, pi + 1, higth, k));
}
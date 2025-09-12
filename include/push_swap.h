#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;    
}

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;


#endif
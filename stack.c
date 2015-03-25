#include "stack.h"

char *
stack_pop(struct stack *stack)
{
    struct stack_elem *top = stack->top;
    char *ptr = top->ptr;
    stack->top = top->next;
    free(top);
    return ptr;
}

char *
stack_peep(struct stack *stack)
{
    return stack->top->ptr;   
}

void 
stack_push(struct stack *stack, char *ptr) 
{
    stack->top = stack_elem_new(ptr, stack->top);
}

struct stack *
stack_init(void)
{
    struct stack *stack = (struct stack *) malloc(sizeof(struct stack));
    stack->top = stack_elem_new(NULL, NULL);
    return stack;
}

void
stack_free(struct stack *stack)
{
    struct stack_elem *curr = stack->top;
    struct stack_elem *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(stack);   
} 

struct stack_elem *
stack_elem_new(char *ptr, struct stack_elem *next)
{
    struct stack_elem *new_elem = (struct stack_elem *) malloc(sizeof(struct stack_elem));
    new_elem->ptr = ptr;
    new_elem->next = next;
    return new_elem;    
}
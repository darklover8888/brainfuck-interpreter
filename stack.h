#include <cstdlib>

struct stack
{
    struct stack_elem *top;   
};

struct stack_elem
{
    char *ptr;
    struct stack_elem *next;    
};

char * stack_pop(struct stack *);
char * stack_peep(struct stack *);
void stack_push(struct stack *, char *);
struct stack * stack_init(void);
void stack_free(struct stack *);
struct stack_elem * stack_elem_new(char *, struct stack_elem *);

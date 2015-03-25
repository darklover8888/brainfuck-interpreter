#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "stack.h"

static int FILE_SIZE;
static int CELL_COUNT;

void execute(char *ins);
void print_cells(char *cells);

int main() {
    char *ins = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    FILE_SIZE = strlen(ins);
    CELL_COUNT = 300;
    execute(ins);
}

void execute(char *ins)
{
    int page_fault = 0;
    int instructions = 0;
    char *eip = ins;
    char *cells = (char*) calloc(1,CELL_COUNT);
    char *ptr = cells;
    struct stack *stack = stack_init();
    printf("[START] ins: [%p -> %p]    size: %d     cells: %d\n\n", 
            ins, ins+FILE_SIZE, FILE_SIZE, CELL_COUNT);
    while (eip >= ins && eip <= ins + FILE_SIZE)
    {
        switch (*eip) {
            case '>': 
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                printf("%c", *ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                stack_push(stack, eip);
                break;
            case ']':
                if (*ptr != 0) {
                    eip = stack_peep(stack);
                } else {
                    stack_pop(stack);
                }
                break;
            default:
                break;
        }
        
        eip++;
        instructions++;
        
        if (ptr < cells) {
            ptr += CELL_COUNT;
            page_fault++;
        } else if (ptr > cells + CELL_COUNT) {
            ptr -= CELL_COUNT;
            page_fault++;
        }  
    }      
    printf("\n[END] ins: [%p -> %p]    eip: %p\n[END] ins executed: %d     page_faults: %d\n", 
            ins, ins+FILE_SIZE, eip, instructions, page_fault);
}

void print_cells(char *cells) 
{
    int i = 0;
    for (i = 0; i < 20; i++) 
        printf("[%d] %c\n", i, *cells++);
}
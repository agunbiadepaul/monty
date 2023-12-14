#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **pcstack, unsigned int pcline_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_fxnc)(stack_t **, unsigned int);

/*file operations*/
void open_pcfile(char *pcfile_name);
int parse_pcline(char *buffer, int pcline_number, int format);
void read_pcfile(FILE *);
int len_chars(FILE *);
void find_pcfxnc(char *, char *, int, int);

/*Stack operations*/
stack_t *create_pcnode(int n);
void free_pcnodes(void);
void print_pcstack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_fxn(op_fxnc, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_pcnodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_pcnodes(stack_t **, unsigned int);
void sub_pcnodes(stack_t **, unsigned int);
void div_pcnodes(stack_t **, unsigned int);
void mul_pcnodes(stack_t **, unsigned int);
void mod_pcnodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int pcerror_code, ...);
void more_error(int pcerror_code, ...);
void string_error(int pcerror_code, ...);
void rotr(stack_t **, unsigned int);

#endif

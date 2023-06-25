#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stackstr - Double linked list model of a stack (or queue)
 * @n: integer
 * @bef: points to the prev element of the stack (or queue)
 * @aft: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX 
 */

typedef struct stackstr
{
	int n;
	struct stackstr *bef;
	struct stackstr *aft;
} stackT;

/**
 * struct instructionStr - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX
 */

typedef struct instructionStr
{
	char *opcode;
	void (*f)(stackT **stack, unsigned int NumberLine);
} instruction_t;

/**
 * struct args_s - structure of arguments from main
 * @av: name of the file from the command line
 * @ac: number of arguments from main
 * @NumberLine: number of the current line in the file
 *
 * Description: arguments passed to main from the cmd-line
 * used in different functions, organized in a struct for clarity
 */

typedef struct args_s
{
	char *av;
	int ac;
	unsigned int NumberLine;
} args_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @words: used line
 * @stack: points to a stack
 * @fptr: points to a file
 * @qflag: flag for queue or stack
 */

typedef struct data_s
{
	char *line;
	char **words;
	stackT *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stackT dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/* main.c */
void monty(args_t *args);

/* get_func.c */
void (*get_func(char **parsed))(stackT **, unsigned int);
void push_handler(stackT **stack, unsigned int NumberLine);
void pall_handler(stackT **stack, unsigned int NumberLine);

/* handler_funcs1.c */
void pint_handler(stackT **stack, unsigned int NumberLine);
void pop_handler(stackT **stack, unsigned int NumberLine);
void swap_handler(stackT **stack, unsigned int NumberLine);
void add_handler(stackT **stack, unsigned int NumberLine);
void nop_handler(stackT **stack, unsigned int NumberLine);

/* handler_funcs2.c */
void sub_handler(stackT **stack, unsigned int NumberLine);
void div_handler(stackT **stack, unsigned int NumberLine);
void mul_handler(stackT **stack, unsigned int NumberLine);
void mod_handler(stackT **stack, unsigned int NumberLine);

/* handler_funcs3.c */
void rotl_handler(stackT **stack, unsigned int NumberLine);
void rotr_handler(stackT **stack, unsigned int NumberLine);
void stack_handler(stackT **stack, unsigned int NumberLine);
void queue_handler(stackT **stack, unsigned int NumberLine);

/* char.c */
void pchar_handler(stackT **stack, unsigned int NumberLine);
void pstr_handler(stackT **stack, unsigned int NumberLine);

/* strtow.c */
int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

/* free.c */
void free_all(int all);

#endif

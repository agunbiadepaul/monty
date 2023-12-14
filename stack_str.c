#include "monty.h"

/**
 * print_char - Prints out the Ascii value of the characxter.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representng the line number associatof the opcode.
 */
void print_char(stack_t **pcstack, unsigned int pcline_number)
{
	int ascii;

	if (pcstack == NULL || *pcstack == NULL)
		string_error(11, pcline_number);

	ascii = (*pcstack)->n;
	if (ascii < 0 || ascii > 127)
		string_error(10, pcline_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Print out a string.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pc_ln: Interger representng the line number associat of the opcode.
 */
void print_str(stack_t **pcstack, __attribute__((unused))unsigned int pc_ln)
{
	int ascii;
	stack_t *tmp;

	if (pcstack == NULL || *pcstack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *pcstack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate first node of stack from top to bottom.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pc_ln: Interger representing the line numberassociate of the opcode.
 */
void rotl(stack_t **pcstack, __attribute__((unused))unsigned int pc_ln)
{
	stack_t *tmp;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		return;

	tmp = *pcstack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *pcstack;
	(*pcstack)->prev = tmp;
	*pcstack = (*pcstack)->next;
	(*pcstack)->prev->next = NULL;
	(*pcstack)->prev = NULL;
}


/**
 * rotr - Rotates last node of the stack from bottom to top.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pc_ln: Interger representing the line numberassociate of the opcode.
 */
void rotr(stack_t **pcstack, __attribute__((unused))unsigned int pc_ln)
{
	stack_t *tmp;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		return;

	tmp = *pcstack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *pcstack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*pcstack)->prev = tmp;
	(*pcstack) = tmp;
}

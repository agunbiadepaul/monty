#include "monty.h"

/**
 * mul_pcnodes - Multiply the top two elements of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representing the line number of of the opcode.
 */
void mul_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	int sum;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		more_error(8, pcline_number, "mul");

	(*pcstack) = (*pcstack)->next;
	sum = (*pcstack)->n * (*pcstack)->prev->n;
	(*pcstack)->n = sum;
	free((*pcstack)->prev);
	(*pcstack)->prev = NULL;
}


/**
 * mod_nodes - create a remainder to the top two elements of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representing the line number asociate of the opcode.
 */
void mod_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	int sum;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)

		more_error(8, pcline_number, "mod");


	if ((*pcstack)->n == 0)
		more_error(9, pcline_number);
	(*pcstack) = (*pcstack)->next;
	sum = (*pcstack)->n % (*pcstack)->prev->n;
	(*pcstack)->n = sum;
	free((*pcstack)->prev);
	(*pcstack)->prev = NULL;
}

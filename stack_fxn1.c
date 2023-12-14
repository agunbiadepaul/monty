#include "monty.h"

/**
 * nop - Performs no operation.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representing the line number ass of the opcode.
 */
void nop(stack_t **pcstack, unsigned int pcline_number)
{
	(void)pcstack;
	(void)pcline_number;
}


/**
 * swap_pcnodes - interchange the top two elements of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representing the line number asociate of the opcode.
 */
void swap_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	stack_t *tmp;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		more_error(8, pcline_number, "swap");
	tmp = (*pcstack)->next;
	(*pcstack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *pcstack;
	tmp->next = *pcstack;
	(*pcstack)->prev = tmp;
	tmp->prev = NULL;
	*pcstack = tmp;
}

/**
 * add_pcnodes - insert to the top two elements of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representng d line number asociatedof the opcode
 */
void add_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	int sum;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		more_error(8, pcline_number, "add");

	(*pcstack) = (*pcstack)->next;
	sum = (*pcstack)->n + (*pcstack)->prev->n;
	(*pcstack)->n = sum;
	free((*pcstack)->prev);
	(*pcstack)->prev = NULL;
}


/**
 * sub_pcnodes - minus the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representng the pcline number asociatedof the opcode.
 */
void sub_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	int sum;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)

		more_error(8, pcline_number, "sub");


	(*pcstack) = (*pcstack)->next;
	sum = (*pcstack)->n - (*pcstack)->prev->n;
	(*pcstack)->n = sum;
	free((*pcstack)->prev);
	(*pcstack)->prev = NULL;
}


/**
 * div_pcnodes - puty the top two elements of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Integer representng the line number associateof the opcode.
 */
void div_pcnodes(stack_t **pcstack, unsigned int pcline_number)
{
	int sum;

	if (pcstack == NULL || *pcstack == NULL || (*pcstack)->next == NULL)
		more_error(8, pcline_number, "div");

	if ((*pcstack)->n == 0)
		more_error(9, pcline_number);
	(*pcstack) = (*pcstack)->next;
	sum = (*pcstack)->n / (*pcstack)->prev->n;
	(*pcstack)->n = sum;
	free((*pcstack)->prev);
	(*pcstack)->prev = NULL;
}

#include "monty.h"


/**
 * add_stack - Pushes a node onto the stack.
 * @new_pcnode: Pointer to the new node.
 * @pc_ln: Integer representing the line number associated with the opcode.
 */
void add_stack(stack_t **new_pcnode, __attribute__((unused))unsigned int pc_ln)
{
	stack_t *tmp;

	if (new_pcnode == NULL || *new_pcnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_pcnode;
		return;
	}
	tmp = head;
	head = *new_pcnode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_pcstack - Prints the elements of the stack.
 * @pcstack: Pointer to a pointer pointing to the top node of the stack.
 * @pcline_number: Line number of the opcode.
 */
void print_pcstack(stack_t **pcstack, unsigned int pcline_number)
{
	stack_t *tmp;

	(void) pcline_number;
	if (pcstack == NULL)
		exit(EXIT_FAILURE);
	tmp = *pcstack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Removes the top node from the stack.
 * @pcstack: Pointer to a pointer pointing to the top node of the stack.
 * @pcline_number: Integer representing the line number
 * associated with the opcode.
 */
void pop_top(stack_t **pcstack, unsigned int pcline_number)
{
	stack_t *tmp;

	if (pcstack == NULL || *pcstack == NULL)
		more_error(7, pcline_number);

	tmp = *pcstack;
	*pcstack = tmp->next;
	if (*pcstack != NULL)
		(*pcstack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @pcstack: Pointer to a pointer pointing to top node of the stack.
 * @pcline_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **pcstack, unsigned int pcline_number)
{
	if (pcstack == NULL || *pcstack == NULL)
		more_error(6, pcline_number);
	printf("%d\n", (*pcstack)->n);
}

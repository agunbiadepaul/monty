#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the program.
 * @argc: Count of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_pcfile(argv[1]);
	free_pcnodes();
	return (0);
}

/**
 * create_pcnode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_pcnode(int n)
{
	stack_t *pcnode;

	pcnode = malloc(sizeof(stack_t));
	if (pcnode == NULL)
		error(4);
	pcnode->next = NULL;
	pcnode->prev = NULL;
	pcnode->n = n;
	return (pcnode);
}

/**
 * free_pcnodes - removes nodes in the stack one after the other.
 */
void free_pcnodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_queue - Enqueues a node.
 * @new_pcnode: Pointer to the new node.
 * @pc_ln: Line number associated with the opcode.
 */
void add_queue(stack_t **new_pcnode, __attribute__((unused))unsigned int pc_ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_pcnode;
	(*new_pcnode)->prev = tmp;

}

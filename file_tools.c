#include "monty.h"

/**
 * open_pcfile - opens a file
 * @pcfile_name: The file pathname.
 * Return: void
 */

void open_pcfile(char *pcfile_name)
{
	FILE *fd = fopen(pcfile_name, "r");

	if (pcfile_name == NULL || fd == NULL)
		error(2, pcfile_name);

	read_pcfile(fd);
	fclose(fd);
}


/**
 * read_pcfile - Reads a file.
 * @fd: Pointer to the file descriptor.
 * Return: void.
 */
void read_pcfile(FILE *fd)
{
	int pcline_number, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (pcline_number = 1; getline(&buffer, &length, fd) != -1; pcline_number++)
	{
		format = parse_pcline(buffer, pcline_number, format);
	}
	free(buffer);
}


/**
 * parse_pcline - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @pcline_number: line number
 * @format:  storage format. for 0, Nodes will be entered as a stack.
 * while 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_pcline(char *buffer, int pcline_number, int format)
{
	char *opcode, *pc_value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	pc_value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_pcfxnc(opcode, pc_value, pcline_number, format);
	return (format);
}

/**
 * find_pcfxnc - find the appropriate function for the opcode
 * @opcode: opcode
 * @pc_value: argument of opcode
 * @pc_ln: The line number.
 * @format:  storage format. when 0, Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_pcfxnc(char *opcode, char *pc_value, int pc_ln, int format)
{
	int i;
	int flag;

	instruction_t fxnc_list[] = {
		{"push", add_stack},
		{"pall", print_pcstack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_pcnodes},
		{"add", add_pcnodes},
		{"sub", sub_pcnodes},
		{"div", div_pcnodes},
		{"mul", mul_pcnodes},
		{"mod", mod_pcnodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; fxnc_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, fxnc_list[i].opcode) == 0)
		{
			call_fxn(fxnc_list[i].f, opcode, pc_value, pc_ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, pc_ln, opcode);
}


/**
 * call_fxn - Calls the necessary function.
 * @fxnc: Pointer to the function that is about to be called.
 * @pcop: string representing the opcode.
 * @pcval: string representing a numeric value.
 * @pc_ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fxn(op_fxnc fxnc, char *pcop, char *pcval, int pc_ln, int format)
{
	stack_t *pcnode;
	int flag;
	int a;

	flag = 1;
	if (strcmp(pcop, "push") == 0)
	{
		if (pcval != NULL && pcval[0] == '-')
		{
			pcval = pcval + 1;
			flag = -1;
		}
		if (pcval == NULL)
			error(5, pc_ln);
		for (a = 0; pcval[a] != '\0'; a++)
		{
			if (isdigit(pcval[a]) == 0)
				error(5, pc_ln);
		}
		pcnode = create_pcnode(atoi(pcval) * flag);
		if (format == 0)
			fxnc(&pcnode, pc_ln);
		if (format == 1)
			add_queue(&pcnode, pc_ln);
	}
	else
		fxnc(&head, pc_ln);
}

#include "monty.h"

/**
 * error - Displays appropriate error messages based on the given error code.
 * @pcerror_code: The error codes are as follows:
 * (1) => The user did not provide any file or provided more
 * than one file to the program.
 * (2) => The specified file cannot be opened or read.
 * (3) => The provided file contains an invalid instruction.
 * (4) => Memory allocation (malloc) has failed.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 */

void error(int pcerror_code, ...)
{
	va_list pcag;
	char *pcop;
	int pcl_num;

	va_start(pcag, pcerror_code);
	switch (pcerror_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(pcag, char *));
			break;
		case 3:
			pcl_num = va_arg(pcag, int);
			pcop = va_arg(pcag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", pcl_num, pcop);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(pcag, int));
			break;
		default:
			break;
	}
	free_pcnodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - Handles errors.
 * @pcerror_code: The error codes are as follows:
 * (6) => Attempting "pint" on an empty stack.
 * (7) => Attempting "pop" on an empty stack.
 * (8) => Stack is too short for the specified operation.
 * (9) => Division by zero.
 */
void more_error(int pcerror_code, ...)
{
	va_list pcag;
	char *pcop;
	int pcl_num;

	va_start(pcag, pcerror_code);
	switch (pcerror_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(pcag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(pcag, int));
			break;
		case 8:
			pcl_num = va_arg(pcag, unsigned int);
			pcop = va_arg(pcag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", pcl_num, pcop);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(pcag, unsigned int));
			break;
		default:
			break;
	}
	free_pcnodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @pcerror_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int pcerror_code, ...)
{
	va_list pcag;
	int pcl_num;

	va_start(pcag, pcerror_code);
	pcl_num = va_arg(pcag, int);
	switch (pcerror_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", pcl_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", pcl_num);
			break;
		default:
			break;
	}
	free_pcnodes();
	exit(EXIT_FAILURE);
}

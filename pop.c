#include "monty.h"
/**
 * s_pop - removes the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void s_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
		free_stack(stack);
}
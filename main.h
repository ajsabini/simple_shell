#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct tokenizar  - structura para guardar los tokens interactivos
 * @n: integer
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct tokenizar
{
	char *str;
	struct tokenizar *next;
			
} tokeniza;

void addnode(tokeniza **head, char *str);
void print_list(tokeniza *head);

#endif

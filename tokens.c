#include "main.h"

/**
 * addnode - agregar un token
 * @head: pasamos la direccion del head y lo recibe como doble puntero
 * @str: el token
 * Return - void
*/

void addnode(tokeniza **head, char *str)
{
	tokeniza *new = malloc(sizeof(tokeniza));

	new->str = str;
	new->next = *head;
	*head = new;
}

/**
 * print_list - imprime la linked list de tokens
 * @head: el token
 * Return - void
*/

void print_list(tokeniza *head)
{
	if (head->next)
		print_list(head->next);

	printf("head->str %s\n", head->str);
	free(head);
}

#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - funcion principal
 * @argc: cantidad de elementos pasados
 * @argv: la lista de argumentos
 * Return: Siempre 0
 */

int main(int argc, char *argv[])
{
		if (argc == 1)
		{
			(void)*argv;
			/*printf("%d", argc); interactivo*/
			char *buffer = NULL, *dev, *copia;
			char delimitador[] = " ";
			size_t buffsize = 0;
			ssize_t characters;
			int cent = 1, largo;
			tokeniza *head = NULL;

			while (cent != 0)
			{
				characters = getline(&buffer, &buffsize, stdin);
				largo = strlen(buffer);
				buffer[largo - 1] = '\0';
				copia = strdup(buffer);
				cent = strcmp(buffer, "end-of-file\n");
				if (characters == -1)
				{
					printf("\n");
					break;
				}
				dev = strtok(copia, delimitador);
				while (dev != NULL)
				{
					printf("%s\n", dev);
					addnode(&head, dev);
					dev = strtok(NULL, delimitador);
				}
				print_list(head);
				free(copia);
			}
			free(buffer);
		}
		else
		{
			/*printf("%d", argc); no int */
		}
		return (0);
}

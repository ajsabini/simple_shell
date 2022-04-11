#include "main.h"

/**
 * command - asads
 * @head: primer nodo
 * @path_concat: as
 * Return: as
 */

int command(tokeniza *head, char *path_concat)
{
	pid_t pid = 0;
	int i = 0, status = 0;
	tokeniza *aux = NULL;
	char **arg = NULL;

	aux = head;
	for (i = 0; aux; i++)
	{
		aux = aux->next;
	}
	i++;
	arg = malloc(i * sizeof(char *));
	if (!arg)
	{
		perror("");
		exit(98);
	}
	aux = head;
	for (i = 0; aux; i++)
	{
		arg[i] = aux->s;
		aux = aux->next;
	}
	arg[i] = NULL;
	pid = fork();
	if (pid == -1)
		perror("");
	if (pid == 0)
	{
		if (execve(path_concat, arg, environ) == -1)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(arg);
	return (WEXITSTATUS(status));
}

/**
 * _fsignal - captura la senial ctrl+c
 * @sig: la senial
 * Return: void
 */

void _fsignal(int sig)
{
	if (sig == SIGINT)
	{
		write(STDIN_FILENO, "\nOSHELL: ", 9);
	}
}

/**
 * _fexit - captura el exit y lo ejecuta
 * @buffer: lo que se ingreso
 * Return: int
 */

int _fexit(char *buffer)
{
	int i = 0, k = 0;
	char *acomp = NULL;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			k++;
	}

	acomp = (malloc(k + 1));
	k = 0;
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
		{
			acomp[k] = buffer[i];
			k++;
		}
	}
	acomp[k] = '\0';
	if (strcmp(acomp, "exit") == 0)
	{
		free(acomp);
		return (1);
	}
	free(acomp);
	return (0);
}

/**
 * cpy_environ - copiamos el environ
 * Return: la copia del
 */

char **cpy_environ()
{
	int i = 0;
	char **envir;

	for (i = 0; environ[i]; i++)
		;

	envir = malloc(i * (sizeof(char *)));

	for (i = 0; environ[i]; i++)
	{
		envir[i] = strdup(environ[i]);
	}
	envir[i] = NULL;
	return (envir);
}

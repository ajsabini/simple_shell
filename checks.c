#include "main.h"

/**
 * check_slash - chequea / para saber si es directorio
 * @buffer: lo que se ingreso
 * Return: si encontro / devuelve 1, sino 0
*/

int check_slash(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * check_space - chequea si hay espacios
 * @buffer: reibe lo que se ingreso
 * Return: 1 si hay algun arater distinto a espacio, sino 0
 */
int check_space(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			return (1);
	}
	return (0);
}

/**
 * buil_exit - cheque si es exit
 * @buffer: recibimos lo que escribieron
 * Return: 1 si escribieron exit, 0 si es otra cosa
 */

int built_exit(char *buffer)
{
	int status = 0;

	status = _fexit(buffer);
	if (status == 1)
		return (1);

	return (0);

}

/**
 *  built_env - chequea si ingresaron env
 *  @buffer: lo que imngresaron
 *  Return: void
 */

void built_env(char *buffer)
{
	int status = 0, i = 0;

	status = _env(buffer);
	if (status == 1)
	{
		for (i = 0; environ[i]; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
		}
	}
}

/**
 * change_tabs - as
 * @buffer: as
 * Return: void
 */

void change_tabs(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '	')
		{
			buffer[i] = ' ';
		}
	}
}


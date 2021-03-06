#include "main.h"

/**
 * main - simpleshell
 * Return: 0 si salio todo bien o el valor del error
 */

int main(void)
{
	char *buffer = NULL;
	size_t size = 0;
	int space = 0, status = 0, exitstatus = 0, slash = 0;
	tokeniza *directorys = NULL, *pwd = NULL, *old_pwd = NULL, *input = NULL;
	ssize_t characters;

	signal(SIGINT, _fsignal);
	while (EOF)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "OSHELL: ", 8);
		do { characters = getline(&buffer, &size, stdin);
		} while (buffer[0] == '\n' && characters > 1);
		if (characters == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		buffer[characters - 1] = '\0', change_tabs(buffer);
		exitstatus = built_exit(buffer);
		if (exitstatus == 1)
		{	free_all(buffer, old_pwd, pwd, directorys);
			return (status); }
		space = check_space(buffer);
		if (space != 0)
		{	tokenizer(buffer, &input, " ");
			slash = check_slash(input->s);
			if (strcmp(input->s, "env") == 0)
				built_env();
			else if (slash == 1)
				status = check_directory(input);
			else
			{	dirs(&directorys, &pwd, &old_pwd);
				status = check_files(directorys, input);
			}
			free_nodes(input), input = NULL; }
	}
	free_all(buffer, old_pwd, pwd, directorys);
	return (status);
}

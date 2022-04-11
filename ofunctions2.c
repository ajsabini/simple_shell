#include "main.h"
/**
 * dirs -as
 * @directorys: as
 * @pwd: as
 * @old_pwd: as
 * Return: sa
*/

void dirs(tokeniza **directorys, tokeniza **pwd, tokeniza **old_pwd)
{
	int  i = 0;
	char *path = NULL, *pwd_s = NULL, *old_pwd_s = NULL;
	char *token_path = NULL;

	old_pwd_s = get_oldpwd();
	if (strcmp(old_pwd, "ERROR") != 0)
	{
		token_path = strtok(old_pwd_s, "=");
		for (i = 0; token_path != NULL; i++)
		{
			if (i != 0)
				add_node(old_pwd, token_path);
			token_path = strtok(NULL, "=");
		}
	}
	path = get_path();
	if (strcmp(path, "ERROR") != 0)
	{
		token_path = strtok(path, "=");
		for (i = 0; token_path != NULL; i++)
		{
			if (i == 1)
				tokenizer(token_path, directorys, ":");
			token_path = strtok(NULL, "=");
		}
	}
	pwd_s = get_pwd();
	if (strcmp(pwd_s, "ERROR") != 0)
	{
		token_path = strtok(pwd_s, "=");
		for (i = 0; token_path != NULL; i++)
		{
			if (i != 0)
				add_node(pwd, token_path);
			token_path = strtok(NULL, "=");
		}
	}
	free(old_pwd_s);
	free(path);
	free(pwd_s);
}

/**
 * free_all - as
 * @buffer: as
 * @o_p: as
 * @pw: as
 * @direct: as
 * Return: void
 */

void free_all(char *buffer, tokeniza *o_p, tokeniza *pw, tokeniza *direct)
{
	free(buffer);
	free_nodes(o_p);
	free_nodes(pw);
	free_nodes(direct);
}

/**
 * _env - as
 * @buffer: as
 * Return: as
 */

int _env(char *buffer)
{
	char *laenv = "env", *acomp = NULL, *laenve = "env ";
	int i = 0, k = 0, m = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
		{
			k++;
		}
	}
	acomp = (malloc(k + 1));
	k = 0;
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
		{
			acomp[k] = buffer[i];
			m++;
		}
	}
	acomp[k] = '\0';
	if ((strcmp(acomp, laenv) == 0) || (strcmp(acomp, laenve) == 0))
	{
		free(acomp);
		built_env();
		return (1);
	}
	free(acomp);
	return (0);
}

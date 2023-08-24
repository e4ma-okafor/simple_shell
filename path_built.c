#include "main.h"

/**
 * is_buit - command line environment
 * @line: wherever
 * @env: add environment
 * Return: 1 on  success.
 */
int is_buit(char **line, char **env)
{
	int chdir_val = 0;

	if (_strcmp(line[0], "exit") == 0 && line[1] == NULL)
	{
		free_dp(line);
		return (1);
	}

	if (_strcmp(line[0], "cd") == 0)
	{
		if (!line[1])
		{
			chdir_val = chdir("..");
			if (chdir_val != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		chdir_val = chdir(line[1]);

		if (chdir_val != 0)
		{
			printf("Error changing directory to: %s\n", line[1]);
			return (1);
		}
		return (1);
	}

	if ((_strcmp(line[0], "env") == 0) && line[1] == NULL)
		_printenv(env);

	return (EXIT_SUCCESS);
}

/**
 * _printenv - prints the current environment
 * @envi: environment variable
 */

void _printenv(char **envi)
{
	int x;

	for (x = 0; envi[x]; x++)

		_puts(envi[x]);
}


/**
 * check_path - checkout the path
 * @env: the environment
 * @argv: argument values
 * Return: return -1
 */

int check_path(char **env, char **argv)
{
	int i;
	char *ruta;
	char **path;

	path = get_path(env);

	if (path == NULL || argv == NULL)
	{
		return (-1);
	}

	for (i = 0; path[i] != NULL; i++)
	{
		ruta = str_concat(path[i], argv[0]);
		if (access(ruta, F_OK & X_OK & R_OK) == 0)
		{
			free(argv[0]);
			*(argv) = ruta;
			free_dp(path);
			return (0);
		}
		free(ruta);
	}

	free_dp(path);
	return (access(argv[0], F_OK & X_OK & R_OK));
}


/**
 * count_chr - count how many char in delimits
 * @str: string
 * @delimits: char to find in str
 * Return: - the number
 */

int count_chr(char *str, char *delimits)
{
	int num = 0, i, j;

	if (str != NULL && delimits != NULL)
	{
		for (i = 0; delimits[i] != '\0'; i++)
			for (j = 0; str[j] != '\0'; j++)
				if (delimits[i] == str[j])
					num++;
	}
	return (num);
}


/**
 * get_path - get the PATH in the environment
 * @envi: enviroment variable
 * Return: the path
 */

char **get_path(char **envi)
{
	char *str = "PATH", *my_path, *aux, **paths;
	unsigned int i = 0, j = 0, size;

	if (envi == NULL)
	{
		return (NULL);
	}

	while (envi[i] != NULL)
	{
		aux = _strstr(envi[i], str);
		if (aux != NULL)
		{
			aux = _strdup(aux);
			size = count_chr(aux, PATH_DELIMIT) + BUFF_MAX;
			paths = (char **)malloc(sizeof(char *) * size);
			if (paths == NULL)
			{
				return (NULL);
			}
			my_path = strtok(aux, PATH_DELIMIT);
			while (my_path != NULL)
			{
				paths[j] = _strdup(my_path);
				if (paths[j] == NULL)
				{
					free(aux);
					return (free_dp(paths));
				}
				j++;
				my_path = strtok(NULL, PATH_DELIMIT);
			}
			paths[j] = NULL;
			free(aux);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

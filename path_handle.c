#include "main.h"

/**
 * get_line - Prints prompt and wait for a command
 * @isatty_val: no_interactive
 * Return: The read command (line)
 **/
char *get_line(int isatty_val)
{
	ssize_t read = 0;
	size_t bufer_len = 0;
	char *line = NULL;

	if (isatty_val == 1)
	{
	write(STDOUT, "\033[1;31m$ ", 32);
	write(STDOUT, "\033[0m", 4);
	}

	read = getline(&line, &bufer_len, stdin);

	if (read == EOF)
	{
		if (isatty_val == 1)
		{
			printf("\n");
		}
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}


/**
 * check_path -function that checkout the path
 * @env: wherever
 * @argvs: wherever
 * Return: return -1
 */
int check_path(char **env, char **argvs)
{
	int i;
	char *ruta;
	char **paths;

	paths = get_path(env);

	if (paths == NULL || argvs == NULL)
		return (-1);

	for (i = 0; paths[i] != NULL; i++)
	{
		ruta = str_concat(paths[i], argvs[0]);
		if (access(ruta, F_OK & X_OK & R_OK) == 0)
		{
			free(argvs[0]);
			*(argvs) = ruta;
			free_dp(paths);
			return (0);
		}
		free(ruta);
	}

	free_dp(paths);
	return (access(argvs[0], F_OK & X_OK & R_OK));
}


/**
 * count_chr - count how many chr  delimitn have *srt
 * @str: string
 * @delimits: char to find in str
 * Return: - int number
 */

int count_chr(char *str, char *delimits)
{
	int result = 0, i, j;

	if (str != NULL && delimits != NULL)
	{
		for (i = 0; delimits[i] != '\0'; i++)
			for (j = 0; str[j] != '\0'; j++)
				if (delimits[i] == str[j])
					result++;
	}
	return (result);
}


/**
 * get_path - get the PATH in the environment
 * @env: enviroment var
 * Return: double ponter with each route in the path.
 */
char **get_path(char **env)
{
	char *str = "PATH", *my_path, *aux, **paths;
	unsigned int i = 0, j = 0, size;

	if (env == NULL)
		return (NULL);

	/* loop for find the PATH var, in the **env */
	while (env[i] != NULL)
	{
		aux = _strstr(env[i], str);
		if (aux != NULL)
		{
			aux = _strdup(aux);
			size = count_chr(aux, PATH_DELIMIT) + BUFF_MAX;
			paths = (char **)malloc(sizeof(char *) * size);

			if (paths == NULL)
				return (NULL);
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

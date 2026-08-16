#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void	start(void);

int	main()
{
	start();
	return (0);
}

int	find_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	size;

	size = 0;
	while (str[size] && find_sep(str[size], charset) != 1)
		size++;
	return (size);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (find_sep(str[i], charset) == 1)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	*make_str (char *str, int size)
{
	int	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (0);
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**box;
	int	i;
	int	num;
	int	len;

	i = 0;
	num = word_count(str, charset);
	box = (char **)malloc(sizeof(char *) * (num + 1));
	while (*str)
	{
		if (!find_sep(*str, charset))
		{
			len = ft_strlen(str, charset);
			box[i] = make_str(str, len);
			str += len;
			i++;
		}
		else
			str++;

	}
	box[i] = NULL;
	return (box);
}

void	free_all(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
	free(data);
	return ;
}

void	start(void)
{
	char	tmp[100];
	char	**input;
	int	status;
	char	*path;
	int	result;
	char	**directory_list;
	int	index;

	pid_t pid;
	index = -1;
	directory_list = (char **)malloc(sizeof(char *) * 100);
	if (!directory_list)
		return ;
	while (1)
	{
		pid = -1;
		printf("# ");
		fgets(tmp, 100, stdin);
		input = ft_split(tmp, " \n");

		if (!strcmp(input[0], "exit") || !strcmp(input[0], "quit"))
		{
			free_all(input);
			free_all(directory_list);
			return ;
		}
		
		if (!strcmp(input[0], "cd") || !strcmp(input[0], "chdir"))
		{
			path = (char *)malloc(100);
			result = chdir(input[1]);
			path = getcwd(path, 100);
			if (result == -1)
				printf("\'chdir\' to \'%s\' is failed.\n", input[1]);
			printf("%s\n", path);
			free(path);
			free_all(input);
			continue;
		}
		
		if (!strcmp(input[0], "pushd"))
		{
			directory_list[++index] = make_str(input[1], strlen(input[1]));
			free_all(input);
			continue;
		}
		if (!strcmp(input[0], "popd"))
		{
			if (index < 0)
			{
				printf("popd: directory stack empty\n");
				free_all(input);
				continue;
			}
			path = (char *)malloc(100);
			result = chdir(directory_list[index]);
			path = getcwd(path, 100);
			if (result == -1)
				printf("\'chdir\' to \'%s\' is failed.\n", directory_list[index]);
			printf("%s\n", path);
			free(path);
			free(directory_list[index]);
			free_all(input);
			index--;
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			execvp(input[0], input);
			printf("\'execvp(%s)\' is failed\n", input[0]);
			exit(1);
		}
		else if (pid > 0)
		{
			wait(&status);
			printf("(%d)\n", pid);
		}
		else
			perror("fork failed\n");
		free_all(input);
	}
	free(directory_list);
}

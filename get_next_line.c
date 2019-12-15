#include "get_next_line.h"
#include <unistd.h>

static ssize_t	get_newline(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		get_line(char **ptr, char **line)
{
	char	*tmp;
	ssize_t	i;
	int		k;

	k = 0;
	if (*ptr == NULL)
		return (k);
	i = get_newline(*ptr);
	tmp = NULL;
	if (**ptr != '\0')
	{
		k = 1;
		if (i == -1)
			*line = ft_strjoin(line, ptr, 2);
		else
		{
			tmp = ft_strndup(*ptr, i);
			*line = ft_strjoin(line, &tmp, 2);
			tmp = ft_strndup(*ptr + i + 1, ft_strlen(*ptr + i + 1));
		}
	}
	free(*ptr);
	*ptr = tmp;
	return (k);
}

static int	read_line(int fd, char **ptr, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*ptr_buff;
	char	*str;
	int		i;

	str = *ptr;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		ptr_buff = buff;
		*ptr = ft_strjoin(ptr, &ptr_buff, 1);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if (get_newline(*ptr) != -1)
			break ;
	}
	if (i == 0 && (str == NULL || *str == '\0'))
	{
		get_line(ptr, line);
		free(*ptr);
		return (0);
	}
	return ((i != -1 && *ptr != NULL) ? get_line(ptr, line) : i);
}

int			get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	int			i;

	i = -1;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		*line = ft_strndup("", 0);
		i = get_line(&str, line);
		if (str == NULL || *line == NULL)
			i = read_line(fd, &str, line);
	}
	return (i);
}

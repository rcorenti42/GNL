#include "get_next_line.h"
#include <stdio.h>

void	ft_memdel(void **ap)
{
	if (ap != (void *)0)
	{
		free(*ap);
		*ap = (void *)0;
	}
}

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac > 1)
	if (fd == -1)
		return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d |>>| %s\n", ret_value, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

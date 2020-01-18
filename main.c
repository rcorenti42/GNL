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

int		main(int argc, char **argv)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ret_value = 1;
	if (!argc)
		return(0);
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d |>>| %s\n", ret_value, line);
		ft_memdel((void **)&line);
	}
	close(fd);
	return (0);
}

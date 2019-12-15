#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char **s2, int i);
char	*ft_strndup(const char *s, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif

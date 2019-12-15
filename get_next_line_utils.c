#include "get_next_line.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char		*ft_strndup(const char *s, size_t size)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (size > i)
		size = i;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, size);
		str[size] = '\0';
	}
	return (str);
}

char		*ft_strjoin(char **s1, char **s2, int i)
{
	char	*str;
	size_t	len;

	if (*s1 != NULL && *s2 != NULL)
	{
		len = ft_strlen(*s1) + ft_strlen(*s2);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			ft_memcpy(str, *s1, ft_strlen(*s1));
			ft_memcpy(str + ft_strlen(*s1), *s2, ft_strlen(*s2));
			str[len] = '\0';
		}
	}
	else
		str = *s1 == NULL ? ft_strndup(*s2, ft_strlen(*s2)) :
			ft_strndup(*s1, ft_strlen(*s1));
	free(*s1);
	*s1 = NULL;
	if (i == 2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (str);
}

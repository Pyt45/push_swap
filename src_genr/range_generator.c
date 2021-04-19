#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
/*
int		nbr_len(int d)
{
	int			len;
	len = (d == 0) ? 1 : 0;

	while (d > 0)
	{
		d /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	int		len;

	len = 1;
	n < 0 ? ++len : 0;
	nbr = n < 0 ? -(long)n : n;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	n < 0 ? *ptr = '-' : 0;
	nbr = n < 0 ? -(long)n : n;
	while (nbr > 9)
	{
		ptr[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	ptr[--len] = nbr + '0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr1;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc((strlen(s1) + strlen(s2) + 1) *
		sizeof(char))))
		return (NULL);
	ptr1 = ptr;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr1);
}

int     *range_gen(int range, int min, int max)
{
    int     i;

    int *arr = malloc(sizeof(int) * range);
    srand(clock());
    for (i = 0; i < range; i++)
        arr[i] = rand() % (max - min  + 1) + min;
    return (arr);
}

int     main(int argc, char **argv)
{
    int     fd;
    int     i;
    int *a = range_gen(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    for (i = 0; i < atoi(argv[1]); i++)
        printf("%d ", a[i]);
    fd = open("rand_num", O_WRONLY | O_CREAT | O_TRUNC, 0660);
    i = 0;
    while (i++ < atoi(argv[1]))
        write(fd, ft_strjoin(ft_itoa(a[i]), " "), strlen(ft_strjoin(ft_itoa(a[i]), " ")));
    close(fd);
    printf("\n");
}*/

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char*)s++) = (unsigned char)0x00;
}

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return ((void*)s);
}

int		check_dup(int *arr, int gen, int pos)
{
	int		i;

	i = 0;
	while (i < pos)
	{
		if (arr[i++] == gen)
			return (0);
	}
	return (1);
}

void	generate_random_num(int *arr, int range)
{
	int		i;
	int		gen;

	i = 0;
	srand(clock());
	while (i < range)
	{
		gen = rand() % range;
		if (check_dup(arr, gen, i))
			arr[i++] = gen;
	}
}

int		*range_gen(int range)
{
	int		*arr;

	arr = ft_memalloc(sizeof(int) * range);
	generate_random_num(arr, range);
	return (arr);
}

int     main(int argc, char **argv)
{
	int		range;
	int		*arr;

	range = atoi(argv[1]);
	arr = range_gen(range);
	while (range--)
		printf("%d ", arr[range]);
	printf("\n");
	free(arr);
}
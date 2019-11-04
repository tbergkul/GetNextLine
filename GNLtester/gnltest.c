#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		tmp;
	int		x;

	x = 1;
	printf("\n------------START-------------\n");
	while (x <= ac)
	{
		fd = open(av[x], O_RDONLY);
		while ((tmp = get_next_line(fd, &line) > 0))
		{
			if (tmp > 0)
				printf("%s\n", line);
		}
		x++;
	}
	return (0);
}

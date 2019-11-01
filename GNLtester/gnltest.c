#include "../get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*line;
	int		x;

	x = ac;
	//line = av[1];
	printf("------------START-------------\n");
	while (x >= 1)
	{
		if (get_next_line(ac, &line) >= 0)
			printf("Ny rad\n");
		x--;
	}
	return (0);
}

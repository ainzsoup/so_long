#include "so_long.h"
size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return i;
}

int get_width(int x)
{
	int fd = open("map.ber", O_RDONLY);
	char *line = get_next_line(fd);
	close(fd);
	return ((ft_strlen(line) - 1) * x);
}


int get_height(int y)
{
	char *line;
	int fd;

	fd = open("map.ber", O_RDONLY);
	
	int i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (!line[0] || line[0] == '\n')
			break;
		line = get_next_line(fd);
		i++;
	}
	return (i * y);
}

// int main()
// {
// 	printf ("%d \n", get_height(50));
// 	return (0);
// }
#include "so_long.h"

int lines(int fd)
{
	char *line;
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
	return (i);
}

char **store_map(int fd, int line)
{
	int j = 0;
	char **map;
	int end = line;
	map = malloc(sizeof(char *) * (end + 1));
	while (j < end)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	map[j] = 0;
	return map;
}

char **get_map(int fd)
{
	int line = lines(fd);
	close (fd);
	fd = open ("map.ber", O_RDONLY);
	return(store_map(fd, line));
}


// int main()
// {
// 	int fd = open("map.ber", O_RDONLY);
// 	char **map = get_map(fd);
// 	if (check_map(map))
// 			printf("naaadi\n");
// 	else
// 		printf("khaaaari\n");
// 	return 0;
// }
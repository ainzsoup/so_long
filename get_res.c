#include "so_long.h"

int get_width(char **map)
{
	return (ft_strlen(map[0]) - 1);
}

int get_height(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}

// int main()
// {
// 	printf ("%d \n", get_height(50));
// 	return (0);
// }
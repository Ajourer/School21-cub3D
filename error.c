#include "cub.h"

void error(int error, t_all *all)
{
	if (error == 1)
		printf("Error\nMalloc fail!\n");
	if (error == 2)
		printf("Error\nInvalid map!\n");
	if (error == 3)
		printf("Error\nInvalid file name!\n");
	if (error == 4)
		printf("Error\nInvalid argument!\n");
	if (error == 5)
		printf("Error\nFile can't be opened!\n");
	if (error == 6)
		printf("Error\nWrong file\n");
	if (error == 7)
		printf("Error\nInvalid texture");
	free_all(all);
	exit(1);
}
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define n 9
int **create_sudoku(char **argv)
{
	int **sudoku;
	int	i;
	int	j;

	i = 0;
	j = 0;
	*argv = (malloc(sizeof(int) * 9));
	//**argv = (malloc(sizeof(int) * 9));
	while (i < n)
	{
		while (j < n)
		{
			if (argv[i + 1][j] > 48 && argv[i + 1][j] < 58)
				sudoku[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				sudoku[i][j] = 0;
			//else
				//return 1;
			j++;
		}
		i++;
		printf("\n");
	}
	return (sudoku);
}

int main(int argc, char **argv)
{
	int **sudoku;
	sudoku = create_sudoku(argv);
	printf("%i ", sudoku);
	return (0);
}
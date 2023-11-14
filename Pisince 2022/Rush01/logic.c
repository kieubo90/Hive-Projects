#include <unistd.h>
#include <stdlib.h>
#define n 9

void ft_putchar(char c)
{
	write (1,&c,1);
}

int	**create_sudoku(char **argv)
{
	int **sudoku;
	int i;
	int j;

	i = 0;
	j = 0;
	//sudoku = (int)malloc((sizeof(char *)) * 81);
	sudoku = malloc(sizeof(int *) * 81);
	while (i < n)
	{
		sudoku[i] = malloc(sizeof(int));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		while (j < 9)
		{
			if (argv[i + 1][j] == '.')
				sudoku[i + 1][j] = 0;
			else if( 48 < argv[i + 1][j] && argv[i + 1][j] < 58)
				sudoku[i + 1][j] = argv[i + 1][j] - '0';
			j++;
		}
		i++;
	}
	return (sudoku);
}

void	print_sudoku(int **sudoku)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(sudoku[i][j] + '0');
			j++;
		}
		i++;
	}
}

int	in_row(int **sudoku, int row, int number)
{
	int column;

	column = 0;
	while (column < n)
	{
		if (sudoku[row][column] == number)
			return (1);
		column++;
	}
	return (0);
}

int	in_column(int **sudoku, int column, int number)
{
	int row;

	row = 0;
	while (row < n)
	{
		if (sudoku[row][column] == number)
			return (1);
		row++;
	}
	return (0);
}

int	in_box(int **sudoku, int row, int column, int number)
{
	int x;
	int y;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			if (sudoku[x + row][y + column] == number)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
int	check_if_legal(int **sudoku, int row, int column, int number)
{
	if (!in_row(sudoku, row, number) &&
		!in_column(sudoku, column, number) &&
		!in_box(sudoku, row - (row % 3), column - (column % 3), number))
		return (1);
	return (0);
}

int	solve_it(int **sudoku)
{
	int row;
	int column;
	int number;

	row = 0;
	column = 0;
	number = 1;
	while (number <= 9)
	{
		if (check_if_legal(sudoku, row, column, number))
		{
			sudoku[row][column] = number;
			if (solve_it(sudoku))
				return (1);
		}
		sudoku[row][column] = 0;
		number++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int **sudoku;

	sudoku = create_sudoku(argv);
	print_sudoku(sudoku);
	solve_it(sudoku);
	print_sudoku(sudoku);
	return (0);
}